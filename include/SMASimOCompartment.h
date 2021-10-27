#ifndef SMASimOCompartment_h
#define SMASimOCompartment_h

// Begin local includes
#include <SMASimDataTypes.h>
#include <SMASimArrayCSetID.h>
#include <SMASimGrid.h>
#include <SMASimArrayInt.h>
#include <SMASimID.h>
#include <mem_AllocationOperators.h>
// End local includes

class SMASimTransfer;

/**
* A class representing an ordered compartment. 
* An ordered compartment defines the dataspace of the domain of a drawer.
**/
class SMASimOCompartment : public mem_AllocationOperators
{
public:
    ///Default constructor
    SMASimOCompartment() : m_created(false) {};

    /// Create an ordered compartment from and array of cset IDs
    explicit SMASimOCompartment(SMASimArrayCSetID const& arrayCSetID);

    /// Create an ordered compartment after default construction and setting of cset IDs
    void Create(SMASimArrayCSetID const& arrayCSetID);

    /// Return the number of dimensions in the compartment
    int Size() const { return m_Array.Size(); }

    /// Returns true if the dimensions have not yet been defined; false if they have
    int IsNull() const { return m_Array.Size()==0;}

    /// Return the ID of the cset define a specific dimension
    SMASimCSetID const& operator[](int i) const { return m_Array[i]; };

	/// Returns the position in this OCompartment of the CSet of the given collection, or -1 if the collection does
    /// not form a dimension in this compartment.
    int Position(SMASimCollectionID const& cid) const;

    /// Returns the array of C-set IDs of this ordered compartment.
    SMASimArrayCSetID const& CSetIDs() const { return m_Array; }

    /// Debug output
    SMASimDebugOut& WriteDebug(SMASimDebugOut& uos) const;

    /// Equality operator, return true if two ordered compartments identify the same dataspace; false otherwise
    bool operator == ( SMASimOCompartment const& other) const {
        return m_Array == other.m_Array;
    }

    /// Inequality operator, return true if two ordered compartments identify the differing dataspaces; false otherwise
    bool operator!=( const SMASimOCompartment& other) const {
        return ! (this->operator==(other));
    }

    /// Return the number of dimensions in the compartment (same as Size())
    int NumDimensions() const { return m_Array.Size(); }

    /// Returns an array containing the sizes of all dimensions
    /// \note for performance reasons, if the drawer description is available, use SMASimDrawerDescription::CSetSizes instead
    SMASimArrayInt DimensionSize() const;

    /// Return a mapping from THIS dimension order to THAT
    SMASimArrayInt MapDimensions(const SMASimOCompartment& that) const;

    /// Assign a cset to a dimension of this compartment
    void SetDimCSet(int dim, SMASimCSetID);

    /// Return the number ot items represented by this compartment (product of the dimension sizes)
    int NumItems()const;

private:
    /// Validation routine to assure csets exist in different collections
    void Validate();

private:
    static int CompareElementsForFind(void const* e1, void const* e2);

    friend class SMASimOCtation;
    SMASimArrayCSetID m_Array;
    bool            m_created;
    friend class SMASimTransfer;
    bool SameGrid(SMASimOCompartment const& that) const;
    int Compare(SMASimOCompartment const& that) const;
    static int CompareElementsForQsort(void const* e1, void const* e2);
};

inline SMASimDebugOut& operator<<(SMASimDebugOut& uos, SMASimOCompartment const& ocompartment)
{
    return ocompartment.WriteDebug(uos);
}

#endif
