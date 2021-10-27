#ifndef odb_StringCmp_h
#define odb_StringCmp_h

#include <string.h>

// Begin local includes
#include <odb_String.h>
#include <atr_NatOrder.h>

inline int BtreeCompare( const odb_String& key1, const odb_String& key2 )
{
	if (atr_getNaturalOrder()) 
		return strnatcmp(key2.CStr(),key1.CStr());
	else
		return strcmp(key2.CStr(),key1.CStr());
}

#endif
