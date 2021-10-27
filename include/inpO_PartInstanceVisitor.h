/*   -*- mode: c++ -*-   */
#ifndef inpO_PartInstanceVisitor_h
#define inpO_PartInstanceVisitor_h

///////////////////////////////////////////////////////////////////////////////
//
// Name: inpO_PartInstanceVisitor
//
// Description: create mesh in the database
//

// Includes

// Forward declarations


// Begin local includes
#include <inpO_Visitor.h>
#include <odb_Types.h>


// Class definition

class inpO_PartInstanceVisitor: public inpO_Visitor
{
public:

   inpO_PartInstanceVisitor(odb_Odb& odb, inpO_ModelInventory&);
   ~inpO_PartInstanceVisitor();

   //
   virtual void VisitAssembly(inp_Keyword&);
   virtual void VisitEndAssembly(inp_Keyword&);
   virtual void VisitEndInstance(inp_Keyword&);

   virtual void VisitInstance(inp_Keyword&);
};

#endif /* inpO_PartInstanceVisitor_h */
