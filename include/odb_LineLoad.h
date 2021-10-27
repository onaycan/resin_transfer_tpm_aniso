#ifndef odb_LineLoad_h
#define odb_LineLoad_h

// Begin local includes
#include <odb_VectorLoad.h>
#include <odb_Types.h>

// Forward declarations
class ddb_LineLoad;

class odb_LineLoad: public odb_VectorLoad
{
    
private:

public:   // undocumented and unsupported

    // Needed for container
    odb_LineLoad();

    odb_LineLoad(const ddb_LineLoad& load);
    
};

#endif // odb_LineLoad_h
