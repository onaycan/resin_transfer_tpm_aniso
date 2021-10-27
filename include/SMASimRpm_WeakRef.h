#ifndef SMASimRpm_WeakRef_h
#define SMASimRpm_WeakRef_h

// Begin local includes
#include <mem_AllocationOperatorsTiny.h>
// End local includes

struct SMASimRpm_RefCounter;

template <typename T>
class SMASimRpm_StrongRef;

template <typename T>
class SMASimRpm_WeakRef : public mem_AllocationOperatorsTiny
{
public:
    SMASimRpm_WeakRef();
    SMASimRpm_WeakRef(const SMASimRpm_WeakRef<T>&);
    SMASimRpm_WeakRef(const SMASimRpm_StrongRef<T>&);
    ~SMASimRpm_WeakRef();

    SMASimRpm_WeakRef& operator=(const SMASimRpm_WeakRef<T>&);
    SMASimRpm_WeakRef& operator=(const SMASimRpm_StrongRef<T>&);

    bool Null() const { return !mPointer; }
    void Nullify();

    SMASimRpm_StrongRef<T> lock() const;

    // For some reason, these can't be outlined.  I'm guessing it's tgen.
    T& operator*() const { return *Get(); }
    T* operator->() const { return Get(); }

    T* Get() const;

private:
    void Disconnect();
    void Connect(T*, SMASimRpm_RefCounter*);

    T* mPointer;
    SMASimRpm_RefCounter* mCounter;
};

#endif
