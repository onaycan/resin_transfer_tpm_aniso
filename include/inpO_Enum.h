/*   -*- mode: c++ -*-   */
#ifndef inpO_Enum_h
#define inpO_Enum_h

///////////////////////////////////////////////////////////////////////////////
//
// Class: inpO_Enum
//
// Description:
//

// Includes

// Forward declarations

// Begin local includes
#include <mem_AllocationOperators.h>

// Class definition

class inpO_Enum  : public mem_AllocationOperators
{
public:

   enum MsgSeverity {
      MESSAGE_SEVERITY_UNDEFINED,
      WARNING_MESSAGE,
      ERROR_MESSAGE,
      FATAL_ERROR_MESSAGE
    };

   enum MsgType {
      MESSAGE_UNDEFINED,
      APP_MESSAGE,
      MODEL_MESSAGE,
      MESH_MESSAGE,
      MATERIAL_MESSAGE
    };

   enum MsgArgType { 
      UNDEFINED,
      INTEGER, 
      BOOLEAN, 
      REAL, 
      STRING, 
      INTEGER_ARRAY, 
      REAL_ARRAY,
      DATA_ARRAY,
      NONE };

   enum CoordTransformationType {
      POLE,
      REFLECT,
      SHIFT,
      REFLECT_LINE,
      REFLECT_PLANE,
      REFLECT_POINT
   };

   enum SurfaceSegmentType {
      START,
      LINE,
      CIRCL,
      PARAB
   };

   enum ARSType {
      SEGMENTS,
      CYLINDER,
      REVOLUTION
   };
};


#endif /* inpO_Enum_h */
