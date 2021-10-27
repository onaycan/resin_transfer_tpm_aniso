#ifndef odb_BodyForce_h
#define odb_BodyForce_h

// Begin local includes
#include <odb_VectorLoad.h>
#include <odb_Types.h>

// Forward declarations
class ddb_BodyForce;

class odb_BodyForce: public odb_VectorLoad
{
    
private:

public:   // undocumented and unsupported

    // Needed for container
    odb_BodyForce();

    odb_BodyForce(const ddb_BodyForce& load);
    
};

#endif // odb_BodyForce_h
