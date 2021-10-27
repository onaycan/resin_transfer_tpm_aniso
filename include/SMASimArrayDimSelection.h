#ifndef SMASimArrayDimSelection_h
#define SMASimArrayDimSelection_h

// Begin local includes
#include <SMASimArray.h>
#include <SMASimDimSelection.h>
// End local includes

/**
* Structure to hold an array of dimension selections
**/
SMASIM_ARRAY_CLASS_DECL(SMASimDimSelection, SMASimArrayDimSelection);

SMASimDebugOut& operator<<(SMASimDebugOut& uos, SMASimArrayDimSelection const&);

#endif
