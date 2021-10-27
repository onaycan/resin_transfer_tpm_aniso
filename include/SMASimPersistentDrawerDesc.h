#ifndef SMASimPersistentDrawerDesc_h
#define SMASimPersistentDrawerDesc_h

// begin local includes
#include <SMASimDrawerDescription.h>
#include <SMASimID.h>
#include <SMASimArrayInt.h>
#include <SMASimRangeValue.h>
// end local includes

/**
* Description of a persistent(on-disk) drawer. 
* Extends the base class drawer description by the persistent drawer ID and chunking information.
**/

class SMASimPersistentDrawerDesc : public SMASimDrawerDescription
{
public:
    /// Debug output
    SMASimDebugOut& WriteDebug(SMASimDebugOut& uos) const; // mainly for debugging

    /// Set the ID of the drawer
    void SetDrawerID(SMASimDrawerID ID) { m_drawerID = ID; }

    /// Return the ID of the drawer
    SMASimDrawerID DrawerID() const { return m_drawerID; }

    /// Set the drawer layout to chunked format and set the chunk size
    void SetChunkSizes(const SMASimArrayInt& chunkSz) { m_chunkSizes = chunkSz; }

    /// Return true if the drawer is stored in chunked format rather than contiguous; false otherwise
    bool IsChunked() const { return !(m_chunkSizes.Size() == 0); }

    /// Return the dimensions of a chunk
    const SMASimArrayInt& ChunkSizes() const {return m_chunkSizes;}

    /// Set the chunk size of a dimension
    void SetChunkSize(int dim, int chunkSz) { m_chunkSizes.Get(dim) = chunkSz; }

    /// Return the size of a chunk dimension
    int ChunkSize(int dim) const {return m_chunkSizes[dim];}

    /// Return true if the drawer initialization value has been specified; false otherwise
    bool InitializationValueDefined() const {
        SMASimTypeKey tkey = m_fillValue.TypeKey();
        if(isNumeric(tkey) && m_fillValue.SizeBytes() > 0)
            return true;
        return false;
    }

    /// Return the drawer initialization value 
    const SMASimRangeValue& InitializationValue() const { return m_fillValue; }

    /// Set the drawer initialization value
    void SetInitializationValue(const SMASimRangeValue& val);

    /// Return the drawer exendable dimension 
    int ExtendableDim() const { return m_extendableDim; }

    /// Set the drawer's exendable dimension
    void SetExtendableDim(int dim)  { m_extendableDim = dim; }

    /// Equality oprator, return true if two drawer descriptions are identical; false otherwise
    bool operator==( const SMASimPersistentDrawerDesc& other) const {
        return m_drawerID==other.m_drawerID 
            && m_chunkSizes == other.m_chunkSizes
            &&  *(const SMASimDrawerDescription*)this == other; // base class equal
    }

    /// Inequality oprator, return true if two drawer descriptions differ; false otherwise
    bool operator!=( const SMASimPersistentDrawerDesc& other) const {
        return ! (this->operator==(other));
    }
    /// Default constructor
    SMASimPersistentDrawerDesc(): m_extendableDim(-1) {};

    /// Construct a persistent drawer description from a drawer description and a drawer ID
    SMASimPersistentDrawerDesc(const SMASimDrawerDescription& base, SMASimDrawerID id);

    /// Return the subclass drawer description
    const SMASimDrawerDescription& Base() const { return *this; }

private:
    /// Id of the drawer
    SMASimDrawerID m_drawerID;
    /// The sizes of the blocks in each dimension in order
    SMASimArrayInt m_chunkSizes;
    /// The default fill value
    SMASimRangeValue m_fillValue;
    int m_extendableDim;
};

inline SMASimDebugOut& operator<<(SMASimDebugOut& uos, SMASimPersistentDrawerDesc const& descr)
{
    return descr.WriteDebug(uos);
}

#endif // SMASimPersistentDrawerDesc_h
