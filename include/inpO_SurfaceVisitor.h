/*   -*- mode: c++ -*-   */
#ifndef inpO_SurfaceVisitor_h
#define inpO_SurfaceVisitor_h

///////////////////////////////////////////////////////////////////////////////
//
// Name: inpO_SurfaceVisitor
//
// Description: create mesh in the database
//

// Includes

// Forward declarations
class inpM_ElementFaceIdSurface;
class inpM_AssemblyInstanceSurface;
class inpM_PartInstanceSurface;

class odb_DiscreteEntity;
class odb_Set;

// Begin local includes
#include <cow_ListInt.h>

#include <inpO_MeshVisitor.h>
#include <inpO_AnalyticalRigidSurface.h>
#include <inpO_RigidBody.h>

#include <odb_SequenceNode.h>
#include <odb_SequenceElement.h>
#include <odb_Types.h>


// Class definition

class inpO_SurfaceVisitor: public inpO_MeshVisitor
{
public:

   inpO_SurfaceVisitor(odb_Odb& odb, inpO_ModelInventory&);
   ~inpO_SurfaceVisitor();

   void VisitList(inp_KeywordList&);
   void CreateAnalyticalRigidSurfaces();

   //
   virtual void VisitAssembly(inp_Keyword&);
   virtual void VisitEndAssembly(inp_Keyword&);
   virtual void VisitEndInstance(inp_Keyword&);
   virtual void VisitEndPart(inp_Keyword&);
   virtual void VisitInstance(inp_Keyword&);
   virtual void VisitPart(inp_Keyword&);

   virtual void VisitRigidSurface(inp_Keyword&);
   virtual void VisitSurface(inp_Keyword&);

private:
   // Surfaces
   void UpdateSurfaceWithOdbElementSet(inpM_ElementFaceIdSurface& aSurface,
                                       odb_Set&                   odbSet,
                                       const cow_String& faceId) const;
   void UpdateSurfaceWithOdbElementSet(inpM_AssemblyInstanceSurface& aSurface,
                                       odb_Set&                      odbSet,
                                       const cow_String&             faceId) const;
   void AddComponentSurface(const cow_String&                name, 
                            const inpM_ElementFaceIdSurface& compSurface,
                            bool                             internal = false);
   void AddAssemblySurface(const cow_String&                   name, 
                           const inpM_AssemblyInstanceSurface& assmSurface,
                           bool                                internal = false);
   void ComponentSurface2Data(const odb_DiscreteEntity*       comp,
                              const inpM_PartInstanceSurface& aSurface,
                              odb_SequenceInt&                labels,
                              odb_SequenceElementFace&        faces);
   odb_Enum::odb_ElementFaceEnum FaceName2FaceEnum(const cow_String& elmType, 
                                                   const cow_String& faceName) const;
   odb_SequenceElementFace MakeFaceEnumArray(odb_Enum::odb_ElementFaceEnum fenum, 
                                             int size) const;

   void AddSurface(const cow_String&              name, 
                   const odb_SequenceInt&         labels, 
                   const odb_SequenceElementFace& faces,
                   bool                           internal = false);

   void CreatePartAnalyticalRigidSurface(const inpO_AnalyticalRigidSurface&);

   void CreateInstanceAnalyticalRigidSurface(const cow_String& instanceName, 
                                             const inpO_AnalyticalRigidSurface& rigidSurface);
   void SavePartRigidBody(const cow_String& partName, 
                          const inpO_RigidBody& rigidBody);

   void CreatePartRigidBody(const inpO_RigidBody& rigidBody);
   void CreateInstanceRigidBody(const cow_String& instanceName, 
                                const inpO_RigidBody& rigidBody);
   void CreateAssemblyRigidBody(const inpO_RigidBody& rigidBody);
};

#endif /* inpO_SurfaceVisitor_h */
