#ifndef SMABasWeakPtr_h
#define SMABasWeakPtr_h


#include <stdlib.h>

// Begin local includes
#include <mem_AllocationOperatorsTiny.h>
#include <SMAAssert.h>
#include <SMABasSharedPtr.h>
#include <SMABasRefCounter.h>
#include <SMABasAlgoBase.h>
// End local includes

// ----------------------------------------------------------------------------
//   David Reynolds May 2009
//   Implementation adapted from SMASimRpm_StrongRef/WeakRef by Rob Defriesse

////  Same interface as boost::weak_ptr, at time of writing in proposal for the C++ Standard.
////
////   SMABasWeakPtr and SMABasSharedPtr are a package.  
////   WeakPtr cannot be used without SharedPtr.  See SharedPtr for an explanation.
////
////  Note:: Operator -> or * are not provided. 
////  Instead, you must go through lock to make sure that a shared-pointer comes into existence
////  to hold the object.
////  Two good idioms and one which is bad --if you care about eventual thread-safety.
////  In the following code, we'll leave out testing on the pointer value, which can be
////  added, and only want to be sure that the code fails honorably (with a null-pointer
////  exception, if the object pointed to is deleted.

////  good (i)  SMABasSharedPtr<T> strong = weakP.lock(); // good
////    And now operate on the object through "strong".

////  OR:

////  good (ii)  weakP.lock()->MethodT( ..); // good

////  bad (iii)  Class* raw = weakP.lock().get(); // bad

////  In (iii) the lock expires when the expression is over, but we still have a raw pointer.
////  If you replace your smart-pointer classes with thread-safe versions, (iii) will not
////  be thread-safe even to the extent of failing honorably (with a null-pointer exception):
////  you can actually use a dangling reference.

template <typename T>
class SMABasWeakPtr : public mem_AllocationOperatorsTiny
{
 private:
  typedef SMABasWeakPtr<T> this_type;
  
 public:

  /// Construct null weak pointer
  SMABasWeakPtr(): mPointer(0), mCounter(0){}
  
  SMABasWeakPtr(const this_type& that) : mPointer(0), mCounter(0) 
  {
    Connect(that.PRIVATEGetPointer(), that.PRIVATEGetCounter());
  }
  
  template<typename T2>   
  SMABasWeakPtr(const SMABasWeakPtr<T2>& that){
    Connect(that.PRIVATEGetPointer(), that.PRIVATEGetCounter());
  }

  // Construct from shared pointer, converting or not.
  template<typename T2>
  SMABasWeakPtr(const SMABasSharedPtr<T2>& that){
    Connect(that.PRIVATEGetPointer(), that.PRIVATEGetCounter());
  }
  
  ~SMABasWeakPtr()
  {
    Disconnect();
  }

  // Assign from weak-pointer
  SMABasWeakPtr& operator=(const this_type& that)
  {
    this_type temp(that);
    temp.swap(*this);
    return *this;
  }

  // Converting-assign from weak-pointer
  template<typename T2>
  SMABasWeakPtr& operator=(SMABasWeakPtr<T2> const & that)
  {
    this_type temp(that);
    temp.swap(*this);
    return *this;
  }

  // Assign from shared-pointer, converting or not.
  template<typename T2>   
  SMABasWeakPtr& operator=(const SMABasSharedPtr<T2>& that)
  {
    this_type temp(that);
    temp.swap(*this);
    return *this;
  }

  /// Construct a strong-pointer from THIS. This is the ONLY WAY to get 
  /// at the underlying object, if it exists.  This makes this interface
  /// thread-compatable but beware that these are NOT THREAD SAFE.
  SMABasSharedPtr<T> lock() const {
    SMABasSharedPtr<T> temp;
    if( expired())
      return temp;
    temp.Connect( mPointer, mCounter);
    return temp;
  }
  
  /// Can we access the object?
  bool expired() const {
    return !use_count();
  }

  /// How many strong-refs are there?  Mainly for debugging -- 
  /// expired() has all you need for normal runs.
  int use_count() const {
    return mCounter ? mCounter->mStrongs : 0;
  }

  /// Equivalent to assigning to null.
  void reset()
  {
    this_type().swap(*this);
  }

  void swap( this_type& that) // never throws
  {
    SMABasSwap(mPointer,that.mPointer);
    SMABasSwap(mCounter,that.mCounter);
  }

  // Do not call these functions.  They are officially private, public until C++ offers
  // friend declarations
  // that are templatized.
  inline T* PRIVATEGetPointer() const{ return mPointer;}
  inline SMABasRefCounter* PRIVATEGetCounter() const{ return mCounter; }


private:

  void Disconnect()
  {
    if(mCounter && 0 == --mCounter->mWeaks && 0 == mCounter->mStrongs)
      {
        delete mCounter;
      }
  }
  
  void Connect(T* p, SMABasRefCounter* c)
  {
    mPointer = p;
    mCounter = c;    
    if(mCounter)
      mCounter->mWeaks++;
  }
  
  T* mPointer;
  SMABasRefCounter* mCounter;
};



#endif
