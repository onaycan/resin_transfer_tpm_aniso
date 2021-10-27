#ifndef uma_FlexibleBodyX_h
#define uma_FlexibleBodyX_h
///
/// Wrapper class for Flexible Body X.
/// Duplicate sub_FlexibleBodyX functionality via uma api.
///

// Begin local includes
#include <uma_System.h>
// End local includes

// Forward declarations
class uma_ArrayInt;


class uma_FlexibleBodyX : public uma_System
{
public: // Public documented API
    
    /// Contstructor
    uma_FlexibleBodyX( const char *subFileName );
    
    /// Access sets (client should delete the pointer when done)
    uma_ArrayInt * FENodes();
    uma_ArrayInt * NodesInASet();
    uma_ArrayInt * ASetNodes();
    uma_ArrayInt * ASetDofs();
    uma_ArrayInt * GFAASetNodes();
    uma_ArrayInt * GFAASetDofs();
    /// Access sets (STL vector API)
    void FENodes     ( std::vector<int> & vector );
    void NodesInASet ( std::vector<int> & vector );
    void ASetNodes   ( std::vector<int> & vector );
    void ASetDofs    ( std::vector<int> & vector );
    void GFAASetNodes( std::vector<int> & vector );
    void GFAASetDofs ( std::vector<int> & vector );

    /// Access matrices (client should delete the pointer when done)
    const uma_Matrix * Matrix( int matrixType );
    const uma_Matrix * Matrix( const char *matrixName );

public: // Internal, undocumented, not to be used explicitly by client
    ~uma_FlexibleBodyX();
};

#endif // uma_FlexibleBodyX_H
