#ifndef SMASimIndexMapEntry_h
#define SMASimIndexMapEntry_h

// Begin local includes
#include <mem_AllocationOperators.h>

/// Members m_index and m_memberIndex are indices in SMASimIndexSetContainer::m_indexTable
/// Member m_ascIndex is an index into this class' index map. This eliminates a lookup when
/// constructing an ordered cset's ascending ID.
/// The members are described below:
/// m_iscIndex: IndexSetContainer(ISC) # where membership set resides  
///             For ascending sets, this is the set of members in ascending order
///             For ordered set, this is the permutation map
///             There is one ISC per bulk file
/// m_index: The indexSet entry in above indexSetContainer
///          For ascending set, an example is (1,2,3)
///          For ordered set, an example is (2,0,1) - permutation of above set
/// m_ascIndex : -1; 
///          -1, if this is an ascending set
///              For an ordered set, this is the indexMapEntry in the 
///              CSET TABLE of THIS COLLECTION
/// We have a requirement to identify Client IDSpaces for SIM IDs.
/// ie..Group SIM entities based on client keys
/// To identify CSets with client keys; we decided to mask
/// upper 8 bits in m_index with client IDSpace(0..255)
///
class SMASimIndexMapEntry  : public mem_AllocationOperators {
public:
    SMASimIndexMapEntry() : m_iscIndex(-1), m_index(-1), m_ascIndex(-1) {}
    SMASimIndexMapEntry(int isc, int ind, int asc) : m_iscIndex(isc), m_index(ind), m_ascIndex(asc) {}

    int m_iscIndex;     
    int m_index;
    int m_ascIndex;
};
#endif


