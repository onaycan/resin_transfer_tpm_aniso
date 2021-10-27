/* -*- mode: c++ -*- */
#ifndef cow_MapString2ListInt_h
#define cow_MapString2ListInt_h

// Begin local includes

#include <cow_Map.h>
#include <cow_String.h>
#include <cow_ListInt.h>

COW_MAP_ITER_DECL(cow_String, cow_ListInt, cow_MapString2ListInt);

// The following declaration is for an additional cow list since we chose
// to use the cow_Keys and cow_Values methods in a class template rather then
// as function templates.

COW_LIST_DECL(cow_ListInt, cow_ListIntLST);

#endif // cow_MapString2ListInt_h
