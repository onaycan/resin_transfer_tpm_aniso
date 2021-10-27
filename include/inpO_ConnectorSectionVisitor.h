/* -*- mode: c++ -*- */
#ifndef inpO_ConnectorSectionVisitor_h
#define inpO_ConnectorSectionVisitor_h

////////////////////////////////////////////////////////////////////////
//
//  Name: inpO_ConnectorSectionVisitor
//
//  Description: Write connector section data to ODB using ODB API 
//

//
// Begin local includes
//

#include <cow_String.h>
#include <inpO_Visitor.h>
#include <inpO_ConnectorSection.h>
#include <inpO_ConnectorBehavior.h>
#include <inpO_ConnDerivedComponent.h>
#include <inpO_ConnectorFriction.h>
#include <inpO_ConnectorPlasticity.h>
#include <inpO_ConnectorDamage.h>
#include <kseO_ApiExtension.h>
#include <odb_Types.h>
#include <odb_ConnBehaviorTypes.h>

// Forward declaration

// Class definitions
class inpO_ConnectorSectionVisitor: public inpO_Visitor
{ 
public:
    inpO_ConnectorSectionVisitor(odb_Odb& odb, inpO_ModelInventory& modelInv);
    ~inpO_ConnectorSectionVisitor();
    
    void CreateConnectorSectionsInOdb(inp_KeywordList&);

protected:    

    virtual void DefaultAction(inp_Keyword &); // Do nothing
    cow_String MakeConnectorSectionName(const inp_Keyword& keyword);

   // Only the following keywords are processed
    virtual void VisitConnectorSection(inp_Keyword& keyword);
    virtual void VisitConnectorBehavior(inp_Keyword&);
    virtual void VisitConnectorConstitutiveReference(inp_Keyword&);
    virtual void VisitConnectorStop(inp_Keyword&);
    virtual void VisitConnectorLock(inp_Keyword&);
    virtual void VisitConnectorFailure(inp_Keyword&);
    virtual void VisitConnectorElasticity(inp_Keyword&);
    virtual void VisitConnectorDamageInitiation(inp_Keyword&);
    virtual void VisitConnectorDamageEvolution(inp_Keyword&);
    virtual void VisitConnectorDamping(inp_Keyword&);
    virtual void VisitConnectorDerivedComponent(inp_Keyword&);
    virtual void VisitConnectorFriction(inp_Keyword&);
    virtual void VisitConnectorPlasticity(inp_Keyword&);
    virtual void VisitConnectorHardening(inp_Keyword&); // for connector_plasticity
    virtual void VisitConnectorPotential(inp_Keyword&);
    virtual void VisitFriction(inp_Keyword&); // for connector_friction


private:
    void setConnectionType( odb_String& aT, odb_String& rT, odb_String& tT, 
			    const cow_String& comp1, const cow_String& comp2 );
    void fixConnectionTypeString( cow_String& component );
    kseO_ApiExtension                        m_sectApi;
    inpO_ConnectorSectionMap     m_connectorSectionMap;    
    inpO_ConnectorBehaviorMap   m_connectorBehaviorMap;
    inpO_ConnectorDerivedComponentMap         m_CDCMap;
    cow_String                          m_connSectName; // name of the current connector_section being processed.
    cow_String                         m_connBehavName; // name of the current connector_behavior being processed.
    cow_String                         m_connElsetName; // name of the elset associated with the current connector
                                       // section being processed.
    inpO_ConnectorFrictionHld     m_connectorFrictionHld;
    inpO_ConnectorPlasticityHld m_connectorPlasticityHld;
    inpO_ConnectorDamageHld         m_connectorDamageHld;
};

#endif // inpO_ConnectorSectionVisitor_h

