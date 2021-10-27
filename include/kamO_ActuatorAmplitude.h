#ifndef kamO_ActuatorAmplitude_h
#define kamO_ActuatorAmplitude_h

// Begin local includes
#include <odb_Amplitude.h>
#include <odb_Types.h>
#include <odb_String.h>
// Forward declarations
class kamC_ActuatorAmplitude;

class kamO_ActuatorAmplitude : public odb_Amplitude
{
public:
    kamO_ActuatorAmplitude( const kamC_AmplitudeShortcut& shortcut );
    kamO_ActuatorAmplitude(odb_String timeSpan="STEP");

    kamO_ActuatorAmplitude( const kamO_ActuatorAmplitude& copy );

    virtual ~kamO_ActuatorAmplitude();
    odb_String timeSpan() const;
    kamO_ActuatorAmplitude& operator=( const kamO_ActuatorAmplitude& rhs );

    const kamC_ActuatorAmplitude* GetPointer() const;

    static unsigned int typeIdentifier();

    virtual odb_Amplitude* Copy() const;

};

#endif
