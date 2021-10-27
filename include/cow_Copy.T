/* -*- mode: c++ -*- */
#ifndef cow_Copy_T
#define cow_Copy_T

// Begin Local Includes
#include <mem_C_Allocation.h>
#include <cow_Copy.h>

// The cow_Direct template simply invokes the copy constructor of the
// target class.
//
template <class Type> 
Type* cow_Direct<Type>::Copy(const Type& value) {
#if defined(COW_COW_BUILTIN)
    Type* retPtr = static_cast<Type*>(mem_Malloc(sizeof(Type)));
    *retPtr = value;
    return retPtr;
#else
    return new Type(value);
#endif
}


// The cow_Virtual template calls the Copy method of the target class.
// This method should be declared virtual, and it should be defined as
// follows, in each target class, including derivatives of that class:
//
// Type* Deriv::Copy() const { return new Deriv(*this); }
//
// Note: We cast the return value in order to allow generating a
// cow_Virtual of a derived class which inherits its virtual Copy method
// and, hence, cannot change its return type.
//
template <class Type>
Type* cow_Virtual<Type>::Copy(const Type &value) {
    return (Type *)value.Copy();
}


#endif  // #ifdef cow_Copy_T
