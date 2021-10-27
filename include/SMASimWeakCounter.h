// -*- Mode: C++ -*-
#ifndef SMASimWeakCounter_h
#define SMASimWeakCounter_h

// Begin local includes
#include <mem_AllocationOperatorsTiny.h>
#include <SMASimAutoPtr.h>

/**
  This class is a helper for object lifetime management.
*/
class SMASimWeakCounter
    : public mem_AllocationOperatorsTiny
{
public:

    /// Creates a counter
    SMASimWeakCounter()
        : m_WeakRefCount(0)
        , m_Alive(1) {}

    /// Returns true if the managed object is still alive.
    bool IsAlive() const {
        return m_Alive; }

    /// Returns the number of live weak references.
    int WeakRefCount() const {
        return m_WeakRefCount; }

    /// Adds a weak reference.
    void Increment() {
        m_WeakRefCount++; }

    /// Removes a weak reference.
    void Decrement() {
        if (!--m_WeakRefCount && !m_Alive)
            delete this; }

    /// Marks all weak references as invalid.
    void Destroy() {
        m_Alive = 0; 
        if (!m_WeakRefCount)
            delete this; }

private:
    int m_WeakRefCount;
    int m_Alive;
};

/**
  This class is a deleter for the weak counter. It only deletes the object
  if there are no weak references left.
  */
class SMASimWeakCounterDeleter: private mem_AllocationOperatorsTiny
{
public:
    /// Delete a weak counter
    static inline void Delete(SMASimWeakCounter* p) { if (p) p->Destroy(); }
};

// Declare the auto pointer of weak counters.
typedef SMASimAutoPtr<SMASimWeakCounter, SMASimWeakCounterDeleter> SMASimAutoPtrWeakCounter;

#endif
