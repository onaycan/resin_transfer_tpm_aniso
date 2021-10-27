#ifndef SMASimSelectionMap_h
#define SMASimSelectionMap_h

// Begin local includes
#include <SMASimAssociation.h>
#include <SMASimSetAssociationItemSel.h>
#include <SMASimMapString2Int.h>
#include <SMASimArrayString.h>
#include <mem_AllocationOperatorsTiny.h>
// End local includes

class SMASimDynamicID;
class SMASimAssociation;
class SMASimAssociationItem;

/**
   This class represents a selection of links of an association that originate
   in a given object. This selection type is used when the other member
   of the association has a string key.
*/
class SMASimSelectionMap
    : public mem_AllocationOperatorsTiny
{
    friend class SMASimSelectionMapIter;

public:

    /** Selects association links that originate at the object with the given ID. */
    SMASimSelectionMap(
        SMASimAssociation const& recAssoc,
        int whichMember,
        SMASimDynamicID const& id);

    /** Returns the length of this selection. */
    int Length() const;

    /** Returns true if a link with the given key exists in this selection. */
    bool IsMember(CATString const& key) const;
  
    /** Retrieves the ID of one object at the other endpoint.
        Returns true if the link was found, false otherwise. */
    bool Get(CATString const& key, SMASimDynamicID& id) const;

    /** Returns the ID of one object at the other endpoint. */
    SMASimDynamicID Get(CATString const& key) const;

    /** Retrieves the keys with which the given object was linked. */
    void GetKeys(SMASimDynamicID id, SMASimArrayString &keys) const;

private:
    bool StillValid() const;
    void FillMap(SMASimMapStringInt &key2index) const;

    int m_WhichMember;
    SMASimAssociation m_Association;
    SMASimSetAssociationItemSelection m_Selection;
    unsigned int m_AssociationModificationCount;
};

/**
   This object is an iterator over the map selection.
*/
class SMASimSelectionMapIter
    : public mem_AllocationOperatorsTiny
{
public:

    /** Creates an iterator object. */
    SMASimSelectionMapIter(SMASimSelectionMap const& map);

    /** Moves to the first link. */
    void First() { m_Iter.First(); }

    /** Moves to the next link. */
    void Next() { m_Iter.Next(); }

    /** Moves to the last link. */
    void Last() { m_Iter.Last(); }

    /** Moves to the previous link. */
    void Previous() { m_Iter.Previous(); }

    /** Returns true if the iterator has been advanced past the
        last or back past the first link. */
    bool IsDone() const  { return m_Iter.IsDone(); }
    
    /** Returns the key associated with the current link. */
    const CATString& CurrentKey() const;

    /** Returns the ID of the object at the other endpoint of the current link. */
    const SMASimDynamicID& CurrentValue() const;

private:
    SMASimSelectionMap const& m_Map;
    SMASimMapStringInt m_Key2Index;
    mutable SMASimMapStringIntIT m_Iter;
};

#endif
