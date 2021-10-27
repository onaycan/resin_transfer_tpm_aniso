/* -*- mode: c++ -*- */
#ifndef inpO_ConnectorPlasticity_h
#define inpO_ConnectorPlasticity_h

////////////////////////////////////////////////////////////////////////
//
//  Name: inpO_ConnectorPlasticity
//
//  Description: Collect keyword data to define a connector_plasticity 
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
#include <odb_String.h>
#include <odb_Types.h>
#include <odb_ConnBehaviorTypes.h>


class inpO_ConnectorPlasticity  : public mem_AllocationOperators
{
    friend class inpO_ConnectorSectionVisitor;
public:
    inpO_ConnectorPlasticity();

    void Read( const inp_Keyword& keyword );
    void ReadHardening( const inp_Keyword& keyword );
    void ReadPlasticity( const inp_Keyword& keyword ); // TangentialBehavior
    void ReadPotential( const inp_Keyword& keyword ); // ConnectorPotential
    void ReadPlasticityConnectorPotential( const inp_Keyword& keyword,
                                         const inpO_ConnectorDerivedComponentMap& dcMap );
    odb_ConnectorPlasticity Create() const;

private:
    odb_String coupling;
    bool isotropic;
    odb_String isotropicType;
    bool isotropicTemperature;
    int isotropicDependencies;
    bool kinematic;
    odb_String kinematicType;
    bool kinematicTemperature;
    int kinematicDependencies;
    odb_String forcePotentialOperator;
    double forcePotentialExponent;
    odb_SequenceConnectorPotential connectorPotentials;
    odb_SequenceSequenceDouble isotropicTable;
    odb_SequenceSequenceDouble kinematicTable;
    odb_SequenceInt components;

};


COW_COUNTEDHLD_DECL(inpO_ConnectorPlasticity, inpO_ConnectorPlasticityHld)


#endif // inpO_ConnectorPlasticity_h

