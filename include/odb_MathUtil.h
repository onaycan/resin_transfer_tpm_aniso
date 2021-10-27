#ifndef odb_MathUtil_h
#define odb_MathUtil_h

// Begin local includes
#include <odb_Enum.h>
#include <odb_Types.h>
#include <odb_SequenceFieldOutput.h>
// End local includes

// Forward declarations
class odb_FieldOutput;
class odb_HistoryOutput;
class odb_FieldValue;
class odb_SubField;
class odb_FieldValueData;

class odb_MathUtil {
public:

    // general
    static bool isLargerThan( float arg1, float arg2 )
                                               { return ( arg1 > arg2 ); }
    static bool isLessThan( float arg1, float arg2 )
                                               { return ( arg1 < arg2 ); }

    // fieldValues
    static odb_FieldValue fieldValueOperation(const odb_FieldValue &,
                                              odb_Enum::odb_MathOperationEnum );
    static odb_FieldValue fieldValueOperation(const odb_FieldValue &,
                                              float,
                                              odb_Enum::odb_MathOperationEnum );
    static odb_FieldValue fieldValueOperation(float,
                                              const odb_FieldValue &,
                                              odb_Enum::odb_MathOperationEnum );
    static odb_FieldValue fieldValueOperation(const odb_FieldValue &,
                                              const odb_FieldValue &,
                                              odb_Enum::odb_MathOperationEnum );

    // fieldValue util
    static bool odb_FieldValueModelLocationIsEqual(const odb_FieldValue&,
                                                    const odb_FieldValue& );

    // fields
    static odb_FieldOutput fieldOperation(const odb_FieldOutput &,
                                          float,
                                          odb_Enum::odb_MathOperationEnum );
    static odb_SubField fieldOperation(const odb_SubField &,
                                       float,
                                       odb_Enum::odb_MathOperationEnum );
    static odb_SubField ScalarfieldOperation(const odb_SubField &,
                                             float,
                                             odb_Enum::odb_MathOperationEnum );
    static odb_SubField VectorfieldOperation(const odb_SubField &,
                                             float,
                                             odb_Enum::odb_MathOperationEnum );
    static odb_SubField MatrixfieldOperation(const odb_SubField &,
                                             float,
                                             odb_Enum::odb_MathOperationEnum );
    static odb_SubField TensorfieldOperation(const odb_SubField &,
                                             float,
                                             odb_Enum::odb_MathOperationEnum );

    static odb_FieldOutput fieldOperation(float,
                                          const odb_FieldOutput &,
                                          odb_Enum::odb_MathOperationEnum );
    static odb_SubField fieldOperation(float,
                                       const odb_SubField &,
                                       odb_Enum::odb_MathOperationEnum );
    static odb_SubField ScalarfieldOperation(float,
                                             const odb_SubField &,
                                             odb_Enum::odb_MathOperationEnum );
    static odb_SubField VectorfieldOperation(float,
                                             const odb_SubField &,
                                             odb_Enum::odb_MathOperationEnum );
    static odb_SubField MatrixfieldOperation(float,
                                             const odb_SubField &,
                                             odb_Enum::odb_MathOperationEnum );
    static odb_SubField TensorfieldOperation(float,
                                             const odb_SubField &,
                                             odb_Enum::odb_MathOperationEnum );

    static odb_FieldOutput fieldOperation(const odb_FieldOutput &,
                                          const odb_FieldOutput &,
                                          odb_Enum::odb_MathOperationEnum );
    static odb_SubField fieldOperation(const odb_SubField &,
                                       const odb_SubField &,
                                       odb_Enum::odb_MathOperationEnum );
    static odb_SubField ScalarfieldOperation(const odb_SubField &,
                                             const odb_SubField &,
                                             odb_Enum::odb_MathOperationEnum );
    static odb_SubField VectorfieldOperation(const odb_SubField &,
                                             const odb_SubField &,
                                             odb_Enum::odb_MathOperationEnum );
    static odb_SubField MatrixfieldOperation(const odb_SubField &,
                                             const odb_SubField &,
                                             odb_Enum::odb_MathOperationEnum );
    static odb_SubField TensorfieldOperation(const odb_SubField &,
                                             const odb_SubField &,
                                             odb_Enum::odb_MathOperationEnum );

    // field functions
    static odb_FieldOutput fieldOperation(const odb_FieldOutput& ,
                                          odb_Enum::odb_MathOperationEnum);
    static odb_SubField fieldOperation(const odb_SubField &,
                                       odb_Enum::odb_MathOperationEnum );
    static odb_SubField ScalarfieldOperation(const odb_SubField &,
                                             odb_Enum::odb_MathOperationEnum );
    static odb_SubField VectorfieldOperation(const odb_SubField &,
                                             odb_Enum::odb_MathOperationEnum );
    static odb_SubField MatrixfieldOperation(const odb_SubField &,
                                             odb_Enum::odb_MathOperationEnum );
    static odb_SubField TensorfieldOperation(const odb_SubField &,
                                             odb_Enum::odb_MathOperationEnum );

    // history
    static odb_HistoryOutput historyOperation(const odb_HistoryOutput &,
                                              float,
                                              odb_Enum::odb_MathOperationEnum );
    static odb_HistoryOutput historyOperation(float,
                                              const odb_HistoryOutput &,
                                              odb_Enum::odb_MathOperationEnum );
    static odb_HistoryOutput historyOperation(const odb_HistoryOutput &,
                                              const odb_HistoryOutput &,
                                              odb_Enum::odb_MathOperationEnum );
    static odb_HistoryOutput historyOperation(const odb_HistoryOutput& ,
                                              odb_Enum::odb_MathOperationEnum);

    // history util
    static odb_SequenceSequenceFloat secondSeqFloatOp(
                                       odb_Enum::odb_MathOperationEnum ,
                                       const odb_SequenceSequenceFloat& ssf);
    static odb_SequenceSequenceFloat secondSeqFloatOp(
                                       const odb_SequenceSequenceFloat& ssf,
                                       odb_Enum::odb_MathOperationEnum,
                                       float);
    static odb_SequenceSequenceFloat secondSeqFloatOp(
                                       float,
                                       odb_Enum::odb_MathOperationEnum ,
                                       const odb_SequenceSequenceFloat& ssf);
    static odb_SequenceSequenceFloat secondSeqFloatOp(
                                       const odb_SequenceSequenceFloat& ssf1,
                                       odb_Enum::odb_MathOperationEnum,
                                       const odb_SequenceSequenceFloat& ssf2);
    static odb_SequenceSequenceFloat secondSeqFloatOpComplex(
                                       const odb_SequenceSequenceFloat& ssf1,
                                       odb_Enum::odb_MathOperationEnum,
                                       const odb_SequenceSequenceFloat& ssf2);

    // fieldValue data
    static odb_FieldValueData fieldValueDataOp( const odb_FieldValueData & lhs,
                                         odb_Enum::odb_MathOperationEnum op);

    // util
    static float mathOperator(float,
                              odb_Enum::odb_MathOperationEnum,
                              float);
    static float mathOperator(odb_Enum::odb_MathOperationEnum,
                              float);

};

#endif // odb_MathUtil_h
