#ifndef cow_ArrayCOW_h
#define cow_ArrayCOW_h

/* -*- mode: c++ -*- */
///////////////////////////////////////////////////////////////////////////////
//
// File Name: cow_ArrayCOW.h
// 
// Author: Uttam Narsu
// 
// Creation date: Tue May 13 1997
//
// Purpose:
//
// This file contains the methods of the cow_ArrayCOW class.
//
// What do you do when you want to put a cow in an array? A cow
// does *not* have a default constructor. This class is the answer.
//


//
// Includes
//

// Begin local includes

#include <cow_COW.h>

template <class T, class Dup> 
class cow_ArrayCOW : public cow_COW<T,Dup>
{
public:
    // Default constructor sets the cow to 0
    // outlined cause used in an array -umn 3/11/97
    cow_ArrayCOW();

    // added dtor cause used in an array -umn 3/11/97
    ~cow_ArrayCOW();

    // This constructor constructs a COW by *COPYING* a value.
    inline cow_ArrayCOW(const T& copy_me);

    // This constructor constructs a COW by *ADOPTING* a value.
    inline cow_ArrayCOW(T* adopt_me);

    // This is the default assignment operator
    inline cow_ArrayCOW<T,Dup>& operator=(
	const cow_ArrayCOW<T,Dup>&);

    // This assignment operator changes the value of the cow by
    // *ADOPTING*  the pointer passed in.
    inline cow_ArrayCOW<T,Dup>& operator=(T* adopt_me);
};

template <class T, class Dup>
inline cow_ArrayCOW<T,Dup>::cow_ArrayCOW(const T &copy_me)
    : cow_COW<T,Dup>(copy_me)
{ }

template <class T, class Dup>
inline cow_ArrayCOW<T,Dup>::cow_ArrayCOW(T *adopt_me)
    : cow_COW<T,Dup>(adopt_me)
{ }

template <class T, class Dup>
inline cow_ArrayCOW<T,Dup>& 
cow_ArrayCOW<T,Dup>::operator=(const cow_ArrayCOW<T,Dup>& that)
{
    if (&that == this){
      return *this;
    }

    this->cow_COW<T,Dup>::operator=((cow_COW<T,Dup>&)that);
    return *this;
}

template <class T, class Dup>
inline cow_ArrayCOW<T,Dup>&  
cow_ArrayCOW<T,Dup>::operator=(T* adopt_me)
{
    this->cow_COW<T,Dup>::operator=(adopt_me);
    return *this;
}

// The COW_COW2_DECL macro will instantiate a cow_CountedHld, cow_Copy, 
// and a cow_COW class, respectively, as <typ>Ptr, <Type>Dup and <Type>COW.

#define COW_ARRAYCOW2_DECL(Type,Copy)\
typedef cow_CountedHld<Type> Type ## Hld;\
typedef Copy<Type> Type ## Dup;\
typedef cow_COW<Type,Type ## Dup> Type ## bCOW;\
typedef cow_ArrayCOW<Type,Type ## Dup> Type ## COW;

// The COW_ARRAYCOW_DECL macro takes only a Type argument and selects 
// cow_Direct as the Copy type.
#define COW_ARRAYCOW_DECL(Type) COW_ARRAYCOW2_DECL(Type,cow_Direct)

// The COW_COW2_IMPL and COW_COW_IMPL macro go into the implementation
// file were you want the template to generated object code. Use the
// form which matches the way you defined the generated class.
#define COW_ARRAYCOW2_IMPL(Type,Copy)\
template class cow_CountedHld<Type>;\
template class Copy<Type>;\
template class cow_COW<Type,Type ## Dup>;\
template class cow_ArrayCOW<Type,Type ## Dup>;

#define COW_ARRAYCOW_IMPL(Type) COW_ARRAYCOW2_IMPL(Type,cow_Direct)

#endif // cow_ArrayCOW_h
