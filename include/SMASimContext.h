#ifndef SMASimContext_h
#define SMASimContext_h

// Begin local includes
#include <SMABasWeakPtr.h>
#include <SMABasVector.h>
#include <SMASimArrayCollectionID.h>
#include <SMASimArrayDistributionID.h>
#include <SMASimArrayDynamicID.h>
#include <SMASimArrayInt.h>
#include <SMASimID.h>
#include <SMASimGUID.h>
#include <SMASimTypeID.h>
#include <mem_AllocationOperators.h>
// End local includes

class SMASimCSet;
class SMASimContextRepr;
class SMASimTypeSchemaSnapshot;
class SMASimView;
class SMASimGrid;
class SMASimRangeType;
class SMASimCtation;
class SMASimOCtation;
class SMASimSchemaTransform;
class SMASimOCompartment;
class SMASimRangeValue;
class SMASimTypeFormManager;
class SMASimUpgFuncs;
class SMASimConvertArgs;

/**
   A context is a reference namespace; it owns the references and can ensure that they are unique. 
   Objects within the context can only refer to other objects within the context.
**/
class SMASimContext : public mem_AllocationOperators 
{
public:

    /** Default constructor */
    SMASimContext() {};

    /** Construct a context reference from an ID */
    SMASimContext(const SMASimContextID& id);

    /** Closes this context and nullifies this context reference.
        Invalidates all IDs originating from this context.
    */
    void Close() const;

    /** Returns true if this context is read only. */
    bool IsReadOnly() const;

    /** Returns the ID of this context */
    SMASimContextID ID() const;

    /** Returns the ID of the focus. */
    SMASimDynamicID FocusID() const;

    /** Returns the schema snapshot associated with this context. */
    SMASimTypeSchemaSnapshot Schema() const;

    //////////////////////////////////////////////////////////////////////////////////////////////////

    /** Returns true if the current view has been modified (by a committed, non-empty transaction).
        This is equivalent to returning true if the view contains unpublished changes.
     */
    
    bool ViewModified();

    /** Creates a new view in the database. If a prior view exists, then 
        this view has (latest view + user defined changes).
     */
    void Open(SMASimTypeSchemaSnapshot schema);

    /** Read the last published view.
     */
    void OpenRead(SMASimTypeSchemaSnapshot schema) const;

    /** Same as Open(). */
    void Extend(SMASimTypeSchemaSnapshot schema);

    /** If modified, publishes the current view update and then replaces it with an Edition view update. */
    void Save();

    /** Not for public consumption
     **/
    void SetIDSpace(int);
    
    /** Not for public consumption 
     **/
    int CurrentIDSpace();

    /** Not for public consumption
     **/
    int MaxIDSpace();

    //////////////////////////////////////////////////////////////////////////////////////////////////

    /** Creates a new data record in this context. */
    SMASimDynamicID CreateDataRecord(SMASimTypeID typeId, 
                                     SMASimCollectionID cid = SMASimCollectionID(), 
                                     long long index = -1) const;
    /** Create FTable */
    SMASimFTableID CreateFTable( SMASimTypeID typeId,
                                 int nrows,
                                 SMABasVector<CATString> const& optionalDepColLabels,
                                 SMABasVector<CATString> const& optionalIndepColLabels,
                                 const double* contentsBufferDoubles,
                                 int bufferSizeDoubles ) const;
    
    /** Creates a new collection in this context. */
    SMASimCollectionID CreateCollection(int spaceSize, SMASimTypeID typeID = SMASimTypeID()) const;

    /** Creates a new distribution in this context. The distribution signature is passed in */
    SMASimDistributionID CreateDistribution(SMASimGrid const& grid, SMASimRangeType const& rangeType, SMASimTypeID typeID = SMASimTypeID()) const;

    /** Creates a new temporary distribution in this context. The distribution signature is passed in */
    SMASimDistributionID CreateTempDistribution(SMASimGrid const& grid, SMASimRangeType const& rangeType, SMASimTypeID typeID = SMASimTypeID()) const;

    /** Creates a new distribution in this context using the light-weight API */
    SMASimDistributionID CreateDistributionLT(const SMASimOCompartment& comp, const SMASimRangeValue& defVal, const SMASimArrayInt* chunkSize = 0) const;

    /** Creates a new empty dset. */
    SMASimDSetID CreateDSet(const SMASimGrid& grid, SMASimTypeID typeID) const;

    /** Creates a new dset represented as a compartmentation. */
    SMASimDSetID CreateDSet(const SMASimCtation& compartmentation, SMASimTypeID typeID) const;

    /** Creates a new volatile (in-memory) dset represented as a compartmentation. */
    SMASimDSet CreateVolatileDSet(const SMASimCtation& compartmentation, SMASimTypeID typeID) const;

    /** Creates a new dset represented as a relational distribution. */
    SMASimDSetID CreateDSet(SMASimDistributionID distributionID, SMASimTypeID typeID) const;

    /** Creates a new dset represented as a table. */
    SMASimDSetID CreateDSet(SMASimTableID tableID, SMASimTypeID typeID) const;

    /** Creates (stores) a new ordered dset (represented as an ordered compartmentation) and returns its id */
    SMASimODSetID CreateOrderedDSet(const SMASimOCtation& compartmentation, SMASimTypeID typeID = SMASimTypeID()) const;

    /** Creates a new table. */
    SMASimTableID CreateTable(const SMASimGrid &grid, SMASimTypeID typeID) const;

    /** Updates the D-set with empty contents. */
    void UpdateDSet(SMASimDSetID id, const SMASimGrid& grid) const;

    /** Updates the D-set with a compartmentation. */
    void UpdateDSet(SMASimDSetID id, const SMASimCtation& compartmentation) const;

    /** Updates the D-set with a relational distribution. */
    void UpdateDSet(SMASimDSetID id, SMASimDistributionID distrID) const;

    /** Updates the D-set with a table. */
    void UpdateDSet(SMASimDSetID id, SMASimTableID tableID) const;

    /** Given and ID, retrieve (as a an ordered compartmentation) the ordered DSet which has been stored. */
    SMASimOCtation ODSetRep(SMASimODSetID id) const;



    /** Allocates an ID of the given category, that doesn't conflict with any of existing IDs.
        This function should only be used during generic copy/merge operations for objects
        other than data records. For data records, use the CreateDataRecord function instead.
    */
    SMASimDynamicID AllocateID(SMASimCategory cat, SMASimTypeID typeID) const;

    //////////////////////////////////////////////////////////////////////////////////////////////////

    /** Returns the type category for the given type ID. */
    SMASimCategory TypeCategory(SMASimTypeID id) const;

    /** Returns the type ID for the object with the given ID.

        The type ID returned from this function is modulo the current context schema.
        For data records it is the ID of the most derived type that belongs to the context schema,
        or an empty ID if none of the bases does. For other types, the return type is non empty
        if the object has a type and if the type belongs to the context schema.
    */
    //SMASimTypeID TypeID(SMASimDynamicID rid) const;

    /** Retrieves the collection ID and member indices of records. All records given in
        the recids array must come from the same collection of the same context.
    */
    void GetCMembership(const SMASimArrayDynamicID &recids, SMASimCollectionID &cid, SMASimArrayInt &membership) const;

    /** Retrieves the c-member index for the record ID.*/
    int GetCMemberIndex(SMASimDynamicID rid) const;

    /** Retrieves the collection ID for the record ID.*/
    SMASimCollectionID GetCollectionID(SMASimDynamicID rid) const;

    /** Retrieves record IDs for all members of the C-Set.*/
    void GetRecords(const SMASimCSet &cset, SMASimArrayDynamicID &recids) const;

    /** Converts a collection ID and a member index to a record ID.*/
    SMASimDynamicID GetRecord(SMASimCollectionID cid, int memberIndex) const;

    /** Indicates if a collection ID and a member index map to a record ID.*/
    bool HasRecord(SMASimCollectionID cid, int memberIndex) const;

    /// Return whether the FTable is 'null'
    bool IsNull() const { return m_impl.expired();}
    
    // UNDOCUMENTED AND UNSUPPORTED
    SMABasSharedPtr<SMASimContextRepr> Repr() const;

private:
    friend class SMASimContextRepr;
    friend class SMASimDatabaseRepr;
    friend class SMASimCollectionRepr;
    friend class SMASimTstContextTest;
    friend class SMASimTstMultiFileSimTest;
    friend class SMASimTstRelDistTest;
    friend class SMASimTstStatDumper;
    friend class SMASimTstRelDistTest;
    friend class SMASimTstTwoContextTest;
    friend class SMASimTstUpgradeServicesTest;
    friend class SMASimTstViewTest;
    friend void SMASimConvert( const char*, const char* , SMASimTypeFormManager& manager, 
                               const SMASimUpgFuncs& funcs, SMASimConvertArgs args, bool verbose);

    SMABasWeakPtr<SMASimContextRepr> m_impl;


};

#endif
