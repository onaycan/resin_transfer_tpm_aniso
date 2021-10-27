#ifndef __SMAAssert
#define __SMAAssert
#include <assert.h>

// Macros for Assert and Verify.
// Assert is only active in debug code
// Verify is active in debug and production code.
// Since SMAAssert is not active in production code, it is not sufficient
// to silence warnings from mkCheckSource that could be silenced by
// SMAVerify

// Note: if the conditions can be asserted at compile-time, 
//   e.g. sizeof(A)==8, 
// prefer to use SMAStaticAssert instead to catch them at compile-time.

#define SMAAssert(cond) assert(cond)

// SMAVerify will assert in debug code. In production code, it throws
// an exception
#ifdef _SHARED_V5_
// Begin local includes
#   include <CATAssert.h>
// End local includes
#   define SMAVerify(cond) CATAssert(cond)
#else
#   ifdef NDEBUG
#      define _SMAstringify(exp) #exp
#      define _SMAstringifyPredef(exp) _SMAstringify(exp)
#      define SMAVerify(exp)  ((void) ( bool(exp) ? (void)0 : throw("***Fatal Error: Assertion Failed: " #exp ": " __FILE__ ": " _SMAstringifyPredef(__LINE__)) ))
#   else
#      define SMAVerify(cond) assert(cond)
#   endif
#endif

// SMAIfThen ::

//  Useful macro tool for any kind of assert, to make a conditional more readable
//  USAGE:
//     ANY_ASSERT( SMAIfThen( p, q) )
//
// When the assert is active, this behaves exactly like runtime equivalent:
// if (p)
//   ANY_ASSERT( q );
//
// where ANY_ASSERT is SMAAssert, SMAVerify, SMAStaticAssert, UTS_ASSERT etc.
// By boolean logic, the  above is actually equivalent to 
//    ANY_ASSERT( !p || q )
// but most people find the IfThen form easier to read and understand -- and also less
// prone to being written buggily.

#define SMAIfThen(x, y) (!(x) || (y))

#endif
