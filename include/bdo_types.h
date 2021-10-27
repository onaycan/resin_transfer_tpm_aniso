// bdo_types.h
#if !defined(bdo_types_h)
#define bdo_types_h

// Begin local includes
#include <omi_types.h>
#include <omu_PrimEnum.h>

typedef uint bdo_Id;

enum bdo_Type {
  bdo_TypeAssembly = 128,
  bdo_TypeGeomPart,
  bdo_TypePartInstance,
  bdo_TypeMeshPart,
  bdo_TypeOdb,
  bdo_TypeNone
};

typedef omu_PrimEnum<bdo_Type,1> bdo_TypeConst;

enum bdo_Space {
    bdo_3D_Space = 2000,
    bdo_2D_Space,
    bdo_Axisymmetric_Space,
    bdo_Unknown_Space
};

typedef omu_PrimEnum<bdo_Space,3> bdo_SpaceConst;

enum bdo_Analysis {
    bdo_Unknown_Analysis = 4000,
    bdo_DeformableBody_Analysis,
    bdo_DiscreteRigidSurface_Analysis,
    bdo_AnalyticRigidSurface_Analysis,
    bdo_Eulerian_Analysis
};

typedef omu_PrimEnum<bdo_Analysis,3> bdo_AnalysisConst;


#endif /* bdo_types_h */
