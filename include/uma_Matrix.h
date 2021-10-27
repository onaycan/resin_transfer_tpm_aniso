#ifndef uma_Matrix_h
#define uma_Matrix_h
///
/// Base class for access to Matrix
///
#include <vector>

// Begin local includes
#include <uma_Enum.h>

#include <mem_AllocationOperators.h>
// End local includes

// Forward declarations
class SMASimCSetID;
class SMAMtxDenseMatrix;
class SMAMtxMatrix;
class uma_ArrayInt;
class uma_IncoreMatrix;
class uma_System;

///////////////////////////////////////////////////////////////////////////////
///
/// Basic matrix class with API common for all/most matrices.
/// Not to be used on itself, but rather as a polymorphic pointer/reference
/// to derived classes.
///
///////////////////////////////////////////////////////////////////////////////

class uma_Matrix : public mem_AllocationOperators
{
public: // Public documented API

    /// Check if matrix is defined
    bool IsNull() const;
    
    /// Matrix dimensions
    int NumRows() const;
    int NumColumns() const;

    /// Domain types for rows and columns: nodes, dofs, etc.
    uma_Enum::uma_MapTypeEnum TypeRows() const;
    uma_Enum::uma_MapTypeEnum TypeColumns() const;

    /// Map rows or columns to nodes, dofs, etc. (client should delete the pointer when done)
    uma_ArrayInt * MapRows( uma_Enum::uma_MapTypeEnum type ) const;
    uma_ArrayInt * MapColumns( uma_Enum::uma_MapTypeEnum type ) const;
    /// Map rows or columns to nodes, dofs, etc. (STL vector API)
    void MapRows   ( std::vector<int> & vector, uma_Enum::uma_MapTypeEnum type ) const;
    void MapColumns( std::vector<int> & vector, uma_Enum::uma_MapTypeEnum type ) const;
    
    /// Get values (incore matrix must have sufficient dimensions)
    void GetValues( int startRow, int endRow, int startCol, int endCol,
                    uma_IncoreMatrix & matrix ) const;
    /// Get values (incore matrix is reset to correct dimensions)
    void GetValues( uma_IncoreMatrix & matrix, 
                    int startRow, int endRow, int startCol, int endCol ) const;
    
    /// Set values
    void SetValues( int startRow, int endRow, int startCol, int endCol,
                    const uma_IncoreMatrix & matrix );
    
    /// Create a submatrix (client should delete the pointer when done)
    uma_Matrix * Submatrix( int startRow, int endRow, int startCol, int endCol ) const;
    
    /// Matrix operations
    /// Multiply: this * B -> C
    void Multiply( const uma_Matrix * matrixB, uma_Matrix * matrixC ) const;
    /// TransposeMultiply: T(this) * B -> C
    void TransposeMultiply( const uma_Matrix * matrixB, uma_Matrix * matrixC ) const;
    
    /// Block sizes for system matrices
    int NumRowBlocks()          const;
    int NumRowsInBlock(int blk) const;
    int MaxRowsInBlock()        const;
    int NumColumnBlocks()       const;
    int NumColumnsInBlock(int blk) const;
    int MaxColumnsInBlock()     const;

///////////////////////////////////////////////////////////////////////////////
protected:
    const uma_System  *m_system;
    SMAMtxDenseMatrix *m_onfile;
    bool              m_readOnly;
    SMAMtxMatrix      *m_incore;
    uma_Matrix();

public: // Internal, undocumented, not to be used explicitly by client
    /// Constructor(s)
    uma_Matrix( const SMAMtxDenseMatrix * matrix,
                const uma_System * system );
    uma_Matrix( SMAMtxDenseMatrix * matrix,
                const uma_System * system = NULL );
    uma_Matrix( SMAMtxMatrix * matrix );
    
    /// Destructor
    virtual ~uma_Matrix();
    
    /// Access to SMAMtx matrix pointers (could be null) - for experts only
    const SMAMtxDenseMatrix * DenseMatrix() const {return m_onfile;}
    const SMAMtxMatrix * Matrix() const {return m_incore;}
    SMAMtxDenseMatrix * DenseMatrix() {return m_onfile;}
    SMAMtxMatrix * Matrix() {return m_incore;}
    
};

#endif //uma_Matrix_h
