/*   -*- mode: c++ -*-   */
#ifndef inpO_appMessages_h
#define inpO_appMessages_h

///////////////////////////////////////////////////////////////////////////////
//
// Class: inpO_appMessages
//
// Description:
//

// Includes

// Forward declarations

// Begin local includes
#include <atr_String.h>


// Class definition

enum inpO_AppMessageEnm {
   inpO_App_Required_Parameter_Missing,
   inpO_App_Invalid_Parameter_Value,
   inpO_App_Required_Mutually_Exclusive_Parameters_Missing,
   inpO_App_Mutually_Exclusive_Parameters_Defined,
   inpO_App_Unsupported_Parameters,
   inpO_App_Unsupported_Parameter_Values,

   inpO_App_Part_Cannot_Be_Created
};

atr_String i18n_inpO_appMessages(int msgId);


#endif /* inpO_appMessages_h */
