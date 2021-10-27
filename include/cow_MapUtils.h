/* -*- mode: c++ -*- */
///////////////////////////////////////////////////////////////////////////////
//
// File Name: cow_MapUtils.h
// 
// Description:
//      utility functions that can be used with the cow_Map template.
//      this is included as function templates rather than member of the
//      map to reduce dependencies
//
//      Functions:
//          cow_List<key>   cow_Keys(const cow_Map<key,value> &);
//          cow_List<value> cow_Values(const cow_Map<key,value> &);
//     
//


#ifndef cow_MapUtils_h
#define cow_MapUtils_h

//
// Forward declarations
//
template<class Key, class Value> class cow_Map;

//
// Begin Local Includes
//
#include <mem_AllocationOperators.h>
#include <cow_List.h>

template<class Key, class Value>
class cow_MapUtils  : public mem_AllocationOperators
{
public:
    static cow_List<Key> cow_Keys(const cow_Map<Key,Value> &map);

    static cow_List<Value> cow_Values(const cow_Map<Key,Value> &map);
};

//
// Macro for instantiating the cow_MapUtils this goes into the .C file,
// don't forget to include the cow_MapUtils.T
//
#define COW_MAPUTILS_IMPL(Key,Value)\
template class cow_MapUtils<Key, Value>;


#endif  // #ifdef cow_MapUtils_h
