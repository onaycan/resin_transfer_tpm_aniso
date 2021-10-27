#ifndef SMASimSelectionList_h
#define SMASimSelectionList_h

// Begin local includes
#include <SMASimAssociation.h>
#include <SMASimSetAssociationItemSel.h>
#include <SMASimArrayInt.h>
#include <mem_AllocationOperatorsTiny.h>
// End local includes

class SMASimAssociationItem;

/**
   This class represents a selection of links of an association that originate
   in a given object. This selection type is used when the other member
   of the association is ordered.
*/
class SMASimSelectionList : public mem_AllocationOperatorsTiny
{
public:

    /** Selects association links that originate at the object with the given ID. */
    SMASimSelectionList(
        SMASimAssociation const& recAssoc,
        int whichMember,
        SMASimDynamicID const& id);

    /** Returns the length of this selection. */
    int Length() const;

    /** Returns true if this selection contains a link with the given key. */
    bool IsMember(int key) const;

    /** Retrieves the ID of one object at the other endpoint.
        Returns true if the link was found, false otherwise. */
    bool Get(int key, SMASimDynamicID& id) const;

    /** Returns the ID of one object at the other endpoint. */
    SMASimDynamicID Get(int key) const;

    /** Retrieves the keys for the given ID. */
    void GetKeys(SMASimDynamicID id, SMASimArrayInt &keys) const;

private:
    friend class SMASimSelectionListIter;

    bool StillValid() const;

    int m_WhichMember;
    SMASimAssociation m_Association;
    SMASimSetAssociationItemSelection m_Selection;
    unsigned int m_AssociationModificationCount;
};

/**
   This object is an iterator over the list selection.
*/
class SMASimSelectionListIter
    : public mem_AllocationOperatorsTiny
{
public:

    /** Creates an iterator object. */
    SMASimSelectionListIter(SMASimSelectionList const& lst);

    /** Moves to the first link. */
    void First();

    /** Moves to the next link. */
    void Next();

    /** Returns true if the iterator has been advanced past the
        last or back past the first link. */
    bool IsDone();
    
    /** Returns the key associated with the current link. */
    int CurrentKey() const;

    /** Returns the ID of the object at the other endpoint of the current link. */
    const SMASimDynamicID& CurrentValue() const;

private:
    SMASimSelectionList const& m_List;
    SMASimSetAssociationItemSelection m_Iter;
};

#endif
