#ifndef omi_for_types_h
#define omi_for_types_h


/* HACK around IBM compiler bug to avoid hugh build */
#if defined(RS6000)
#include <inttypes.h> /* intptr_t */
#else
/* Begin local includes */
#include <omi_types.h>
#endif

/* FORTRAN Data type mapping */

typedef int Integer;
typedef char          Char;
typedef unsigned int  UInt;
typedef int           Int;

typedef double        Double;
typedef double        Real64;
typedef float         Single;

#if defined(DPX)
typedef double        Real;
#else
typedef float         Real;
#endif

/* NOTE if we have a system with truly large memory space, i.e. > LONG_MAX
   we potentially will run into trouble and we will have to change Address
   to be uintptr_t */
typedef intptr_t Address;

#endif
