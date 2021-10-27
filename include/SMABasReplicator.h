//-*- mode: c++ -*-//
#ifndef SMABasReplicator_h
#define SMABasReplicator_h

#include <stddef.h> // for size_t
#include <string.h> // for memcpy

// Begin local includes

// End local includes


enum SMABasPlacement { SMABasPlace };

inline void* operator new (size_t sz, void* pos, SMABasPlacement) { return pos; }
inline void  operator delete(void* p, void* pos, SMABasPlacement) { }

typedef void (*SMABasCopyFunc)    ( const void*, void*, size_t);
typedef void (*SMABasDestroyFunc)       ( const void* , size_t);

template <typename T>
inline void SMABasStandardCopy( const void* from1, void* to1, size_t n )
{
  const T* from = reinterpret_cast<const T*>(from1);
  T* to = reinterpret_cast<T*>(to1);
  // invoke copy-constructor n times through placement new
  for (size_t k =0; k< n; k++) {
    ::new (to + k, SMABasPlace) T(*(from+k));
  }
}

template <typename T>
inline void SMABasStandardDestroy( const void* a1 , size_t n)
{
  const T* a = reinterpret_cast<const T*>(a1);
   for (size_t k =0; k< n; k++)
     (a+k)->~T();
}

// This is the default replicator that will be used.
template <typename T>
class SMABasReplicator {
public:
  static inline SMABasCopyFunc GetCopyFunc(){ return &SMABasStandardCopy<T>;}
  static inline SMABasDestroyFunc GetDestroyFunc(){ return &SMABasStandardDestroy<T>;}
};

// ---------------  Some optimizations: the POD replicator.

// For a class to be a POD:
// (i) It can copy as bytes
// (ii) Its destructor does not need to be called
// (iii) b2 = b  works to make b2 a copy of b, EVEN IF b2 is not initialized.

// The infrastructure recognizes a POD because the pointer-to-destructor is 0.
// The destructor is skipped.  There are useful optimizations for vector fill,
// which occurs during Vector::resize and certain overloads of Vector::insert.

template <typename T>
inline void SMABasPODCopy( const void* from1, void* to1, size_t n )
{
  const T* from = reinterpret_cast<const T*>(from1);
  T* to = reinterpret_cast<T*>(to1);
  if(n==1)
    *to=*from; // Optimize for common case when only one;
  // assuming pod assignment is faster than call to memcpy.
  // Copy the rest with memset if there are any more:
  else
    memcpy(to1,from1,n*sizeof(T));
}


template <typename T>
class SMABasPODReplicator {
public:
  static inline SMABasCopyFunc GetCopyFunc(){ return &SMABasPODCopy<T>;}
  static inline SMABasDestroyFunc GetDestroyFunc(){ return 0;}
};

#define SMA_BAS_POD_DECL(TYPE)\
template<>                     \
class SMABasReplicator<TYPE> : public SMABasPODReplicator<TYPE>{}; \

// Declare all built-ins to be PODS.  (Did we leave out any that matter?).
SMA_BAS_POD_DECL(void*); // works also for any pointer of any kind because of
// further specialization below.
SMA_BAS_POD_DECL(bool);
SMA_BAS_POD_DECL(char);
SMA_BAS_POD_DECL(unsigned char);
SMA_BAS_POD_DECL(short);
SMA_BAS_POD_DECL(unsigned short);
SMA_BAS_POD_DECL(int);
SMA_BAS_POD_DECL(unsigned int);
SMA_BAS_POD_DECL(long long);
SMA_BAS_POD_DECL(unsigned long long);
SMA_BAS_POD_DECL(float);
SMA_BAS_POD_DECL(double);

// Specialization so that all pointers of all kinds are replicated like void*s.
template<typename Pointed>                  
class SMABasReplicator<Pointed*> : public SMABasReplicator<void*>{}; 

// To have your class replicate like a POD, make SURE it satisfies the assumptions.
// Then place the decl at the end of your class definition:
// File MyClass.h:
// #include <SMABasReplicator.h>
// class MYClass {
//    ....
// };
// SMA_BAS_POD_DECL( MyClass);


//------------------------------------------------------------------------
// The generic replicator. Just a struct holding the size of the class;
// an SMABasCopyFunc for the class and an SMABasDestroyFunc for the class.

class SMABasReplicatorGeneric 
{
 public:

  typedef SMABasCopyFunc CopyFunc ; // todo -- no need for this typedef.
  typedef SMABasDestroyFunc DestroyFunc ; // todo -- no need for this typedef.

  inline SMABasReplicatorGeneric(int size) // TODO -- remove cruft
    : 
    m_size(size),
    m_copy(0),
    m_destroy(0)
  { }

  inline SMABasReplicatorGeneric(int size, SMABasCopyFunc copy, SMABasDestroyFunc destroy)
    : 
    m_size(size),
    m_copy(copy),
    m_destroy(destroy)
  { }

  int          m_size;  // size of one item in bytes
  SMABasCopyFunc     m_copy;
  SMABasDestroyFunc  m_destroy;
};

template <typename T> 
inline SMABasReplicatorGeneric 
SMABasGetReplicator(){
  return SMABasReplicatorGeneric( sizeof(T), 
				  SMABasReplicator<T>::GetCopyFunc(),
				  SMABasReplicator<T>::GetDestroyFunc()
				  );
}


#endif // SMABasReplicator_h
