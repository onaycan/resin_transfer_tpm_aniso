/*   -*- mode: c++ -*-   */
#ifndef inpO_ElsetVisitor_h
#define inpO_ElsetVisitor_h

///////////////////////////////////////////////////////////////////////////////
//
// Name: inpO_ElsetVisitor
//
// Description: create mesh in the database
//

// Includes

// Forward declarations
class inpO_NodeData;
class inpO_AbaqusName;
class inpO_Coord;
class inpM_BaseSet;

class odb_DiscreteEntity;
class odb_Part;
class odb_Instance;
class odb_Node;
class odb_Set;

// Begin local includes
#include <cow_ListInt.h>
#include <inpO_Visitor.h>
#include <inpO_MeshVisitor.h>
#include <inpO_BasicElemTypeData.h>

#include <odb_SequenceNode.h>
#include <odb_SequenceElement.h>
#include <odb_Types.h>


// Class definition

class inpO_ElsetVisitor: public inpO_MeshVisitor
{
public:

   inpO_ElsetVisitor(odb_Odb& odb, inpO_ModelInventory&);
   ~inpO_ElsetVisitor();

   //
   virtual void VisitAssembly(inp_Keyword&);

   virtual void VisitElcopy(inp_Keyword&);
   virtual void VisitElgen(inp_Keyword&);
   virtual void VisitElset(inp_Keyword&);
   virtual void VisitEndAssembly(inp_Keyword&);
   virtual void VisitEndInstance(inp_Keyword&);
   virtual void VisitEndPart(inp_Keyword&);

   virtual void VisitInstance(inp_Keyword&);
   virtual void VisitPart(inp_Keyword&);
};


#endif /* inpO_ElsetVisitor_h */
