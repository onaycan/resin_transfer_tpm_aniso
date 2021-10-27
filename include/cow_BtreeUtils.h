/* -*- mode: c++ -*- */
///////////////////////////////////////////////////////////////////////////////
//
// File Name: cow_BtreeUtils.h
// 
// Description:
//      utility functions that can be used with the cow_Btree template.
//      this is included as function templates rather than member of the
//      btree to reduce dependencies
//
//      Functions:
//          cow_List<key>   cow_Keys(const cow_Btree<key,value> &);
//          cow_List<value> cow_Values(const cow_Btree<key,value> &);
//     
//


#ifndef cow_BtreeUtils_h
#define cow_BtreeUtils_h

//
// Forward declarations
//
template<class Key, class Value> class cow_Btree;

//
// Begin Local Includes
//
#include <mem_AllocationOperators.h>
#include <cow_List.h>

template<class Key, class Value>
class cow_BtreeUtils  : public mem_AllocationOperators
{
public:
    static cow_List<Key> cow_Keys(const cow_Btree<Key,Value> &btree);

    static cow_List<Value> cow_Values(const cow_Btree<Key,Value> &btree);
};

// DECL macro is used to produce guiding declarations required by some 
// compilers. Currently only g++ requires these.

#if defined(HKS_REQUIRE_SPCL_DECL)
# define COW_BTREEUTILS_DECL(Key, Value)\
cow_List<Key> cow_BtreeUtils<Key, Value>::cow_Keys(const cow_Btree<Key,Value> &);\
cow_List<Value> cow_BtreeUtils<Key, Value>::cow_Values(const cow_Btree<Key,Value> &);
#else
# define COW_BTREEUTILS_DECL(Key, Value)
#endif

//
// Macro for instantiating the cow_BtreeUtils this goes into the .C file,
// don't forget to include the cow_BtreeUtils.T
//
#define COW_BTREEUTILS_IMPL(Key,Value)\
template class cow_BtreeUtils<Key, Value>;


#endif  // #ifdef cow_BtreeUtils_h
