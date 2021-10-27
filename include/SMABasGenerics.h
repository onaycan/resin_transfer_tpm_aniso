//-*- mode: c++ -*-//
#ifndef SMABasGenerics_h
#define SMABasGenerics_h

///
/// Configuration settings:
///
/// SMA_USE_NATIVE_STL    -- use native implementation of STL.
/// 
///      This is the implementation that comes supplied 
///      by default with the OS or the compiler.

// #define SMA_USE_NATIVE_STL 1

#ifndef SMA_USE_NATIVE_STL
#if defined(ABQ_WIN86_32) || defined(ABQ_WIN86_64)
#define SMA_USE_NATIVE_STL 0
#else
#define SMA_USE_NATIVE_STL 0
#endif
#endif


// #if SMA_USE_NATIVE_STL

// #define AIO_IOSTREAM_H 1
// #define AIO_OFSTREAM_H 1
// #define AIO_IFSTREAM_H 1
// #define UTS_FILEFWD_H  1

// #include <iostream>
// #include <iomanip>

// #define aio_ifstream  std::ifstream
// #define aio_ofstream  std::ofstream
// #define aio_ostream   std::ostream
// #define aio_ios       ios

// using std::cout;
// using std::endl;
// using std::ios; 
// using std::setw;
// using std::setprecision;

// #endif // SMA_USE_NATIVE_STL

// Exceptions are only enabled in the DEBUG object in ABAQUS.
// Disabled everywhere else.

// Addendum: disable exceptions in all objects, per Nick Monyatovsky, 2009-06-02

#define SMA_BAS_GENERICS_EXCEPTIONS 0

#endif // SMABasGenerics_h


