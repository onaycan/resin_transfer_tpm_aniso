#ifndef SMAMtxMatrix_h
#define SMAMtxMatrix_h

/* Begin local includes */
#include <mem_AllocationOperators.h>
/* End local includes  */

class SMAMtxDenseMatrix;

class SMAMtxMatrix : public mem_AllocationOperators
{
public:
    /// Constructors
    SMAMtxMatrix(int numRows,     // Size of 1st dimension
                 int numColumns,  // Size of 2nd dimension
                 double* array=0, // Pre-allocated array (optional) 
                 bool isSymmetric=false,
                 bool isDiagonal=false);  

    SMAMtxMatrix(const SMAMtxMatrix &rhs); // Construct a copy
    
    SMAMtxMatrix(); // Construct a null matrix

    ~SMAMtxMatrix();
    
    void Reset();   // Reset to null matrix
    
    void Reset( int numRows,        // Size of 1st dimension
                int numColumns,     // Size of 2nd dimension
                double * array = 0, // Pre-allocated array (optional) 
                bool isSymmetric = false,
                bool isDiagonal = false);  

    bool IsNull()    const {return m_array;}
    bool operator!() const {return m_array;}
    
    int NumberOfRows()    const { return m_dim1; }
    int NumberOfColumns() const { return m_dim2; }
    bool IsDiagonal()     const { return m_isDiagonal; }
    bool IsSymmetric()    const { return m_isSymmetric; }

    void SetValues(int startRow, int lastRow, int startCol, int lastCol, 
                   const double* array);    
    void SetValues(int startRow, int lastRow, int startCol, int lastCol, 
                   const SMAMtxMatrix& dimMatrix);    
    void SetRows(int startRow, int lastRow, SMAMtxMatrix& dMatrix);  

    void GetValues(int startRow, int lastRow, int startCol, int lastCol, SMAMtxMatrix& dimMatrix) const;    
    void GetRows(int startRow, int lastRow, SMAMtxMatrix& dMatrix) const;        

    void SetDiagonal( const SMAMtxMatrix& dMatrix );
    void SetDiagonal( const double *diag );

    // this will replace the matrix data with its factorization
    void Factorize(int* pivots);

    // used to solve a system of equations that was previously
    // factorized with the Factorize method
    //
    // if transpose == true, this will execute  rhs <- inverse(A^T) * rhs
    //
    void ForwardBackwardPass(const int* pivots, SMAMtxMatrix& rhs,
                             bool transpose = false) const;
    
    /// Solve generalized eigenvalue problem A*x=(lambda)*B*x
    void SolveEigenproblemSymmetric(const SMAMtxMatrix& B, SMAMtxMatrix& Lambda, SMAMtxMatrix& X);    
    
    // A = A + a*B
    void Add(double a,const SMAMtxMatrix& B);
    // A = b*B + c*C
    void Add(double b,const SMAMtxMatrix& B, double c,const SMAMtxMatrix& C);
    void Add(double a,const SMAMtxDenseMatrix& B);

    // A(firstRow,firstCol) = a*B;  set a part(slice) of A
    void SetSlice(double a, const SMAMtxMatrix& B, const int firstRow,
                  const int firstCol);
    // A(firstRow,firstCol) += a*B;  set a part(slice) of A
    void AddSlice(double a, const SMAMtxMatrix& rhs, const int firstRow, 
                  const int firstCol);
    
    // permute rows of matrix A(permVector,:) = A
    void PermuteRowsInPlace(const int *permVector, const int permLength);

    void Transpose();

    /// Multiply matrix with a scalar factor:  A = factor*A
    void Multiply(double factor);    
    
    /// Multiply matrix with a matrix: C=A*B (A - this matrix)
    void Multiply( const SMAMtxMatrix& B, SMAMtxMatrix& C, int symFlag, int addFlag ) const;
    
    //  C = A*B
    void Multiply(const SMAMtxMatrix& A, const SMAMtxMatrix& B);

    // C = A*B
    void SymmetricMultiply(const SMAMtxMatrix& A,const SMAMtxMatrix& B);
    
    /// Calculate C=A^T*B, where A is this matrix
    void TransposeMultiply( const SMAMtxMatrix& B, SMAMtxMatrix& C, int symFlag = 0, int addFlag = 0 ) const;

    /// Set symmetric results from L to U or from U to L
    void SetSymmetricResults();
    
    /// Set skew symmetric results from L to U or from U to L
    void SetSkewSymmetricResults();

    /// C = (1-a)*A + a*B
    void Interpolate(double a,const SMAMtxMatrix& A,const SMAMtxMatrix& B);

    /// A = A*B  or x = B*x
    SMAMtxMatrix& operator*= (const SMAMtxMatrix& B);
    
    /// A += B
    SMAMtxMatrix& operator+= ( const SMAMtxMatrix& rhs );
    
    /// Assignment operator
    SMAMtxMatrix& operator= (const SMAMtxMatrix&);
    SMAMtxMatrix& operator= (double);
    
    /// ==
    bool operator== (const SMAMtxMatrix& rhs) const;
    bool operator== (double rhs) const;

    /// Return the data buffer
    const double *constPtr() const {return m_array;}
    double *getPtr() {return m_array;}

    /// Return the data buffer value
    double operator[](int i) const {return m_array[i];}
    double & operator[](int i) {return m_array[i];}

    /// Return the matrix value by indices
    double get(int r, int c) const {return m_array[r + c*m_dim1];}
    double & get(int r, int c) {return m_array[r + c*m_dim1];}
    
    /// Check numerically if this matrix is symmetric
    bool IsSymmetricNumerically() const;

private:
    // Constructor intialization method
    double* AllocateArray(int, int, double*, bool);

    double  *m_array;

    int      m_dim1;
    int      m_dim2;

    bool     m_ownMem;
    bool     m_isSymmetric;
    bool     m_isDiagonal;
};


#endif
