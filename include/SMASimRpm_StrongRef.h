#ifndef SMASimRpm_StrongRef_h
#define SMASimRpm_StrongRef_h

// Begin local includes
#include <mem_AllocationOperatorsTiny.h>
// End local includes

struct SMASimRpm_RefCounter;

template <typename T>
class SMASimRpm_WeakRef;

template <typename T>
class SMASimRpm_StrongRef : public mem_AllocationOperatorsTiny
{
public:
    SMASimRpm_StrongRef();
    SMASimRpm_StrongRef(T* t);
    SMASimRpm_StrongRef(const SMASimRpm_StrongRef<T>&);
    ~SMASimRpm_StrongRef();

    SMASimRpm_StrongRef& operator=(const SMASimRpm_StrongRef<T>&);

    bool Null() const { return !mPointer; }
    void Nullify();

    // For some reason, these can't be outlined.  I'm guessing it's tgen.
    T& operator*() const { return *Get(); }
    T* operator->() const { return Get(); }

    T* Get() const;

private:
    friend class SMASimRpm_WeakRef<T>;

    void Disconnect();
    void Connect(T*, SMASimRpm_RefCounter*);

    T* mPointer;
    SMASimRpm_RefCounter* mCounter;
};

#endif
