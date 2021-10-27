#ifndef SMABasSharedPtr_h
#define SMABasSharedPtr_h

// Begin local includes
#include <mem_AllocationOperatorsTiny.h>
#include <SMAAssert.h>
#include <SMABasRefCounter.h>
#include <SMABasAlgoBase.h>
// End local includes

// ----------------------------------------------------------------------------
// David Reynolds May 2009
//
// Implementation adapted from SMASimRpm_StrongRef by Rob Defriesse

// SMABasSharedPtr : A smart-pointer. Lifecycle-manages an object 
// by non-intrusive reference counting. Same interface as boost::shared_ptr,
//  at the time of writing, in a recommendation for the C++ Standard.
//   Note: compatibility with boost is one-direction: not all methods of 
// boost::shared_ptr are implemented. Rather, a more minimal set, which
// offers most capabilities is provided.

// ----------------------------------------------------------------------------
// THREAD ISSUES
// ---------------------------------------------------------------------------

// For emphasis, I'm going to to say this three times:

//   SharedPtr/WeakPtr are NOT THREAD-SAFE and should not be
//   SharedPtr/WeakPtr are NOT THREAD-SAFE and should not be
//   SharedPtr/WeakPtr are NOT THREAD-SAFE and should not be

// They are not intended to be thread-safe, because we want them to be maximally
// efficient.  It's worth emphasizing that they are not thread-safe because the 
// interface, with it's lock() method,
// looks as if it is thread-safe.  There is a reason for this apparent deception:
// the **interface is thread-compatible**, while the implementation is not thread-safe.
// This means that a thread-safe VERSION of these classes can be made. 
// (say ThrdSharedPtr, ThrdWeakPtr).
// If you write your code with SharedPrt/WeakPtr, you should be able to change
// your declarations to ThrdSharedPtr, ThrdWeakPtr and have your code run,
// thread-safely, but of course less efficiently.


// ---------------------------------------------------------------------------------
//  USAGE OVERVIEW
// ---------------------------------------------------------------------------------

// To use SharedPtr<T>, the only requirement on T is that delete can be called on it.
// (This means that it has an accessible destructor, and delete is not made inaccessible).

// SMABasSharedPtr and SMABasWeakPtr are a 'package'.  SharedPtr is the 
//  'strong' one, and can be used
//  without WeakPtr, but not vice-versa.

// SharedPtr first:

//   The best-practice idiom:
//   To put an object under shared-pointer ownership, construct the shared
//    pointer from a newly-constructed T:
//     SharedPtr<T> p( new T ( args...) );
//   The above exact idiom is a good practice: if you follow it exactly, you
//   are safe -- you will be following 'the rules'.  If you are not going to follow it exactly, 
//   you need to know what rules are to be obeyed.
//   [ Another alternative is p.reset( new T(args..)); ]

//   The Rules:
//    SharedPtr<T> is constructed from a pointer to an object of type T,
//    ( or of type convertible to T). 
//   These next two conditions MUST be met, or there will be trouble:
//    (i) the object has been allocated on the heap, e.g.  T* objPtr = new T;
//    (ii)  the object is NOT ALREADY under shared-pointer ownership.


//   To access obj from the shared_ptr EITHER:
//     Use the -> operator to work directly with the methods of the object:
//           p->MethodOnT();
//     Use the * operator to obtain a reference:
//           T& objRef = *p;
//     Use get() to obtain a raw pointer
//           T* objPtr = p.get();

// Copying/Assignment
// The shared-pointer may be copied and assigned as expected to other
// shared-pointers.  Ownership is shared, by the shared-pointers which
// are looking at the object, and when the last one of them is destructed,
// the object is deleted.

// The null shared-pointer
// A default-constructed shared-pointer is like a pointer-to-null.

// Setting to null: Two styles to choose from, exactly equivalent:
//    p.reset();
//    p = SharedPtr<T>();
//
// Taking ownership of something new:
//    p.reset( new T( args));
//

// Testing for null-ness
//   if (p.get())      // p is not null.
//   if( p.get() == 0) // p is null

// Conversions:
//   Useful automatic conversions occur which mirror the conversions 
//   of raw pointers, e.g.
//   SharedPtr<T> p = ...
//   SharedPtr< const T> pC = p; // OK
//   p = pc; // Compiler error, conversion loses qualifiers.

// Another useful conversion is:

//   SharedPtr< DERIVED> pDER = ...
//   SharedPtr< BASE > pBASE = p; // OK
//   pDER = pBASE; // Compiler error, as with raw pointer.
//   Warning: BASE needs a virtual-destructor if these conversions are being used.

// WeakPtr:

//   A WeakPtr<T> can be constructed from a SharedPtr<T> (also the kind of 
//   conversions mentioned above are allowed).  The semantics is as follows:
//   the SharedPtr(s) continue to manage the object lifecycle.  Actual 
//   pointers to the object can't be obtained from the weak pointer(s) 
//   directly, rather, shared pointers can be obtained from them through lock() 
//   when a pointer is needed. If the last SharedPointer goes while weak 
//   pointers remain in existence, the object is destructed, and any subsequent 
//   call to lock() on any of the weak pointers produces a null 
//   shared pointer, (from which a get() will return a null pointer).  
//   Consequently, the holding of weak pointers allows the object to be 
//   destroyed,  but will never lead to the evaluation of a dangling 
//   reference.

// In short: Weak pointers do not 'hold' the object, but allow access to 
//   the object if it is still there, while removeing the possibility of 
//   dereferencing a dangling pointer; they are looking at the object while
//   it is there, then they are looking at NULL.

// Question: where is boost's unspecified_bool so I can write expressions like "if(p)" ?
//   We do not provide the boost 'unspecified_bool_type' because it 
//   (currently) requires elaborate compiler-dependent implementations.  
//   Just use p.get() in the conditional expressions. If something comes
//   into the standard which makes this simple, we'll provide it.

// Question: where is the expected RELEASE method??  Don't smart pointers have
//     a RELEASE method of some sort?
//   Not his one. Once the object has been put under shared pointer ownership, it is 
//   not possible, in the boost interface (as currently provided), to 
//   RELEASE it from shared-pointer ownership, and continue to manage it 
//   (keep it alive) by other means. It remains under shared-pointer 
//   ownership until destructed.  This seems paternalistic, however, 
//   this is not really as restrictive as it might seem, and is helpful 
//   for other reasons.

// Question: how do I access the reference-count??
//   There is a reference count on WeakPtr, but not on SharedPtr.
//   The number returned by use_count() on WeakPtr is the number of 
//   **SharedPtrs** holding the object.
//   This is what Boost provides and, in truth, there is
//   not much you COULD do with a reference-count except 
//   use it for debugging or program statistics etc.  To get a reference
//   count from the SharedPtr, just construct a temporary WeakPtr and
//   get the use_count() from that.

// -----------------------------------------------------------------------


template <typename T>
class SMABasWeakPtr;

template <typename T>
class SMABasSharedPtr : public mem_AllocationOperatorsTiny
{
 private:
  typedef SMABasSharedPtr<T> this_type;
  
public:
  
  /// Constructs a null shared-pointer
  SMABasSharedPtr() // never throws
    : mPointer(0), mCounter(0){}

  /// This puts an object of type T2 ( a type convertible to T)
  /// under smart-pointer ownership. See 'rules' above.
  template<typename T2>
  explicit SMABasSharedPtr(T2* t)
    : mPointer(0), mCounter(0) // can throw for out-of-heap-memory only
  {
    Connect(t, new SMABasRefCounter); 
  }

  /// Copy constructor
  SMABasSharedPtr(const SMABasSharedPtr<T>& that) // never throws
    : mPointer(0), mCounter(0)
  {
    Connect(that.PRIVATEGetPointer(), that.PRIVATEGetCounter());
  }

  /// Converting copy constructor
  template <typename T2>
  SMABasSharedPtr(const SMABasSharedPtr<T2>& that) // never throws
    : mPointer(0), mCounter(0)
  {
    Connect(that.PRIVATEGetPointer(), that.PRIVATEGetCounter());
  }
  
  ~SMABasSharedPtr() // never throws
  {
    Disconnect();
  }

  /// Assignment works as expected.
  SMABasSharedPtr& operator=(const SMABasSharedPtr<T>& that) // never throws
  {
    SMABasSharedPtr<T> temp(that);
    temp.swap(*this);
    return *this;
  }

  /// Assignment-with-conversion works as expected.
  template <typename T2>
  SMABasSharedPtr& operator=(const SMABasSharedPtr<T2>& that) // never throws
  {
    SMABasSharedPtr<T> temp(that);
    temp.swap(*this);
    return *this;
  }

  /// Equivalent to assigning to null.  Never throws.
  void reset()
  {
    this_type().swap(*this);
  }

  // Taking ownership of something new. The best idiom is  .reset( new T(...));
  template<typename T2>
  void reset(T2* t)
  {
    *this = this_type(t);
  }

  /// Dereference the shared-pointer
  T& operator*() const { return *get(); } // can throw (for 0 pointer)
  /// Arrow operator returns pointer to underlying object, 0 if this is a null shared-pointer.
  T* operator->() const { return get(); } // can throw (for 0 pointer)
  
  // Return a pointer to the underlying object. The pointer is 0 if the smart pointer is NULL.
  T* get() const // never throws
  {
    return mPointer;
  }
  
  void swap( SMABasSharedPtr<T>& that) // never throws
  {
    SMABasSwap(mPointer,that.mPointer);
    SMABasSwap(mCounter,that.mCounter);
  }

  // Do not call these functions.  They are officially private, public until C++ offers
  // friend declarations  that are templatized.
  inline T* PRIVATEGetPointer() const{ return mPointer;}
  inline SMABasRefCounter* PRIVATEGetCounter() const{ return mCounter; }


private:
  friend class SMABasWeakPtr<T>;
  

  void Disconnect()
  {
    if(mCounter){
      if( mCounter->mStrongs == 1) 
	{
	  delete mPointer; // delete object
	  -- mCounter->mStrongs; // then decrement! (Object may have weak-pointers to self!)
	  if(0 == mCounter->mWeaks)
	    {
	      delete mCounter;
	    }
	}
      else
	-- mCounter->mStrongs;
    }
  }
  
  void Connect(T* p, SMABasRefCounter* c)
  {
    mPointer = p;
    mCounter = c; 
    if(mCounter)
      mCounter->mStrongs++;
  }

  T* mPointer;
  SMABasRefCounter* mCounter;
};

#endif
