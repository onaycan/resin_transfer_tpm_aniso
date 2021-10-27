#ifndef thr_SpinMacros_h
#define thr_SpinMacros_h

// Begin local includes

#include <thr_ThreadingModel.h>

// End local includes

//-----------------------------------------------------------------
// PTHREADS IMPLEMENTATION
//-----------------------------------------------------------------
#if defined HKS_PTHREADS

// Remove definitions from compile files. 
#undef THR_SPIN_LOOP
#undef THR_SPIN_YIELD

// use THR_SPIN_LOOP for increased performance
#define THR_SPIN_LOOP

#if defined THR_SPIN_YIELD
#include	<sched.h>
#define THR_SPIN sched_yield()
#elif defined THR_SPIN_LOOP
#define THR_SPIN
#endif

//-----------------------------------------------------------------
// WINDOWS THREADS IMPLEMENTATION
//-----------------------------------------------------------------
#elif defined HKS_WINTHREADS

#undef THR_SPIN_LOOP
#undef THR_SPIN_YIELD

#define THR_SPIN_LOOP

#if defined THR_SPIN_YIELD
#define THR_SPIN Sleep(0)
#elif defined THR_SPIN_LOOP
#define THR_SPIN
#endif

// This definition removes a name clash between ADB VarFormat and Windows OLE VarFormat!
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
// A bit more to try and speed things up ...
#ifndef NOSERVICE
#define NOSERVICE
#endif
#ifndef NOMCX
#define NOMCX
#endif
#ifndef NOIME
#define NOIME
#endif
#ifndef NOSOUND
#define NOSOUND
#endif
#ifndef NOCOMM
#define NOCOMM
#endif
#ifndef NOKANJI
#define NOKANJI
#endif
#ifndef NORPC
#define NORPC
#endif
#ifndef NOPROXYSTUB 
#define NOPROXYSTUB 
#endif
#ifndef NOIMAGE
#define NOIMAGE
#endif
#ifndef NOTAPE
#define NOTAPE
#endif
#include <windows.h>

//-----------------------------------------------------------------
// NO THREADS IMPLEMENTATION
//-----------------------------------------------------------------
#else

#undef THR_SPIN_LOOP
#undef THR_SPIN_YIELD

#define THR_SPIN_LOOP
#define THR_SPIN

#endif /* HKS_PTHREADS, HKS_WINTHREADS, NO THREADS */

#endif /* thr_SpinMacros_h */
