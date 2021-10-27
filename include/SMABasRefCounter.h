#ifndef SMABasRefCounter_h
#define SMABasRefCounter_h

// Begin local includes
#include <mem_AllocationOperatorsTiny.h>
// End local includes


struct SMABasRefCounter : public mem_AllocationOperatorsTiny
{
    SMABasRefCounter() : mStrongs(0), mWeaks(0) {}
    unsigned int mStrongs;
    unsigned int mWeaks;
};

#endif
