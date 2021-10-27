#ifndef SMASimSerializationType_h
#define SMASimSerializationType_h

// begin local includes
#include <mem_AllocationOperators.h>
#include <SMASimDataTypes.h>
#include <SMASimArrayInt.h>
// end local includes

/// Serialization types
enum SMASimSerializationEnum
{
    SMASimVoidSerialization=0,     ///< unset
    SMASimStandardSerialization,   ///< standard serialization
    SMASimUniformitySerialization, ///< uniform serialization (at least one dimension is uniform)
    SMASimSparseSerialization,     ///< sparse serialization
    SMASimSparseSymSerialization   ///< sparse-symmetric serialization
};

/**
* Specifies what we need to know about how to serialize a certain drawer.
* \note The 'serialization buffer' is needed to complete the description in 
* the case of sparse serialization.
**/
class SMASimSerializationType : public mem_AllocationOperators
{

public:
    /// constructs void serialization type.
    /// then assign, or construct with 'Set'.
    SMASimSerializationType( );

    /// Debug output
    SMASimDebugOut& WriteDebug(SMASimDebugOut& uos) const;

    /// Set serialization type to standard
    SMASimSerializationType& SetStandard();

    /// Set serialization type to sparse
    SMASimSerializationType& SetSparse();

    /// Set serialization type to sparse-symmetric
    SMASimSerializationType& SetSparseSym();

    /// To make uniform, call with each "uniform" dimension to make uniform in that dimension.
    /// For the first one, provide the number of dimensions as the second argument, it
    /// is optional in the next calls.
    /// \code ser.SetUniform(0, 4).SetUniform(3);\endcode (sets dimensions 0 and 3 of a 4D drawer to uniform)
    SMASimSerializationType& SetUniform( int dim, int nDim = -1);

    //---- Querying -----

    /// IsStandard means there are no serialization modifications.
    bool IsStandard() const { return m_key == SMASimStandardSerialization;}

    /// Returns true if sparse serialization is set; false otherwise
    /// \note The API is designed to admit more than one serialization modification per drawer.
    ///       Currently only one serialization modificationper drawer is supported.
    bool HasSparse() const { return m_key == SMASimSparseSerialization;}

     /// Returns true if sparse-symmetric serialization is set; false otherwise
    /// \note The API is designed to admit more than one serialization modification per drawer.
    ///       Currently only one serialization modificationper drawer is supported.
    bool HasSparseSym() const { return m_key == SMASimSparseSymSerialization;}

    /// Returns true if a dimension is serializaed uniformly; false otherwise
    /// \note The API is designed to admit more than one serialization modification per drawer.
    ///       Currently only one serialization modificationper drawer is supported.
    bool HasUniform() const { return m_key == SMASimUniformitySerialization;}

    /// Return true if the specified dimension is serialized uniformly; false otherwise
    bool IsDimUniform( int dim) const; 

    /// Return the number of dimensions serialized uniformly
    int NumUniform() const { return m_uniformDims.Size(); }

    /// Equality operator, returns true if two serialization types are identical; false otherwise
    bool operator==( const SMASimSerializationType other) const {
        return m_key == other.m_key && m_uniformDims == other.m_uniformDims;
    }

    /// Inequality operator, returns true if two serialization types differ; false otherwise
    bool operator!=( const SMASimSerializationType other) const {
        return !operator==(other);
    }

public:

    // Not exported (private) since later expansion would mean there is not one single key.
    SMASimSerializationEnum Type() const;

private:

    SMASimSerializationEnum m_key;
    SMASimArrayInt m_uniformDims;

};

inline bool SMASimSerializationType::IsDimUniform( int dim) const
{
    if(!HasUniform())
        return false;
    return m_uniformDims[dim];
}

inline SMASimDebugOut& operator<<(SMASimDebugOut& uos, SMASimSerializationType const& ser)
{
    return ser.WriteDebug(uos);
}

/// Return the name of the serialization type
const char* SMASimstringName( SMASimSerializationEnum);
const char* SMASimStringName( const SMASimSerializationType& );

/// Debug output
inline SMASimDebugOut& operator << ( SMASimDebugOut& uos, const SMASimSerializationEnum& e){
    uos << SMASimstringName(e);
    return uos;
}

#endif // SMASimSerializationType_h
