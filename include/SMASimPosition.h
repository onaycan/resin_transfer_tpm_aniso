#ifndef SMASIMPosition_h
#define SMASIMPosition_h
/**
 * @file
 * @brief SMASimPosition and its Iterators
 *
 * These classes are designed to help position the client programming within
 * the SIM object model without having to resort to concrete classes,
 * e.g. mesh.
 */

// Forward declarations
class SMASimAssociation;
class SMASimCtation;
class SMASimDataRecord;
class SMASimGrid;
class SMASimOCtation;
class SMASimMap;
class SMASimVector;
class SMASimSet;
class SMASimPositionListIterator;
class SMASimPositionMapIterator;
class SMASimPositionSetIterator;
class SMASimRangeType;
class SMASimPropTableHeader;
class SMASimCollection;
class SMASimCSet;
class SMASimDistribution;
class SMASimDataRecord;
class SMASimFTable;
class SMASimDSet;
class SMASimDatabase;

template <typename T> class SMABasVector;

// Begin local includes
#include <SMASimID.h>
#include <SMASimArrayCollectionID.h>
#include <SMASimSelectionMap.h>
#include <SMASimSelectionSet.h>
#include <SMASimSelectionList.h>
#include <SMASimTypeKey.h>
#include <SMASimContext.h>
#include <CATString.h>
#include <mem_AllocationOperatorsTiny.h>

/**
 * @brief A class to assist with the traversal of a SIM file.
 *
 * This tool is schema independent and has minimal resource requirements.
 */
class SMASimPosition: public mem_AllocationOperatorsTiny
{
    friend class SMASimPositionMapIterator;
    friend class SMASimPositionListIterator;
    friend class SMASimPositionSetIterator;

  public:

    /**
     * Default constructor creates an object that cannot be operated on.
     */
    SMASimPosition();

    /**
     * Create position object initialially positioned at view origin,
     * i.e. focus id.
     * @param contextID
     *   Context id
     */
    SMASimPosition(SMASimContextID contextID);

    /**
     * Create position object using an id. The id must not be null.
     * @param id
     *   Dynamic id of new position
     */
    SMASimPosition(SMASimDynamicID id);

    /**
     * Create position object using an id. 
     * @param id
     *   The position will have this id
     */
    SMASimPosition(SMASimCSetID id);

    /**
     * Create position object using an id. 
     * @param id
     *   The position will have this id
     */
    SMASimPosition(SMASimCollectionID id);

    /**
     * Create position object using an id. 
     * @param id
     *   The position will have this id
     */
    SMASimPosition(SMASimDSetID id);

    /**
     * Create position object using an id. 
     * @param id
     *   The position will have this id
     */
    SMASimPosition(SMASimDistributionID id);

    /**
     * Create position object using an id. 
     * @param id
     *   The position will have this id
     */
    SMASimPosition(SMASimDrawerID id);

    /**
     * Create position object using an id. 
     * @param id
     *   The position will have this id
     */
    SMASimPosition(SMASimTableID id);

    /**
     * Create position object using an id. 
     * @param id
     *   The position will have this id
     */
    SMASimPosition(SMASimFTableID id);

    /**
     * Create position object using an id. 
     * @param id
     *   The position will have this id
     */
    SMASimPosition(SMASimODSetID id);

    /**
     * Retrieve the dynamic id for the object at the current position
     */
    SMASimDynamicID ID() const;

    /** Name for composition child **/
    CATString Name(int type) const;

    /** Name for reference **/
    CATString GetReferenceKey(int type) const;
    /**
     * Query method to check if the current position points to a valid object
     */
    bool IsNull() const { return !m_id; }

    /**
     * Two positions are equal if they contain the same Dynamic ID and the same context
     */
    inline bool operator==(const SMASimPosition &other) {return m_id==other.m_id && m_contextID==other.m_contextID;}

    /**
     * Operator less-than compares the dynamic IDs.
     */
    inline bool operator < ( const SMASimPosition & other) const  { return m_id < other.m_id;}

    ///////////////////////////////////////////////////////////////
    /////////////////////// Begin SIM 2.0 API /////////////////////
    ///////////////////////////////////////////////////////////////

    /**
     * Convenience methods to cast the position to an object of its 
     * category. Will throw an exception if the category is wrong.
     *
     * e.g.  SMASimFTable f = position.FTable();
     *
     * Note: each of these types below has a method Pos() which returns its
     * SMASimPosition. You can conveniently go from Position to these types 
     * and back.
     */

     SMASimCollection Collection() const;
     SMASimCSet CSet() const;
     SMASimDistribution Distribution() const;
     SMASimDataRecord DataRecord() const;
     SMASimFTable FTable() const;
     SMASimDSet DSet() const;

    /**
     * The int 'member' is also the association generated-constant in
     * the methods below.
     * e.g. ads_Model_Mesh
     */

    /**
     * For composition or reference in which THIS is the owner/referrer
     * and there is a maximum of 1 target object, identified by member.
     * This sets the given member of THIS to the given target object.
     * (If the member is already set, it will be changed to the new value)
     */

     void SetPosition( int member, SMASimPosition const& target) const;


    /**
     * For composition or reference in which THIS is the owner/referrer
     * and there is a maximum of 1 target identified by member. 
     * Returns the given member of THIS. 
     * Returns a Position which IsNull() if the member is not set.
     */

     SMASimPosition GetPosition( int member) const;

    /**
     * For composition or reference in which THIS is the owner/referrer
     * and there is a maximum of 1 target object.
     * This unsets the given member of THIS.
     */

     void UnsetPosition( int member) const;


    /**
     * For composition or reference in which THIS is the owner/referrer
     * and the relationship is SEQUENCED (iterator preserves insertion-
     * order).
     * Retrieve SMASimVector, identified by given member of this Position,
     * holding children/referents
     */
     SMASimVector GetVector( int member);


    /**
     * For composition or reference in which THIS is the owner/referrer
     * and the relationship is NOT SEQUENCED (iterator does not preserve
     * insertion-order).
     * Retrieve SMASimSet, identified by given member of this Position,
     * holding children/referents
     */
     SMASimSet GetSet( int member) const;


    /**
     * For composition or reference in which THIS is the owner/referrer
     * and the relationship to the target object is KEYED on STRINGS.
     * Retrieve SMASimMap,identified by given member of this Position,
     *  holding mapping of strings to children/referents.
     * 
     * Example: SMASimMap map = position.GetMap(ads_Model_sections);
     */
     SMASimMap GetMap( int member) const;


    ///////////////////////////////////////////////////////////////
    /////////////////////// End SIM 2.0 API ///////////////////////
    ///////////////////////////////////////////////////////////////


    /**
     * Query method to retrieve the type name of the object
     */
    CATString TypeName() const;

    /**
     * Query method to retrieve the integer value of the schema constant,
     * e.g. ads_StaticStep.
     */
    int TypePosition() const;

    /**
     * Query method to retrieve the integer value of the schema constant for give type string
     * e.g. ads_StaticStep for "StaticStep".
     */
    int
    TypePositionFromTypeName(const CATString& typeName) const;

    /**
     * Query method to retrieve the integer value of the schema constant for give type string
     * from given form.
     * e.g. ads_StaticStep for "StaticStep".
     */
    int
    TypePositionFromTypeName(const CATString& formName, const CATString& typeName) const;

    /**
     * Query method to retrieve the context id of the view.
     */
    SMASimContextID ContextID() const { return m_contextID; }

    /**
     * Return the context for this position
     */
    SMASimContext Context() const;

    /**
     * Return the focus position for this position
     */
    SMASimPosition Focus() const;

    /**
     * Build a SMASimDatabase (lighweight and refernce counted) instance corresponding to the document that this position is pointing at
     */
    SMASimDatabase Doc() const;

    /**
     * Compare the type pointed to by THIS position to the passed in value.
     *  For example  meshedField.IsA(ads_Field) == true
     * @param type
     *    The type to test against, e.g. ads_Field
     * @warning Works only for data records at this time.
     */
    bool IsA(int type) const;

    /**
     * Compare the type of FIRST argument to see if it ISA the type of SECOND argument.
     *  In contrast with IsA() above,  in FirstIsASecond, THIS is used only to provide context for the schema;
     *  its type is not involved in the check.
     *  For example  contextProvider.FirstIsASecond(ads_MeshedField, ads_Field) == true.
     * @param typeFirst
     *    The type to test for being of type typeSecond
     * @param typeSecond
     * @warning Works only for types of data records at this time.
     */
     bool FirstIsASecond(int typeFirst, int typeSecond) const;

    /**
     * Retrieve collection id type from the current position if valid.
     * @warning Error checking is limited to an assert in the debug object
     */
    SMASimCollectionID GetCollection() const;

    /**
     * Retrieve cset id type from the current position if valid.
     * @warning Error checking is limited to an assert in the debug object
     */
    SMASimCSetID GetCSet() const;

    /**
     * Retrieve dset id type from the current position if valid.
     * @warning Error checking is limited to an assert in the debug object
     */
    SMASimDSetID GetDSet() const;

    /**
     * Retrieve ordered compartmentation of a dset from the current position
     * if valid.
     * @warning Error checking is limited to an assert in the debug object
     */
    SMASimOCtation GetOCtation() const;

    /**
     * Retrieve distribution id type from the current position if valid.
     * @warning Error checking is limited to an assert in the debug object
     */
    SMASimDistributionID GetDistribution() const;

    /**
     * Retrieve drawer id type from the current position if valid.
     * @warning Error checking is limited to an assert in the debug object
     */
    SMASimDrawerID GetDrawer() const;


    /**
     * Retrieve FTable id type from the current position if valid.
     * @warning Error checking is limited to an assert in the debug object
     */
    SMASimFTableID GetFTable() const;


    /**
     * Retrieve data record from the current position if valid.
     * @warning Error checking is limited to an assert in the debug object
     */
    SMASimDataRecord GetDataRecord() const;

    /**
     * Retrieve symbol name from the current position if valid.
     * @warning Error checking is limited to an assert in the debug object
     */
    CATString GetSymbolName() const;

    /**
     * Retrieve (code_generated) symbol position from the current position if valid.
     * @warning Error checking is limited to an assert in the debug object
     */
    int GetSymbolPosition() const;

    /*
     * Retrieve the dynamic id of a symbol from the view held by the position
     * @param type
     *    The type of the data record
     * @param name
     *    The symbol name
     */
    SMASimDynamicID GetSymbol(int type, const CATString& name) const;

    /*
     * Retrieve the dynamic id of a symbol from the view held by the position
     * and the specified collection
     * @param type
     *    The type of the data record
     * @param name
     *    The symbol name
     * @param collection
     *    The collection id
     */
    SMASimDynamicID GetSymbol(int type, const CATString& name, SMASimCollectionID collection) const;

    /*
     * Retrieve the dynamic id of a symbol from the view given the record type
     * and the symbol (code generated) position.
     * @param type
     *    The type of the data record
     * @param position
     *    The symbol position
     */
    SMASimDynamicID GetSymbol(int type, int position) const;

    /**
     * Create a new position by following an association from the current
     * position to the specified association member.
     * @param type
     *   Symbolic constant for the association type, e.g. ads_MeshCoordinates.
     * @param member
     *   Symbolic constant for association member, e.g. ads_MeshCoordinates_coordinates.
     */
    SMASimPosition Follow(int type, int member) const;

    /**
     * Create a new position by following an association from the current
     * position to the specified association member.
     * @param type
     *   String identifier for the association type, e.g. "MeshCoordinates".
     * @param member
     *   String identifier for association member, e.g. "coordinates".
     */
    SMASimPosition Follow(const CATString& type,const CATString& member) const;

    /**
     * Create a new position by following an association from the current
     * position to the specified association member.
     * @param formName
     *   String identifier for the form, e.g. "Core".
     * @param type
     *   String identifier for the association type, e.g. "MeshCoordinates".
     * @param member
     *   String identifier for association member, e.g. "coordinates".
     */
    SMASimPosition Follow(
        const CATString& formName,
        const CATString& type,
        const CATString& member) const;


    /**
     * Create a new position by following an integer keyed association from
     * the current position.
     * @param type
     *   Symbolic constant for the association type.
     * @param member
     *   Symbolic constant for association member.
     * @param position
     *   Position within the list
     */
    SMASimPosition FollowIntKey(int type, int member, int position) const;

    /**
     * Create a new position by following an integer keyed association from
     * the current position.
     * @param type
     *   Symbolic constant for the association type.
     * @param member
     *   Symbolic constant for association member.
     * @param key
     *   String key for specific link in the association
     */
    SMASimPosition FollowStringKey(int type, int member, CATString key) const;

    /**
     * Retrieve string keys for the given association with the current
     * position.  Multiple associations with different keys can exist for the
     * same ids in an association.  An example is when the same set members are
     * listed under the same name.
     * @param type
     *   Symbolic constant for the association type.
     * @param member
     *   Symbolic constant for association member.
     * @param id
     *   Dynamic id for something that's on the other end of the association.
     */
    SMASimArrayString GetStringKeys(int type, int member, SMASimDynamicID id) const;

    /**
     * Retrieve integer positions for the given association with the current
     * position.  Multiple associations with different keys can exist for the
     * same ids in an association.
     * @param type
     *   Symbolic constant for the association type.
     * @param member
     *   Symbolic constant for association member.
     * @param id
     *   Dynamic id for something that's on the other end of the association.
     */
    SMASimArrayInt GetIntKeys(int type, int member, SMASimDynamicID id) const;

    /**
     * Create an iterator of positions for a string keyed association.
     * @param type
     *   Symbolic constant for the association type.
     * @param member
     *   Symbolic constant for association member.
     */
    SMASimPositionMapIterator FollowMap(int type, int member) const;

    /**
     * Create an iterator of positions for a list association.
     * @param type
     *   Symbolic constant for the association type.
     * @param member
     *   Symbolic constant for association member.
     */
    SMASimPositionListIterator FollowList(int type, int member) const;

    /**
     * Create an iterator of positions for a unordered association.
     * @param type
     *   Symbolic constant for the association type.
     * @param member
     *   Symbolic constant for association member.
     */
    SMASimPositionSetIterator FollowSet(int type, int member) const;


    /**
     * Create an association with the current position.
     * @param type
     *   Symbolic constant for the association type.
     * @param member
     *   Symbolic constant for association member.
     * @param target
     *   The other position with which to create the association.
     */
    SMASimAssociation Associate(int type, int member, const SMASimPosition &target) const;

    /**
     * Create an association with the current position.
     * @param type
     *   Symbolic constant for the association type.
     * @param member
     *   Symbolic constant for association member.
     * @param target
     *   The other position with which to create the association.
     */
    SMASimAssociation Associate(const CATString& type, const CATString& member, const SMASimPosition &target) const;

    /**
     * Create an association with the current position.
     * @param formName
     *   String identifier for the form, e.g. "Core".
     * @param type
     *   Symbolic constant for the association type.
     * @param member
     *   Symbolic constant for association member.
     * @param target
     *   The other position with which to create the association.
     */
    SMASimAssociation Associate(const CATString& formName, const CATString& type, const CATString& member, const SMASimPosition &target) const;


    /**
     * Create an ordered association with the current position.
     * @param type
     *   Symbolic constant for the association type.
     * @param member
     *   Symbolic constant for association member.
     * @param target
     *   The other position with which to create the association.
     * @param key
     *   The position in the ordered association.
     */
    SMASimAssociation AssociateIntKey(int type, int member, const SMASimPosition &target, int key) const;

    /**
     * Create a string keyed association with the current position.
     * @param type
     *   Symbolic constant for the association type.
     * @param member
     *   Symbolic constant for association member.
     * @param target
     *   The other position with which to create the association.
     * @param key
     *   The string key used to identify this association.
     */
    SMASimAssociation AssociateStringKey(int type, int member, const SMASimPosition &target, CATString key) const;

    /**
     * Create a data record using current position's view.
     * @param type
     *   Symbolic constant for the data record type.
     */
    SMASimDataRecord CreateDataRecord(int type) const;


    /**
     * Create a table using current position's view.
     * @param grid
     *   The grid for the new table.
     * @param gridtype
     *   The grid type for the new table.
     */
    SMASimTableID CreateTable(SMASimGrid const& grid, int gridType);

    /**
     * Create an FTable using current position's context
     * @param fTableType
     *   The type-position giving the type for the new property table.
     * @param nrows
     *   The number of rows in the contents
     * @param optionalDepColLabels
     *   a vector containing the labels of any optional dependent columns
     *   for the ftable. The order of labels must match the order of optional
     *   dependent columns ( if specified) in schema.
     *   Use an empty vector if there are no extra columns.
     * @param optionalIndepColLabels
     *   a vector containing the labels of any optional independent columns
     *   for the ftable. The order of labels must match the order of optional
     *   independent columns ( if specified) in schema.
     *   Use an empty vector if there are no extra columns.
     * @param contentsBufferDoubles
     *   Buffer containing the contents for the new property table
     * @param bufferSizeDoubles
     *   The size of the buffer in double-precision words
     */
    SMASimFTableID CreateFTable( int fTableType,
                                 int nrows,
                                 SMABasVector<CATString> const& optionalDepColLabels,
                                 SMABasVector<CATString> const& optionalIndepColLabels,
                                 const double* contentsBufferDoubles,
                                 int bufferSizeDoubles);

    /**
     * Create a data record using current position's view in the specified
     * collection and position.
     * @param type
     *   Symbolic constant for the data record type.
     * @param collection
     *   The collection in which the data record will be placed
     * @param index
     *   The position in the collection where this record will be placed. If
     *   value is -1, the collection will be extended
     */
    SMASimDataRecord CreateDataRecord(int type,
                                      SMASimCollectionID collection,
                                      int index = -1);

    /**
     * Create a symbol record using current position's view.
     * @param type
     *   Symbolic constant for the symbol record type, e.g. ads_ElementType.
     * @param symbol
     *   Symbolic constant value.
     */
    SMASimDataRecord CreateSymbol(int type,
                                  CATString symbol);

    /**
     * Create a symbol record using current position's view in the specified
     * collection.
     * @param type
     *   Symbolic constant for the symbol record type, e.g. ads_ElementType.
     * @param symbol
     *   Symbolic constant value.
     * @param collection
     *   The collection in which the symbol's data record will be placed
     * @param index
     *   The position in the collection where this symbol's record will be
     *   placed, or if value is -1, the collection will be extended.
     */
    SMASimDataRecord CreateSymbol(int type,
                                  const CATString& symbol,
                                  SMASimCollectionID collection,
                                  int index = -1);

    /**
     * Check for the presence of a symbol
     * @param type
     *   Symbolic constant for the symbol record type
     * @param symbol
     *   Symbolic constant value
     */
    bool SymbolPresent(int type, const CATString& symbol) const;

    /**
     * Check for the presence of a symbol in a specific collection
     * @param type
     *   Symbolic constant for the symbol record type
     * @param symbol
     *   Symbolic constant value
     * @param collection
     *   The collection in which the symbol resides
     */
    bool SymbolPresent(int type,
		       const CATString& symbol,
		       SMASimCollectionID collection) const;

    /**
     * Create a collection using the current position's view.
     * @param space
     *   The size of the new collection.
     */
    SMASimCollectionID CreateCollection(int space);

    /**
     * Create a collection using the current position's view.
     * @param space
     *   The size of the new collection.
     * @param type
     *   The type of the new collection.
     */
    SMASimCollectionID CreateTypedCollection(int space,
					     int type) const;


    /**
     * Create a distribution using the current position's view.
     * @param grid
     *   The grid for the new distribution.
     * @param rangeType
     */
    SMASimDistributionID CreateDistribution(SMASimGrid const& grid,
                        SMASimRangeType const& rangeType) const;

    /**
     * Create a typed distribution using the current position's view.
     * @param grid
     *   The grid for the new distribution.
     * @param gridtype
     *   The grid type for the new distribution
     * @param rangeType
     */
    SMASimDistributionID CreateTypedDistribution(SMASimGrid const& grid,
        int gridtype,
        SMASimRangeType const& rangeType) const;

    /**
     * Create a new untyped dset using a compartmentation
     * @param compartmentation
     *   A compartmentation representation of a dset
     */
    SMASimDSetID CreateDSet(const SMASimCtation& compartmentation) const;

    /**
     * Create a new untyped volatile (in-memory) dset using a compartmentation
     * @param compartmentation
     *   A compartmentation representation of a dset
     */
    SMASimDSet CreateVolatileDSet(const SMASimCtation& compartmentation) const;

    /**
     * Create a new typed dset using a compartmentation
     * @param compartmentation
     *   A compartmentation representation of a dset
     * @param gridType
     *   The grid type for the new DSet
     */
    SMASimDSetID CreateTypedDSet(const SMASimCtation& compartmentation,
				 int gridType) const;

    /**
     * Create a new typed dset using a table
     * @param table
     *   A table representation of a dset
     * @param gridType
     *   The grid type for the new DSet
     */
    SMASimDSetID CreateTypedDSet(SMASimTableID table,
				 int gridType) const;

    /**
     * Create a new untyped ordered dset
     * @param compartmentation
     *   A dset represented as an ordered compartmentation
     */
    SMASimODSetID CreateOrderedDSet(const SMASimOCtation& compartmentation) const;

    /**
     * Create a new typed ordered dset
     * @param compartmentation
     *   A dset represented as an ordered compartmentation
     * @param gridType
     *   The grid type of the new ordered DSet
     */
    SMASimODSetID CreateTypedOrderedDSet(const SMASimOCtation& compartmentation,
					 int gridType) const;

    /**
     * Remove a link from an association with the current position given the
     * id at the other end.
     * @param type
     *   Symbolic constant for the association type.
     * @param member
     *   Symbolic constant for association member.
     * @param id
     *   The dynamic id on the other end of the link to remove.
     */
    void Remove(int type,
		int member,
		SMASimDynamicID id) const;

    /**
     * Remove a link from an association with the current position given the
     * string key.
     * @param type
     *   Symbolic constant for the association type.
     * @param member
     *   Symbolic constant for association member.
     * @param key
     *   The string key of the item on the other end of the link to remove.
     */
    void RemoveStringKey(int type,
			 int member,
			 CATString key) const;

    /**
     * Remove a link from an association with the current position given the
     * position.
     * @param type
     *   Symbolic constant for the association type.
     * @param member
     *   Symbolic constant for association member.
     * @param position
     *   The position of the item on the other end of the link to remove.
     */
    void RemoveIntKey(int type,
		      int member,
		      int position) const;

    /**
     * Remove all links from an association with the current position.
     * @param type
     *   Symbolic constant for the association type.
     * @param member
     *   Symbolic constant for association member to remove.
     */
    void RemoveAll(int type, int member) const;

  protected:

    // Get id of association end point - specify member location of position
    SMASimArrayDynamicID GetAssociationEndPoint(int type, int member) const;

  private:

    SMASimDynamicID m_id;
    SMASimContextID m_contextID;	// because id may be null
};

/**
 * @example Coordinates
 *  Here is an example on how to use the SMASimPosition class to get
 * the mesh nodal coordinates.
 * @code
 * SMASimPosition focus(contextID);
 * SMASimPosition product = focus.Follow(ads_FocusProduct, ads_FocusProduct_rootProduct);
 * SMASimPosition mesh = product.Follow(ads_ProductMesh, ads_ProductMesh_meshes);
 * SMASimPosition coordinates = mesh.GetPosition(ads_Mesh_coordinates);
 * SMASimDistributionID coords = coordinates.GetDistribution();
 * @endcode
*/


/**
 * @brief A class used to iterate over the the members of a string indexed
 * association.
 */
class SMASimPositionMapIterator: public mem_AllocationOperators
{
    friend class SMASimPosition;

  public:

    /**
     * Copy constructor is needed to return an iterator by value
     * @param iterator
     *   Iterator created by SMASimPosition methods FollowXXX methods
     */
    SMASimPositionMapIterator(const SMASimPositionMapIterator& iterator);
   ~SMASimPositionMapIterator();


    /**
     * Position the iterator on the first item
     */
    void First();

    /**
     * Query the iterator to see if there are more entries to process
     */
    bool IsDone() const;

    /**
     * Move the current iterator position to the next item in the association
     */
    void Next();

    /**
     * Return the number of items in the association
     */
    int Size() const;

    /**
     * Return the iterator current string key
     */
    const CATString& CurrentKey() const;

    /**
     * Return the iterator current position object
     */
    SMASimPosition CurrentValue() const;

    /**
     * Return the dynamic id of the iterator current position
     */
    SMASimDynamicID CurrentValueID() const;

  private:

    SMASimPositionMapIterator(SMASimPosition, int type, int member);

    // Disallow operator = due to no default SMASimSelectionMap constructor
    SMASimPositionMapIterator& operator=(const SMASimPositionMapIterator&);

    SMASimPosition m_position;
    int m_typePosition;
    int m_memberPosition;
    SMASimSelectionMap m_map;
    SMASimSelectionMapIter* m_iter;
};

/**
 * @example Nset
 * Here is an example on how to use the SMASimPositionMapIterator class to
 * loop over the node sets in a SIM file with only one instance (old-style
 * input file without parts and an assembly).
 * @code
 * SMASimPosition focus(contextID);
 * SMASimPosition context = focus.Follow(ads_FocusContext, ads_FocusContext_context);
 * SMASimPosition assembly = context.Follow(ads_ProductInstance, ads_ProductInstance_instance);
 * SMASimPositionMapIterator nsets = assembly.FollowMap(ads_InstanceNodeSets, ads_InstanceNodeSets_nodeSets);
 * for (nsets.First(); ! nsets.IsDone(); nsets.Next())
 *     cout << "Node set :" << nsets.CurrentKey().CStr() << "\n";
 * @endcode
 */

/**
 * @brief A class used to iterate over the the members of an ordered
 * association.
 */
class SMASimPositionListIterator: public mem_AllocationOperators
{
    friend class SMASimPosition;

  public:

    /**
     * Copy constructor is needed to return an iterator by value
     * @param iterator
     *   An iterator created by the SMASimPosition FollowXXX methods.
     */
    SMASimPositionListIterator(const SMASimPositionListIterator& iterator);
   ~SMASimPositionListIterator();


    /**
     * Position the iterator on the first item
     */
    void First();

    /**
     * Query the iterator to see if there are more entries to process
     */
    bool IsDone() const;

    /**
     * Move the current iterator position to the next item in the association
     */
    void Next();

    /**
     * Return the number of items in the association
     */
    int Size() const;

    /**
     * Return the current position in the list
     */
    int CurrentKey() const;

    /**
     * Return the iterator current position object
     */
    SMASimPosition CurrentValue() const;

    /**
     * Return the dynamic id of the iterator current position
     */
    SMASimDynamicID CurrentValueID() const;

  private:

    SMASimPositionListIterator(SMASimPosition, int type, int member);

    // Disallow operator = due to no default SMASimSelectionList constructor
    SMASimPositionListIterator& operator=(const SMASimPositionListIterator&);

    SMASimPosition m_position;
    int m_typePosition;
    int m_memberPosition;
    SMASimSelectionList m_list;
    SMASimSelectionListIter* m_iter;
};


/**
 * @brief A class used to iterate over the the members of an unordered
 * association.
 */
class SMASimPositionSetIterator: public mem_AllocationOperators
{
    friend class SMASimPosition;

  public:

    /**
     * Copy constructor is needed to return an iterator by value
     * @param iterator
     *   An iterator created by SMASimPosition FollowXXX methods.
     */
    SMASimPositionSetIterator(const SMASimPositionSetIterator& iterator);
   ~SMASimPositionSetIterator();

    /**
     * Position the iterator on the first item
     */
    void First();

    /**
     * Query the iterator to see if there are more entries to process
     */
    bool IsDone() const;

    /**
     * Move the current iterator position to the next item in the association
     */
    void Next();

    /**
     * Return the number of items in the association
     */
    int Size() const;

    /**
     * Return the current position in the set
     */
    int CurrentKey() const;

    /**
     * Return the iterator current position object
     */
    SMASimPosition CurrentValue() const;

    /**
     * Return the dynamic id of the iterator current position
     */
    SMASimDynamicID CurrentValueID() const;

  private:

    SMASimPositionSetIterator(SMASimPosition, int type, int member);

    // Disallow operator = due to no default SMASimSelectionSet constructor
    SMASimPositionSetIterator& operator=(const SMASimPositionSetIterator&);

    SMASimPosition m_position;
    int m_pos;
    int m_typePosition;
    int m_memberPosition;
    SMASimSelectionSet m_set;
};

#endif

