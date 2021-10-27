#ifndef SMASimGrid_h
#define SMASimGrid_h

// Begin local includes
#include <mem_AllocationOperators.h>
#include <SMASimDataTypes.h>
#include <SMASimArrayCollectionID.h>
// End local includes

/**
* A Grid is an unordered set of one or more collections
**/
class SMASimGrid : public mem_AllocationOperators
{
public:
    /// Default constructor.  Constructs an empty grid.
    /// Typically, the grid will be assigned later to a non-empty value.
    SMASimGrid(){};

    /// Create a grid from an array of collection IDs.  The grid
    /// keeps a sorted copy.
    explicit SMASimGrid(SMASimArrayCollectionID const& arrayCollectionID);

    /// Return the number of grid dimensions
    int Size() const { return m_Array.Size(); }

    /// Return true if the grid is empty; false otherwise
    int IsNull() const { return m_Array.Size()==0;}

    /// Return the collection ID defining a grid dimension. 
    SMASimCollectionID const& operator[](int i) const { return m_Array[i]; };

    /// Returns the position of the given collection, or -1 if the collection does
    /// not belong to this grid.
    int Position(SMASimCollectionID cid) const;

    /// Returns the array of Collection IDs that represents this grid.
    /// This is not necessarily the same array as was passed in at construction,
    /// but rather a sorted version.
    SMASimArrayCollectionID const& CollectionIDs() const { return m_Array; }

	/// Debug output
    SMASimDebugOut& WriteDebug(SMASimDebugOut& uos) const;

    /// Equality operator, return true if two grids are defined by the same collections; false otherwise
    bool operator ==( const SMASimGrid& other) const {
        return m_Array == other.m_Array;
    }

    /// Inquality operator, return true if two grids are not defined by the same collections; false if they are
    bool operator !=( const SMASimGrid& other) const { return !((*this) == other);}

private:
    static int CompareElementsForQsort(void const* e1, void const* e2);
    static int CompareElementsForFind(void const* e1, void const* e2);

    SMASimArrayCollectionID m_Array;
};

inline SMASimDebugOut& operator<<(SMASimDebugOut& uos, SMASimGrid const& grid)
{
    return grid.WriteDebug(uos);
}

#endif
