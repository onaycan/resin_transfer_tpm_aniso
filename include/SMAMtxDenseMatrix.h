#ifndef SMAMtxDenseMatrix_H
#define SMAMtxDenseMatrix_H

/* Begin local includes */
#include <SMASimDistribution.h>
/* End local includes */

class SMAMtxMatrix;
class SMASimTransfer;

//! Base class for matrices
/*!
 * This class provides the generic interface for matrices, and supports
 * a certain set of mathematical operations (see below).
*/
class SMAMtxDenseMatrix  : public mem_AllocationOperators
{
public:
    /// Default ctor
    SMAMtxDenseMatrix();

    /// Construct on an ID (may be null)
    SMAMtxDenseMatrix(const SMASimDistributionID& did);    

    /// Construct the matrix with a distribution
    SMAMtxDenseMatrix(const SMASimDistribution& dist);

    virtual ~SMAMtxDenseMatrix();

    bool IsNull() const;
    
    int NumberOfRows() const;

    int NumberOfColumns() const;

    int NumberOfRowBlocks() const;

    int NumberOfColumnBlocks() const;

    /// Number of rows in the j'th block 
    int NumberOfRowsInBlock(int j) const;

    /// Number of columns in the j'th block 
    int NumberOfColumnsInBlock(int j) const;

    /// Maximal number of rows in block 
    int MaxNumberOfRowsInBlock() const;

    /// Maximal number of columns in block 
    int MaxNumberOfColumnsInBlock() const;

    /// Total number of rows in the blocks startRowBlock,startRowBlock+1,...,lastRowBlock
    int NumberOfRowsInBlockRange( int startRowBlock, int lastRowBlock ) const;

    /// Total number of columns in the blocks startColumnBlock,startColumnBlock+1,...,lastColumnBlock
    int NumberOfColumnsInBlockRange( int startColumnBlock, int lastColumnBlock ) const;
    
    /// The first row number in block # rowBlock
    int FirstRowInBlock( int rowBlock ) const;
    
    /// The first column number in block # columnBlock
    int FirstColumnInBlock( int columnBlock ) const;
    
    /// Row block containing i'th row
    int BlockContainingRow( int i ) const;
    
    /// Column block containing j'th column
    int BlockContainingColumn( int j ) const;    

    /// ID of the underlying distribution
    // @note: Use with care! If distribution is masked from another distribution,
    // the ID still refers to the very original distribution totally ignorant of masking.
    SMASimDistributionID DistributionID() const;

    /// Get the set for the rows of the drawer
    virtual SMASimCSetID RowCSetID() const;

    /// Get the set for the cols of the drawer
    virtual SMASimCSetID ColumnCSetID() const;
    
    /// Create Submatrix from the current matrix 
    virtual SMAMtxDenseMatrix *Submatrix( int startRow, int endRow, int startCol, int endCol ) const;
    
    /// Check which matrix dimension is extendable
    int ExtendableDim() const;
    
    /// Extend matrix dimension by specified number of items. Return 0 if OK, error code otherwise.
    int ExtendDim( int dim, int number, const int * ordinals = NULL );
    
    //
    // Dense Matrix Get and Set methods
    //
    void GetAllValues( double *values) const;
    // upper triangle of A by columns
    void GetUpperValues(double *values) const;
    // lower triangle of A by rows == upper triangle of transposed matrix by columns
    void GetLowerValues(double *values) const;
    // symmetrization of the matrix: A+transpose(A)/2
    void GetSymmetricValues(double *values) const;

    void GetValues(int startRow, int lastRow, int startCol, int lastCol, 
                   SMAMtxMatrix& dimMatrix) const;
    void GetValues(const int * rowNumbers, int numRows, const int * colNumbers, int numCols,
                   SMAMtxMatrix& dimMatrix) const;

    void SetValues(int startRow, int lastRow, int startCol, int lastCol, 
                   const SMAMtxMatrix& dimMatrix);
    void SetValues(const int * rowNumbers, int numRows, const int * colNumbers, int numCols,
                   const SMAMtxMatrix& dimMatrix);

    void GetRows(int startRow, int lastRow, SMAMtxMatrix & dimMatrix) const;
    void GetRows(const int * rowNumbers, int numRows, SMAMtxMatrix & dimMatrix) const;

    void SetRows(int startRow, int lastRow, const SMAMtxMatrix & dimMatrix);
    void SetRows(const int * rowNumbers, int numRows, const SMAMtxMatrix & dimMatrix);

    void GetColumns(int startCol, int lastCol, SMAMtxMatrix & dimMatrix) const;
    void GetColumns(const int * colNumbers, int numCols, SMAMtxMatrix & dimMatrix) const;

    void SetColumns(int startCol, int lastCol, const SMAMtxMatrix & dimMatrix);
    void SetColumns(const int * colNumbers, int numCols, const SMAMtxMatrix & dimMatrix);
                    
    /// Copy all values from the rhs to this matrix
    void CopyValues( const SMAMtxDenseMatrix * rhs );
       
    /// Copy values (A --> this) for positions (i,j) mapped by row and column ordinals
    void CopyMappedValues(const SMAMtxDenseMatrix * A);
    
    /// Copy mapped rows A --> this
    void CopyMappedRows(const SMAMtxDenseMatrix * A);
    
    /// Copy mapped columns A --> this
    void CopyMappedColumns(const SMAMtxDenseMatrix * A);
    
    /// Copy a dense block of the matrix to another DenseMatrix
    void GetSubmatrix(SMAMtxDenseMatrix& subm, int startRow, int lastRow,
		      int startCol, int lastCol) const;

    /// Copy all rows of the matrix to the destinations specified by the
    /// mapping array
    void CopyRowsToMemory(const int* destRowIds, int destNumRows,
			  SMAMtxMatrix& dimMatrix) const;

    //
    // Dense Matrix Operations
    //

    // C = alpha*A*B + beta*C, A:mtx, B:double, C:mtx
    virtual void Multiply(double alpha, const SMAMtxMatrix &B, double beta, SMAMtxDenseMatrix &C) const;

    // C = A*B
    virtual void Multiply(const SMAMtxDenseMatrix &B, SMAMtxDenseMatrix &C) const;
    virtual void Multiply(const SMAMtxDenseMatrix *B, double *C) const;
    virtual void Multiply(const SMAMtxMatrix &B, SMAMtxMatrix &C) const;

    // C += A*B - with add!
    virtual void Multiply(const double* B, int numColsB, double* C) const;

    // A *= B, A:mtx; B:mtx;
    virtual void MultiplyAssign(const SMAMtxMatrix& B);

    /// C = A^T * B
    virtual void TransposeMultiply(const SMAMtxDenseMatrix* B, SMAMtxMatrix& C, int symFlag=0) const;
    virtual void TransposeMultiply(const SMAMtxDenseMatrix *B, double *C, int symFlag=0) const;
    virtual void TransposeMultiply(const SMAMtxDenseMatrix* B, SMAMtxDenseMatrix* C, int symFlag=0) const;
    virtual void TransposeMultiply(const SMAMtxMatrix& B, SMAMtxMatrix& C, int symFlag=0) const;
    virtual void TransposeMultiply(const SMAMtxMatrix& B, double *C, int symFlag=0) const;

    /// C = alpha*A^T*B + beta*C (DGEMM notation)
    /// Rows of the matrix A will be permuted if rowPermutation != 0 (newRow# = rowPermutation[oldRow#])
    /// If numRowsA > numRowsB then the first numRowsB rows of A will be used after the permutation
    virtual void TransposeMultiply( const int *rowPermutation, const SMAMtxMatrix& B, SMAMtxMatrix& C, 
                                    double alpha = 1.0, double beta = 0.0 );
    
    /// C += A(1:numRowsToMultiply,:)^T * B
    virtual void TransposeMultiply(const double* B, int numColsB, double *C,
				   int numRowsToMultiply) const;

    // C = A*B, where only the rows of A in indexSet are multiplied. The number of
    // rows in the resulting matrix, C, is equal to the number of indices in the
    // index set.
    virtual void IndexedMultiply(const SMAMtxMatrix& B, SMAMtxDenseMatrix& C,
				 const int* indexSet, const int* rangeSet, int numRange) const;

    // A += B, A:mtx; B:mtx;
    void AddAssign(const SMAMtxDenseMatrix& B);


    // A = alpha*A
    void Scale(double alpha);

    bool IsSymmetric() const;
    
    /// Estimates number of row blocks (chunks) to read/write simultaneously
    int NumberOfRowBlocksToIO(int numCols = 0) const;

    /// Set cache size to access matrix values by rows/columns of blocks
    enum SMAMtxAccessType { Unknown, ByColumn, ByRow, Random };
    void SetAccess(SMAMtxAccessType access);
    
    //DEBUG
    bool BlockAllocated(int rowOrigin, int colOrigin) const;

protected:
    /// Sets the persitant storage of the matrix
    void setDistribution(const SMASimDistribution& dist);

    /// Constructor for a submatrix
    SMAMtxDenseMatrix( const SMAMtxDenseMatrix& rhs, 
                       int startRow, int lastRow,
		       int startCol, int lastCol );

			           
private:  
    /// Initializes the internal state. Called by the ctors
    void initializeState();

    /// Unimplemented copy constructor (this class has no copy semantics)
    SMAMtxDenseMatrix(const SMAMtxDenseMatrix& rhs);
    
    /// Unimplemented assignment operator (this class has no assignment semantics)
    SMAMtxDenseMatrix& operator=(const SMAMtxDenseMatrix& rhs);

    /// Extend matrix by specified cset. Return 0 if OK, error code otherwise.
    int ExtendSet( const SMASimCSetID &newCSetID );
    
    /// Helper function for GetValues() and SetValues()
    size_t SetTransferDims(int startRow, int lastRow, int startCol, int lastCol,
                           const SMAMtxMatrix & dimMatrix, SMASimTransfer & transfer) const;
    size_t SetTransferDims(const int * rowNumbers, int numRows,
                           const int * colNumbers, int numCols,
                           const SMAMtxMatrix & dimMatrix, SMASimTransfer & transfer) const;
   
private:	
    SMASimDistribution  m_distribution;

    bool                 m_submatrix;
    int                  m_numRows;
    int                  m_numCols;
    int                  m_numRowBlocks;
    int                  m_numColBlocks;
    int                  m_numRowsPerBlock;
    int                  m_numColsPerBlock;
    int                  m_numRowsInFirstBlock;
    int                  m_numColsInFirstBlock;     
    int                  m_numRowsInLastBlock;
    int                  m_numColsInLastBlock;
    int                  m_rowOffset;
    int                  m_colOffset;    

    SMASimTransfer      *m_transfer;
    SMASimCSetID         m_rowCSetID;
    SMASimCSetID         m_colCSetID;

    size_t               mPreviousCacheSize;
};

#endif
