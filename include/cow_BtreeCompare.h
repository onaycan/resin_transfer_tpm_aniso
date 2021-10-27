#ifndef cow_BtreeCompare_h
#define cow_BtreeCompare_h

#include <string.h>
// Begin local includes
#include <omi_types.h>
#include <cow_String.h>
#include <atr_NatOrder.h>

// Forward declarations

template <class Key>
int BtreeCompare(const Key& key1, const Key& key2);


inline int BtreeCompare(const int& key1, const int& key2)
{
     return key2 - key1;
}


inline int BtreeCompare(const int64& key1, const int64& key2)
{
     if(key1 < key2)
        return 1;
     if(key1 > key2)
        return -1;
     return 0;
}


inline int BtreeCompare(const cow_String& key1, const cow_String& key2)
{
	if (atr_getNaturalOrder()) 
		return strnatcmp(key2.CStr(),key1.CStr());
	else
		return strcmp(key2.CStr(),key1.CStr());
}

inline int BtreeCompare(const uint& key1, const uint& key2)
{
     return key2 - key1;
}

inline int BtreeCompare(const float& key1, const float& key2)
{
     if(key1 < key2)
        return 1;
     if(key1 > key2)
        return -1;
     return 0;
}

#endif
