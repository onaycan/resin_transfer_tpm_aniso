#ifndef SMASimDimSelection_h
#define SMASimDimSelection_h

// begin local includes
#include <mem_AllocationOperators.h>
#include <SMASimOrdinalRange.h>
#include <SMASimID.h>
#include <SMASimCSet.h>
#include <SMASimAssert.h>
// end local includes

/** 
* This class defines the selection of one dimension for creating/reading/writing a drawer.
* It is in fact essentially qualified-union of SMASimCSetID, and SMASimDimRange
**/
class SMASimDimSelection  : public mem_AllocationOperators
{
 public:

     /// Default constructor
    SMASimDimSelection()
    :  m_qualify(SMASimDSundefined)
    // , m_cset(0) 
    {}
  
    /// Return the type of selection specified
    SMASimDimSelectionQualify Type() const { return m_qualify; };

    /// Return the size of the selection
    size_t Size() const;

    /// All selections refer to a collection ID, return this ID
    SMASimCollectionID CollectionID() const; 

    /// Return true of the selection has not been defined, flase otherwise
    bool IsUndefined() const { return m_qualify == SMASimDSundefined;}

    /// Set the selection to be specified as a cset
    void SetCSetID( const SMASimCSetID& d) { m_CSetID = d;  m_qualify = SMASimDScsetID; }

    /// Set the selection to be specified as a cset
    void SetCSet(SMASimCSet cset) { m_cset = cset;  m_qualify = SMASimDScset; }

    /// Set the selection to be specified as a cset
    void SetCMemberID( const SMASimCMemberID& cm) { m_CMember = cm;  m_qualify = SMASimDScmember; }

    /// Return true if the selection is specified by a c-set, false otherwise
    bool IsCSet() const { return m_qualify == SMASimDScset; }
        // { return m_qualify == SMASimDScset && m_cset != 0; }

    /// Return true if the selection is specified by a c-set ID, false otherwise
    bool IsCSetID() const { return m_qualify == SMASimDScsetID; }

    /// Return true if the selection is specified by a c-member, false otherwise
    bool IsCMember() const { return m_qualify == SMASimDScmember; }

    /// Return the cset ID identifying the selection
    /// Note, verify the selection is by cset ID before calling
    const SMASimCSetID CSetID() const;

    /// Return the cset identifying the selection
    /// Note, verify the selection is by cset before calling
    const SMASimCSet& CSet() const;

    /// Return the c-member index identifying the selection
    const SMASimCMemberID CMemberID() const;

    /// Set the selection as a range of ordinal values
    void SetOrdinalRange( const SMASimCollectionID & coll, size_t first, size_t last) {
        m_OrdinalRange.m_collectionID = coll;
        m_OrdinalRange.m_first = first;
        m_OrdinalRange.m_last = last;
        m_qualify = SMASimDSordrange;
    } 

    /// Return true if the selection is specified as an ordinal range, false otherwise
    bool IsOrdinalRange() const { return m_qualify == SMASimDSordrange; }

    /// Return the ordinal range identifying the selection
    /// Note, verify the selection is by ordinal range before calling
    const SMASimOrdinalRange& OrdinalRange() const;

    /// Return a reference to the ordinal range identifying the selection
    /// Note, verify the selection is by ordinal range before calling
    SMASimOrdinalRange& OrdinalRangeRef();

    /// Do not use
    bool operator!=( const SMASimDimSelection& other){
        SMASimVALIDATE(0);  // not implemented yet - not needed, needed for explicit instantiation of array.
        return false;
    }

    /// Debug output
    SMASimDebugOut& WriteDebug(SMASimDebugOut& uos) const;

 private:
    SMASimDimSelectionQualify m_qualify;
    SMASimCSetID              m_CSetID;
    SMASimCMemberID           m_CMember;
    SMASimOrdinalRange        m_OrdinalRange;
    SMASimCSet                m_cset;
  
};
/// Debug output
inline SMASimDebugOut& operator<<(SMASimDebugOut& uos, SMASimDimSelection const& sel)
{
  return sel.WriteDebug(uos);
}

#endif // SMASimDimSelection_h
