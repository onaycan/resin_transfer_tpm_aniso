#ifndef odb_SurfaceTraction_h
#define odb_SurfaceTraction_h

// Begin local includes
#include <odb_Traction.h>

// Forward declarations
typedef ddb_Traction ddb_SurfaceTraction;

class odb_SurfaceTraction: public odb_Traction
{
public:

    // member access

    // Options

private:

public:   // Undocumented and unsupported

    // Needed for container
    odb_SurfaceTraction();

    odb_SurfaceTraction(const ddb_SurfaceTraction& load);

};

#endif // odb_SurfaceTraction_h
