#ifndef uma_System_h
#define uma_System_h
///
/// Base class for access to SIM FE System
///
#include <vector>

// Begin local includes
#include <mem_AllocationOperators.h>
#include <omi_BlkBitVect.h>
#include <uma_Enum.h>
// End local includes

// Forward declarations
class SMASimCSetID;
class SMASimDistributionID;
class SMAMtxDenseMatrix;
class SMAFsmSystem;
class uma_ArrayInt;
class uma_Matrix;
class uma_EbeMatrix;

///////////////////////////////////////////////////////////////////////////////
///
/// Base class for FE System of any type 
///
///////////////////////////////////////////////////////////////////////////////

class uma_System : public mem_AllocationOperators
{
public: // Public documented API

    /// Constructor(s)
    uma_System( const char * systemFileName, bool edit = false );

    /// Check if system is defined
    bool IsNull() const;
    
    /// Return type of the system: ads_GenericSystem, ads_ModalSystem, ads_SusbtructureSystem
    int Type() const;

    /// Map cset to nodes, dofs, etc. (client should delete the pointer when done)
    uma_ArrayInt * MapCSet( int csetType, uma_Enum::uma_MapTypeEnum mapType ) const;
    /// Map cset to nodes, dofs, etc. (STL vector API)
    void MapCSet( std::vector<int> & vector, int csetType, uma_Enum::uma_MapTypeEnum mapType ) const;
    
    /// Check if matrix exist
    bool HasMatrix( int matrixType ) const;
    bool HasMatrix( const char * matrixName ) const;

    /// Access matrix for read (client should delete the pointer when done)
    /// Optional skip mask to filter rows/columns
    const uma_Matrix * Matrix( int matrixType, int skipMask = 0 ) const;
    const uma_Matrix * Matrix( const char * matrixName, int skipMask = 0 ) const;

    /// Get EBE matrix
    void GetEbeMatrix( uma_EbeMatrix & matrix, int matrixType ) const;
    void GetEbeMatrix( uma_EbeMatrix & matrix, const char * matrixName ) const;

///////////////////////////////////////////////////////////////////////////////
private:
    SMAFsmSystem *m_system;
    bool m_edit;
    
    void Open( const char * systemFileName );
    const uma_Matrix * MakeMatrix( SMASimDistributionID distID, int skipMask ) const;
    void MakeEbeMatrix( uma_EbeMatrix & matrix, SMASimDistributionID distID ) const;
    omi_BlkBitVect InternalNodes() const;
    omi_BlkBitVect RetainedDofs() const;

public: // Internal, undocumented, not to be used explicitly by client
    virtual ~uma_System();
    const SMAFsmSystem & System() const;
    /// Map c-set members  (client should delete the pointer when done)
    uma_ArrayInt *MapCSet( SMASimCSetID setID, uma_Enum::uma_MapTypeEnum type ) const;
    void MapCSet( std::vector<int> & vector, SMASimCSetID setID, uma_Enum::uma_MapTypeEnum type ) const;
    /// Number of loads on the system
    int NumLoads() const;
    /// Number of static modes (== retained nodal dofs)
    int NumStaticModes() const;
    /// Get matrix for edit (client should delete the pointer when done)
    uma_Matrix * GetMatrix( int matrixType );
    uma_Matrix * GetMatrix( const char * matrixName );
};

#endif //uma_System_h
