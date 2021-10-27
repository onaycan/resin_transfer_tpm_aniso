#ifndef SMASimArray_h
#define SMASimArray_h

// Begin local includes
#include <mem_AllocationOperators.h>
// End local includes
// ====================================================================

template <typename T>
struct SMASimArrayBuiltinPolicy;

template <typename T>
struct SMASimArrayClassPolicy;

template <typename T>
struct SMASimArrayCopyClassPolicy;

template <typename T, typename P>
class SMASimArrayPointer;

// ====================================================================

template <typename T, typename P>
struct SMASimArrayImpl : public mem_AllocationOperators
{
    SMASimArrayImpl(int size,
                    T* data,
                    int extension = 0,
                    int cursor = 0)
        : m_RefCount(1),
          m_Size(size),
          m_Extension(extension),
          m_Cursor(cursor), 
          m_Data(data)
        {}

    int m_RefCount;
    int m_Size;
    int m_Extension;
    int m_Cursor;
    T* m_Data;
};

// ===================================================================

/**
* Template class for holding an array of specified type employing a specified management policy
**/
template <typename T, typename P>
class SMASimArray : public mem_AllocationOperators
{
    friend class SMASimArrayPointer<T,P>;

public:
    /// Default constructor
    SMASimArray() : m_Impl(0) {}

    /// Construct an array of specified size
    SMASimArray(int size, int extension = 0);

    /// Destructor
    ~SMASimArray();

    /// Return the number of items in the array
    int Size() const;

    /// Extend the array to hold a new number of items
    void SetSize(int newSize);

    /// Set the amount the array is extended when Append()
    /// reaches Size()
    void SetExtension(int extension);

    /// Override the position at which the next append will occur
    void SetAppendLocation(int loc);

    /// Get the position at which the next append will occur
    int GetAppendLocation() const;

    /// Return a const reference to item in the array
    T const& ConstGet(int i) const;

    /// Return a const reference to item in the array
    T const& operator[](int i) const { return ConstGet(i); }

    /// Return a non-const reference to item in the array
    T& Get(int);

    /// Append a member at the end of the array.
    void Append(T item);
    
    /// Sort the array using the specified comparison function. This Sort function
    /// must be used in those rare cases when members of this array cannot be sorted
    /// with qsort. This happens when objects directly or indirectly point to
    /// themselves. One example of such object is CATString.
    void Sort(int (*compare)(T const **ppfirst, T const **ppsecond));

    /// Sort the array using the specified comparison function. This Sort function
    /// can only be used in cases when members of this array can be sorted
    /// with qsort. This is the case when objects do not directly or indirectly point to
    /// themselves.
    void Sort(int (*compare)(T const *pfirst, T const *psecond));

    /// Return true if the array is insorted order, specified by the comparison function. 
    /// Similar to the Sort method preceeding this one, it can only be used in cases when 
    /// members of this array can be sorted with qsort. This is the case when objects do 
    /// not directly or indirectly point to themselves.
    bool IsSorted(int (*compare)(T const *pfirst, T const *psecond));

    /// Searches for the given element in this array. Returns the element index
    /// or -1 if the element hasn't been found. The array must have been sorted before
    /// with the same or equivalent comparison function.
    int BinarySearch(const T &item, int (*compare)(T const *pfirst, T const *psecond)) const;

    /// Copy constructor
    SMASimArray(SMASimArray const&);

    /// Assignment operator
    SMASimArray const& operator=(SMASimArray const&);

    /// Compare two arrays to see if they are different
    /// This is an optimization for operator==().  It is not
    /// for general consumption.
    bool Different(SMASimArray<T, P> const&) const;

private:
    const T* Ptr() const;
    void Clone();
    void CheckIndex(int i) const;

    SMASimArrayImpl<T,P>* m_Impl;
};

/// Array equality operator
//  This would have been implemented very differently if it
//  weren't for tgen.  Tgen forces the a class method to be
//  instantiated, even if it isn't needed.  That causes a
//  problem when operator==() is not defined on the target
//  class.
template <typename T, typename P>
inline bool operator== (SMASimArray<T, P> const& left,
                        SMASimArray<T, P> const& right)
{
    if(left.Different(right))
        return false;

    int size = left.Size();
    for(int i = 0; i < size; ++i)
        if(left[i] != right[i])
            return false;

    return true;
}

/// Array inequality operator
template <typename T, typename P>
inline bool operator!= (SMASimArray<T, P> const& left,
                        SMASimArray<T, P> const& right)
{
    return !operator==(left, right);
}

/**
* Template class to provide raw pointer to data contained in
* a SMASIMArray object.  This class guarantees that the
* memory that is pointed to is available for the life time
* of the object and is cleaned up when the object is destroyed.
**/
template <typename T, typename P>
class SMASimArrayPointer : public mem_AllocationOperators
{
public:
    /// Convert an array to a pointer
    SMASimArrayPointer(const SMASimArray<T,P>& sa) : m_Ptr(sa.Ptr()) {}

    /// Return pointer to a buffer
    const T* Ptr() const { return m_Ptr; }

private:
    const T* m_Ptr;
};

#define SMASIM_ARRAY_BUTILTIN_DECL(T, N)                                \
    typedef SMASimArray<T, SMASimArrayBuiltinPolicy<T> > N;             \
    typedef SMASimArrayPointer<T, SMASimArrayBuiltinPolicy<T> > N ## Pointer;
    
#define SMASIM_ARRAY_BUTILTIN_IMPL(T, N)                                \
    template class SMASimArrayBuiltinPolicy<T>;                         \
    typedef SMASimArrayBuiltinPolicy<T> N ## tgenShouldBeEliminated;    \
    template class SMASimArray<T, N ## tgenShouldBeEliminated>;

#define SMASIM_ARRAY_CLASS_DECL(T, N)                                   \
    typedef SMASimArray<T, SMASimArrayClassPolicy<T> > N;               \
    typedef SMASimArrayPointer<T, SMASimArrayClassPolicy<T> > N ## Pointer;
    
#define SMASIM_ARRAY_CLASS_IMPL(T, N)                                   \
    template class SMASimArrayClassPolicy<T>;                           \
    typedef SMASimArrayClassPolicy<T> N ## tgenShouldBeEliminated;      \
    template class SMASimArray<T, N ## tgenShouldBeEliminated>;

#define SMASIM_ARRAY_COPY_CLASS_DECL(T, N)                             \
    typedef SMASimArray<T, SMASimArrayCopyClassPolicy<T> > N;          \
    typedef SMASimArrayPointer<T, SMASimArrayCopyClassPolicy<T> > N ## Pointer;
    
#define SMASIM_ARRAY_COPY_CLASS_IMPL(T, N)                             \
    template class SMASimArrayCopyClassPolicy<T>;                      \
    typedef SMASimArrayCopyClassPolicy<T> N ## tgenShouldBeEliminated; \
    template class SMASimArray<T, N ## tgenShouldBeEliminated>;

#endif
