#ifndef SMASimCSet_h
#define SMASimCSet_h

// Begin local includes
#include <mem_AllocationOperators.h>
#include <SMASimIndexSet.h>
#include <SMASimID.h>
#include <SMASimArrayInt.h>
#include <cow_ListInt.h>
#include <SMASimIndexSetPtr.h>
#include <SMASimDataTypes.h>
#include <SMASimCSetExternal.h>
#include <SMASimIndexMapEntry.h>

class SMASimCSet;
class SMASimCSetExternal;
class SMASimCSetIterator;
class SMASimCollection;
class SMASimCollectionRepr;
class SMASimIndexSpaceMap;
class SMASimPosition;

/** 
* The CSet class.  A c-set can be viewed as an array of c-member indexes, the c-member 
* indexes representing the c-members belonging to the c-set: if we say c= (9, 14, 8 ) 
* we mean that c is the c-set with three c-members, the first c-member (at position 0) 
* with c-member index 9, the second c-member (at position 1) with c-member index 14, etc.
**/
class SMASimCSet : public mem_AllocationOperators
{
    friend class SMASimCollection;
    friend class SMASimCollectionRepr;
    friend class SMASimCSetIterator;
    friend class SMASimCSetExternal;
    friend class SMASimIndexSpaceMap;
    friend class SMASimTstCSetTest;
public:

	/// Construct an empty cset in a collection
    SMASimCSet(SMASimCollectionID collectionID);

    /// Retrievel constructor.  See also the 'Create' methods on CollectionRef
    SMASimCSet(SMASimCSetID id);

    /// Return the position of this CSet. returned position will be null for a volatile
    /// CSet.
    SMASimPosition Pos() const;

    /// Constructs a cset from an external representation
    /// The external represenation of a cset consists of buffer of bytes that can later be used to reconstruct
    /// the cset. The reconstructed cset will be a volatile cset even though the original may not have been.
    SMASimCSet(SMASimContextID contextID, const SMASimCSetExternal& extSet);

    /// Construct an orphan cset from an array of members
    SMASimCSet(int* members, int numMembers);

    /// Construct an orphan strided cset 
    SMASimCSet(int start, int count, int stride = 1, int width = 1);

	/// Construct an orphan ascending cset from a bit vector
	SMASimCSet(const omi_BlkBitVect& membership);

    /// Construct an empty, orphan, volatile cset
    SMASimCSet();

    /// Return the ID 
    SMASimCSetID ID() const { return m_myID;}

    /// Return a new cset ID refering to this set
    SMASimCSetID NewID();

    /// Return the number of members in the cset
    int Size() const;

    /// Is the Cset ascending?  Note that this is also available directly from the ID
    bool IsAscending() const { return (m_type & SMASimCSetAscending); }

    /// Return true if this is the empty set; false otherwise.
    /// Note for non-volatile csets this is also available directly from the ID
    bool IsEmpty() const { return (m_type & SMASimCSetEmpty); }

    /// Return true if the cset is volatile; false otherwise;
    /// A volatile cset has no associated ID and must be ascending.
    bool IsVolatile() const { return (m_type & SMASimCSetVolatile); }

    /// Return the bounds of the cset, the c-members with lowest and highest index
    /// The returned value is a pair  (first, last)
    SMASimIntRange Bounds() const;

    /// Populate 'membership' array with cset index values in sequential order
    /// Note that this produces ascending members even for a non-ascending c-set.
    void Members(int* out1) const;  ///< pre-allocated array for holding membership,  size THIS.Size()

    /// Returns true if the two c-sets contain the same members; false otherwise
    bool SameMembers(const SMASimCSet& other) const;

    /// Returns true if the two c-sets contain the same members and same ordering; false otherwise
    bool SameSet(const SMASimCSet& other) const;

    /// Populate the out array with cset index values in order.
    /// It the c-set is ascending, this will be ascending, just like the out2 returned by Members( )
    /// above.  For a non-ascending c-set, this will be in the non-ascending order defining the c-set
    void OrderedMembers(int* out2) const;

    /// Return members in bit vector form
    void AsBitVector(omi_BlkBitVect& vector) const;

    /// Return the ID of the **ascending counterpart** of THIS.  That is the CSet which contains
    /// the same members as this, and is ascending.  (Such an ascending CSet always exists;
    /// if THIS is not ascending,  an ascending counterpart would have been silently created if
    /// necessary when THIS was created.)
    /// If THIS is itself ascending,  the ID of THIS is returned
    SMASimCSetID AscendingID() const;

    /// Return (in out-argument) the permutation array which permutes the ordered membership array of THIS CSet
    /// (call such array orderedMembership) into ascending form
    /// (call such array membershipAscending). The following
    /// relationship holds and defines the 'returned' permutation array,  perm[ ]:
    ///
    ///     membershipAscending[k] == orderedMembership[perm[k]],  k = 0 .. THIS.Size() -1
    ///
    /// ( For an ascending c-set, this function is not needed, since membershipAscending and
    ///   orderedMembership are the same. However, for generality, it can 
    ///   be called and returns the identity-permutation 0,1,2,3... size-1 )
    void Permutation(int* perm) const;

    /// Return the permuted member ordinals
    void Permute(SMASimCSetID memberOrd,
                 SMASimArrayInt& permutedOrdVec) const; 

    /// Return the permuted member ordinals
    void Permute(const omi_BlkBitVect& memberOrdVec,
                 cow_ListInt& permutedOrdVec) const; 

    /// Determine if a c-member of given c-member index is found in this c-set. 
    /// For example, if c=(3,7,5),  c.IsMember(3)=True, c.IsMember(7)=True, c.IsMember(999)=False
    bool IsMember( int index ) const;

    /// Returns the position in the set of the c-member of given c-member index.  
    /// Return -1 if the c-member is not in the c-set. 
    /// For example, if c=(3,7,5),  c.SeekMember(3)=0, c.SeekMember(5)=2, c.SeekMember(99)=-1
    int SeekMember( int index ) const;

    /// Returns a VOLATILE ascending c-set which contains the INTERSECTION of this and the specified c-set
    SMASimCSet Intersection( SMASimCSet rhs ) const;

    /// Returns a VOLATILE ascending c-set which contains the UNION of this and the specified c-set.
    SMASimCSet Union( SMASimCSet rhs ) const;

    /// Returns a boolean that indicates if this set and the specified set overlap.  
    bool HasOverlap( SMASimCSet lhs ) const;

    /// Returns a VOLATILE ascending c-set which is the result of subtracting the specified c-set from this one.
    SMASimCSet operator-( SMASimCSet rhs ) const;

    /// Commits a VOLATILE c-set to the collection. The C-Set will no longer be volatile,
    /// and will have a non-null ID 
    SMASimCSetID RegisterWithCollection(); // Makes this set persistent if it isn't already

    /// Commits a VOLATILE c-set to the temporary collection. The C-Set will no longer be volatile,
    /// and will have a non-null ID, but will only last as long as the session lasts
    SMASimCSetID RegisterWithTempCollection(); // Makes this set persistent if it isn't already

    /// Return true if cset belongs to the same collection as this cset
    bool SameCollection(const SMASimCSet& that) const;

    /// Returns the c-member index of the c-member at the given position in the set;
    /// for example if c=(3,7,5),  c[0]=3, c[1]=7, c[2]=5
    /// CAUTION: extremely poor performance if used to access more than one member
    ///          use iterator or Members() method instead.
    int operator[]( int position ) const;

    /// Returns the size of the external representation in bytes
    int ExternalSize() const;

    /// Returns true if cset does not belong to a collection
    bool IsOrphan() const;

    /// Register cset with specified collection
    SMASimCSetID Register(SMASimCollection& collection);

    /// Returns true if both sets are the same; false otherwise
    bool operator==( SMASimCSet rhs ) const;

    /// Returns true if both sets are not the same; false otherwise
    bool operator!=( SMASimCSet rhs ) const;

private:
    /// Return the index set
    const SMASimIndexSet* IndexSet() const;

    /// Return the index set holder
    SMASimIndexSetPtr IndexSetPtr() const;

    /// Return the permutation map for an ordered c-set
    const SMASimIndexSet* PermutationMap() const;

    /// Return the index set holder
    SMASimIndexSetPtr PermutationMapPtr() const;

    /// Create a volatile c-set
    SMASimCSet(SMASimIndexSet* permutationMap, 
               SMASimIndexSet* ascendingSet,
               SMASimCollectionID collectionID);

    /// Register a temp cset with the persistent collection
    SMASimCSetID RegisterTempSet(SMASimCollection& collection);

    friend class SMASgl2XmlModelWriterRepr;
    friend class SMASgl2XmlElementArrayRef; 
    SMASimIndexMapEntry IndexMapEntry() { return m_entry; }

    enum SMASimCSetType {
        SMASimCSetUnset      = 0,
        SMASimCSetVolatile   = 1,
        SMASimCSetAscending  = 2,
        SMASimCSetEmpty      = 4
    };

    /// Create a volatile c-set
    SMASimCSet(SMASimIndexSet* unregistered, SMASimCSetID id);

    // members
    SMASimCSetID      m_myID;
    unsigned int      m_type;

    SMASimIndexMapEntry m_entry;
    SMASimIndexSetPtr m_unregAscendingSet;
    SMASimIndexSetPtr m_unregPermutationMap;
    SMASimCSetID      m_unregAscendingID;

    // Non-volatile index set caching
    mutable SMASimIndexSetPtr m_indexSet;
    mutable SMASimIndexSetPtr m_permutation;
};

/** 
* C-set iterator to traverse the members of a c-set.  For ordered c-sets, this
* iterator simply converts the set to canonical and traverses it.  Due to the
* way ordered c-sets are stored, the alternative would be an n-squared loop.
**/
class SMASimCSetIterator : public mem_AllocationOperators
{
public:
    friend class SMASimCSet;
    /// Constructor
    SMASimCSetIterator(const SMASimCSet& set);

    /// Destructor
    ~SMASimCSetIterator();

    /// resets the iterator to the first position (location = 0)
    void First();

    /// indicates if we have reached the end of the cset
    bool IsDone() const;

    /// advances the iterator to the next position
    void Next();

    /// returns the value of the current location
    int CurrentValue() const;

    /// returns the index of the current location
    int CurrentLocation() const;
private:
    SMASimCSetIterator(SMASimIndexSetPtr set);

    // members
    const SMASimIndexSetPtr m_set;
    int m_currentLocation;
    int m_currentRangeLocation;
    int m_rangeOffset;
    int m_blockCount;
    int m_maskCount;
    bool m_permutation;
    int* m_orderedMembers;
};

#endif

