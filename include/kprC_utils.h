/* -*- mode: c++ -*- */
#ifndef  kprC_utils_h
#define  kprC_utils_h

// Includes

// Begin local includes
#include <cow_String.h>
#include <cow_ListInt.h>
#include <cow_ListString.h>
#include <cow_ListTranslatedString.h>
#include <omu_PrimEnum.h>

enum kprC_SuppressionEnm { kprC_RESUMED=0, kprC_SUPPRESSED_ATTRIBUTE, kprC_SUPPRESSED_STEP, kprC_SUPPRESSED_BOTH };
typedef omu_PrimEnum<kprC_SuppressionEnm,1> kprC_SuppressionConst;

cow_ListTranslatedString kprC_getMechanicalAdptMeshConsTypesforStep(int procType );
cow_ListTranslatedString kprC_getOtherAdptMeshConsTypesforStep(int procType );

bool kprC_isValidAdptMeshConsTypeforStep(int loadType, int procType );

cow_String kprC_InitialStepName();

// Convenience functions to manage suppression values
// for propagating attributes
void kprC_SuppressPropagatingAttribute(bool fromStepSuppression,
		  kprC_SuppressionEnm &suppressionState,
                  bool allowStepFlagReset); // used by step replacement to clear the BOTH value
void kprC_ResumePropagatingAttribute(bool fromStepResume, 
		  kprC_SuppressionEnm &suppressionState);

#endif /*kprC_utils_h*/

