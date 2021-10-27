#ifndef SMASimIndexSetPtr_h
#define SMASimIndexSetPtr_h

// Begin Local Includes
#include <mem_AllocationOperators.h>
#include <SMABasAllocator.h>

// Forward declarations
class cow_Counter;
class SMASimIndexSet;

struct SMASimIndexSetPtrImpl : public mem_AllocationOperators
{
    SMASimIndexSetPtrImpl(const SMABasAllocator& pool) : mCount(0), mPool(pool) {}
    int mCount;
    SMABasAllocator mPool;
};

///
/// A reference counted index set pointer holder
///
class SMASimIndexSetPtr : public mem_AllocationOperators
{
public:
    /// Default constructor
    SMASimIndexSetPtr() : mRef(0), mImpl(0) {}

    /// Constructor, adopt index set pointer
    SMASimIndexSetPtr(SMASimIndexSet* set, const SMABasAllocator& pool);

    /// Copy constructor.  Make another shared ownership reference to the index set.
    SMASimIndexSetPtr(const SMASimIndexSetPtr&);

    ~SMASimIndexSetPtr();

    /// Assignment operator.   Make another shared ownership reference to the index set.
    SMASimIndexSetPtr& operator= (const SMASimIndexSetPtr&);

    /// Return the pointer to the index set
    SMASimIndexSet* GetPtr() const { return mRef; }

    /// Return true if the index set pointer is not set, false if it is
    bool IsNull() const { return !mRef; }

protected:
    void Disconnect();
    void Connect(SMASimIndexSet*, SMASimIndexSetPtrImpl*);
    void Swap(SMASimIndexSetPtr&);

    SMASimIndexSet *mRef;
    SMASimIndexSetPtrImpl* mImpl;
};

#endif
