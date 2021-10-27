#ifndef __CATAssert
#define __CATAssert

// Stand-in for the V5 CATAssert macros - currently just rewraps assert.h
// This will not be shared into V5.
#include <assert.h>

#define CATAssert(cond) assert(cond)

#endif
