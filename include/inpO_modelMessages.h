/*   -*- mode: c++ -*-   */
#ifndef inpO_modelMessages_h
#define inpO_modelMessages_h

///////////////////////////////////////////////////////////////////////////////
//
// Class: inpO_modelMessages
//
// Description:
//

// Includes

// Forward declarations

// Begin local includes
#include <atr_String.h>


// Class definition

enum inpO_ModelMessageEnm {
   inpO_Model_Undefined_Part_Name,
   inpO_Model_Undefined_Instance,
   inpO_Model_Part_Already_Defined,
   inpO_Model_Parts_Created_With_Instance_Names,

   inpO_Model_Undefined_Instance_Name,
   inpO_Model_Instance_Already_Defined,
   inpO_Model_More_Than_One_Instance_To_Empty_Part,

   inpO_Model_Undefined_Material,

   inpO_Model_Orientation_AB_Defined_Origin,
   inpO_Model_Orientation_Same_AB,
   inpO_Model_Orientation_ABOrigin_In_Line,
   inpO_Model_Orientation_Not_Defined,
   inpO_Model_Orientation_With_Layer_Angle,

   inpO_Model_Rotation_Axis_Points_Coincident,

   inpO_App_Zero_Valued_Table,

   inpO_Model_More_Than_One_ARS_Per_Part,

   inpO_Fourier_Term_Mismatch_In_Amplitude_Data,
   inpO_Model_Duplicate_Ply_Name,

   inpO_No_ARS_In_Part_Instance,
   inpO_No_ARS_In_Assembly,
   inpO_No_ARS_In_Part,
   inpO_No_More_Than_One_ARS_In_Part
};

atr_String i18n_inpO_modelMessages(int msgId);


#endif /* inpO_modelMessages_h */
