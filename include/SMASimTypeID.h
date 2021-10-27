#ifndef SMASimTypeID_h
#define SMASimTypeID_h
// Begin local includes
#include <mem_AllocationOperatorsTiny.h>
#include <SMASimIDMinor.h>
// End local includes

// Forward declarations
class SMASimTypeFormRepr;
class SMASimRecTypeReader;
class SMASimDatabaseRepr;
class SMASimDataRecordRepr;
class SMASimCollectionRepr;
class SMASimDynamicID;
class SMASimIDExternal;
class SMASimDebugOut;
class SMASimDistributionRepr;
class SMASimDrawer;

/**
   This class represents a globally unique type ID.
*/
class SMASimTypeID
    : public mem_AllocationOperatorsTiny
{
public:
    /** Constructs an empty type ID object. */
    SMASimTypeID() : m_Value(-1){}

    /** Create a TypeID() with the given value */
    explicit SMASimTypeID(int value): m_Value(value){}

    /** Returns the index of this type ID. */
    int TypeIndex() const;

    /** Returns the form of this type ID. */
    int FormIndex() const;

    /** Returns the integer representation of this type. The value of -1 is returned for the NULL Type. */
    int Value() const { return m_Value; }

    /** Returns true if this is an empty ID. */
    bool IsNull() const {
        return m_Value == -1; }

    /** Returns true if this is NOT an empty ID. */
    operator const void *() const {
        return !IsNull() ? this : 0; }

    /** Returns true if this is an empty ID. */
    bool operator !() const {
        return IsNull(); }

    /** Compares this object to another type ID. */
    int Compare(const SMASimTypeID &other) const {
        return m_Value < other.m_Value ? -1 : (m_Value > other.m_Value ? 1 : 0); }

    /** Upper bounds for Category Bits(reserved for FormID) 
     (Idea borrowed from CollectionID::CategoryBits) */
    /* DEVELOPER CAUTION: FIX 31 when namespaceID bit is removed */
    enum CategoryBits {
        e_FormBits = 8, ///< 8 bits used for 'form'
        e_MaxForm = 1 << e_FormBits, ///< maximum color number plus 1
        e_ExcessiveTypeID = 1 << (32-e_FormBits) ///< must not collide with the 6 bits used for coloring
    };

    /** Get an informal string representation of the ID. */
    CATString AsString() const;

    /// Display on ostream 
    /// For dpa use only - do not export
    SMASimDebugOut& WriteDebug(SMASimDebugOut& uos) const;

    // *** FOR INTERNAL USE ONLY ***
    // Constructs a type ID object.
    SMASimTypeID(int typeIndex, int formIndex);


private: // only for friends

    friend class SMASimTypeFormRepr;
    friend class SMASimDatabaseRepr;
    friend class SMASimDataRecordRepr;
    friend class SMASimCollectionRepr;
    friend class SMASimDynamicID;
    friend class SMASimDistributionRepr;
    friend class SMASimDrawer;
    friend class SMASimIDExternal;

private:
    int m_Value;
};

/** Display of SMASimTypeID - ONLY for debugging */
inline SMASimDebugOut& operator<<(SMASimDebugOut& uos, SMASimTypeID tid)
{
    return tid.WriteDebug(uos);
}

inline bool operator ==(const SMASimTypeID &a, const SMASimTypeID &b) { return a.Compare(b) == 0; }
inline bool operator !=(const SMASimTypeID &a, const SMASimTypeID &b) { return a.Compare(b) != 0; }
inline bool operator < (const SMASimTypeID &a, const SMASimTypeID &b) { return a.Compare(b) < 0; }
inline bool operator <=(const SMASimTypeID &a, const SMASimTypeID &b) { return a.Compare(b) <= 0; }
inline bool operator > (const SMASimTypeID &a, const SMASimTypeID &b) { return a.Compare(b) > 0; }
inline bool operator >=(const SMASimTypeID &a, const SMASimTypeID &b) { return a.Compare(b) >= 0; }

#endif
