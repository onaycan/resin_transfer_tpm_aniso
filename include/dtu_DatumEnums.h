/* -*- mode: c++ -*- */
///////////////////////////////////////////////////////////////////////////////
//
// File Name: dtu_DatumEnums.h
// 
// Description:
//
//     
//


#ifndef dtu_DatumEnums_h
#define dtu_DatumEnums_h

//
// Begin Local Includes
//
#include <omu_PrimEnum.h>


//
// Static variables
//

enum dtu_DatumType
{
    dtu_DATUMINVALID = 0, 
    dtu_DATUMPOINT, 
    dtu_DATUMAXIS, 
    dtu_DATUMPLANE, 
    dtu_DATUMCSYS
};

enum dtu_DatumCsysType
{
    dtu_UNKNOWN = 0, 
    dtu_CARTESIAN, 
    dtu_CYLINDRICAL, 
    dtu_SPHERICAL
};

enum dtu_CsysAxisType
{
    dtu_CSYSAXISINVALID = 0, 
    dtu_CSYSAXIS1, 
    dtu_CSYSAXIS2, 
    dtu_CSYSAXIS3
};


typedef omu_PrimEnum<dtu_DatumType,1> dtu_DatumTypeConst;
typedef omu_PrimEnum<dtu_DatumCsysType,1> dtu_DatumCsysTypeConst;

#endif  // #ifdef dtu_DatumEnums_h
