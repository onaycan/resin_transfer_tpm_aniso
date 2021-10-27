/* -*- mode: c++ -*- */
#ifndef inpO_ConnectorFriction_h
#define inpO_ConnectorFriction_h

////////////////////////////////////////////////////////////////////////
//
//  Name: inpO_ConnectorFriction
//
//  Description: Collect keyword data to define a connector_friction 
//  object in the ODB 

// Forward declaration
class inpO_ConnectorSectionVisitor;
class inp_Keyword;
//
// Begin local includes
#include <mem_AllocationOperators.h>
//
#include <cow_CountedHld.h>

#include <inpO_ConnDerivedComponent.h>
#include <inpO_ConnTangentialBehavior.h>
#include <odb_String.h>
#include <odb_Types.h>
#include <odb_ConnBehaviorTypes.h>


class inpO_ConnectorFriction  : public mem_AllocationOperators
{
    friend class inpO_ConnectorSectionVisitor;
public:
    inpO_ConnectorFriction();

    void Read( const inp_Keyword& keyword,
               const inpO_ConnectorDerivedComponentMap& dcMap );
    void ReadFriction( const inp_Keyword& keyword ); // TangentialBehavior
    void ReadFrictionConnectorPotential( const inp_Keyword& keyword,
                                         const inpO_ConnectorDerivedComponentMap& dcMap );
    bool HasDerivedComponent() const;
    odb_ConnectorFriction Create() const;

private:
    odb_String frictionModel;
    odb_String slipStyle;
    odb_Union tangentDirection;
    odb_Union stickStiffness;
    odb_String componentType;
    bool slipDependency;
    bool temperatureDependency;
    int dependencies;
    bool useContactForceComponent;
    odb_String contactForceStyle;
    int contactForceComponent;
    odb_String forcePotentialOperator;
    double forcePotentialExponent;
    kbeO_SequenceConnectorPotential connectorPotentials;
    odb_SequenceSequenceDouble dataTable;
    odb_SequenceInt indepComps;
    inpO_ConnectorTangentialBehaviorHld tangentialBehavior; 
    inpO_ConnectorDerivedComponent derivedComponent; 
};


COW_COUNTEDHLD_DECL(inpO_ConnectorFriction, inpO_ConnectorFrictionHld)


#endif // inpO_ConnectorFriction_h

