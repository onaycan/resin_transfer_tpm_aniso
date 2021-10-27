#ifndef SMASimOrdinalRange_h
#define SMASimOrdinalRange_h

// begin local includes
#include <mem_AllocationOperators.h>
#include <SMASimID.h>

// end local includes

/**
* Selection defined as a range of ordinal values.
* A simple struct indicating a selection of ordinals in a drawer,  associated
* with a particular collection
**/
class SMASimOrdinalRange : public mem_AllocationOperators
{ 
 public: 
     /// Default constructor
    SMASimOrdinalRange()
    : m_first(0), m_last(0) {}

    /// Debug output
    SMASimDebugOut& WriteDebug(SMASimDebugOut& uos) const;

    /// Return the ID of the collection the ordinals refer to
    SMASimCollectionID CollectionID() const { return m_collectionID;}

    /// Members
    SMASimCollectionID m_collectionID;
    int m_first;
    int m_last;
};

/// Debug output
inline SMASimDebugOut& operator<<(SMASimDebugOut& uos, SMASimOrdinalRange const& dr)
{
  return dr.WriteDebug(uos);
}

// TEMPORARILY LOCATED HERE FOR ZVERSION CHANGES
/// Type of selection
enum SMASimDimSelectionQualify { 
    SMASimDSundefined, 
    SMASimDScsetID, 
    SMASimDScset, 
    SMASimDSordrange, 
    SMASimDScmember };

#endif // SMASimOrdinalRange_h

