#ifndef SMASimIDMinor_h
#define SMASimIDMinor_h

// Begin local includes
#include <SMASimDataTypes.h>
#include <CATString.h>
#include <mem_AllocationOperatorsTiny.h>
#include <SMASimRpm_Offset.h>
// End local includes

// Forward declarations
class SMASimDebugOut;
class SMASimRpm_BStreamRead;
class SMASimRpm_BStreamWrite;

/**
   A minor ID uniquely identifies and object within the context of it's 
   parent ID. A minor ID was an int(4 bytes).. later represented by a 
   long long(8 bytes). Now we are reverting back to int(4 bytes). The
   argument for retaining an int is as follows. The IDMinor is an index
   to represent collections,distributions,drawers,csets. Our present
   needs are well served by this index being < (2^24). Using a long long
   is waste of storage. Another requirement is that we have a relational
   distribution on to cset_ids. The range_type of this distribution is
   int(we would like it to be int). IDMinors need to be ints for this
   to be possible(because an IDMinor & a collection_ID are adequate to
   recreate a cset_ID.
**/

class SMASimIDMinor
    : public mem_AllocationOperatorsTiny
{
public:
    /** Creates a NULL ID minor. */
    SMASimIDMinor(): m_Value(-1) {}

    /** Creates an ID minor object with the given value. Pass a c-member index here to get its ID minor representation.*/
    explicit SMASimIDMinor(int value) : m_Value(value) {}

    /** Creates an ID minor for the given object index and category bits. The namespace can be NULL.
        Category bits can be used to store extra per-object information, for example collection color,
        ascending/temporary flags for c-sets etc.
     */
    SMASimIDMinor(int objectIndex, int numCatBits, int catBits);

    /** Returns true if this is a NULL ID minor. */
    bool IsNull() const { return m_Value == -1; }

    /** Returns true if this minor fits in an int. */
    //bool FitsInInt() const { return m_Value >= -(1LL << 32) && m_Value < (1LL << 32); }


    /** Returns the object index, or -1 if this is a NULL ID. This function assumes there are no category bits in this minor. */
    int ObjectIndex() const;

    /** Returns the object index, or -1 if this is a NULL ID. */
    int ObjectIndex(int numCatBits) const;

    /** Returns the category bits for this object, or -1 if this is a NULL ID*/
    int CategoryBits(int numCatBits) const;

    /** Returns the integer value representation of this minor. The value of -1 is returned for the NULL ID minor. */
    int Value() const { return m_Value; }

    /** Returns true if this is NOT a NULL ID minor. */
    operator const void *() const { return !IsNull() ? this : 0; }

    /** Returns true if this is a NULL ID minor. */
    bool operator !() const { return IsNull(); }

    /** Returns a value smaller than zero if this < that, larger than zero if this > that, and zero if this == that. */
    int Compare(const SMASimIDMinor& that) const { return m_Value < that.m_Value ? -1 : (m_Value > that.m_Value ? 1 : 0); }

    /** Get an informal string representation of the ID. */
    CATString AsString() const;

    //--------------------------------
    // Not exported - for dpa use only
    //--------------------------------

    /// Display on ostream 
    /// For dpa use only - do not export
    SMASimDebugOut& WriteDebug(SMASimDebugOut& uos) const;

    /// Internal - do not use
    SMASimRpm_Offset ExternalSizeImpl() const;
    /// Internal - do not use
    void InternalizeImpl(SMASimRpm_BStreamRead& str);
    /// Internal - do not use
    void ExternalizeImpl(SMASimRpm_BStreamWrite& str) const;

private:

    int m_Value;
};

/// Display of SMASimIDMinor - ONLY for debugging
inline SMASimDebugOut& operator<<(SMASimDebugOut& uos, SMASimIDMinor id)
{
    return id.WriteDebug(uos);
}

inline bool operator ==(const SMASimIDMinor &a, const SMASimIDMinor &b) { return a.Compare(b) == 0; }
inline bool operator !=(const SMASimIDMinor &a, const SMASimIDMinor &b) { return a.Compare(b) != 0; }
inline bool operator < (const SMASimIDMinor &a, const SMASimIDMinor &b) { return a.Compare(b) < 0; }
inline bool operator <=(const SMASimIDMinor &a, const SMASimIDMinor &b) { return a.Compare(b) <= 0; }
inline bool operator > (const SMASimIDMinor &a, const SMASimIDMinor &b) { return a.Compare(b) > 0; }
inline bool operator >=(const SMASimIDMinor &a, const SMASimIDMinor &b) { return a.Compare(b) >= 0; }


#endif
