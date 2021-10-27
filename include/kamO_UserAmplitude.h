#ifndef kamO_UserAmplitude_h
#define kamO_UserAmplitude_h

// Begin local includes
#include <odb_Amplitude.h>
#include <odb_Types.h>
#include <odb_String.h>
// Forward declarations
class kamC_UserAmplitude;

class kamO_UserAmplitude : public odb_Amplitude
{
public:
    kamO_UserAmplitude( const kamC_AmplitudeShortcut& shortcut );
    kamO_UserAmplitude();

    kamO_UserAmplitude(int numVariables,
                       odb_String timeSpan="STEP");

    kamO_UserAmplitude( const kamO_UserAmplitude& copy );

    virtual ~kamO_UserAmplitude();
    int numVariables() const;
    odb_String timeSpan() const;
    kamO_UserAmplitude& operator=( const kamO_UserAmplitude& rhs );

    const kamC_UserAmplitude* GetPointer() const;

    static unsigned int typeIdentifier();

    virtual odb_Amplitude* Copy() const;

};

#endif
