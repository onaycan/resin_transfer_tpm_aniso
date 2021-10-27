#ifndef odb_SurfaceSubset_h
#define odb_SurfaceSubset_h

// Begin local includes
#include <mem_AllocationOperators.h>
#include <odb_Enum.h>
#include <odb_SequenceNode.h>
#include <odb_SequenceElement.h>
#include <odb_Mesh.h>

// End local includes


// Forward Declarations
class ddb_Subset;
COW_COW_DECL(ddb_Subset);

class odb_SurfaceSubset : public mem_AllocationOperators
{
friend class odb_Set;

public:

private:
    ddb_SubsetCOW   SubSet;
    odb_MeshCOW     Mesh;  
    bool            Init;
    odb_SequenceElement     ElCon;
    odb_SequenceElementFace FaceCon;
    odb_SequenceNode        NodeCon;

    void ReadFaces();

public: // undocumented and unsupported

    // constructors
    odb_SurfaceSubset(const ddb_Subset& set, const odb_MeshCOW& m);

    // member access
    int size() const;
    const odb_SequenceElement& elements() ;
    const odb_SequenceElementFace& faces() ;
    const odb_SequenceNode& nodes();

    const ddb_Subset& set() const;
    const odb_Mesh& mesh() const;

};

#endif // odb_SurfaceSubset_h
