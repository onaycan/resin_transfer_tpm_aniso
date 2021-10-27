// -*- Mode: C++ -*-
#ifndef SMASimWeakReference_h
#define SMASimWeakReference_h

// Begin local includes
#include <SMASimWeakCounter.h>
#include <mem_AllocationOperators.h>

class SMASimInsider;

/**
  This class is a helper for implementing weak references. In order to create
  a weak reference class suitable for use with SMASimHolder, derive it from
  SMASimWeakReference<T> and provide suitable access API.
  */
template <class T>
class SMASimWeakReference
    : public mem_AllocationOperators
{
public:
    /// Return the target if is exists
    operator const void *() const { return IsAlive() && m_Target ? this : 0; };

	/// Returns true if target does not exist
    bool operator !() const { return IsAlive() && m_Target ? 0 : this; };

protected:
    /// Default constructor
    SMASimWeakReference()
        : m_Target(0), m_Counter(0) {}

    /// Construct from a target and counter
    SMASimWeakReference(T *target, SMASimWeakCounter *counter)
        : m_Target(target), m_Counter(counter) { Increment(); }
        
    /// Destructor
    ~SMASimWeakReference() {
        Decrement(); }

    /// Copy constructor
    SMASimWeakReference(const SMASimWeakReference &other)
        : m_Target(other.m_Target), m_Counter(other.m_Counter) { Increment(); }

    /// Assignment operator
    void operator =(const SMASimWeakReference &other) {
        other.Increment(); Decrement(); m_Target = other.m_Target; m_Counter = other.m_Counter; }

    /// Return true if a reference exists; false otherwise
    bool IsAlive() const {
        return m_Counter && m_Counter->IsAlive(); }

    /// Return the target if is exists
    T *Get() const {
        return IsAlive() ? m_Target : 0; }

    /// Equality operator
    friend bool operator ==(const SMASimWeakReference<T> &a, const SMASimWeakReference<T> &b) {
        return a.m_Target == b.m_Target; }

    /// Inequality operator
    friend bool operator !=(const SMASimWeakReference<T> &a, const SMASimWeakReference<T> &b) {
        return a.m_Target != b.m_Target; }

private:
    friend class SMASimInsider;
    void Increment() const { if (m_Counter) m_Counter->Increment(); }
    void Decrement() const { if (m_Counter) m_Counter->Decrement(); }

    T *m_Target;
    SMASimWeakCounter *m_Counter;
};

#endif
