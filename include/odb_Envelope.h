#ifndef odb_Envelope_h
#define odb_Envelope_h

// Begin local includes
#include <mem_AllocationOperators.h>
#include <odb_Enum.h>
#include <odb_SequenceFieldOutput.h>
// End local includes

// Forward declarations

class odb_Envelope  : public mem_AllocationOperators
{
public:
    enum envRequestEnm { MAXIMUM=0, MINIMUM };

    odb_Envelope( odb_SequenceFieldOutput &,
                  envRequestEnm req );

    odb_Envelope( odb_SequenceFieldOutput &,
                  odb_Enum::odb_InvariantEnum,
                  envRequestEnm req );

    odb_Envelope( odb_SequenceFieldOutput &,
                  const odb_String& componentLabel,
                  envRequestEnm req );

    // methods
    void compute();

    // members
    odb_FieldOutput& values() {return m_val;}
    odb_FieldOutput& locations() {return m_loc;}
    envRequestEnm request()  const {return m_req;}
    cow_String requestName()  const;

private:
    odb_SequenceFieldOutput&    m_fieldsIn;
    odb_Enum::odb_InvariantEnum m_invar;
    odb_String                  m_compL;
    envRequestEnm               m_req;

    odb_FieldOutput m_val;
    odb_FieldOutput m_loc;

    // 
    void verifyFields();
    void setEmptyFields();

    // envelope calcs
    void scalarEnvelope();
    void compEnvelope();
    void invarEnvelope();
    void fieldFromEnvelopIndices(const odb_String& operatorName=odb_String());
};

#endif // odb_Envelope
