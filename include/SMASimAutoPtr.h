#ifndef SMASimAutoPtr_h
#define SMASimAutoPtr_h
// Begin local includes
#include <mem_AllocationOperatorsTiny.h>
// End local includes

#ifndef ABQ_NO_AUTOPTR
template <class T>
struct SMASimAutoPtrMoveSrc
    : public mem_AllocationOperatorsTiny
{
    explicit SMASimAutoPtrMoveSrc(T *impl):
        m_Impl(impl) {}

    T *m_Impl;
};
#endif

template <class T>
class SMASimAutoPtrObjectInline: private mem_AllocationOperatorsTiny
{
public:
    static inline void Delete(T* p) { delete p; };
};

template <class T>
class SMASimAutoPtrObjectOutline: private mem_AllocationOperatorsTiny
{
public:
    static void Delete(T* p);
};

template <class T>
class SMASimAutoPtrArrayInline: private mem_AllocationOperatorsTiny
{
public:
    static inline void Delete(T* p) { delete [] p; };
};

template <class T>
class SMASimAutoPtrArrayOutline: private mem_AllocationOperatorsTiny
{
public:
    static void Delete(T* p);
};

///////////////////////////////////////////////////////////////////////////////
// This class template implements a standard-like auto ptr

template <class T, class P>
class SMASimAutoPtr
    : public mem_AllocationOperatorsTiny
{
public:

    // Creates an uninitialized pointer.
    SMASimAutoPtr()
        : m_Impl(0) {}

    // Creates an auto-pointer initialized with an object.
    explicit SMASimAutoPtr(T *impl)
        : m_Impl(impl) {}


    // Moves the object here from another auto pointer
#ifndef ABQ_NO_AUTOPTR
    SMASimAutoPtr(SMASimAutoPtr &ptr)
        : m_Impl(ptr.m_Impl)
    {
        ptr.m_Impl = 0;
    }
#else
    // For compilers that do not support the standard auto_ptr
    SMASimAutoPtr(const SMASimAutoPtr &ptr)
        : m_Impl(ptr.m_Impl)
    {
        ((SMASimAutoPtr&)ptr).m_Impl = 0;
    }
#endif

    // Deletes the held object.
    ~SMASimAutoPtr() {
        Delete(); }

    // Moves the object here from another auto pointer
#ifndef ABQ_NO_AUTOPTR
    void operator =(SMASimAutoPtr &ptr)
    {
        Delete();
        m_Impl = ptr.m_Impl;
        ptr.m_Impl = 0;
    }
#else
    // For compilers that do not support the standard auto_ptr
    void operator =(const SMASimAutoPtr &ptr)
    {
        Delete();
        m_Impl = ptr.m_Impl;
        ((SMASimAutoPtr&)ptr).m_Impl = 0;
    }
#endif

    // Returns a non-NULL value if this pointer has a value.
    operator void *() const {
        return m_Impl; }

    // Returns true if this pointer has no value.
    bool operator !() const {
        return !m_Impl; }

    // Returns a handle to the held object.
    T *Get() const {
        return m_Impl; }

    // Allows access to the held object using the arrow operator.
    T *operator ->() const {
        return m_Impl; }

    // Dereferences the object.
    T &operator *() const {
        return *m_Impl; }

    // Deletes the held object and resets it with another one
    void Reset(T *ptr = 0) {
        if (ptr != m_Impl) Delete();
        m_Impl = ptr; }

    // Deletes the held object and resets it with another one
    void NewValue(T *ptr = 0) {
        Reset(ptr); }

    // Releases the held object and returns a pointer to it.
    T *Release() {
        T *tmp = m_Impl;
        m_Impl = 0;
        return tmp; }

    // Releases the held object and returns a pointer to it.
    T *HandOver() {
        return Release(); }

#ifndef ABQ_NO_AUTOPTR

    // Support for auto_ptr-like behavior.

    operator SMASimAutoPtrMoveSrc<T>() {
        SMASimAutoPtrMoveSrc<T> src(m_Impl);
        m_Impl = 0;
        return src;
    }

    SMASimAutoPtr(SMASimAutoPtrMoveSrc<T> ms)
        : m_Impl(ms.m_Impl) {}

    void operator =(SMASimAutoPtrMoveSrc<T> ms) {
        Delete();
        m_Impl = ms.m_Impl;
    }
#endif

private:

    void Delete() {
        P::Delete(m_Impl);
        m_Impl = 0; }

    T *m_Impl;
};


#define DPA_AUTOPTR_DECL(Type,Name) \
    typedef SMASimAutoPtr<Type, SMASimAutoPtrObjectOutline<Type> > Name

#define DPA_AUTOPTR_IMPL(Type,Name) \
    template class SMASimAutoPtrObjectOutline<Type>

#define DPA_AUTOPTR_INL_DECL(Type,Name) \
    typedef SMASimAutoPtr<Type, SMASimAutoPtrObjectInline<Type> > Name

// For use in variable declaration
#define DPA_AUTOPTR(Type) \
    SMASimAutoPtr<Type, SMASimAutoPtrObjectInline<Type> >


#define DPA_AUTOPTR_ARR_DECL(Type,Name) \
    typedef SMASimAutoPtr<Type, SMASimAutoPtrArrayOutline<Type> > Name

#define DPA_AUTOPTR_ARR_IMPL(Type,Name) \
    template class SMASimAutoPtrArrayOutline<Type>

#define DPA_AUTOPTR_ARR_INL_DECL(Type,Name) \
    typedef SMASimAutoPtr<Type, SMASimAutoPtrArrayInline<Type> > Name

// For use in variable declaration
#define DPA_AUTOPTR_ARR(Type) \
    SMASimAutoPtr<Type, SMASimAutoPtrArrayInline<Type> >

#endif // SMASimAutoPtr_h
