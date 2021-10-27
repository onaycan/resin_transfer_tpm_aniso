#ifndef sub_FlexibleBodyX_H
#define sub_FlexibleBodyX_H

// Begin local includes
#include <sub_SubstructureSystem.h>
// End local includes

class SMAMtxDenseMatrix;

class sub_FlexibleBodyX: public sub_SubstructureSystem
{
public:
    /// Constructor
    sub_FlexibleBodyX( const char *subFileName );
    
    /// Destructor
    virtual ~sub_FlexibleBodyX();
    
    /// Access matrix on substructure system
    const SMAMtxDenseMatrix &Matrix( int matrixType );
    const SMAMtxDenseMatrix &Matrix( const char *matrixName );
    
    /// Access node labels for all the nodes
    /// Nodes() returns an array of the node lables and the number of nodes in the FE model
    const int *FENodes( int &numFENodes ) const;
    
    /// Access a list nodes in a-set (correspond to M1AA matrix columns)
    /// Returns an array of the node lables and the number of nodes in a-set
    /// (including modal coordinates)
    /// Returned value of numNodesInASet is the number of nodes in a-set
    const int *NodesInASet( int &numNodesInASet ) const;
    
    /// Access a-set nodes/dofs
    /// ASetNodes() returns an array of the node lables for members of a-set
    /// ASetDofs()  returns an array of the dof lables for members of a-set (0 for modal coordinates)
    /// Returned value of aSetSize is the number of members in a-set
    const int *ASetNodes( int &aSetSize ) const;
    const int *ASetDofs( int &aSetSize ) const;

    /// Access recovery-set nodes/dofs (recovery-set is a subset of o-set)
    /// RecoverySetNodes() returns an array of the node lables for members of recovery-set
    /// RecoverySetDofs()  returns an array of the dof lables for members of recovery-set
    /// Returned value of recoverySetSize is the number of members in recovery-set 
    const int *RecoverySetNodes( int &recoverySetSize ) const;
    const int *RecoverySetDofs( int &recoverySetSize) const;
    
    /// Access GFAA-set nodes/dofs
    /// GFAA-set is a subset of translational dofs in o-set which belong to the nodes 
    /// with at least one retained translational dof (translational dof in a-set)
    /// GFAASetNodes() returns an array of the node lables for members of GFAA-set
    /// GFAASetDofs()  returns an array of the dof lables for members of GFAA-set
    /// Returned value of gfaaSetSize is the number of members in GFAA-set (gfaaSetSize=naa)    
    const int *GFAASetNodes( int &gfaaSetSize ) const;
    const int *GFAASetDofs( int &gfaaSetSize ) const;
    
private:    
    
    int m_numFENodes;
    int *m_feNodes;
    
    int m_numNodesInASet;
    int *m_nodesInASet;

    int m_aSetSize;
    int *m_aSetNodes;
    int *m_aSetDofs;
        
    int m_recoverySetSize;
    int *m_recoverySetOrdinals;
    int *m_recoverySetNodes;
    int *m_recoverySetDofs;
    
    int m_gfaaSetSize;
    int *m_gfaaSetNodes;
    int *m_gfaaSetDofs;
    
//  Private functions    
    void RecoveryMatrix();    
    void defineRecoverySet();
    void LumpedMassMatrix();
    void NodeCoordinatesMatrix();
    
};
#endif // sub_FlexibleBodyX_H
