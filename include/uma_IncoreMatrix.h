#ifndef uma_IncoreMatrix_h
#define uma_IncoreMatrix_h
///
/// Class for in-core custom matrix of small size.
///

// Begin local includes
#include <uma_Matrix.h>
// End local includes

// Forward declarations
class SMAMtxMatrix;

class uma_IncoreMatrix : public uma_Matrix
{
public: // Public, documented API

    /// Constructor(s)
    uma_IncoreMatrix();
    uma_IncoreMatrix( int numRows, int numColumns, double value );
    uma_IncoreMatrix( int numRows, int numColumns, double * values = NULL );

    /// All the methods from the basic class...

    /// Direct access to matrix values buffer
    double * Values();
    const double * Values() const;

    /// Matrix value by indices
    double value(int r, int c) const;
    double & value(int r, int c);

    /// Set values
    void SetValues( double value );
    void SetValues( const double * values );
    void SetValues( int startRow, int endRow, int startCol, int endCol,
                    const double * values );
    void SetValues( int startRow, int endRow, int startCol, int endCol,
                    const uma_IncoreMatrix & matrix );

    // Reset matrix
    void Reset();
    void Reset( int numRows, int numColumns, double value );
    void Reset( int numRows, int numColumns, double * values = NULL );

private:

public: // Undocumented, not to be used explicitly by user
    /// Constructor(s)
    uma_IncoreMatrix( SMAMtxMatrix * matrix );
};

#endif //uma_IncoreMatrix_h
