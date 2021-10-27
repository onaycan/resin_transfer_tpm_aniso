#ifndef thr_ThreadingModel_h
#define thr_ThreadingModel_h

// Use this header file to dictate the threading model in use. Current options
// are windows threads (HKS_WINTHREADS) and posix threads (HKS_PTHREADS). 
// OpenMP is another possibility, but as too many compilers lack C or C++ 
// support at this time, it is only for testing. In addition the option of having
// no threads is defined by HKS_NOTHREADS. This is used to handle HPUX 10.20 and 
// any other possible machines that do not support threads.

#if defined HKS_NT
#    define HKS_WINTHREADS
#else
#    define HKS_PTHREADS
#endif

#endif // thr_ThreadingModel_h
