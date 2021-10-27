#ifndef odb_Radiation_h
#define odb_Radiation_h

// Begin local includes
#include <mem_AllocationOperators.h>
#include <odb_Types.h>
#include <cow_COW.h>
#include <cow_2DArrayDouble.h>

// Forward declarations
class ddb_Radiation;
//class odb_FilmConditionProp;
//class odb_Amplitude;
COW_COW_DECL(ddb_Radiation);

class odb_Radiation : public mem_AllocationOperators
{
public:

   
    void setMasterEmissivity(double me);
    void setSlaveEmissivity(double se);

    void setTable(const cow_2DArrayDouble& tb);

private:
   ddb_RadiationCOW radiation;

public:   // Undocumented and unsupported

    // Needed for container
    odb_Radiation();

    odb_Radiation(const ddb_Radiation& gr);

};

#endif //odb_ Radiation_h
