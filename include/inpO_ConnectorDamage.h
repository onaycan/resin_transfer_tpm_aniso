/* -*- mode: c++ -*- */
#ifndef inpO_ConnectorDamage_h
#define inpO_ConnectorDamage_h

////////////////////////////////////////////////////////////////////////
//
//  Name: inpO_ConnectorDamage
//
//  Description: Collect keyword data to define a connector_damage 
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


class inpO_ConnectorDamage  : public mem_AllocationOperators
{
    friend class inpO_ConnectorSectionVisitor;
public:
    inpO_ConnectorDamage();

    void Read( const inp_Keyword& keyword );
    void ReadEvolution( const inp_Keyword& keyword ); // evolution behavior
    void ReadInitiationPotential( const inp_Keyword& keyword,
                                  const inpO_ConnectorDerivedComponentMap& dcMap );
    void ReadEvolutionPotential( const inp_Keyword& keyword,
                                 const inpO_ConnectorDerivedComponentMap& dcMap );
    // ConnectorPotential
    odb_ConnectorDamage Create() const;

private:
    odb_String coupling;
    odb_String criterion;
    bool initiationTemperature;
    odb_String initiationPotentialOperator;
    double initiationPotentialExponent;
    int initiationDependencies;
    bool evolution;
    odb_String evolutionType;
    odb_String softening;
    bool useAffected;
    odb_String degradation;
    bool evolutionTemperature;
    int evolutionDependencies;
    odb_String evolutionPotentialOperator;
    double evolutionPotentialExponent;
    odb_SequenceConnectorPotential initiationPotentials;
    odb_SequenceConnectorPotential evolutionPotentials;
    odb_SequenceSequenceDouble initiationTable;
    odb_SequenceSequenceDouble evolutionTable;
    odb_SequenceInt components;
    odb_SequenceInt affectedComponents;
};


COW_COUNTEDHLD_DECL(inpO_ConnectorDamage, inpO_ConnectorDamageHld)


#endif // inpO_ConnectorDamage_h

