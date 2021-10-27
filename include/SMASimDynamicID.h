#ifndef SMASimDynamicID_h
#define SMASimDynamicID_h
// Begin local includes
#include <SMASimDynamicDataID.h>
#include <SMASimCategory.h>
#include <SMASimContextID.h>
#include <SMASimTypeID.h>
#include <mem_AllocationOperatorsTiny.h>
// End local includes

// Forward declarations
class SMASimCMemberID;
class SMASimCSet;
class SMASimCSetID;
class SMASimCollectionID;
class SMASimContextRepr;
class SMASimDSetCtation;
class SMASimDSetEmpty;
class SMASimDSetID;
class SMASimDSetRelDistr;
class SMASimDSetSparse;
class SMASimDSetTable;
class SMASimDataRecordID;
class SMASimDatabaseRepr;
class SMASimDistributionID;
class SMASimDrawerID;
class SMASimDynamicID;
class SMASimFTableID;
class SMASimIDExternal;
class SMASimInsider;
class SMASimODSetID;
class SMASimPosition;
class SMASimRecTypeRegistryRepr;
class SMASimSchemaTransformRepr;
class SMASimSymbolsRepr;
class SMASimTableID;
class SMASimTableRepr;
class SMASimTransactionRepr;
class SMASimViewRepr;
class SMASimPosition;
class SMASimUpgPosition;

/**
   This class represents a generic ID.
*/
class SMASimDynamicID : public mem_AllocationOperatorsTiny
{
    friend class SMASimInsider;
    friend class SMASimPosition;
    friend class SMASimUpgPosition;
    friend class SMASimCollectionID;
    friend class SMASimDistributionID;
    friend class SMASimSchemaTransformRepr;
    friend class SMASimDSetID;
    friend class SMASimODSetID;
    friend class SMASimCSetID;
    friend class SMASimCSet;
    friend class SMASimDrawerID;
    friend class SMASimCMemberID;
    friend class SMASimTableID;
    friend class SMASimFTableID;
    friend class SMASimDataRecordID;
    friend class SMASimIDExternal;

    friend class SMASimDatabaseRepr;
    friend class SMASimTransactionRepr;
    friend class SMASimViewRepr;
    friend class SMASimContextRepr;
    friend class SMASimSymbolsRepr;
    friend class SMASimTableRepr;
    friend class SMASimRecTypeRegistryRepr;
    friend class SMASimDSetEmpty;
    friend class SMASimDSetCtation;
    friend class SMASimDSetSparse;
    friend class SMASimDSetTable;
    friend class SMASimDSetRelDistr;
    friend class SMASimDynamicID;

    friend struct SMASimDynamicIdPrivate; // Access to Internalize()

    friend SMASimDebugOut& operator<<(SMASimDebugOut& dbs,  const SMASimDynamicID &b);

public:

    /** Creates a dynamic ID that does not refer to anything. */
    SMASimDynamicID() : m_Category(SMASimCategoryNull) {}

    /** Creates a dynamic ID from a context ID and an external ID. */
    SMASimDynamicID(SMASimContextID contextID, SMASimIDExternal extID);

    /** OBSOLETE: Returns the context ID. */
    SMASimContextID Context() const {
        return m_ContextID; }

    /** Returns the context ID. */
    SMASimContextID ContextID() const {
        return m_ContextID; }

    /** Returns a Position object. */
    SMASimPosition Position() const;

    /** Returns true if this ID does not refer to any object. */
    bool IsNull() const {
        return m_Category == SMASimCategoryNull; }

    /** Returns true if this ID refers to some object. */
    operator const void *() const {
        return IsNull() ? 0 : this; }

    /** Returns true if this ID does not refer to any object. */
    bool operator !() const {
        return IsNull(); }

    /** Compliance with SMABasMap<K,V> */
    bool operator <( const SMASimDynamicID& that) const 
        { return Compare(that) < 0 ? true : false; }

    /** Compares this ID with another one. The return value indicates relative
        order of the IDs: smaller than zero if this < that, zero if this == that, and
        larger than zero if this > that. */
    int Compare(SMASimDynamicID const& that) const;

    /** Returns true if this ID refers to the same object as the other one. */
    bool Equal(SMASimDynamicID const& that) const;

    /** Returns the category of the object referred to by this ID. 
        The return value is one of the SMASimCategory enumerations. */
    int Category() const;

    /** Returns the data ID. */
    SMASimDynamicDataID DataID() const {
        return m_DataID; }

    /** Returns the type ID. */
    SMASimTypeID Type() const {
        return m_Type; }

    int IDSpace() const;

    /** Converts this ID to an external representation. */
    int Externalize(char* buffer) const;

    /** Returns the size of the external representation in bytes. */
    static int ExternalSize();


private:

    int PrivateInternalize(char const* buffer, SMASimContextID context);

    /** The category is constrained to the range allowed for API use. 
        Not for public consumption **/
    SMASimDynamicID(int cat, SMASimContextID cid, SMASimDynamicDataID did = SMASimDynamicDataID(), SMASimTypeID tp = SMASimTypeID(), int idSpace = 0);

    // This method allows the ID to be set to any category in the legal range.
    void Reset(int cat, SMASimContextID cid, SMASimDynamicDataID did, SMASimTypeID tp = SMASimTypeID(), int idSpace = 0);

    void ValidateCategory(int cat) const;
    SMASimDebugOut& WriteDebug(SMASimDebugOut& uos) const;
    int GetCategoryPrivate() const;
    bool IsNullCategory() const {return m_Category == -1; }

    int                    m_Category;
    SMASimContextID        m_ContextID;
    SMASimDynamicDataID    m_DataID;
    SMASimTypeID           m_Type;
};

inline bool operator ==(const SMASimDynamicID &a, const SMASimDynamicID &b) { return a.Equal(b); }
inline bool operator !=(const SMASimDynamicID &a, const SMASimDynamicID &b) { return !a.Equal(b); }
inline SMASimDebugOut& operator<<(SMASimDebugOut& dbs,  const SMASimDynamicID &b) { return b.WriteDebug(dbs); }

#endif
