#ifndef odb_ValidFieldInvar_h
#define odb_ValidFieldInvar_h

// Begin local includes
#include <odb_Enum.h>
// End local includes

// this must become a namespace once IBM allows
// it cannot be a class because we init an static const array


static const int odb_NumVectorInvar = 1;
static const odb_Enum::odb_InvariantEnum
             odb_ValidVectorInvar[odb_NumVectorInvar] = {odb_Enum::MAGNITUDE};


static const int odb_NumFullTensorInvar = 7;
static const odb_Enum::odb_InvariantEnum
             odb_ValidFullTensorInvar[odb_NumFullTensorInvar] = {
                                                odb_Enum::MAX_PRINCIPAL,
                                                odb_Enum::MID_PRINCIPAL,
                                                odb_Enum::MIN_PRINCIPAL,
                                                odb_Enum::MISES,
                                                odb_Enum::TRESCA,
                                                odb_Enum::PRESS,
                                                odb_Enum::INV3
                                                };

static const int odb_NumPlanarTensorInvar = 10;
static const odb_Enum::odb_InvariantEnum
             odb_ValidPlanarTensorInvar[odb_NumPlanarTensorInvar] = {
                                                odb_Enum::MAX_PRINCIPAL,
                                                odb_Enum::MID_PRINCIPAL,
                                                odb_Enum::MIN_PRINCIPAL,
                                                odb_Enum::MAX_INPLANE_PRINCIPAL,
                                                odb_Enum::MIN_INPLANE_PRINCIPAL,
                                                odb_Enum::OUTOFPLANE_PRINCIPAL,
                                                odb_Enum::MISES,
                                                odb_Enum::TRESCA,
                                                odb_Enum::PRESS,
                                                odb_Enum::INV3
                                                };

static const int odb_NumSurfaceTensorInvar = 8;
static const odb_Enum::odb_InvariantEnum
             odb_ValidSurfaceTensorInvar[odb_NumSurfaceTensorInvar] = {
                                                odb_Enum::MAX_PRINCIPAL,
                                                odb_Enum::MIN_PRINCIPAL,
                                                odb_Enum::MAX_INPLANE_PRINCIPAL,
                                                odb_Enum::MIN_INPLANE_PRINCIPAL,
                                                odb_Enum::MISES,
                                                odb_Enum::TRESCA,
                                                odb_Enum::PRESS,
                                                odb_Enum::INV3};

#endif // odb_ValidFieldInvar_h
