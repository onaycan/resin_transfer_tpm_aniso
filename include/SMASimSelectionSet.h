#ifndef SMASimSelectionSet_h
#define SMASimSelectionSet_h

// Begin local includes
#include <mem_AllocationOperatorsTiny.h>
#include <SMASimArrayInt.h>
#include <SMASimAssociation.h>
// End local includes

class SMASimDynamicID;
class SMASimAssociationItem;

/**
   This class represents a selection of links of an association that originate
   in a given object. This selection type is used when the other member
   of the association is unordered and it has no key.
*/
class SMASimSelectionSet : public mem_AllocationOperatorsTiny
{
public:

    /** Selects association links that originate at the object with the given ID. */
    SMASimSelectionSet(
        SMASimAssociation const& recAssoc,
        int whichMember,
        SMASimDynamicID const& id);

    /** Returns the length of this selection. */
    int Length() const { return m_SelectionList.Size(); }

    /** Retrieves the ID of one object at the other endpoint. */
    void Get(int position, SMASimDynamicID& id) const;

    /** Returns the ID of one object at the other endpoint. */
    SMASimDynamicID Get(int position) const;

private:
    bool StillValid() const;

    int m_WhichMember;
    SMASimArrayInt m_SelectionList;
    SMASimAssociation m_Association;
    unsigned int m_AssociationModificationCount;
};

#endif
