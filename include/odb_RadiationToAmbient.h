#ifndef odb_RadiationToAmbient_h
#define odb_RadiationToAmbient_h

// Begin local includes
#include <odb_Interaction.h>
#include <odb_Types.h>
#include <cow_COW.h>

// Forward declarations
class ddb_RadiationToAmbient;
//class odb_FilmConditionProp;
//class odb_Amplitude;

class odb_RadiationToAmbient: public odb_Interaction
{
public:

   
    void setAmbientTemperatureInStep( const odb_String& stepName,
				   double t );

    void setAmbientTemperatureAmpInStep( const odb_String& stepName,
				 const cow_String& lab );

    void setEmissivityInStep( const odb_String& stepName,
			     double em );

    void setRadiationTypeInStep( const odb_String& stepName,
			     const cow_String& radType);

private:

public:   // Undocumented and unsupported

    // Needed for container
    odb_RadiationToAmbient();

    odb_RadiationToAmbient(const ddb_RadiationToAmbient& interaction);

};

#endif //odb_ RadiationToAmbient_h
