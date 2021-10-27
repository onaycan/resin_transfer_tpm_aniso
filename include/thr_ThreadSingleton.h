#ifndef thr_ThreadSingleton_h
#define thr_ThreadSingleton_h

// This file defines a class template, which provides a uniform interface
// to enforce singleton behavior for its instance classes. All public
// access to a singleton class must invoke the static Instance method
// provided by this template. For example:
// 
//    fac_Class::Instance().Methods(args);
// 
// This singleton form implicitly constructs the singleton object on
// demand. It requires a default constructor. If the class requires
// specific arguments for construction or it must be constructed at a
// specific point during execution, use the thr_ThreadSingletonExplicit
// template. The thr_ThreadSingleton form is preferred; use the more
// complicated form only when necessary.
//
// A singleton class must be declared as follows. The class must inherit
// from its singleton instance. The class must provide a default
// constructor. This must be declared private, it must be the only
// constructor, and the instance class must be declared a friend, so that
// only this template can construct an object. For example:
// 
//    class fac_Class : public thr_ThreadSingleton<fac_Class> {
//        friend class thr_ThreadSingleton<fac_Class>;
//        fac_Class();
// 
// A singleton class must explicitly instantiate it singleton interface
// by including its class header file and this template's implementation
// file, followed by an explicit instantiator. For example:
// 
//    #include <fac_Class.h>
//    #include <thr_ThreadSingleton.T>
//    THR_THREADSINGLETON(fac_Class);
//
// A singleton class must be finalized within the fac_initialize.C file
// of its facility by calling the static Finalize method provided by this
// template. For example:
// 
//    #include <fac_Class.h>
//    /// End of Headers ///
// 
//    /// Begin Facility Finalization ///
//    fac_Class::Finalize();
//    /// End Facility Finalization ///
// 
// 

// Begin local includes
#include <thr_ThreadSingletonBase.h>
// End local includes

template <class Class>
class thr_ThreadSingleton : public thr_ThreadSingletonBase<Class> {
public:
    // This Instance method constructs an object on demand. It must be
    // out-of-line to avoid the need to export the static data member.
    //
    static Class& Instance();
};

#endif // thr_ThreadSingleton_h
