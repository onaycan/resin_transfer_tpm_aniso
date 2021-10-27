/* -*- mode: c++ -*- */
#ifndef cow_COW_T
#define cow_COW_T

// Begin local includes

#include <cow_COW.h>
#include <cow_Copy.T>
#include <cow_CountedHld.T>

// This constructor constructs a COW by *COPYING* a value.
//
template <class Type,class Dup>
cow_COW<Type,Dup>::cow_COW(const Type &copy_me)
    : valuePtr(Dup::Copy(copy_me))
{}

// This constructor constructs a COW by *ADOPTING* a value.
// The typical usage will be
//        cow_COW<type>(new type()).
// This constructor is important because it avoids the copy of the
// object passed in; however, it should be used with caution
// because the cow_COW *ADOPTS* (i.e. *DELETES*) the object
// pointed to by the pointer passed in.
//
template <class Type,class Dup>
cow_COW<Type,Dup>::cow_COW(Type *adopt_me)
    : valuePtr(adopt_me)
{}

// The Get method returns a mutable reference to the current value.
// It ensures that the target object is held only by this reference.
// If necessary, it creates a new copy of the current value by assigning
// its value to itself.
//
template <class Type,class Dup>
Type& cow_COW<Type,Dup>::Get()
{
    const Type& ref = valuePtr.GetRef();  // assert HasValue
    if (! valuePtr.Exclusive()) {
	valuePtr = Dup::Copy(ref);
    }

    return *(valuePtr.GetPtr());          // no check necessary
}

#endif  // cow_COW_T
