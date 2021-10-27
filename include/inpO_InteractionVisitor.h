/*   -*- mode: c++ -*-   */
#ifndef inpO_InteractionVisitor_h
#define inpO_InteractionVisitor_h

///////////////////////////////////////////////////////////////////////////////
//
// Name: inpO_InteractionVisitor
//
// Description: create mesh in the database
//

// Includes

// Forward declarations

class odb_DiscreteEntity;
class odb_Set;

// Begin local includes
#include <cow_ListInt.h>

#include <inpO_Visitor.h>
#include <odb_Odb.h>
#include <odb_SequenceNode.h>
#include <odb_SequenceElement.h>
#include <odb_Types.h>


// Class definition

class inpO_InteractionVisitor: public inpO_Visitor
{
public:

   inpO_InteractionVisitor(odb_Odb& odb, inpO_ModelInventory&);
   ~inpO_InteractionVisitor();
  void CreateInteractionsInOdb( inp_KeywordList& kwList );
  //  void CreateInteractionPropertiesInOdb( inp_KeywordList& kwList );

protected: // methods
    virtual void DefaultAction(inp_Keyword & ); // Do nothing

    odb_Odb& m_odb;
  //    odb_InteractionCOW m_interactionCOW;
    odb_String m_analysisType;

private: 
  //   void VisitListAndReport(inp_KeywordList&);

   //
  virtual void VisitContact(inp_Keyword&);
  virtual void VisitContactPair(inp_Keyword&);
  virtual void VisitSurfaceInteraction(inp_Keyword&);
  virtual void VisitFriction(inp_Keyword&);
  virtual void VisitChangeFriction(inp_Keyword&);


  cow_String IPName;

};

#endif /* inpO_InteractionVisitor_h */
