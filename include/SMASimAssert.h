#ifndef SMASimAssert_h
#define SMASimAssert_h

#include <stdlib.h>
// Begin local includes
#include <mem_AllocationOperatorsTiny.h>
// End local includes

/**
* Assertion class for catching programming errors
**/
class SMASimUttAssert : public mem_AllocationOperatorsTiny
{
public:
    // NOTE: These methods are not public.  Don't use them directly.
    static void ReportAssertionFailure(char const* message, char const* filename, int linenumber);
    static void ReportValidationFailure(char const* message, char const* filename, int linenumber);
};

/// Assertion macro, outputs debug information prior to aborting
/// exit(1) is there to allow mkCheckSource to recognize this as 
/// an exiting construct.
#define SMASimASSERT(C) if(!(C)){SMASimUttAssert::ReportAssertionFailure(#C, __FILE__, __LINE__); *(char*)0=0; exit(1);}
/// Validation macro, outputs debug information prior to throwing an exception
#define SMASimVALIDATE(C) if(!(C)){SMASimUttAssert::ReportValidationFailure(#C, __FILE__, __LINE__); *(char*)0=0; exit(1);}


#endif
