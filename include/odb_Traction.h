#ifndef odb_Traction_h
#define odb_Traction_h

// Begin local includes
#include <odb_Load.h>

// Forward declarations
class ddb_Traction;
class odb_PropagatingComponent;

class odb_Traction: public odb_Load
{
public:

    void setMagnitudeInStep(const odb_String& stepName, 
                            const odb_PropagatingComponent& mag);
    
private:

public:   // undocumented and unsupported

    // Needed for container
    odb_Traction();

    odb_Traction(const ddb_Traction& load);
    
};

#endif // odb_Traction_h
