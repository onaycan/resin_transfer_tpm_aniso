#ifndef sub_SubstructureSystem_H
#define sub_SubstructureSystem_H

// Begin local includes
#include <cow_Btree.h>
#include <cow_BtreeString2ListInt.h>
#include <cow_ListString.h>
#include <cow_MapInt2String.h>
#include <cow_String.h>
#include <mem_AllocationOperators.h>
#include <SMAMtxDenseMatrix.h>
#include <SMAMtxDenseMatrixBtree.h>
#include <SMAFsmSubstructureSystem.h>
// End local includes

template <class T> class SMABasVector;

COW_BTREE_DECL(cow_String, SMAMtxDenseMatrixPtr, UserMatrixMap);

struct sub_TotalInertia 
{
    double volume;
    double mass[3];
    double momentsOfInertia[3];
    double productsOfInertia[3];
    double centerOfMass[3];
};

class sub_SubstructureSystem: public mem_AllocationOperators
{
public:
    /// Constructor
    sub_SubstructureSystem( const char *subFileName );
    sub_SubstructureSystem( SMAFsmSubstructureSystem system );
    
    /// Destructor
    virtual ~sub_SubstructureSystem();
    
    /// Return true if system is not defined
    bool IsNull() const;

    /// Get dimension and array of element labels (client must delete the array)
    int *ElementLabels( int &numElements ) const;
    void ElementLabels( SMABasVector<int> &labels ) const;
    
    /// Get dimension and array of node labels (client must delete the array)
    int *NodeLabels( int &numNodes ) const;
    void NodeLabels( SMABasVector<int> &labels ) const;

    /// Get nodal coodinates (as a matrix)
    const SMAMtxDenseMatrix & NodeCoordinates() const;
    
    /// Get list of load case names if any
    cow_ListString LoadCaseNames() const;

    /// Get dimension and array of members of cset on substructure (client must delete the array)
    int *CSetMembers( int csetType, int &size ) const;
    int *CSetMembers( int csetType, const char *key, int &size ) const;
    void CSetMembers( SMABasVector<int> &members, int csetType ) const;
    void CSetMembers( SMABasVector<int> &members, int csetType, const char *key ) const;

    /// Get list of cset names
    cow_ListString CSetNames( int csetType ) const;
    
    /// Return number of static modes (retained nodal dofs)
    int NumStaticModes() const;

    /// Return number of dynamic modes (currently eigenmodes)
    int NumDynamicModes() const;

    /// Return number of substructure modes (static + dynamic)
    int NumSModes() const;
    
    /// Return number of substructure loads
    int NumLoads() const;

    /// Check matrix presence
    bool HasMatrix( int matrixType ) const;
    bool HasMatrix( const char *matrixName ) const;
    bool HasRecovery() const; // simplified alias to check Recovery matrix

    /// Access matrix on substructure system
    virtual const SMAMtxDenseMatrix & Matrix( int matrixType ) const;
    virtual const SMAMtxDenseMatrix & Matrix( const char *matrixName ) const;
    
    /// Get list of all user matrix names defined on the system
    cow_ListString MatrixNames() const;
    
    /// Get the substructure system and its position
    SMAFsmSubstructureSystem System() const {return m_system;}
    SMASimPosition MyPosition() const {return m_system.MyPosition();}
    
    /// Get type name for a schema object type
    cow_String TypeName( int objectType ) const;
    
    /// Access/Write total inertia data
    void TotalInertia( sub_TotalInertia & data ) const;
    void WriteTotalInertia( const sub_TotalInertia & data );

    /// Support for nested subsystems
    bool HasNested() const;
    void AddNested( int element, const char *substructureName );
    void SetNested( const cow_BtreeString2ListInt & subElems );
    cow_MapInt2String GetNested() const;
    
protected:    
    SMAFsmSubstructureSystem        m_system;
    mutable SMAMtxDenseMatrixBtree  m_matrices;
    mutable UserMatrixMap           m_userMatrices;

    // Access to matrix pointers (their memory deleted in d-tor!)
    const SMAMtxDenseMatrix *MatrixPtr( int matrixType ) const;
    const SMAMtxDenseMatrix *MatrixPtr( const char *matrixName ) const;

private:
    /// Unimplemented copy constructor and assignment operator - not allowed!
    sub_SubstructureSystem(const sub_SubstructureSystem& rhs);
    sub_SubstructureSystem & operator=(const sub_SubstructureSystem& rhs);

    SMASimPosition          m_simFile;
    mutable SMASimCSetID    m_retainedDofs;
    SMAMtxDenseMatrix       m_dummyMatrix;
};
#endif // sub_ExportToDMIG_H
