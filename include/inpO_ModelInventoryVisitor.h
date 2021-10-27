/*   -*- mode: c++ -*-   */
#ifndef inpO_ModelInventoryVisitor_h
#define inpO_ModelInventoryVisitor_h

///////////////////////////////////////////////////////////////////////////////
//
// Name: inpO_ModelInventoryVisitor
//
// Description: set model parameters
//

// Includes

// Forward declarations
class inpO_ModelInventory;
class inpO_PartInventory;

// Begin local includes
#include <inpO_MessageContainer.h>
#include <inp_Visitor.h>
#include <odb_Enum.h>

// Class definition

class inpO_ModelInventoryVisitor: public inp_Visitor, public inpO_MessageContainer
{
  public:

   inpO_ModelInventoryVisitor(inpO_ModelInventory&);
   ~inpO_ModelInventoryVisitor();

   virtual void VisitList(inp_KeywordList&);
   virtual void DefaultAction(inp_Keyword&);

  private:

   bool InPart() const;
   bool InInstance() const;

   void CheckCoordinateDimension(const inp_Keyword&, inpO_PartInventory&);

   void UpdateElementTheory(const inp_Keyword&, inpO_PartInventory&);
   void UpdateElementDimension(inpO_PartInventory&, odb_Enum::odb_DimensionEnum);
   void UpdateElementType(inpO_PartInventory&, odb_Enum::odb_PartTypeEnum);

   virtual void VisitAssembly(inp_Keyword&);
   virtual void VisitDynamic(inp_Keyword&);
   virtual void VisitDynamicTemperatureDisplacement(inp_Keyword&);

   virtual void VisitElement(inp_Keyword&);

   virtual void VisitEndAssembly(inp_Keyword&);
   virtual void VisitEndInstance(inp_Keyword&);
   virtual void VisitEndPart(inp_Keyword&);

   virtual void VisitHeading(inp_Keyword&);

   virtual void VisitInstance(inp_Keyword&);
   virtual void VisitNode(inp_Keyword&);

   virtual void VisitPart(inp_Keyword&);
   virtual void VisitRigidBody(inp_Keyword&);
   virtual void VisitSurface(inp_Keyword&);

   // data
   inpO_ModelInventory& m_inventory;
   inpO_PartInventory*  m_partOrInstInv;
};



#endif /* inpO_Visitor_h */
