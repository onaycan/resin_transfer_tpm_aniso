#ifndef odb_RigidBodyConstraint_h
#define odb_RigidBodyConstraint_h
//////////////////////////////////////////
//
// Project 4077 consumed odb_RigidBody.
// This class is the old odb_RigidBody.
// 
/////////////////////////////////////////
// Begin local includes
#include <odb_Constraint.h>

// Forward declarations
class ddb_RigidBody;

class odb_RigidBodyConstraint: public odb_Constraint
{
public:

    // member access

    // Options

private:

public:   // Undocumented and unsupported

    // Needed for container
    odb_RigidBodyConstraint();

    odb_RigidBodyConstraint(const ddb_RigidBody& constraint);
};

#endif // odb_RigidBodyConstraint_h
