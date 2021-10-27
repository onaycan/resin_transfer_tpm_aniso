#ifndef SMASimAssociation_h
#define SMASimAssociation_h

// Begin local includes
#include <SMASimWeakReference.h>
#include <SMASimRpm_WeakRef.h>
#include <SMASimRpm_StrongRef.h>
// End local includes

class CATString;
class SMASimTypeID;
class SMASimDynamicID;
class SMASimContextID;
class SMASimAssociationRepr;
class SMASimTransactionRepr;
class SMASimTypeAssociationMember;
class SMASimTransaction;
class SMASimAssociationLink;
template <class Repr, class Ref> class SMASimHolder;
typedef SMASimRpm_WeakRef<SMASimTransactionRepr> SMASimTransactionReprWRef;
typedef SMASimRpm_StrongRef<SMASimTransactionRepr> SMASimTransactionReprSRef;

/**
   This class represents an update of an association.
*/
class SMASimAssociation : public SMASimWeakReference<SMASimAssociationRepr>
{
public:
    enum DuplicateThrow { Throw, NoThrow };

    /** Create an empty handle. */
    SMASimAssociation(){}

    /** Create a handle from an ID. */
    SMASimAssociation(SMASimContextID ctxID, SMASimTypeID typeID);

    /** NOT FOR GENERAL USE - Copy constructor with a twist */
    SMASimAssociation(SMASimAssociation const& that,
                      SMASimTransactionReprWRef& transaction)
        : SMASimWeakReference<SMASimAssociationRepr>(that),
          m_Transaction(transaction)
        {}

    /** Returns the type ID of this association. */
    SMASimTypeID TypeID() const;

    /** Returns the type metadata for one association member. The member index may
        be either 0 or 1. */
    SMASimTypeAssociationMember Member(int whichMember) const;

    /** Returns the category of the association member. The returned value is one
        of the SMASimCategory enumerations. The member index may either be 0 or 1.*/
    int MemberCategory(int whichMember) const;

    /** Inserts a link into an association. Link members must be placed in the right order.*/
    bool Insert(SMASimAssociationLink const &link,
                DuplicateThrow noThrow = Throw) const;

    /** Inserts a link into an association. Both association members must either have no key
        or an int key. */
    bool Insert(int whichMemberFirst,
                SMASimDynamicID const& firstID,
                SMASimDynamicID const& secondID,
                DuplicateThrow noThrow = Throw) const;

    /** Inserts a link into an association. The first member must have no key or an int key,
        the second member must have a string key. */
    bool Insert(int whichMemberFirst,
                SMASimDynamicID const& firstID,
                SMASimDynamicID const& secondID,
                CATString const& secondKey,
                DuplicateThrow noThrow = Throw) const;

    /** Inserts a link into an association. The first member must have no key or an int key,
        the second member must have an int key. */
    bool Insert(int whichMemberFirst,
                SMASimDynamicID const& firstID,
                SMASimDynamicID const& secondID,
                int secondKey,
                DuplicateThrow noThrow = Throw) const;

    /** Inserts a link into an association. The first member must have a string key,
        the second member must have no key or an int key. */
    bool Insert(int whichMemberFirst,
                SMASimDynamicID const& firstID,
                CATString const& firstKey,
                SMASimDynamicID const& secondID,
                DuplicateThrow noThrow = Throw) const;

    /** Inserts a link into an association. Both association members must have a string key. */
    bool Insert(int whichMemberFirst,
                SMASimDynamicID const& firstID,
                CATString const& firstKey,
                SMASimDynamicID const& secondID,
                CATString const& secondKey,
                DuplicateThrow noThrow = Throw) const;

    /** Inserts a link into an association. The first member must have a string key, the second member
        must have an int key. */
    bool Insert(int whichMemberFirst,
                SMASimDynamicID const& firstID,
                CATString const& firstKey,
                SMASimDynamicID const& secondID,
                int secondKey,
                DuplicateThrow noThrow = Throw) const;

    /** Inserts a link into an association. The first member must be ordered, the second member
        must have no key or have an int key. */
    bool Insert(int whichMemberFirst,
                SMASimDynamicID const& firstID,
                int firstKey,
                SMASimDynamicID const& secondID,
                DuplicateThrow noThrow = Throw) const;

    /** Inserts a link into an association. The first member must have an int key, the second member
        must have a string key. */
    bool Insert(int whichMemberFirst,
                SMASimDynamicID const& firstID,
                int firstKey,
                SMASimDynamicID const& secondID,
                CATString const& secondKey,
                DuplicateThrow noThrow = Throw) const;

    /** Inserts a link into an association. Both association members must have int keys. */
    bool Insert(int whichMemberFirst,
                SMASimDynamicID const& firstID, int firstKey,
                SMASimDynamicID const& secondID, int secondKey,
                DuplicateThrow noThrow = Throw) const;


    /** Removes a link from an association given IDs of objects on both endpoints.
        Both association members must have no key. */
    void Remove(int whichMember, SMASimDynamicID const& id, SMASimDynamicID const& otherID) const;

    /** Removes a link from this association by the ID of the object at one endpoint and
        the string key of the object at the other endpoint.*/
    void Remove(int whichMember, SMASimDynamicID const& id, CATString const& otherKey) const;

    /** Removes a link from this association by the ID of the object at one endpoint and
        the int key of the object at the other endpoint. */
    void Remove(int whichMember, SMASimDynamicID const& id, int otherKey) const;

    /** Removes a link from this association by the string key of the object at one endpoint and
        the ID of the object at the other endpoint. */
    void Remove(int whichMember, CATString key, SMASimDynamicID const& otherID) const;

    /** Removes a link from this association by the int key of the object at one endpoint and
        the ID of the object at the other endpoint. */
    void Remove(int whichMember, int key, SMASimDynamicID const& otherID) const;

    /** Removes from this association all links that originate in the given ID. */
    void RemoveAll(int whichMember, SMASimDynamicID const& id) const;


    /** Returns true if this association has the given link. */
    bool HasLink(int whichMember, SMASimDynamicID const& id, SMASimDynamicID const& otherID) const;

    /** Returns true if this association has the given link. */
    bool HasLink(int whichMember, SMASimDynamicID const& id, CATString const& otherKey) const;

    /** Returns true if this association has the given link. */
    bool HasLink(int whichMember, SMASimDynamicID const& id, int otherKey) const;

    /** Returns true if this association has the given link. */
    bool HasLink(int whichMember, CATString key, SMASimDynamicID const& otherID) const;

    /** Returns true if this association has the given link. */
    bool HasLink(int whichMember, int key, SMASimDynamicID const& otherID) const;

    /** Returns true if this association has any links where the given ID serves as the given member. */
    bool HasLinks(int whichMember, SMASimDynamicID const& id) const;


    /** NOT FOR PUBLIC CONSUMPTION: return pointer to representation */
    SMASimAssociationRepr* Repr() const { return SMASimWeakReference<SMASimAssociationRepr>::Get(); }

private:
    friend class SMASimHolder<SMASimAssociationRepr, SMASimAssociation>;
    // Following constructor is used to create an Association object
    // for an empty association table in the view.. i.e. the view has a type
    // registered for this association, but it hasn't yet been created by the
    // user...
    SMASimAssociation(SMASimAssociationRepr *repr, SMASimWeakCounter *counter)
        : SMASimWeakReference<SMASimAssociationRepr>(repr, counter)
        {}

    SMASimTransactionReprWRef   m_Transaction;
};


#endif
