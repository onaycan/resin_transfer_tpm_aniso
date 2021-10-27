#ifndef kamO_SpectrumAmplitude_h
#define kamO_SpectrumAmplitude_h

// Begin local includes
#include <odb_Amplitude.h>
#include <odb_Types.h>
#include <odb_String.h>
// Forward declarations
class kamC_SpectrumAmplitude;

class kamO_SpectrumAmplitude : public odb_Amplitude
{
public:
    kamO_SpectrumAmplitude( const kamC_AmplitudeShortcut& shortcut );
    kamO_SpectrumAmplitude();

    kamO_SpectrumAmplitude(const odb_String& method,
                           const odb_SequenceSequenceDouble& data,
                           odb_String specificationUnits="ACCELERATION",
                           odb_String eventUnits="EVENT_ACCELERATION",
                           odb_String solution="ABSOLUTE_VALUE",
                           double timeIncrement=0.0,
                           double gravity=1.0,
                           bool criticalDamping=false,
                           odb_String amplitude="",
                           odb_String timeSpan="STEP");

    kamO_SpectrumAmplitude( const kamO_SpectrumAmplitude& copy );

    virtual ~kamO_SpectrumAmplitude();
    odb_String method() const;
    odb_String specificationUnits() const;
    odb_String eventUnits() const;
    odb_String solution() const;
    double timeIncrement() const;
    double gravity() const;
    bool criticalDamping() const;
    odb_SequenceSequenceDouble data() const;
    odb_String amplitude() const;
    odb_String timeSpan() const;
    kamO_SpectrumAmplitude& operator=( const kamO_SpectrumAmplitude& rhs );

    const kamC_SpectrumAmplitude* GetPointer() const;

    static unsigned int typeIdentifier();

    virtual odb_Amplitude* Copy() const;

};

#endif
