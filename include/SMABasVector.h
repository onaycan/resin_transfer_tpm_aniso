//-*- mode: c++ -*-//
#ifndef SMABasVector_h
#define SMABasVector_h

/// SMABasVector
/// Nick Monyatovsky, David Reynolds, Dec 2008-
/// 
/// Simulia Generic vector. Same interface as std::vector.
/// Unlike std::vector, this works under both Explicit and Automatic Template Instantiation Modes.
/// In addition, this does not cause code bloat and compiles much more quickly.
///
/// Objects to be placed in a vector must conform to two requirements (just as in STL):
///  * must be CopyConstructible ( must have the copy constructor )
///  * must be Assignable ( must have the assigment operator )

/*
 *
 * Copyright (c) 1994
 * Hewlett-Packard Company
 *
 * Permission to use, copy, modify, distribute and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation.  Hewlett-Packard Company makes no
 * representations about the suitability of this software for any
 * purpose.  It is provided "as is" without express or implied warranty.
 *
 *
 * Copyright (c) 1996
 * Silicon Graphics Computer Systems, Inc.
 *
 * Permission to use, copy, modify, distribute and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation.  Silicon Graphics makes no
 * representations about the suitability of this software for any
 * purpose.  It is provided "as is" without express or implied warranty.
 */
/* Modifications © Dassault Systèmes, 2009 */


// Begin local includes
#include <SMABasGenerics.h>
// End local includes


#if SMA_USE_NATIVE_STL

#include <vector>
using std::vector;
#define SMABasVector std::vector

#else

#include <assert.h>
#include <string.h>

// Begin local includes
#include <SMABasPair.h>
#include <SMABasIterator.h>
#include <SMABasAlgoGeneric.h>
#include <SMABasVectorGeneric.h>
#include <mem_AllocationOperators.h>
#include <SMABasAlgorithm.h>
// End local includes


template <class T>
class SMABasVector : public mem_AllocationOperators
{
public:
  typedef T                  value_type;
  typedef value_type*        pointer;
  typedef const value_type*  const_pointer;
  typedef value_type*        iterator;
  typedef const value_type*  const_iterator;
  typedef value_type&        reference;
  typedef const value_type&  const_reference;
  typedef size_t             size_type;
  typedef ptrdiff_t          difference_type;
  typedef SMABasVectorAllocator allocator_type;

  allocator_type get_allocator() const { return allocator_type(); }


  SMABasVector()
    :
    m_replicator(SMABasGetReplicator<T>()),
    m_start(0), 
    m_finish(0), 
    m_end_of_storage(0) 
  {}
  
  SMABasVector( SMABasVector<T> const& other)
    :
    m_replicator(SMABasGetReplicator<T>())
  {
    Generic().Init(other.Generic());
  }
  
  SMABasVector(size_type __n, const T& value) 
    :
    m_replicator(SMABasGetReplicator<T>()),
    m_start(0), 
    m_finish(0), 
    m_end_of_storage(0)
  {
    Generic().Init( __n, &value) ;
  }

  SMABasVector(const T* __first, const T* __last)
    :
    m_replicator(SMABasGetReplicator<T>()),
    m_start(0), 
    m_finish(0), 
    m_end_of_storage(0) 
  {
    Generic().Init(  __first, __last);
  }

  explicit SMABasVector(size_type __n)  
    :
    m_replicator(SMABasGetReplicator<T>()),
    m_start(0), 
    m_finish(0), 
    m_end_of_storage(0) 
  {
    const T __t = T();
    SMABasVector<T> temp( __n, __t ); 
    swap(temp);
  }

  SMABasVector& operator=( const SMABasVector<T>& other){
    Generic() = other.Generic();
    return *this;
  }

  // Forward the destructor
  inline ~SMABasVector(){
    (this->Generic()).SMABasVectorGeneric::~SMABasVectorGeneric();
  }

  void swap(SMABasVector<T>& __x)
  { 
    Generic().swap(__x.Generic());
  }
  
  // -----------------------------------------------


  iterator         begin()       { 	return reinterpret_cast<iterator>(Generic().Begin()); }
  const_iterator   begin() const { 	return reinterpret_cast<const_iterator>(Generic().Begin());}

  iterator         end()         { 	return reinterpret_cast<iterator>(Generic().End()); }
  const_iterator   end() const   { 	return reinterpret_cast<const_iterator>(Generic().End());}

  size_type        size() const      {  return Generic().Size();  }
  size_type        max_size() const  {  return size_type(-1) / sizeof(T); }
  size_type        capacity() const  {  return Generic().Capacity(); }
  bool             empty() const     {  return begin() == end(); }

  reference        front()           { return *begin(); }
  const_reference  front() const     { return *begin(); }

  reference        back()            { return *(end() - 1); }
  const_reference  back() const      { return *(end() - 1); }

  reference       operator[](size_type __n)       { 
	assert(__n <= Generic().Size()); 
	return *(begin() + __n); 
  }

  const_reference operator[](size_type __n) const { 
	assert(__n <= Generic().Size()); 
	return *(begin() + __n); 
  }

  void reserve(size_type __n)                { Generic().Reserve(__n);   }

  void assign(size_type __n, const T& __val) { Generic().Assign(__n, &__val); }

  void push_back(const T& __x)               { Generic().PushBack(&__x);   }
  void push_back()                           { push_back( T() );   }

  void pop_back()  { 	Generic().PopBack();    }


  /// Performance caution: know the implementation of insert in a 
  /// vector;  it is not necessarily fast.
  iterator insert(iterator __position, const T& __x) 
  {
	return fromGeneric(Generic().Insert(__position,&__x));
  }

  iterator insert(iterator __position) 
  {
	return insert(__position, T()  );
  }

  void insert(iterator __position, const_iterator __first, const_iterator __last) 
  {
	Generic().Insert(__position, __first, __last );
  }

  void insert (iterator __position, size_type __n, const T& __x)
  { 
	Generic().Insert(__position, __n, &__x);
  }

  /// Performance caution: know the implementation of erase in a 
  /// vector;  it is not necessarily fast.
  iterator erase(iterator __position) 
  {
	return fromGeneric(Generic().Erase(__position));
  }

  iterator erase(iterator __first, iterator __last) 
  {
	return fromGeneric(Generic().Erase(__first,__last));
  }


  // --------  resize.  
  // 
  /// Resize. Sets the vector to new size.
  /// If newsize > old, inserts fill elements copy of provided
  /// default elements.
  void resize(size_type __new_size, const T& fillElement) 
  {
	Generic().Resize(__new_size, &fillElement);
  }

  /// Resize: fill element is default-constructed.
  void resize(size_type __new_size)
  { 
	resize(__new_size, T()); 
  }

  /// Empties vector: like resize(0).
  void clear() 
  { 
	Generic().Clear(); 
  }



  reference at(size_type __n) 
  { 
	range_check(__n); return (*this)[__n]; 
  }

  const_reference at(size_type __n) const 
  { 
	range_check(__n); return (*this)[__n]; 
  }

protected:


  // For 'cast' to 'true' vector generic.
  inline SMABasVectorGeneric& Generic() { return reinterpret_cast<SMABasVectorGeneric&>(*this);}
  inline SMABasVectorGeneric const& Generic() const { return reinterpret_cast<SMABasVectorGeneric const&>(*this);}
  
  
  // Converter methods toGeneric and fromGeneric

   inline char* toGeneric(T* tp) {
	 return reinterpret_cast<char*>(tp);
   }
   inline const char* toGeneric(const T* tp) {
	 return reinterpret_cast<const char*>(tp);
   }
   inline T* fromGeneric(char* gp) {
	 return reinterpret_cast<T*>(gp);
   }
   inline T* fromGeneric(void* gp) {
	 return reinterpret_cast<T*>(gp);
   }
   inline const T* fromGeneric(char* const gp) const {
	 return reinterpret_cast<const T*>(gp);
   }

   /// optimization for int
   // inline void Destroy(int* first) {  }
   // inline void Destroy(int* first, int* last) {  }

   /// optimization for unsigned int
   // inline void Destroy(unsigned int* first) {  }
   // inline void Destroy(unsigned int* first, unsigned int* last) {  }

   /// optimization for long long
   // inline void Destroy(long long* first) {  }
   // inline void Destroy(long long* first, long long* last) {  }

   /// optimization for unsigned unsigned long long
   // inline void Destroy(unsigned long long* first) {  }
   // inline void Destroy(unsigned long long* first, unsigned long long* last){ }

   /// optimization for unsigned unsigned float
   // inline void Destroy(float* first) {  }
   // inline void Destroy(float* first, float* last) {  }

   /// optimization for unsigned unsigned __int64
   // inline void Destroy(double* first) {  }
   // inline void Destroy(double* first, double* last) {  }

   // inline void Destroy(SMABasTstGenericsClass* first) {  
   //	   Generic().Destroy(first);
   //}
   //inline void Destroy(SMABasTstGenericsClass* first, 
   //                    SMABasTstGenericsClass* last) {  
   //   for ( ; first != last; ++first)
   //     Generic().Destroy(first);
   //}

   // inline void Destroy(T* first) {
   //	   Generic().Destroy(first);
   // }

   // inline void Destroy(T* first, T* last) {
   //	 for ( ; first != last; ++first)
   //	   Generic().Destroy(first);
   // }

   /// The following methods are slow. They are for debugging.
   /// They perform range checking, and will abort when they detect
   /// and out-of-bounds reference.

  void range_check(size_type __n) const 
  {
	Generic().RangeCheck(__n);
  }

private:

  friend class SMABasTester;

  // ----------------------------------------------------------------------

  /// Data Members -- exactly as VectorGeneric, but strongly-typed pointers.
  /// It is done like this just to make the vector browsable by type in the debugger.
  /// This system does not add any run-time cost.

  /// This class is essentially identical to VectorGeneric, except that its pointers
  /// are strongly-typed.  It is essential for viewing in the debugger that the members
  /// appear strongly-typed.  The constrained relationship between VectorGeneric
  /// and this class is not supported explicitly by C++, so there are StaticAsserts
  /// in the vector test to ensure that these classes are properly aligned.
  /// 

  SMABasVectorAllocator    m_allocator;
  SMABasReplicatorGeneric  m_replicator;

  T*                    m_start;     // pointer to data
  T*                    m_finish;    // pointer to one past the last element
  T*                    m_end_of_storage;

};

template <class T>
inline bool 
operator==(const SMABasVector<T>& __x, const SMABasVector<T>& __y)
{
  return __x.size() == __y.size() &&
    SMABasEqual(__x.begin(), __x.end(), __y.begin());
}

template <class T>
inline bool 
operator!=(const SMABasVector<T>& __x, const SMABasVector<T>& __y)
{
  return ! ( __x == __y);
}

template <class T>
inline bool 
operator<(const SMABasVector<T>& __x, const SMABasVector<T>& __y)
{
  return SMABasLexicographicalCompare(__x.begin(), __x.end(), 
				      __y.begin(), __y.end());
}


#endif // SMA_USE_NATIVE_STL


#endif // SMABasVector_h
