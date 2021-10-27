#ifndef SMASimDrawerDescription_h
#define SMASimDrawerDescription_h

// begin local includes
#include <mem_AllocationOperators.h>
#include <SMASimAssert.h>
#include <SMASimRangeType.h>
#include <SMASimSerializationType.h>
#include <SMASimOCompartment.h>
#include <SMASimArrayInt.h>
#include <SMASimID.h>
#include <SMASimDataTypes.h>
#include <SMASimBufferSet.h>
#include <SMASimTypeKey.h>
// end local includes

/**
* Description of a drawer.
**/

class SMASimDrawerDescription  : public mem_AllocationOperators
{
public:
    /// Default contructor
    SMASimDrawerDescription( ) {}

    /// Return the number of dimensions
    int NumDimensions() const { return m_csetSizes.Size(); }

    /// The drawer data type(i.e. int, float, relational,...)
    const SMASimRangeType& Range() const  { return m_rangeType; }

    /// Return the domain of the drawer, the dataspace of the domain is defined as a compartment
    const SMASimOCompartment&  Domain() const { return m_oCompartment; }

    /// Return the method in which the drawer's data is serialized (standard, uniform, sparse or sparse-symmetric)
    const SMASimSerializationType&  SerializationType() const { return m_serializationType; }

    /// Debug output
    SMASimDebugOut& WriteDebug(SMASimDebugOut& uos) const;

    /// The sizes of the drawer dimensions. Uniform dimension sizes will be one.
    const SMASimArrayInt& DimensionSizes() const { return m_dimensionSizes; }

    /// The sizes of the c-sets defining the drawer dimensions.
    const SMASimArrayInt& CSetSizes() const { return m_csetSizes; }
    
    /// Buffer size required to hold the drawer's data
    size_t DataSizeBytes(int k = SMASimbufMain) const { return m_bufferSizes[k]; }

    /// Number of data items contained in the drawer
    size_t DataSizeItems(int k = SMASimbufMain) const;

    /// The buffer data type(i.e. int, float)
    SMASimTypeKey DataTypeKey( int k = SMASimbufMain) const {  return m_bufferDataKeys[k]; }

    /// Equality operator, will return true when two drawer descriptions are identical; false otherwise
    bool operator==( const SMASimDrawerDescription& other) const;

    /// Inequality operator, will return true when two drawer descriptions differ; false otherwise
    bool operator!=( const SMASimDrawerDescription& other) const { return ! (this->operator==(other)); }

    /// Set the number of dimensions
    void SetNumDimensions(int num);

    /// The drawer data type(i.e. int, float, relational,...)
    void SetRange(const SMASimRangeType& rangeType) { m_rangeType = rangeType; }

    /// Set the domain of the drawer, the dataspace of the domain is defined as a compartment
    void SetDomain(const SMASimOCompartment& ocomp) { m_oCompartment = ocomp; }

    /// Set the drawer's serialization type(standard, uniform, sparse or sparse-symmetric)
    void  SetSerializationType(const SMASimSerializationType& ser) { m_serializationType = ser; }

    /// Buffer size required to hold the drawer's data
    void SetDataSizeBytes(size_t sz, int buf=SMASimbufMain ) { m_bufferSizes[buf] = sz; }

    /// Set the data type(i.e. int, float) of a buffer
    void SetDataTypeKey(const SMASimTypeKey& typ, int buf = SMASimbufMain) { m_bufferDataKeys[buf] = typ; }

    /// Set the sizes of the c-sets defining the drawer dimensions.
    void SetCSetSizes(const SMASimArrayInt& sz) { m_csetSizes = sz; }

    /// Set the size of dimensions, this should normally be computed as a function of the domain and serialization
    /// Provided here for testing
    void SetDimSizes(const SMASimArrayInt& dsz) { m_dimensionSizes = dsz; }

    /// Compute the logical and physical sizes of the drawer
    void ComputeDomainSizes(unsigned int uniformDims=0);

private:
    friend class SMASimDistribution;
    friend class SMASimDrawer;
    friend class SMASimTransfer; 
    friend class SMASimSaveAsVisitor;

    /// Type of data in contained in the drawer
    SMASimRangeType m_rangeType;
    /// Drawer serialization type
    SMASimSerializationType m_serializationType;
    /// Drawer domain
    SMASimOCompartment m_oCompartment;
    /// sSizes of csets in the order they appear in the OCompartment defining the dimensions
    SMASimArrayInt m_csetSizes;
    /// Dimension sizes, will be the same as m_csetSizes for standard and sparse serialization.
    /// For uniform serialization, uniform dimension sizes will one.
    SMASimArrayInt m_dimensionSizes;
    /// Buffer types and sizes
    SMASimBufferSizes m_bufferSizes; 
    /// Data-type keys of the buffers
    SMASimBufferDataKeys m_bufferDataKeys;
};

inline SMASimDebugOut& operator<<(SMASimDebugOut& uos, SMASimDrawerDescription const& descr)
{
    return descr.WriteDebug(uos);
}

#endif // SMASimDrawerDescription_h
