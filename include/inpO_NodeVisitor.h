/*   -*- mode: c++ -*-   */
#ifndef inpO_NodeVisitor_h
#define inpO_NodeVisitor_h

///////////////////////////////////////////////////////////////////////////////
//
// Name: inpO_NodeVisitor
//
// Description: create mesh in the database
//

// Includes

// Forward declarations
class inpO_NodeData;
class inpO_AbaqusName;
class inpO_Coord;
class inpM_BaseSet;
class inpM_ElementFaceIdSurface;
class inpM_AssemblyInstanceSurface;
class inpM_PartInstanceSurface;

class odb_DiscreteEntity;
class odb_Part;
class odb_Instance;
class odb_Node;
class odb_Set;

// Begin local includes
#include <cow_ListInt.h>
#include <inpO_MeshVisitor.h>

#include <odb_SequenceNode.h>
#include <odb_SequenceElement.h>
#include <odb_Types.h>


// Class definition

class inpO_NodeVisitor: public inpO_MeshVisitor
{
public:

   inpO_NodeVisitor(odb_Odb& odb, inpO_ModelInventory&);
   ~inpO_NodeVisitor();

   //
   virtual void VisitAssembly(inp_Keyword&);

   virtual void VisitEndAssembly(inp_Keyword&);
   virtual void VisitEndInstance(inp_Keyword&);
   virtual void VisitEndPart(inp_Keyword&);

   virtual void VisitInstance(inp_Keyword&);
   virtual void VisitNcopy(inp_Keyword&);
   virtual void VisitNfill(inp_Keyword&);
   virtual void VisitNgen(inp_Keyword&);
   virtual void VisitNode(inp_Keyword&);
   virtual void VisitNset(inp_Keyword&);
   virtual void VisitPart(inp_Keyword&);
};

#endif /* inpO_NodeVisitor_h */
