/* -*- mode: c++ -*- */
#ifndef inpO_ConnectorPotential_h
#define inpO_ConnectorPotential_h

////////////////////////////////////////////////////////////////////////
//
//  Name: inpO_ConnectorPotential
//
//  Description: Collect keyword data to define a connector_potential 
//  object in the ODB

// Forward declaration
class inp_Keyword;
//
// Begin local includes
#include <mem_AllocationOperators.h>
//

#include <inpO_ConnDerivedComponent.h>
#include <odb_String.h>
#include <odb_Types.h>
#include <odb_ConnBehaviorTypes.h>


class inpO_ConnectorPotential  : public mem_AllocationOperators
{

public:
    static void ReadConnectorPotential( cow_String&       potOperator,
                                        double&           exponent,
                                        odb_SequenceConnectorPotential& potList,
                                        const inp_Keyword& keyword,
                                        const inpO_ConnectorDerivedComponentMap& dcMap );
};

#endif // inpO_ConnectorPotential_h

