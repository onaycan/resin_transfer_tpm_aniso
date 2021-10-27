/* -*- mode: c++ -*- */
///////////////////////////////////////////////////////////////////////////////
//
// File Name: odb_MessageText.h
//
// Description: File for defining error messages.
//

#ifndef odb_MessageText_h
#define odb_MessageText_h

// Begin local includes
#include <odb_Enum.h>
#include <atr_String.h>
// End local includes

class odb_MessageText
{
public:

    // exception text for math operators
    static const atr_String fieldsNotCompatible();
    static const atr_String locationsNotCompatible();
    static const atr_String invalidMathOperation();
    static const atr_String unknownDataType();
    static const atr_String fieldSizeNotCompatible();
    static const atr_String dataSizeNotCompatible();
    static const atr_String opScalarDivFieldValidForScalarOnly();
    static const atr_String opInvalidBetweenTensors();
    static const atr_String opInvalidBetweenVectors();
    static const atr_String opInvalidBetweenMatrices();
    static const atr_String operandMustBeGreaterThanZero();
    static const atr_String operandMustBeGreaterEqualZero();
    static const atr_String zeroDivision();
    static const atr_String invalidLoadCase();
    static const atr_String mustBeScalar();

    //  Error taking arguments
    static atr_String typesNotCompatible( odb_Enum::odb_DataTypeEnum,
                                          odb_Enum::odb_DataTypeEnum );
};

#endif
