/*   -*- mode: c++ -*-   */
#ifndef inpO_RigidBodyVisitor_h
#define inpO_RigidBodyVisitor_h

///////////////////////////////////////////////////////////////////////////////
//
// Name: inpO_RigidBodyVisitor
//
// Description: create mesh in the database
//

// Includes

// Forward declarations

// Begin local includes
#include <inpO_MeshVisitor.h>
#include <inpO_RigidBody.h>


// Class definition

class inpO_RigidBodyVisitor: public inpO_MeshVisitor
{
public:

   inpO_RigidBodyVisitor(odb_Odb& odb, inpO_ModelInventory&);
   ~inpO_RigidBodyVisitor();

   //
   virtual void VisitRigidBody(inp_Keyword&);
   virtual void VisitRigidSurface(inp_Keyword&);

private:
   void CreateRigidBody(const inpO_RigidBody& rigidBody);
   void CreatePartRigidBody(const inpO_RigidBody& rigidBody);
   void CreateAssemblyRigidBody(const inpO_RigidBody& rigidBody);
};

#endif /* inpO_RigidBodyVisitor_h */
