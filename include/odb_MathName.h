#ifndef odb_MathName_h
#define odb_MathName_h

// Begin local includes
#include <mem_AllocationOperators.h>
#include <odb_Enum.h>
#include <odb_Types.h>
// End local includes

class odb_MathName : public mem_AllocationOperators
{
public:
    odb_MathName(const odb_String &lhs,
                 odb_Enum::odb_MathOperationEnum,
                 float);                            // "S + 2.0"
    odb_MathName(float ,
                 odb_Enum::odb_MathOperationEnum,
                 const odb_String &lhs);            // "2.0 + S"
    odb_MathName(odb_Enum::odb_MathOperationEnum,
                 const odb_String &lhs);            // "tan( T )"
    odb_MathName(const odb_String &lhs,
                 odb_Enum::odb_MathOperationEnum,
                 const odb_String &rhs);            // " S + S "
    odb_MathName(odb_Enum::odb_MathOperationEnum,
                 const odb_String &rhs,
                 float);                            // "power( T, 2.0 )"
    odb_MathName(odb_Enum::odb_MathOperationEnum,
                 const odb_String &lhs,             
                 const odb_String &rhs);            // "power( T, T )"
    odb_MathName(const odb_String &lhs,
                 odb_Enum::odb_InvariantEnum i);  // "S.MISES"
    odb_MathName(const odb_String &lhs,
                 const odb_String &comp,          // "S.S11"
                 bool isFunc=false);              // "transformed( cSys )"
    odb_MathName(const odb_String &op,  // "env( ('s1',.., s2'), MISES)"
                 const odb_SequenceString& names,
                 const odb_String& op2 = odb_String() );
    odb_MathName(odb_Enum::odb_MathOperationEnum); //  "+"
    odb_MathName(odb_Enum::odb_InvariantEnum); // "MISES"
    odb_MathName(odb_Enum::odb_DataTypeEnum); // "TENSOR_2D_SURFACE"

    operator odb_String() const;
    odb_String value() const;

private:
    odb_String Value;
};

#endif // odb_MathName_h

