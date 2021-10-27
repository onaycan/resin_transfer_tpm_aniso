#ifndef SMAFsmSystem_h
#define SMAFsmSystem_h

// Begin local includes
#include <SMASimPosition.h>
#include <mem_AllocationOperators.h>
// End local includes

// Forward declarations
class CATString;
class SMASimDistributionID;

///
/// Base class for FE System
///
class SMAFsmSystem : public mem_AllocationOperators
{
public:
    /// Create an empty system.
    SMAFsmSystem();

    /// Create a system given the position of the system record.
    SMAFsmSystem(const SMASimPosition & system);

    virtual ~SMAFsmSystem();

    /// Return the position of the system
    SMASimPosition MyPosition() const;

    /// Return true if we are not on a valid position.
    bool IsNull() const;

    /// Type of the system: ads_GenericSystem, ads_ModalSystem, ads_SusbtructureSystem
    int Type() const;

    ///------------------------------------------------------------------------
    /// Set methods - mutators

    /// Associate with the results record. Remove existing association.
    void SetResults(const SMASimPosition & target);

    /// Associate with the task record. Remove existing association.
    void SetTask(const SMASimPosition & target);

    /// Associate with the mesh record. Remove existing association.
    void SetMesh(const SMASimPosition & target);

    /// Set a collection based on association name
    void SetCollection(int association, const SMASimCollectionID & target);

    /// Set a c-set based on association name
    void SetCSet(int association, const SMASimCSetID & target);

    /// Set a distribution based on association name
    void SetDistribution(int association, const SMASimDistributionID & target);

    /// Set distribution as a user matrix
    void SetUserMatrix(const CATString &key, const SMASimDistributionID & target);
    void SetUserMatrix(const char *key, const SMASimDistributionID & target);

    ///------------------------------------------------------------------------
    /// Get methods - accessors
    
    /// Return the results record
    SMASimPosition Results() const;

    /// Return the task record
    SMASimPosition Task() const;

    /// Return the mesh record
    SMASimPosition Mesh() const;

    /// Generic collection accessor based on association symbolic constant
    SMASimCollectionID Collection(int association) const;

    /// Generic c-set accessor based on association symbolic constant
    SMASimCSetID CSet(int association) const;
    SMASimCSetID CSet(int association, const CATString &key) const;
    SMASimCSetID CSet(int association, const char *key) const;
    
    /// Generic distribution accessor based on association symbolic constant
    SMASimDistributionID Distribution(int assocciation) const;
    
    /// Generic distribution accessor based on association string name
    SMASimDistributionID Distribution(const CATString &assocciation) const;
    SMASimDistributionID Distribution(const char *asocciation) const;

    /// Retrieve a user matrix distribution by key name
    SMASimDistributionID UserMatrix(const CATString &key) const;
    SMASimDistributionID UserMatrix(const char *key) const;

    /// Retrieve the load cses c-set
    SMASimCSetID       Cases() const;
    
    /// Retrieve the mode collection
    SMASimCollectionID ModeCollection() const;

    /// Retrieve the dof types collection from Focus
    SMASimCollectionID DofTypes() const;

    /// Retrieve the complex number types collection from Focus.
    SMASimCollectionID ComplexNumberPart() const;

    /// Retrieve the component collection from Focus.
    SMASimCollectionID Components() const;

    ///------------------------------------------------------------------------
    /// Accessors from Mesh

    SMASimCSetID         Dofs() const; // analysis dofs

    SMASimDSetID         NodalDofTypes() const; // [nodes x dof type]
    
    SMASimDistributionID NodeCoordinates() const;
    
    SMASimCollectionID   NodeCollection() const;
    SMASimCSetID         Nodes() const;

    SMASimCollectionID   ElementCollection() const;
    SMASimCSetID         Elements() const;

    SMASimDSetID         NestedSubmodels() const; // [elements x occurrences]

protected:
    SMASimPosition m_pos;
    
    void CheckAndRemove(int type, int member);
};

#endif

