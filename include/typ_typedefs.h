#ifndef typ_typedefs_h
#define typ_typedefs_h

/* -*- mode: c++ -*- */
///////////////////////////////////////////////////////////////////////////////
//
// File Name: typ_typedefs.h
// 
// Author: Uttam Narsu
// 
// Creation date: Tue Jan 20 1995
//
// Purpose:
//
// This file contains the definition of the typ_typedefs struct.
//

//
// Forward Declarations
//

//
// Includes
//

// Begin local includes

#include <omi_types.h>
#include <typ_typeTag.h>

// Forward Decls (so this inferior facility doesn't have knowledge
// of the superior ipc and pnt facilities)

class aio_ostream;
class bio_Ifilter;
class bio_Ofilter;
class pnt_PrettyPrint;
class mem_Heap;
class mem_ObjectPtr;
class mem_ObjectObj;
class obj_ObjectPtr;
class obj_ObjectObj;

//
// Function typedefs for boxed types.
//

// Construct a smartptr from an ipc input filter

typedef obj_ObjectPtr (*typ_Ctor) (bio_Ifilter&);

/*
 *	Uttam and I believe that the ability to construct a handle
 * and call a virtual method on all heap objects eliminates then
 * need for these routines.
 *
 *	They could be useful for simple types, but we believe that
 * the compiler always has enough information to support this case
 * since we have no intention of dynamic instantiation of templates
 * with simple types for FER.
 */

// Write an object out to an ipc output filter
typedef bio_Ofilter& (*typ_outMarshall) (bio_Ofilter&, 
					 const obj_ObjectPtr&);

// Pretty print the object passed as the second arg
typedef pnt_PrettyPrint& (*typ_PntPrint) (pnt_PrettyPrint&,
					  const obj_ObjectPtr&);

// Construct a smartptr given a body pointer; To be removed in type
// table cleanup.

typedef void* typ_HandleCtor;


// typedefs for p0 read & write routines to a stream 
// Note: the void* stuff is to keep from imposing a common base
// class on p0 objects at the cost of some loss of type safety.

typedef void         (*typ_ReadMsgFunc)(bio_Ifilter&, void*);
typedef bio_Ofilter& (*typ_WriteMsgFunc)(bio_Ofilter&, const void*);

// Pretty print the void* object passed as the second arg
typedef pnt_PrettyPrint& (*typ_PrintFunc) (pnt_PrettyPrint&, 
					   const void*);

// return a constructed object of a certain type
typedef void*        (*typ_CtorMsgFunc)(bio_Ifilter&, void*);

// Delete an object received and constructed by the ipc.
// This function is superfluous for a smartptr.
typedef void (*typ_Dtor)(void*);

#endif  // #ifdef typ_typedefs_h
