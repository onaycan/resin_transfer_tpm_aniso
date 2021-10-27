#ifndef SMASimArrayInt_h
#define SMASimArrayInt_h

// Begin local includes
#include <SMASimArray.h>
#include <SMASimDataTypes.h>
// End local includes

SMASIM_ARRAY_BUTILTIN_DECL(int, SMASimArrayInt);

SMASimDebugOut& operator<<(SMASimDebugOut& uos, SMASimArrayInt const& );

#endif
