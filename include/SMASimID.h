#ifndef SMASimID_h
#define SMASimID_h
//
// Begin Local includes
//
#include <mem_AllocationOperatorsTiny.h>
#include <SMASimDataTypes.h>
#include <SMASimDynamicID.h>
#include <SMASimContextID.h>
#include <SMASimIDMinor.h>
#include <SMASimAssert.h>
//
// End Local includes
//

//
// Forward declarations
//
class SMASimCMemberID;
class SMASimCSet;
class SMASimCSetID;
class SMASimCollectionID;
class SMASimCollectionRepr;
class SMASimDSet;
class SMASimDSetCtation;
class SMASimDSetEmpty;
class SMASimDSetID;
class SMASimDSetRelDistr;
class SMASimDSetSparse;
class SMASimDSetTable;
class SMASimDatabaseRepr;
class SMASimDistributionID;
class SMASimDistributionRepr;
class SMASimDrawer;
class SMASimDrawerID;
class SMASimFTableRepr;
class SMASimInsider;
class SMASimODSet;
class SMASimODSetID;
class SMASimTableID;
class SMASimTableRepr;
class SMASimTransactionRepr;
class SMASimTstMultiFileSimTest;
class SMASimViewRepr;

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

/**
* An ID that uniquely identifies a collection - [ contextID/collectionID ]
**/
class SMASimCollectionID
    : public mem_AllocationOperatorsTiny
{
public:
    /// Default constructor
    SMASimCollectionID() {}

    /// Construct from a dynamic ID.
    explicit SMASimCollectionID(SMASimDynamicID did);

    /// Returns the context ID
    SMASimContextID ContextID() const {
        return m_ID.ContextID(); }

    /// Gets the Minor representation
    SMASimIDMinor Minor() const {
        return m_ID.DataID().Minor2(); }

    /// Gets the type ID
    SMASimTypeID Type() const {
        return m_ID.Type(); }

    /// Test for NULL
    bool IsNull() const {
        return m_ID.IsNull() || Minor().IsNull(); }

    /** Returns true if this is NOT a NULL ID. */
    operator const void *() const {
        return !IsNull() ? this : 0; }

    /** Returns true if this is a NULL ID. */
    bool operator !() const {
        return IsNull(); }

    /// Return true if ids are equal; false otherwise
    bool operator ==(SMASimCollectionID const&  that) const {
        return m_ID == that.m_ID; }

    /// Return true if ids are NOT equal; false otherwise
    bool operator !=(SMASimCollectionID const&  that) const {
        return !this->operator==(that); }

    /// Display on ostream  - ONLY for debugging.
    SMASimDebugOut& WriteDebug(SMASimDebugOut& uos) const;

    /// Convert to a dynamic ID format.
    SMASimDynamicID DynamicID() const {
        return m_ID; }

    /// Convert to a dynamic ID format.
    operator SMASimDynamicID() const {
        return m_ID; }

    /// Test to see if dynamic ID can be converted to this type of ID
    static bool CanBeConverted(SMASimDynamicID did);

    /// The 'color' associated with this ID.
    int Color() const {
        return ColorOf(m_ID.DataID().Minor2()); }

    /// make a cset ID same as THIS but with given color
    SMASimCollectionID AltColor(int color) const {
        return SMASimCollectionID(ContextID(), SetColor(Minor(), color), Type()); }

    /// Returns this collection ID in the base color.
    SMASimCollectionID BaseColor() const {
        return AltColor(0); }

    /// change the color of THIS (returns ref-to-self)
    SMASimCollectionID& SetColor(int color) {
        return *this = AltColor(color);  }

    /// Upper bounds
    enum CategoryBits {
        e_ColorBits = 6,                                     ///< 6 bits used for 'color'
        e_MaxColor = 1 << e_ColorBits,                       ///< maximum color number plus 1
        e_ExcessiveCollectionID = 1 << (31-e_ColorBits)      ///< must not collide with the 6 bits used for coloring
    };

    /** Compliance with SMABasMap<K,V> */
    bool operator <( const SMASimCollectionID& that) const 
        { return Compare(that) < 0 ? true : false; }

    /// Compare collection IDs
    /// returns -1 if this ID is less than the specified ID
    /// returns  1 if this ID is greater than the specified ID
    /// returns  0 if they are equal
    int Compare(const SMASimCollectionID& that) const {
        return m_ID.Compare(that.m_ID); }

public: /// Not exported - for dpa use only

    /// Extract the 'color' from an int
    /// For dpa use only - do not export
    static int ColorOf(SMASimIDMinor idminor);

    /// For dpa use only - do not export
    static SMASimIDMinor SetColor(SMASimIDMinor idminor, int color);

private:
    friend class SMASimDatabaseRepr;
    friend class SMASimViewRepr;
    friend class SMASimCollectionRepr;
    friend class SMASimDistributionRepr;
    friend class SMASimCSetID;
    friend class SMASimDrawerID;
    friend class SMASimCMemberID;
    friend class SMASimDrawer;
    friend class SMASimDSet;
    friend class SMASimODSet;
    friend class SMASimDSetCtation;
    friend class SMASimDSetTable;
    friend class SMASimTableRepr;
    friend class SMASimTstMultiFileSimTest;
    friend class SMASimInsider;

    SMASimCollectionID(SMASimContextID contextID, SMASimIDMinor id, SMASimTypeID type,
        int idSpace = 0);

    SMASimDynamicID m_ID;
};

/// Display of SMASimCollectionID - ONLY for debugging
inline SMASimDebugOut& operator<<(SMASimDebugOut& uos, SMASimCollectionID const& id)
{
    return id.WriteDebug(uos);
}

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

/**
* An ID that uniquely identifies a distribution - [ contextID/distributionID ]
**/
class SMASimDistributionID
    : public mem_AllocationOperatorsTiny
{
public:
    /// Default constructor
    SMASimDistributionID() {}

    /// Construct from a dynamic ID.
    explicit SMASimDistributionID(SMASimDynamicID did);

    /// Returns the context ID
    SMASimContextID ContextID() const {
        return m_ID.ContextID(); }

    /// Gets the Minor representation
    SMASimIDMinor Minor() const {
        return m_ID.DataID().Minor2(); }

    /// Gets the type representation
    SMASimTypeID Type() const {
        return m_ID.Type(); }

    /// Test for NULL
    bool IsNull() const {
        return m_ID.IsNull() || Minor().IsNull(); }

    /** Returns true if this is NOT a NULL ID. */
    operator const void *() const {
        return !IsNull() ? this : 0; }

    /** Returns true if this is a NULL ID. */
    bool operator !() const {
        return IsNull(); }

    /// Return true if ids are equal; false otherwise
    bool operator ==(SMASimDistributionID const&  that) const {
        return m_ID == that.m_ID; }

    /// Return true if ids are NOT equal; false otherwise
    bool operator !=(SMASimDistributionID const&  that) const {
        return !this->operator==(that); }

    /// Display on ostream  - ONLY for debugging.
    SMASimDebugOut& WriteDebug(SMASimDebugOut& uos) const;

    /// Convert to a dynamic ID format.
    SMASimDynamicID DynamicID() const {
        return m_ID; }

    /// Convert to a dynamic ID format.
    operator SMASimDynamicID() const {
        return m_ID; }

    /// Test to see if dynamic ID can be converted to this type of ID
    static bool CanBeConverted(SMASimDynamicID did);

    /** Compliance with SMABasMap<K,V> */
    bool operator <( const SMASimDistributionID& that) const 
        { return Compare(that) < 0 ? true : false; }

    /// Compares distribution IDs
    /// returns -1 if this ID is less than the specified ID
    /// returns  1 if this ID is greater than the specified ID
    /// returns  0 if they are equal
    int Compare(const SMASimDistributionID& that) const {
        return m_ID.Compare(that.m_ID); }

private:
    friend class SMASimDatabaseRepr;
    friend class SMASimViewRepr;
    friend class SMASimDistributionRepr;
    friend class SMASimDrawerID;
    friend class SMASimTstMultiFileSimTest;
    friend class SMASimFTableRepr;
    friend class SMASimInsider;
    friend class SMASimTableRepr;
    friend class SMASimDSetRelDistr;
    friend class SMASimDSetSparse;
    SMASimDistributionID(SMASimContextID contextID, SMASimIDMinor id, SMASimTypeID type,
        int idSpace = 0)
        : m_ID(SMASimCategoryDistribution, contextID, SMASimDynamicDataID(SMASimIDMinor(0), id), type,idSpace) {}

    SMASimDynamicID m_ID;
};

/// Display of SMASimDistributionID - ONLY for debugging
inline SMASimDebugOut& operator<<(SMASimDebugOut& uos, SMASimDistributionID const& id)
{
    return id.WriteDebug(uos);
}

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

/**
* An ID that uniquely identifies a dset - [ contextID/dsetID ]
**/

class SMASimDSetID
    : public mem_AllocationOperatorsTiny
{
public:
    /// Default constructor
    SMASimDSetID() {}

    /// Construct from a dynamic ID.
    explicit SMASimDSetID(SMASimDynamicID did);

    /// Returns the context ID
    SMASimContextID ContextID() const {
        return m_ID.ContextID(); }

    /// Gets the Minor representation
    SMASimIDMinor Minor() const {
        return m_ID.DataID().Minor2(); }

    /// Gets the type representation
    SMASimTypeID Type() const {
        return m_ID.Type(); }

    /// Test for NULL
    bool IsNull() const {
        return m_ID.IsNull() || Minor().IsNull(); }

    /** Returns true if this is NOT a NULL ID. */
    operator const void *() const {
        return !IsNull() ? this : 0; }

    /** Returns true if this is a NULL ID. */
    bool operator !() const {
        return IsNull(); }

    /// Return true if ids are equal; false otherwise
    bool operator ==(SMASimDSetID const&  that) const {
        return m_ID == that.m_ID; }

    /// Return true if ids are NOT equal; false otherwise
    bool operator !=(SMASimDSetID const&  that) const {
        return !this->operator==(that); }

    /// Display on ostream  - ONLY for debugging.
    SMASimDebugOut& WriteDebug(SMASimDebugOut& uos) const;

    /// Convert to a dynamic ID format.
    SMASimDynamicID DynamicID() const {
        return m_ID; }

    /// Convert to a dynamic ID format.
    operator SMASimDynamicID() const {
        return m_ID; }

    /// Test to see if dynamic ID can be converted to this type of ID
    static bool CanBeConverted(SMASimDynamicID did);

    /** Compliance with SMABasMap<K,V> */
    bool operator <( const SMASimDSetID& that) const 
        { return Compare(that) < 0 ? true : false; }

    /// Compare d-set IDs
    /// returns -1 if this ID is less than the specified ID
    /// returns  1 if this ID is greater than the specified ID
    /// returns  0 if they are equal
    int Compare(const SMASimDSetID& that) const {
        return m_ID.Compare(that.m_ID); }

private:
    friend class SMASimDSet;
    friend class SMASimDatabaseRepr;
    friend class SMASimViewRepr;
    friend class SMASimInsider;
    friend class SMASimDSetEmpty;
    friend class SMASimDSetRelDistr;
    friend class SMASimDSetCtation;
    friend class SMASimDSetSparse;
    friend class SMASimDSetTable;

    /// Re-construct from an IDMinor.
    SMASimDSetID(SMASimContextID cid, 
                 SMASimIDMinor idminor, 
                 SMASimTypeID type,
                 int idSpace = 0)
        : m_ID(SMASimCategoryDSet, 
               cid, 
               SMASimDynamicDataID(SMASimIDMinor(0), idminor), 
               type,
               idSpace) {}

    SMASimDynamicID m_ID;
};

/// Display of SMASimDSetID - ONLY for debugging
inline SMASimDebugOut& operator<<(SMASimDebugOut& uos, SMASimDSetID const& id)
{
    return id.WriteDebug(uos);
}

/**
* An ID that uniquely identifies a dset - [ contextID/dsetID ]
**/

class SMASimODSetID
    : public mem_AllocationOperatorsTiny
{
public:
    /// Default constructor
    SMASimODSetID() {}

    /// Construct from a dynamic ID.
    explicit SMASimODSetID(SMASimDynamicID did);

    /// Returns the context ID
    SMASimContextID ContextID() const {
        return m_ID.ContextID(); }

    /// Gets the Minor representation
    SMASimIDMinor Minor() const {
        return m_ID.DataID().Minor2(); }

    /// Gets the type representation
    SMASimTypeID Type() const {
        return m_ID.Type(); }

    /// Test for NULL
    bool IsNull() const {
        return m_ID.IsNull() || Minor().IsNull(); }

    /** Returns true if this is NOT a NULL ID. */
    operator const void *() const {
        return !IsNull() ? this : 0; }

    /** Returns true if this is a NULL ID. */
    bool operator !() const {
        return IsNull(); }

    /// Return true if ids are equal; false otherwise
    bool operator ==(SMASimODSetID const&  that) const {
        return m_ID == that.m_ID; }

    /// Return true if ids are NOT equal; false otherwise
    bool operator !=(SMASimODSetID const&  that) const {
        return !this->operator==(that); }

    /// Display on ostream  - ONLY for debugging.
    SMASimDebugOut& WriteDebug(SMASimDebugOut& uos) const;

    /// Convert to a dynamic ID format.
    SMASimDynamicID DynamicID() const {
        return m_ID; }

    /// Convert to a dynamic ID format.
    operator SMASimDynamicID() const {
        return m_ID; }

    /// Test to see if dynamic ID can be converted to this type of ID
    static bool CanBeConverted(SMASimDynamicID did);

    /** Compliance with SMABasMap<K,V> */
    bool operator <( const SMASimODSetID& that) const 
        { return Compare(that) < 0 ? true : false; }

    /// Compare ordered d-set IDs
    /// returns -1 if this ID is less than the specified ID
    /// returns  1 if this ID is greater than the specified ID
    /// returns  0 if they are equal
    int Compare(const SMASimODSetID& that) const {
        return m_ID.Compare(that.m_ID); }

private:
    friend class SMASimDatabaseRepr;
    friend class SMASimViewRepr;
    friend class SMASimODSet;
    friend class SMASimInsider;


    SMASimDynamicID m_ID;
};

/// Display of SMASimDSetID - ONLY for debugging
inline SMASimDebugOut& operator<<(SMASimDebugOut& uos, SMASimODSetID const& id)
{
    return id.WriteDebug(uos);
}

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

/**
* An ID that uniquely identifies a cset - [ contextID/collectionID/csetID ]
**/

class SMASimCSetID
    : public mem_AllocationOperatorsTiny
{
public:
    /// Default constructor
    SMASimCSetID() {}

    /// Re-construct from a CollectionID and a 'minor' of the resulting c-set ID.
    /// Minor can be constructed from integers read from a relational distribution.
        SMASimCSetID(SMASimCollectionID cid, SMASimIDMinor idminor, int idSpace = 0)
            : m_ID(SMASimCategoryCSet, cid.ContextID(), SMASimDynamicDataID(cid.Minor(), idminor), cid.Type(), idSpace) {}

    /// Construct from a dynamic ID.
    explicit SMASimCSetID(SMASimDynamicID did);

    /// Returns the context ID
    SMASimContextID ContextID() const {
        return m_ID.ContextID(); }

    /// Returns the collection ID
    SMASimCollectionID CollectionID() const {
        return m_ID ? SMASimCollectionID(m_ID.ContextID(), m_ID.DataID().Minor1(), m_ID.Type()) : SMASimCollectionID(); }

    /// Gets the Minor representation -- after conversion to an int can be stored
    /// as the range item of a relational distribution
    SMASimIDMinor Minor() const {
        return m_ID.DataID().Minor2(); }

    /// Gets the type representation
    SMASimTypeID Type() const {
        return m_ID.Type(); }

    /// Return true if this ID refers to an empty set; false otherwise
    bool IsEmpty() const {
        return Minor().Value() == 0; }

    /// Return true if the cset is ascending; false otherwise
    bool IsAscending() const {
        return !IsNull() && (Minor().CategoryBits(e_NumBits) & e_AscendingBit); }

    /// Returns true if cset is temporary; false otherwise
    bool IsTemp() const {
        return !IsNull() && (Minor().CategoryBits(e_NumBits) & e_TempBit); }

    /// Test for NULL. A NULL c-set ID may still return a non-NULL collection ID.
    bool IsNull() const {
        return m_ID.IsNull() || Minor().IsNull(); }

    /** Returns true if this is NOT a NULL ID. */
    operator const void *() const {
        return !IsNull() ? this : 0; }

    /** Returns true if this is a NULL ID. */
    bool operator !() const {
        return IsNull(); }

    /// Return true if ids are equal; false otherwise
    bool operator ==(SMASimCSetID const&  that) const {
        return m_ID == that.m_ID; }

    /// Return true if ids are NOT equal; false otherwise
    bool operator !=(SMASimCSetID const&  that) const {
        return !this->operator==(that); }

    /// Display on ostream  - ONLY for debugging.
    SMASimDebugOut& WriteDebug(SMASimDebugOut& uos) const;

    /// Convert to a dynamic ID format.
    SMASimDynamicID DynamicID() const {
        return m_ID; }

    /// Convert to a dynamic ID format.
    operator SMASimDynamicID() const {
        return m_ID; }

    /// Test to see if dynamic ID can be converted to this type of ID
    static bool CanBeConverted(SMASimDynamicID did);

    /// The 'color' associated with this ID.
    int Color() const {
        return CollectionID().Color(); }

    /// make a cset ID same as THIS but with given color
    SMASimCSetID AltColor(int color) const {
        return SMASimCSetID(CollectionID().AltColor(color), Minor(), m_ID.IDSpace()); }

    /// change the color of THIS (returns ref-to-self)
    SMASimCSetID& SetColor(int color) {
        return *this = AltColor(color); }

    /** Compliance with SMABasMap<K,V> */
    bool operator <( const SMASimCSetID& that) const 
        { return Compare(that) < 0 ? true : false; }

    /// Compare c-set IDs
    /// returns -1 if this ID is less than the specified ID
    /// returns  1 if this ID is greater than the specified ID
    /// returns  0 if they are equal
    /// Compares collections owning the IDs first (see SMASimCollectionID.Compare())
    int Compare(const SMASimCSetID& that) const {
        return m_ID.Compare(that.m_ID); }

    //---------------------------------
    //  Not exported - for dpa use only
    //---------------------------------

    /// For dpa use only - do not export
    int Index() const  {
        return IsNull() ? -1 : Minor().ObjectIndex(e_NumBits); }

    /// Set the cset as sorted/ascending or not. This function has no effect if this ID is null.
    SMASimCSetID& SetAscending(bool ascending=true);

    /// CSet category bits
    enum {
        e_NumBits = 2,          ///< number of bits used by c-sets
        e_AscendingBit = 1,     ///< set if this ID refers to an ascending c-set
        e_TempBit = 2           ///< set if this ID refers to a temporary c-set
    };

private:
    friend class SMASimCSet;
    friend class SMASimDatabaseRepr;
    friend class SMASimViewRepr;
    friend class SMASimInsider;

    SMASimDynamicID m_ID;
};

inline SMASimDebugOut& operator<<(SMASimDebugOut& uos, SMASimCSetID const& id)
{
    return id.WriteDebug(uos);
}

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

/**
* An ID that uniquely identifies a drawer - [ contextID/collectionID/drawerID ]
**/

class SMASimDrawerID
    : public mem_AllocationOperatorsTiny
{
public:
    /// Default constructor
    SMASimDrawerID() {}

    /// Construct from a dynamic ID.
    explicit SMASimDrawerID(SMASimDynamicID did);

    /// Returns the context ID
    SMASimContextID ContextID() const {
        return m_ID.ContextID(); }

    /// Returns the distribution ID
    SMASimDistributionID DistributionID() const {
        return m_ID ? SMASimDistributionID(m_ID.ContextID(), m_ID.DataID().Minor1(), m_ID.Type()) : SMASimDistributionID(); }

    /// Gets the Minor representation
    SMASimIDMinor Minor() const {
        return m_ID.DataID().Minor2(); }

    /// Gets the type representation
    SMASimTypeID Type() const {
        return m_ID.Type(); }

    /// Test for NULL
    bool IsNull() const {
        return m_ID.IsNull() || Minor().IsNull(); }

    /** Returns true if this is NOT a NULL ID. */
    operator const void *() const {
        return !IsNull() ? this : 0; }

    /** Returns true if this is a NULL ID. */
    bool operator !() const {
        return IsNull(); }

    /// Return true if ids are equal; false otherwise
    bool operator ==(SMASimDrawerID const&  that) const {
        return m_ID == that.m_ID; }

    /// Return true if ids are NOT equal; false otherwise
    bool operator !=(SMASimDrawerID const&  that) const {
        return !this->operator==(that); }

    /// Display on ostream  - ONLY for debugging.
    SMASimDebugOut& WriteDebug(SMASimDebugOut& uos) const;

    /// Convert to a dynamic ID format.
    SMASimDynamicID DynamicID() const {
        return m_ID; }

    /// Convert to a dynamic ID format.
    operator SMASimDynamicID() const {
        return m_ID; }

    /// Test to see if dynamic ID can be converted to this type of ID
    static bool CanBeConverted(SMASimDynamicID did);

    /** Compliance with SMABasMap<K,V> */
    bool operator <( const SMASimDrawerID& that) const 
        { return Compare(that) < 0 ? true : false; }

    /// Compare drawer IDs
    /// returns -1 if this ID is less than the specified ID
    /// returns  1 if this ID is greater than the specified ID
    /// returns  0 if they are equal
    /// Compares distributions owning the IDs first (see SMASimDistributionID.Compare())
    int Compare(const SMASimDrawerID& that) const {
        return m_ID.Compare(that.m_ID); }

private:
    friend class SMASimDistributionRepr;
    friend class SMASimDatabaseRepr;
    friend class SMASimTstMultiFileSimTest;
    friend class SMASimInsider;

    SMASimDrawerID(SMASimDistributionID did, SMASimIDMinor idminor, int idSpace = 0)
        : m_ID(SMASimCategoryDrawer, did.ContextID(), SMASimDynamicDataID(did.Minor(), idminor), did.Type(),idSpace) {}

    SMASimDynamicID m_ID;
};

inline SMASimDebugOut& operator<<(SMASimDebugOut& uos, SMASimDrawerID const& id)
{
    return id.WriteDebug(uos);
}


// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

/**
* An ID that uniquely identifies a member of a collection - [ contextID/collectionID/cmemberID ]
**/

class SMASimCMemberID
    : public mem_AllocationOperatorsTiny
{
public:
    // Construct a NULL member ID.
    SMASimCMemberID() {}

    /// Re-construct from a CollectionID and a 'minor' of the resulting c-set ID.
    /// Minor can be constructed from integers read from a relational distribution.
    SMASimCMemberID(SMASimCollectionID cid, SMASimIDMinor idminor)
        : m_ID(SMASimCategoryCMember, cid.ContextID(), SMASimDynamicDataID(cid.Minor(), idminor), cid.Type()) {}

    /// Construct from a dynamic ID.
    explicit SMASimCMemberID(SMASimDynamicID did);

    /// Returns the context ID
    SMASimContextID ContextID() const {
        return m_ID.ContextID(); }

    /// Returns the collection ID
    SMASimCollectionID CollectionID() const {
        return m_ID ? SMASimCollectionID(m_ID.ContextID(), m_ID.DataID().Minor1(), m_ID.Type()) : SMASimCollectionID(); }

    /// Gets the Minor representation -- after conversion to an int can be stored
    /// as the range item of a relational distribution
    SMASimIDMinor Minor() const {
        return m_ID.DataID().Minor2(); }

    /// Gets the type representation
    SMASimTypeID Type() const {
        return m_ID.Type(); }

    /// Test for NULL
    bool IsNull() const {
        return m_ID.IsNull(); }

    /** Returns true if this is NOT a NULL ID. */
    operator const void *() const {
        return !IsNull() ? this : 0; }

    /** Returns true if this is a NULL ID. */
    bool operator !() const {
        return IsNull(); }

    /// Return true if ids are equal; false otherwise
    bool operator ==(SMASimCMemberID const&  that) const {
        return m_ID == that.m_ID; }

    /// Return true if ids are NOT equal; false otherwise
    bool operator !=(SMASimCMemberID const&  that) const {
        return !this->operator==(that); }

    /// Display on ostream  - ONLY for debugging.
    SMASimDebugOut& WriteDebug(SMASimDebugOut& uos) const;

    /// Convert to a dynamic ID format.
    SMASimDynamicID DynamicID() const {
        return m_ID; }

    /// Convert to a dynamic ID format.
    operator SMASimDynamicID() const {
        return m_ID; }

    /// Test to see if dynamic ID can be converted to this type of ID
    static bool CanBeConverted(SMASimDynamicID did);

    /** Compliance with SMABasMap<K,V> */
    bool operator <( const SMASimCMemberID& that) const 
        { return Compare(that) < 0 ? true : false; }

    /// Compare c-member IDs
    /// returns -1 if this ID is less than the specified ID
    /// returns  1 if this ID is greater than the specified ID
    /// returns  0 if they are equal
    /// Compares collections owning the IDs first (see SMASimCollectionID.Compare())
    int Compare(const SMASimCMemberID& that) const {
        return m_ID.Compare(that.m_ID); }

private:
    friend class SMASimDatabaseRepr;
    friend class SMASimInsider;

    SMASimDynamicID m_ID;
};

inline SMASimDebugOut& operator<<(SMASimDebugOut& uos, SMASimCMemberID const& id)
{
    return id.WriteDebug(uos);
}

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

/**
* An ID that uniquely identifies a table - [ contextID/tableID ]
**/
class SMASimTableID
    : public mem_AllocationOperatorsTiny
{
public:
    /// Default constructor
    SMASimTableID() {}

    /// Construct from a dynamic ID.
    explicit SMASimTableID(SMASimDynamicID did);

    /// Returns the context ID
    SMASimContextID ContextID() const {
        return m_ID.ContextID(); }

    /// Gets the Minor representation
    SMASimIDMinor Minor() const {
        return m_ID.DataID().Minor2(); }

    /// Gets the type representation
    SMASimTypeID Type() const {
        return m_ID.Type(); }

    /// Test for NULL
    bool IsNull() const {
        return m_ID.IsNull(); }

    /** Returns true if this is NOT a NULL ID. */
    operator const void *() const {
        return !IsNull() ? this : 0; }

    /** Returns true if this is a NULL ID. */
    bool operator !() const {
        return IsNull(); }
    
    /// Return true if ids are equal; false otherwise
    bool operator ==(SMASimTableID const&  that) const {
        return m_ID == that.m_ID; }

    /// Return true if ids are NOT equal; false otherwise
    bool operator !=(SMASimTableID const&  that) const {
        return !this->operator==(that); }

    /// Display on ostream  - ONLY for debugging.
    SMASimDebugOut& WriteDebug(SMASimDebugOut& uos) const;

    /// Convert to a dynamic ID format.
    SMASimDynamicID DynamicID() const {
        return m_ID; }

    /// Convert to a dynamic ID format.
    operator SMASimDynamicID() const {
        return m_ID; }

    /// Test to see if dynamic ID can be converted to this type of ID
    static bool CanBeConverted(SMASimDynamicID did);

    /** Compliance with SMABasMap<K,V> */
    bool operator <( const SMASimTableID& that) const 
        { return Compare(that) < 0 ? true : false; }

    int Compare(const SMASimTableID& that) const {
        return m_ID.Compare(that.m_ID); }

private:
    friend class SMASimDatabaseRepr;
    friend class SMASimViewRepr;
    friend class SMASimTransactionRepr;
    friend class SMASimInsider;
    friend class SMASimTableRepr;
    friend class SMASimDSetTable;

    SMASimTableID(SMASimContextID cid, SMASimIDMinor idminor, SMASimTypeID type,
        int idSpace = 0)
        : m_ID(SMASimCategoryTable, cid, SMASimDynamicDataID(SMASimIDMinor(0), idminor), type, idSpace) {}

    SMASimDynamicID m_ID;
};

/// Display of SMASimTableID - ONLY for debugging
inline SMASimDebugOut& operator<<(SMASimDebugOut& uos, SMASimTableID const& id)
{
    return id.WriteDebug(uos);
}

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

/**
* An ID that uniquely identifies a data record.
**/

class SMASimDataRecordID
    : public mem_AllocationOperatorsTiny
{
public:
    // Construct a NULL member ID.
    SMASimDataRecordID() {}

    /// Construct from a dynamic ID.
    explicit SMASimDataRecordID(SMASimDynamicID did);

    /// Returns the context ID
    SMASimContextID ContextID() const {
        return m_ID.ContextID(); }

    /// Gets the Minor representation -- after conversion to an int can be stored
    /// as the range item of a relational distribution
    SMASimIDMinor Minor() const {
        return m_ID.DataID().Minor2(); }

    /// Gets the type representation
    SMASimTypeID Type() const {
        return m_ID.Type(); }

    /// Test for NULL
    bool IsNull() const {
        return m_ID.IsNull(); }

    /** Returns true if this is NOT a NULL ID. */
    operator const void *() const {
        return !IsNull() ? this : 0; }

    /** Returns true if this is a NULL ID. */
    bool operator !() const {
        return IsNull(); }

    /// Return true if ids are equal; false otherwise
    bool operator ==(SMASimDataRecordID const&  that) const {
        return m_ID == that.m_ID; }

    /// Return true if ids are NOT equal; false otherwise
    bool operator !=(SMASimDataRecordID const&  that) const {
        return !this->operator==(that); }

    /// Display on ostream  - ONLY for debugging.
    SMASimDebugOut& WriteDebug(SMASimDebugOut& uos) const;

    /// Convert to a dynamic ID format.
    SMASimDynamicID DynamicID() const {
        return m_ID; }

    /// Convert to a dynamic ID format.
    operator SMASimDynamicID() const {
        return m_ID; }

    /// Test to see if dynamic ID can be converted to this type of ID
    static bool CanBeConverted(SMASimDynamicID did);

    /** Compliance with SMABasMap<K,V> */
    bool operator <( const SMASimDataRecordID& that) const 
        { return Compare(that) < 0 ? true : false; }

    /// Compare data record IDs
    /// returns -1 if this ID is less than the specified ID
    /// returns  1 if this ID is greater than the specified ID
    /// returns  0 if they are equal
    /// Compares collections owning the IDs first (see SMASimCollectionID.Compare())
    int Compare(const SMASimDataRecordID& that) const {
        return m_ID.Compare(that.m_ID); }

private:
    friend class SMASimViewRepr;
    friend class SMASimInsider;

    /// Re-construct from a CollectionID and a 'minor' of the resulting c-set ID.
    /// Minor can be constructed from integers read from a relational distribution.
        SMASimDataRecordID(SMASimCollectionID cid, SMASimIDMinor idminor, SMASimTypeID type, int idSpace = 0)
            : m_ID(SMASimCategoryDataRecord, cid.ContextID(), SMASimDynamicDataID(cid.Minor(), idminor), type,idSpace) {}

    SMASimDynamicID m_ID;
};

inline SMASimDebugOut& operator<<(SMASimDebugOut& uos, SMASimDataRecordID const& id)
{
    return id.WriteDebug(uos);
}

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

/**
* An ID that uniquely identifies a property table.
**/

class SMASimFTableID
    : public mem_AllocationOperatorsTiny
{
public:
    // Construct a NULL member ID.
    SMASimFTableID() {}

    /// Construct from a dynamic ID.
    explicit SMASimFTableID(SMASimDynamicID did);

    /// Returns the context ID
    SMASimContextID ContextID() const {
        return m_ID.ContextID(); }

    /// Gets the Minor representation -- after conversion to an int can be stored
    /// as the range item of a relational distribution
    SMASimIDMinor Minor() const {
        return m_ID.DataID().Minor2(); }

    /// Gets the type representation
    SMASimTypeID Type() const {
        return m_ID.Type(); }

    /// Test for NULL
    bool IsNull() const {
        return m_ID.IsNull(); }

    /** Returns true if this is NOT a NULL ID. */
    operator const void *() const {
        return !IsNull() ? this : 0; }

    /** Returns true if this is a NULL ID. */
    bool operator !() const {
        return IsNull(); }

    /// Return true if ids are equal; false otherwise
    bool operator ==(SMASimFTableID const& that) const {
        return m_ID == that.m_ID; }

    /// Return true if ids are NOT equal; false otherwise
    bool operator !=(SMASimFTableID const& that) const {
        return !this->operator==(that); }

    /// Display on ostream  - ONLY for debugging.
    SMASimDebugOut& WriteDebug(SMASimDebugOut& uos) const;

    /// Convert to a dynamic ID format.
    SMASimDynamicID DynamicID() const {
        return m_ID; }

    /// Convert to a dynamic ID format.
    operator SMASimDynamicID() const {
        return m_ID; }

    /// Test to see if dynamic ID can be converted to this type of ID
    static bool CanBeConverted(SMASimDynamicID did);

    /** Compliance with SMABasMap<K,V> */
    bool operator <( const SMASimFTableID& that) const 
        { return Compare(that) < 0 ? true : false; }

    /// Compare data record IDs
    /// returns -1 if this ID is less than the specified ID
    /// returns  1 if this ID is greater than the specified ID
    /// returns  0 if they are equal
    /// Compares collections owning the IDs first (see SMASimCollectionID.Compare())
    int Compare(const SMASimFTableID& that) const {
        return m_ID.Compare(that.m_ID); }

private:
    friend class SMASimInsider;
    friend class SMASimFTableRepr;
    /// Re-construct from an IDMinor.
        SMASimFTableID(SMASimContextID cid, SMASimIDMinor idminor, SMASimTypeID type, int idSpace = 0)
            : m_ID(SMASimCategoryFTable, cid, SMASimDynamicDataID(SMASimIDMinor(0), idminor), type, idSpace) {}


    SMASimDynamicID m_ID;
};

inline SMASimDebugOut& operator<<(SMASimDebugOut& uos, SMASimFTableID const& id)
{
    return id.WriteDebug(uos);
}

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------


#endif
