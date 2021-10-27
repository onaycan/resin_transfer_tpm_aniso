#ifndef cow_ListString_h
#define cow_ListString_h

// Begin local includes

#include <cow_List.h>
#include <cow_String.h>

COW_LIST_ITER_DECL(cow_String, cow_ListString);


// In the future the following two methods will exits as members of 
// the cow_ListString class
// At that time the methods should be declared const

unsigned GetLengthShortestString( const cow_ListString & );
    // Determine the number of characters in the shortest string in the
    // cow_ListString
    // 0 if the list has no strings

unsigned GetLengthLongestString( const cow_ListString & );
    // Determine the number of characters in the longest string in the
    // cow_ListString

#endif // cow_ListString_h
