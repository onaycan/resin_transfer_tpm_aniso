#ifndef uma_EbeMatrix_h
#define uma_EbeMatrix_h
///
/// Class to access element-by-element matrices from Generic System SIM database
///
#include <vector>

// Begin local includes
#include <uma_Enum.h>
#include <mem_AllocationOperators.h>
#include <SMAMtxMultiMatrix.h>
// End local includes

// Forward declarations
class uma_IncoreMatrix;
class uma_System;


class uma_EbeMatrix : public mem_AllocationOperators
{
public: // Public documented API

    /// Create null-matrix
    uma_EbeMatrix();
    /// Reset to a null-matrix
    void Reset();

    /// Check if matrix is defined
    bool IsNull() const;
    
    /// Number of elements
    int NumElements() const;

    /// Domain types for rows and columns: nodes, dofs, etc.
    uma_Enum::uma_MapTypeEnum TypeRows() const;
    uma_Enum::uma_MapTypeEnum TypeColumns() const;
        
    /// Element matrix dimensions
    int NumRows   ( int elemId ) const;
    int NumColumns( int elemId ) const;

    /// Map element to user label
    int MapElement( int elemId ) const;
    /// Map rows or columns to nodes, dofs, etc. (vector is reset to correct dimension)
    void MapRows   ( std::vector<int> & vector, int elemId, uma_Enum::uma_MapTypeEnum type ) const;
    void MapColumns( std::vector<int> & vector, int elemId, uma_Enum::uma_MapTypeEnum type ) const;

    /// Get values (incore matrix is reset to correct dimensions)
    void GetValues( uma_IncoreMatrix & matrix, int elemId ) const;

///////////////////////////////////////////////////////////////////////////////
private:
    const uma_System *m_system;
    const SMAMtxMultiMatrix *m_matrix;

public: // Internal, undocumented, not to be used explicitly by client
    /// Constructor(s)
    uma_EbeMatrix( const SMAMtxMultiMatrix * matrix, const uma_System * system );
    void Reset( const SMAMtxMultiMatrix * matrix, const uma_System * system );
    /// Destructor
    ~uma_EbeMatrix();
};

inline bool uma_EbeMatrix::IsNull() const
{
    return m_matrix? m_matrix->IsNull() : true;
}

#endif //uma_EbeMatrix_h
