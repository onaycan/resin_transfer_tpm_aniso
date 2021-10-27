#ifndef cls_CtorDtorDefs_h
#define cls_CtorDtorDefs_h

///////////////////////////////////////////////////////////////////////////////
//
//
// Description:
//   
// Modification history:
//      Rob deFriesse 3/2000 original
//
////////////////////////////////////////////////////////////////////////// */

// Begin local includes

#include <cls_IntCOW.h>

// End local includes

class cls_ReadVisitor;

typedef void* (*cls_Ctor)(cls_ReadVisitor& rv);
typedef void  (*cls_Dtor)(cls_IntCOW* cow);

#endif
