#ifndef SMABasAllocator_h
#define SMABasAllocator_h

#include <sys/types.h>

// Begin local includes
#include <mem_AllocationOperators.h>
#include <mem_AllocationOperatorsTiny.h>

/// A base class for a hierarchy of allocators used in SIMULIA.

class SMABasAllocator;

class SMABasAllocatorBase : public mem_AllocationOperators
{
public:
    SMABasAllocatorBase() : mRefCount(0) {}
    virtual ~SMABasAllocatorBase() { }
    virtual void* Alloc(const size_t size) = 0;    
    virtual void* Alloc(const size_t size, size_t& returnSize) = 0;    
    virtual void Free(void *ptr) = 0;
    virtual const SMABasAllocator& LargeBlockAllocator(const SMABasAllocator&) const = 0;

private:
    friend class SMABasAllocator;
    int mRefCount;

    SMABasAllocatorBase(const SMABasAllocatorBase&);
    SMABasAllocatorBase& operator=(const SMABasAllocatorBase&);
};

class SMABasAllocator : public mem_AllocationOperatorsTiny
{
public:
    SMABasAllocator() : mBase(0) {}
    explicit SMABasAllocator(SMABasAllocatorBase* base);
    SMABasAllocator(const SMABasAllocator& that);
    ~SMABasAllocator();

    SMABasAllocator& operator=(const SMABasAllocator& that);

    void* Alloc(const size_t size);
    void* Alloc(const size_t size, size_t& returnSize);
    void Free(void *ptr);

    bool IsNull() const { return !mBase; }

    const SMABasAllocator& LargeBlockAllocator() const;

private:
    void Swap(SMABasAllocator& that);

    SMABasAllocatorBase* mBase;
};

#endif // SMABasAllocator_h
