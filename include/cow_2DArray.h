/* -*- mode: c++ -*- */
///////////////////////////////////////////////////////////////////////////////
//
// File Name: cow_2DArray.h
// 
// Description:
//     A Simple matrix template for nxm arrays of data. This template is
//     optimized for matrix of float or int, this is the most common case
//     but it can be instantiated with other classes, as long as the
//     class has a default constructor.
//


#ifndef cow_2DArray_h
#define cow_2DArray_h

//
// Begin Local Includes
//
#include <cow_COW.h>
#include <mem_AllocationOperators.h>
#include <mem_C_Allocation.h>
//
// Forward Declarations
//
//
// Class definition
//
template <class Type> struct cow_2DArrayRep  : public mem_AllocationOperators
{
    int rows;
    int cols;
    Type *array;
    
    cow_2DArrayRep(int r, int c);
    cow_2DArrayRep(const cow_2DArrayRep<Type> &);
    cow_2DArrayRep<Type>& operator=(const cow_2DArrayRep<Type> &);
    ~cow_2DArrayRep();
    
};


template <class Type> class cow_2DArray : public mem_AllocationOperators
{
  public:
    //
    // 2DArrayMatix Constructor, creates a matrix, with r x c rows and columns
    // this is fixed at the construction and cannot be extended.
    // 
    // This version of the contructor does not take a default argument,
    // if this instantiation is over a primitive type (int, float) then the
    // value of the ements in the Matrix are undefined (use next constructor
    // if you want them initialized) if the instantiation is over a class,
    // then the default constructor is called for each element.
    //
    cow_2DArray(int r, int c);
    //
    // 2DArrayMatix Constructor, creates a matrix, with r x c rows and columns
    // this is fixed at the construction and cannot be extended.
    // 
    // This version of the contructor does take a default argument,
    // if this instantiation is over a primitive type (int, float) then the
    // value of the ements in the 2dArray are initialized to the default
    // value. If the instantiation is over a class,
    // then the default constructor is called for each element, then the
    // default value is assigned to each element.
    //
    cow_2DArray(int r, int c,const Type &def);

    inline const Type &ConstGet(int r, int c) const;
    inline Type &Get(int r, int c);
    inline int Rows() const;
    inline int Cols() const;
    
  private:
    typedef cow_COW<cow_2DArrayRep<Type>,
            cow_Direct<cow_2DArrayRep<Type> > > RepCOW;

    RepCOW rep;
};


//
// Inlines
//


template <class Type>
inline 
const Type &
cow_2DArray<Type>::ConstGet(int r, int c) const
{
    return rep.ConstGet().array[r * rep.ConstGet().cols + c];
}

template <class Type>
inline 
Type &
cow_2DArray<Type>::Get(int r, int c)
{
    return rep.Get().array[r * rep.ConstGet().cols + c];
}


template <class Type>
inline 
int cow_2DArray<Type>::Rows() const
{
    return rep.ConstGet().rows;
}

template <class Type>
inline 
int cow_2DArray<Type>::Cols() const
{
    return rep.ConstGet().cols;
}


//
// Instantiation macros.
//
#define COW_2DARRAY_DECL(TYPE,NAME)\
typedef cow_2DArrayRep<TYPE> NAME ## Rep;\
COW_COW_DECL(NAME ## Rep);\
typedef cow_2DArray<TYPE> NAME;

//
// These macros go in the .C file.
//
// Remember to include cow_2DArray.T!
//
#define COW_2DARRAY_IMPL(TYPE,NAME)\
template class cow_2DArrayRep<TYPE>;\
COW_COW_IMPL(NAME ## Rep);\
template class cow_2DArray<TYPE>;


#endif  // #ifdef cow_2DArray_h
