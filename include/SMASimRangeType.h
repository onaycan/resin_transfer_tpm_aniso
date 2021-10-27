#ifndef SMASimRangeType_h
#define SMASimRangeType_h

// begin local includes
#include <mem_AllocationOperators.h>
#include <SMASimID.h>
#include <SMASimTypeKey.h>
#include <SMASimAssert.h>
// end local includes

/**
*  Specifies the type of the range of a distribution.
**/

class SMASimRangeType : public mem_AllocationOperators
{
public:
    /// Construct a numeric (non-relational) range type
    SMASimRangeType( SMASimTypeKey k );

    /// Construct a relational range type
    SMASimRangeType( SMASimTypeKey k, SMASimCollectionID const& coll );

    /// Construct void range type (for later assignment)
    SMASimRangeType( ); 

    /// Return the range data type 
    SMASimTypeKey TypeKey() const
    {  return m_key; }

    /// Return true if this is a relational range; false otherwise
    bool IsRelational() const 
    { return m_isRelational; }

    /// Debug output
    SMASimDebugOut& WriteDebug(SMASimDebugOut& uos) const; // mainly for debugging

    /// Equality operator, return true if the two range types are identical; false otherwise
    bool operator == ( SMASimRangeType const& other) const {
        return m_key == other.m_key && m_collectionID == other.m_collectionID;
    }

    /// Inequality operator, return true if the two range types differ; false otherwise
    bool operator!=( const SMASimRangeType& other) const {
        return ! (this->operator==(other));
    }

    /// Return the ID collection over which this range is defined
    SMASimCollectionID CollectionID() const { return m_collectionID; }

private:
    friend class SMASimDistributionRepr;
    SMASimRangeType(SMASimTypeKey k, bool isRelational, SMASimCollectionID const& coll);

    SMASimTypeKey m_key;
    bool m_isRelational;
    SMASimCollectionID m_collectionID;
};

inline SMASimDebugOut& operator<<(SMASimDebugOut& uos, SMASimRangeType const& rType)
{
    return rType.WriteDebug(uos);
}

#endif // SMASimRangeType_h
