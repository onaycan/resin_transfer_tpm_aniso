/*   -*- mode: c++ -*-   */
#ifndef inp_types_h
#define inp_types_h

///////////////////////////////////////////////////////////////////////////////
//
// File Name: inp_types.h
//
// Description:  
//

// Includes

// Begin local includes
#include <mem_AllocationOperators.h>

#include <omn_FixedString.h>

class inp_Types  : public mem_AllocationOperators
{
  
public:

  // Enum definitions
  
  enum typeEnm { inp_INTEGER, inp_BOOLEAN, inp_REAL, inp_STRING, inp_NONE };

  // Strings

  static omn_FixedString stringPat();
  static omn_FixedString integerPat();
  static omn_FixedString doublePat();
  static omn_FixedString doublePatD();
  static omn_FixedString paramPat();
  static omn_FixedString setNamePat();
  static omn_FixedString scopedIDPat();
  static omn_FixedString fileNamePat();
  static omn_FixedString superelementIDPat();
  static omn_FixedString userElementIDPat();
  static omn_FixedString fakeName();
};

#endif /* inp_types_h */

