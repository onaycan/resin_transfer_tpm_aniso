#ifndef odb_ConcRadiation_h
#define odb_ConcRadiation_h

// Begin local includes
#include <odb_Interaction.h>
#include <odb_Types.h>
#include <cow_COW.h>

// Forward declarations
class ddb_ConcRadiation;

class odb_ConcRadiation: public odb_Interaction
{
public:

   
    void setAmbientTemperatureInStep( const odb_String& stepName,
				   double t );

    void setAssociatedAreaInStep( const odb_String& stepName,
				double asa);

    void setEmissivityInStep( const odb_String& stepName,
			     double em );


private:

public:   // Undocumented and unsupported

    // Needed for container
    odb_ConcRadiation();

    odb_ConcRadiation(const ddb_ConcRadiation& interaction);

};

#endif //odb_ConcRadiation_h
