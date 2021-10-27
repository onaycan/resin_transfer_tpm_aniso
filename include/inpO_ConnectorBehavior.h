/* -*- mode: c++ -*- */
#ifndef inpO_ConnectorBehavior_h
#define inpO_ConnectorBehavior_h

////////////////////////////////////////////////////////////////////////
//
//  Name: inpO_ConnectorBehavior
//
//  Description: Write connector section data to ODB using ODB API 
//

// Forward declaration
class inpO_ConnectorSectionVisitor;

//
// Begin local includes
#include <mem_AllocationOperators.h>
//

#include <odb_String.h>
#include <cow_Map.h>
#include <odb_Types.h>
#include <odb_ConnBehaviorTypes.h>

class inpO_ConnectorBehavior  : public mem_AllocationOperators
{
    friend class inpO_ConnectorSectionVisitor;
public:
    inpO_ConnectorBehavior() :
        integration("UNSPECIFIED"),
        u1ReferenceLength("NONE"), u2ReferenceLength("NONE"), u3ReferenceLength("NONE"),
        ur1ReferenceAngle("NONE"), ur2ReferenceAngle("NONE"), ur3ReferenceAngle("NONE")
        {}

private:
    odb_String integration;
    odb_Union u1ReferenceLength;
    odb_Union u2ReferenceLength;
    odb_Union u3ReferenceLength;
    odb_Union ur1ReferenceAngle;
    odb_Union ur2ReferenceAngle;
    odb_Union ur3ReferenceAngle;
    odb_SequenceConnectorBehaviorOption behaviorOptions;
};

COW_MAP_ITER_DECL(cow_String, inpO_ConnectorBehavior, inpO_ConnectorBehaviorMap);


#endif // inpO_ConnectorBehavior_h

