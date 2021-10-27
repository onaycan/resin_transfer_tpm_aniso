#ifndef thr_ThreadSingletonBase_h
#define thr_ThreadSingletonBase_h

// Begin local includes
#include <mem_AllocationOperators.h>
#include <thr_ThreadingModel.h>

// This file defines an abstract base class template. Do not instantiate
// this template directly. Use either the thr_ThreadSingleton derivative.


//-----------------------------------------------------------------
// PTHREADS IMPLEMENTATION
//-----------------------------------------------------------------
#if defined HKS_PTHREADS

template <class Class> class thr_ThreadSingletonBase  : public mem_AllocationOperators
{
     static void*  instanceKeyPtr;
     static int    refCount;

     static void DeleteKey(void* arg);

protected:
    // The constructor enforces that at most one instance is created.
    //
    thr_ThreadSingletonBase();

    // This Instance method is overridden in the derivative templates,
    // and return type is change from a pointer to a reference.
    //
    static Class* Instance();

public:
    // The Finalize method should be called from within its
    // fac_initialize.C file.
    //
    static int Finalize();
};


//-----------------------------------------------------------------
// WINDOWS THREADS IMPLEMENTATION
//-----------------------------------------------------------------
#elif defined HKS_WINTHREADS
template <class Class> class thr_ThreadSingletonBase  : public mem_AllocationOperators
{
    static int   instanceTlsIndex;
    static int   refCount;

protected:
    // The constructor enforces that at most one instance is created.
    //
    thr_ThreadSingletonBase();

    // This Instance method is overridden in the derivative templates,
    // and return type is change from a pointer to a reference.
    //
    static Class* Instance();

public:
    // The Finalize method should be called from within its
    // fac_initialize.C file.
    //
    static int Finalize();
};

//-----------------------------------------------------------------
// NOTHREADS IMPLEMENTATION
//-----------------------------------------------------------------
#elif defined HKS_NOTHREADS

// The following is for machines with no threads. This is provided
// to avoid forcing if def's for all threaded code. This singleton
// will behave like an omi_Singleton.

template <class Class> class thr_ThreadSingletonBase  : public mem_AllocationOperators
{
    static Class* instance;

protected:
    // The constructor enforces that at most one instance is created.
    //
    thr_ThreadSingletonBase();

    // This Instance method is overridden in the derivative templates,
    // and return type is change from a pointer to a reference.
    //
    static Class* Instance() { return instance; }

public:
    // The Finalize method should be called from within its
    // fac_initialize.C file.
    //
    static int Finalize();
};

#endif

#endif /* thr_ThreadSingletonBase_h */
