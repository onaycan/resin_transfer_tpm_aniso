/*   -*- mode: c++ -*-   */
#ifndef inpO_ElementVisitor_h
#define inpO_ElementVisitor_h

///////////////////////////////////////////////////////////////////////////////
//
// Name: inpO_ElementVisitor
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
#include <inpO_Visitor.h>
#include <inpO_MeshVisitor.h>
#include <inpO_BasicElemTypeData.h>

#include <odb_SequenceNode.h>
#include <odb_SequenceElement.h>
#include <odb_Types.h>


// Class definition

class inpO_ElementVisitor: public inpO_MeshVisitor
{
public:

   inpO_ElementVisitor(odb_Odb& odb, inpO_ModelInventory&);
   ~inpO_ElementVisitor();

   //
   virtual void VisitAssembly(inp_Keyword&);

   virtual void VisitElement(inp_Keyword&);
   virtual void VisitEndAssembly(inp_Keyword&);
   virtual void VisitEndInstance(inp_Keyword&);
   virtual void VisitEndPart(inp_Keyword&);

   virtual void VisitInstance(inp_Keyword&);
   virtual void VisitPart(inp_Keyword&);
};


#endif /* inpO_ElementVisitor_h */
