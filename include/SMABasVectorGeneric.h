//-*- mode: c++ -*-//
#ifndef SMABasVectorGeneric_H
#define SMABasVectorGeneric_H

#include <assert.h>

// Begin local includes
#include <SMABasGenerics.h>
#include <mem_C_Allocation.h>
#include <SMABasReplicator.h>
// End local includes

class SMABasVectorAllocator 
{
public:
  SMABasVectorAllocator() {} 

  static void* allocate(size_t __n) {  
	return mem_Malloc_Handled(__n); 
  }
  static void  deallocate(void* __p, size_t __n) {  
	mem_Free(__p);
  }
};


struct SMABasVectorGenericIterator
{
  int   m_size;
  char* m_pointer;

  inline void* Dereference(){ return m_pointer; }

  void Set( void* pointer) { m_pointer = reinterpret_cast<char*>( pointer );}

  void Increment() { m_pointer += m_size; } 

  void Decrement() { m_pointer -= m_size; }
};



/// Generic Vector class, free of type knowledge

class SMABasVectorGeneric 
{
 public:


  // ----   Ctors/Dtor  -------------------------------------------------
  //
  //  The ctors are contrived to be split into two so that SMABasVector can
  /// get a back-door in.
  //

  // Some of these constructors are no longer called, so I've commented them out.
  /// The equivalent is called on
  // the strongly-typed vector.

  //   SMABasVectorGeneric(  )
  //     : m_replicator(),
  //       m_start(0), 
  //       m_finish(0), 
  //       m_end_of_storage(0) 
  //   {}

  inline SMABasVectorGeneric(const SMABasReplicatorGeneric& replicator, 
  			     size_t __n, const void* __valp)
    : m_replicator(replicator),
      m_start(0), 
      m_finish(0), 
      m_end_of_storage(0) 
  {
    Init( __n, __valp);
  }
  void Init( size_t __n, const void* __valp);


  //   SMABasVectorGeneric(const SMABasReplicatorGeneric& replicator,
  //                       const void* __first, const void* __last)
  //     : 
  //     m_replicator(replicator),
  //     m_start(0), 
  //     m_finish(0), 
  //     m_end_of_storage(0) 
  //   { 
  //     Init( __first, __last);
  //   }
  void Init( const void* __first, const void* __last);


  SMABasVectorGeneric( const SMABasVectorGeneric& v):  
    m_replicator(v.m_replicator),
    m_start(0), 
    m_finish(0), 
    m_end_of_storage(0)
  {
    Init( v);
  }
  void Init(const SMABasVectorGeneric&);

  ~SMABasVectorGeneric(){
    Destroy(m_start, Size());
    Deallocate(m_start, Capacity()); 
  }

  // ----------------------------------------------------------------------

  SMABasVectorGeneric& operator=( const SMABasVectorGeneric& other){
    SMABasVectorGeneric temp( other);
    temp.swap(*this);
    return *this;
  }

  void * operator[](size_t i){
    assert(0 <= i && i < Size());
    return Item(i);
  }

  const void * operator[](int i) const {
    assert(0 <= i && i < Size());
    return ItemConst(i);
  }
  
  void        Reserve(size_t newCapacity);

  size_t      Size() const     { return (m_finish - m_start) / m_replicator.m_size;  }
  size_t      Capacity() const { return (m_end_of_storage-m_start) / m_replicator.m_size; }

  void*       Begin()       { return m_start; }
  const void* Begin() const { return m_start; }

  void*       End()         { return m_finish; }
  const void* End() const   { return m_finish; }

  void        Resize(size_t new_size, const void* __xp);

  void        PushBack(const void* __valp);

  void*       Erase(void* __position);
  void*       Erase(void* __first, void* __last);

  void        Insert(void* __position, const void* __first, const void* __last);
  char*       Insert(void* __position, const void* __valp);
  void        Insert(void* __position, size_t __n, const void* __xp);

  void        PopBack();

  void        Assign(const size_t __n, const void* __valp);

  void        Clear();  

  void        swap( SMABasVectorGeneric& other);

  void        RangeCheck(size_t __n) const; /// This function is for debugging and correctness checks.
                                            /// When in ABAQUS and in DEBUG mode, it will throw an
                                            /// exception if index __n into the vector is out-of-bounds.
                                            /// "No-op" in all other cases.
private:

  inline char*  Allocate(size_t __n) { 
    if(__n == 0)
      return 0;
    else
      return reinterpret_cast<char*>( m_allocator.allocate(__n * m_replicator.m_size )); 
  }

  inline void  Deallocate(void* __p, size_t __n) {
    if( __p != 0)
      m_allocator.deallocate(__p, __n); 
  }

  inline void Destroy(void* first) {
	if(m_replicator.m_destroy) 
	   m_replicator.m_destroy(first,1);
  }

  inline void Destroy(void* first, size_t __n) {
	if(m_replicator.m_destroy) 
	   m_replicator.m_destroy(first,__n);
  }

  inline void* Item(int i){
    return m_start + i*m_replicator.m_size;
  }
  inline void* ItemConst(int i) const {
    return m_start + i*m_replicator.m_size;
  }

  void  GrowCapacity(size_t sizeIncrease);

  /// returns distance between two pointers in number of items
  inline size_t  distance(const void* end, const void* start) 
  {
	return ( reinterpret_cast<const char*>(end) - 
             reinterpret_cast<const char*>(start) ) / m_replicator.m_size;
  }

  /// Is each byte of value the same?
  inline bool sameBytes( const void* value){
    const char* valp = reinterpret_cast<const char*>(value);
    char val0 = *valp;
    for( int k=1; k < m_replicator.m_size; k++)
      if( valp[k] != val0)
	return false;
    return true;
  }

  /// Copies __val into each slot from __first to __last.
  /// Has a side effect of advancing the __first pointer.
  inline void   fill(char* __first, char* __last, const void* __valp) {
    // POD-memset optimization:  if holding PODs, call memset if all bytes are the
    // same.  This can be of great value when initializing large vectors
    // of builtins or other PODs.
    if(! m_replicator.m_destroy ) { // We have a POD
      if ( __last - __first > 3 * m_replicator.m_size // at least 4 items
	   && sameBytes(__valp)) // and all bytes the same
	{
	  memset(__first,
		 *reinterpret_cast<const char*>(__valp),
		 __last - __first);
	  return;
	}
    }
    for ( ; __first != __last; __first += m_replicator.m_size)
      m_replicator.m_copy(__valp,__first,1);
  }

  /// Writes __val __n times in memory location, starting from __first.
  /// Returns a pointer one past the last written item.

  inline char*   fill_n(char* __first, size_t __n, const void* __valp) 
  {
    // POD-memset optimization:  if holding PODs, call memset if all bytes are the
    // same.  This can be of great value when initializing large vectors
    // of builtins or other PODs, to 0, (of -1 for ints).
    if(! m_replicator.m_destroy ) { // We have a POD
      if ( __n > 3 // at least 4 items
	   && sameBytes(__valp)) // and all bytes the same
	{
	  memset(__first,
		 *reinterpret_cast<const char*>(__valp),
		 __n* m_replicator.m_size);
	  return __first + __n* m_replicator.m_size;
	}
    }
    for ( ; __n > 0; --__n, __first += m_replicator.m_size)
      m_replicator.m_copy(__valp,__first,1);
    return __first;
  }

  inline char*   copy_backward(void* __first, char* __last, char* __result) 
  {
	while ((char*)__first != __last) {
	  __result -= m_replicator.m_size;
	  __last   -= m_replicator.m_size;
	  m_replicator.m_copy(__last,__result,1);
	}
	return __result;
  }

  inline char* copy_over(const void* __first, const void* __last, void* __result)
  {
	   char* __dest = reinterpret_cast<char*>( __result ); 
	   size_t items = distance(__last,__first);
	   m_replicator.m_copy(__first,__dest,items);
	   __dest += items*m_replicator.m_size;
	   return __dest;
  }

  inline const size_t& LargerOf(const size_t& __a, const size_t& __b) 
  {
	return  __a < __b ? __b : __a;
  }


  void InsertAux(void* __position, const void* __valp);


  // Data Members

  SMABasVectorAllocator    m_allocator;
  SMABasReplicatorGeneric  m_replicator;

  char*                    m_start;     // pointer to data
  char*                    m_finish;    // pointer to one past the last element
  char*                    m_end_of_storage;
};


#endif // SMABasVectorGeneric_H

