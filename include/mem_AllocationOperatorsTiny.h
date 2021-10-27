#ifndef MEM_AllocationOPERatorsTIny_h
#define MEM_AllocationOPERatorsTIny_h

// The class in this file implements the new and delete operators for all 
// ABAQUS classes with sizeof(class) <= 129. All ABAQUS classes with 
// sizeof(class) <= 129 must derive from this class.
// The class is implemented such that we get interface inheritance .
// Do NOT change this file without consulting with Dennis Flanagan or 
// Robert Schweikert.

// Any classes with sizeof(class) > 128 must derive from mem_AllocOperator.

// Allocations for built in types need to use interfaces defined in 
// mem_AllocationOperatorsBuiltIn.h

// Declarations and implementation follow C++ Standard ISO/IEC 14882:1998(E)
// Applicaple sections 3.7.3, 5.3.4, 5.3.5, 12.5, 17.4.3.4, 18.4 

#include <stddef.h>  // For size_t

// Forward declarations
// HACK around non C++ compliant compiler on PA-RISC
#if (defined(HP11) && !defined (HKS_HPUXI))
struct nothrow_t;
#define ABQ_NOTHROW nothrow_t
#else
namespace std { struct nothrow_t; }
#define ABQ_NOTHROW std::nothrow_t
#endif

extern void* mem_OperatorNewTinyThrow(size_t);
extern void* mem_OperatorNewTinyNoThrow(size_t);

extern "C" void mem_Free(void*);

// Begin local includes


class mem_AllocationOperatorsTiny
{
public:
    // Plain operator new, throw on out of memory
    static void* operator new(size_t sz) {
        return mem_OperatorNewTinyThrow(sz);
    }
    // Array new, throw on out of memory
    // Note that we will return memory alligned according to 
    // the underlying operator alignment here.
    // There are a number of chances where the alignment can get messed up
    // 1.) The compiler can do the wrong thing
    // 2.) The user can replace the underlying allocator which can get the
    //     alignment wrong
    // The default implementation returns 16 byte aligned memory
    static void* operator new[](size_t sz) {
        return mem_OperatorNewTinyThrow(sz);
    }
    // Plain operator new, will not throw on out of memory
    static void* operator new(size_t sz, const ABQ_NOTHROW&) throw() {
        return mem_OperatorNewTinyNoThrow(sz);
    }
    // Array new, will not throw on out of memory
    static void* operator new[](size_t sz, const ABQ_NOTHROW& noTh) 
        throw() { return mem_OperatorNewTinyNoThrow(sz); }
    // Plain delete
    static void operator delete(void* ptr) { mem_Free(ptr); }
    static void operator delete(void* ptr, void*) { }
    // Array delete
    static void operator delete[](void* ptr) { mem_Free(ptr); }
    static void operator delete[](void* ptr, void*) { }
    // In-place new
    static void* operator new(size_t sz, void* ptr) {return ptr;}
    static void* operator new[](size_t sz, void* ptr) {return ptr;}
};

#endif  /* MEM_AllocationOPERatorsTIny_h */
