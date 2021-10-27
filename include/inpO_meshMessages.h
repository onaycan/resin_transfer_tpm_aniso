/*   -*- mode: c++ -*-   */
#ifndef inpO_meshMessages_h
#define inpO_meshMessages_h

///////////////////////////////////////////////////////////////////////////////
//
// Class: inpO_meshMessages
//
// Description:
//

// Includes

// Forward declarations

// Begin local includes
#include <atr_String.h>


// Class definition

enum inpO_MeshMessageEnm {
   inpO_Mesh_Invalid_Element_Label,
   inpO_Mesh_Element_Label_Greater_Max,
   inpO_Mesh_Missing_Connectivity,
   inpO_Mesh_Zero_Negative_Connectivity,

   inpO_Mesh_Node_Set_Does_Not_Exist,
   inpO_Mesh_Element_Set_Does_Not_Exist,

   inpO_Mesh_Surface_NoFaceId,

   inpO_Mesh_Incomplete_Data,

   inpO_Mesh_Arc_End_Point_Same_As_Center,
   inpO_Mesh_Line_C_Radii_Not_Equal,
   inpO_Mesh_Circle_Is_Line,
   inpO_Mesh_Different_Size_Sets,
   inpO_Mesh_Invalid_Number_Intervals,
   inpO_Mesh_Noneven_Number_Intervals
};

atr_String i18n_inpO_meshMessages(int msgId);


#endif /* inpO_meshMessages_h */
