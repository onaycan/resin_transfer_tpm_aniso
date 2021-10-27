#ifndef SMASimDMember_h
#define SMASimDMember_h

// Begin local includes
#include <SMASimID.h>
#include <SMASimArrayCMemberID.h>
// End local includes

/** 
* A DMember uniquely identifies a member of a distribution by aggregating 
* a single cmember for each dimension of a distribution's grid.
**/
class SMASimDMember : public mem_AllocationOperators
{
public:
    ///  The default constructor 
    SMASimDMember() {};
    
    /// Construct a dmember from an array of cmembers
    SMASimDMember(SMASimArrayCMemberID const& cmembers);

    /// Construct a dmember from a single cmember
    SMASimDMember(const SMASimCMemberID& cMemberID);

    /// Return the ID of the distribution
    const SMASimArrayCMemberID& Array() const { return m_array; }

    /// Return the number of dimensions
    inline int Size() const { return m_array.Size(); }

    /// Return true if the d-member has not been defined; false otherwise
    int IsNull() const { return m_array.Size()==0;}

    /// Return the cmember ID for a specific dimension
    /// Note, the array of cmember IDs specified in the constructor have been sorted
    inline SMASimCMemberID const& operator[](int i) const { return m_array[i]; }

    /// Return the position of the given collection, or -1 if the collection is not
    /// a d-member dimension.
    int Position(SMASimCollectionID cid) const;

    /// Equality operator, return true if the c-members are the same, false otherwise
    bool operator==( SMASimDMember const& other) const { return m_array == other.m_array; }

    /// Equality operator, return true if the c-members are the not same, false otherwise
    bool operator != (SMASimDMember const& other) const { return ! ((*this)== other); }

    /// Return true if the d-mambers exist on the same grid; false otherwise
    bool SameGrid(SMASimDMember const& that) const;

    /// Debug output
    SMASimDebugOut& WriteDebug(SMASimDebugOut& uos) const;

private:
    int Compare(SMASimDMember const& that) const;
    static int CompareElementsForQsort(void const* e1, void const* e2);
    static int CompareElementsForFind(void const* e1, void const* e2);

    SMASimArrayCMemberID m_array;
};

/// Display of SMASimDMember - ONLY for debugging
inline SMASimDebugOut& operator<<(SMASimDebugOut& uos, SMASimDMember const& id)
{
    return id.WriteDebug(uos);
}

#endif
