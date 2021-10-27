#ifndef odb_Set_h
#define odb_Set_h

// Begin local includes
#include <mem_AllocationOperators.h>
#include <odb_Enum.h>
#include <odb_SequenceNode.h>
#include <odb_SequenceElement.h>
#include <odb_SequenceSequenceElement.h>
#include <odb_SequenceSequenceNode.h>
#include <odb_MeshList.h>

#include <odiC_Enums.h>
// End local includes


// Forward Declarations
class ddb_Set;
COW_COW_DECL(ddb_Set);
class rgnC_SubsetData;

class odb_Set : public mem_AllocationOperators
{
public:
    // member access
    odb_String name() const;
    bool isInternal() const;
    int size() const;
    odb_Enum::odb_SetTypeEnum type() const; 
    odb_SequenceString instanceNames() const;
    // data for instance sets
    odb_Enum::odb_ElementFaceEnum face(int index);
    const odb_SequenceNode& nodes() const;
    const odb_SequenceElement& elements() const;
    const odb_SequenceElementFace& faces() const;

    // data for assembly sets
    const odb_SequenceNode& nodes(const odb_String& instanceName) const;
    const odb_SequenceElement& elements(const odb_String& instanceName) const;
    const odb_SequenceElementFace& faces(const odb_String& instanceName) const;

private:

    ddb_SetCOW   m_set;
    bool m_init;
    bool         m_isAssemblySet;
    bool         m_isRigidBodySet;//reference_node_set for a rigid body
    odb_String   m_name;
    odb_MeshList m_meshList;  
    odb_SequenceSequenceElement     m_elCon;
    odb_SequenceSequenceNode        m_nCon;
    odb_SequenceSequenceElementFace m_faces;

    void Init();
    void ReadNodes();
    void ReadElements();
    void ReadFaces();

    odb_SequenceInt SetIndicesFromSubSetIndices(const rgnC_SubsetData& subset) const;


public: // undocumented and unsupported
    odb_Set();
    odb_Set( const odb_String& name,
             const ddb_Set& set,
             const odb_MeshCOW& m,
             bool isRigidBodySet = false );
    odb_Set( const odb_String& name,
             const ddb_Set& set,
             const odb_MeshList& ml,
             bool isRigidBodySet = false );

    ddb_Set set() const;
    const odb_MeshList& MeshList() const;

    bool isAssemblySet() const {return m_isAssemblySet;}
    bool isRigidBodySet() const {return m_isRigidBodySet;}
    bool isUnsorted() const;

    void summaryValue1( odb_String & ) const {};
    void summaryValue2( odb_String & ) const {};

    // utility
    odb_SequenceInt SubsetUserLabels( int subsetIndex ) const;
    void refreshMeshObject() const;

   void addLabels(const odb_SequenceInt& labels, 
                  bool internal = false, 
                  bool unsorted = false);
   void addSurfaceLabels(const odb_SequenceInt& labels, 
                         const odb_SequenceElementFace faces,
                         bool internal = false);
   void resetItemInit();
};

#endif // odb_Set_h
