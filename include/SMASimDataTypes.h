#ifndef SMASimDataTypes_h
#define SMASimDataTypes_h

//
// SECTION: System includes
//

//
// Begin Local includes
//
#include <SMASimDebugOut.h>
//
// End local includes
//

//
// SECTION: Forward declarations
//

/**
* Distribution data types
**/

/// ID type
typedef int SMASimID;

/// Integer range struct
struct SMASimIntRange {
    int m_first;
    int m_last;
};

#endif 
