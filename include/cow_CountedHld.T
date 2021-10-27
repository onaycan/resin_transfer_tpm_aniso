/* -*- mode: c++ -*- */
#ifndef cow_CountedHld_T
#define cow_CountedHld_T

#include <assert.h>

// Begin local includes
#include <mem_C_Allocation.h>
#include <cow_CountedHld.h>


// Delete the referent and counter.
//
template <class Type>
void cow_CountedHld<Type>::Delete()
{
    assert(count->References() == 0);
#if defined(COW_COUNTED_BUILTIN)
    mem_Free(ref);
#else
    delete ref;
#endif
    ref = 0;
    delete count, count = 0;
}

// Delete the referent.
//
template <class Type>
void cow_CountedHld<Type>::DeleteReferent()
{
    assert(count->References() >= 0);
#if defined(COW_COUNTED_BUILTIN)
    mem_Free(ref);
#else
    delete ref;
#endif
}

#endif
