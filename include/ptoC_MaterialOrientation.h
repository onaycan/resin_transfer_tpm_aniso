/* -*- mode: c++ -*- */
///////////////////////////////////////////////////////////////////////////////
// File Name: ptoC_BeamOrientation.h
// Description:
//   A ptoC_MaterialOrientation contains the region, the orientation (name and csys)
//    which the user defines

#ifndef ptoC_MaterialOrientation_h
#define ptoC_MaterialOrientation_h

// Includes
// Begin local includes
#include <cls_TypeAdapter.h>
#include <cls_Uid.h>
#include <cow_String.h>
#include <dtmC_DatumRef.h>
#include <gsl_PersistentVector.h>
#include <omu_PrimEnum.h>
#include <ptoC_PartAttribute.h>
#include <rgnC_Region.h>


class cls_ReadVisitor;
class cls_WriteVisitor;
class cls_ClassRegistrar;

enum
{
    ptoC_DISPLAY_ORIENT_1 = 0x00001,
    ptoC_DISPLAY_ORIENT_2 = 0x00002,
    ptoC_DISPLAY_ORIENT_3 = 0x00004,
    ptoC_DISPLAY_ORIENT_REF_1 = 0x00010,
    ptoC_DISPLAY_ORIENT_REF_2 = 0x00020,
    ptoC_DISPLAY_ORIENT_REF_3 = 0x00040,
    ptoC_DISPLAY_ORIENT_PRIMARY = ptoC_DISPLAY_ORIENT_1 | ptoC_DISPLAY_ORIENT_2 | ptoC_DISPLAY_ORIENT_3,
    ptoC_DISPLAY_ORIENT_REFERENCE = ptoC_DISPLAY_ORIENT_REF_1 | ptoC_DISPLAY_ORIENT_REF_2 | ptoC_DISPLAY_ORIENT_REF_3,
    ptoC_DISPLAY_ORIENT_ALL = ptoC_DISPLAY_ORIENT_PRIMARY | ptoC_DISPLAY_ORIENT_REFERENCE
};

class ptoC_MaterialOrientation: public ptoC_PartAttribute
{
public:
    enum axisEnm { AXIS_1, AXIS_2, AXIS_3 };
    enum stackDirectionEnm { STACK_1, STACK_2, STACK_3, STACK_ORIENTATION };
    enum orientationTypeEnum { GLOBAL, SYSTEM, FIELD, USER, DISCRETE };
    enum additionalRotTypeEnum { ROTATION_NONE, ROTATION_ANGLE, ROTATION_FIELD };
    enum normalDirectionDefinitionEnum { SURFACE, NORMAL_DATUM, NORMAL_VECTOR };
    enum primaryDirectionDefinitionEnum { EDGE, PRIMARY_DATUM, PRIMARY_VECTOR };

    ptoC_MaterialOrientation(const cow_String& oriName, const rgnC_Region&,
        const dtmC_DatumRef& csys, axisEnm n,double angle,
        const orientationTypeEnum &oType, stackDirectionEnm stack = STACK_3,
        const cow_String &fieldName=cow_String(), const cow_String &aField=cow_String(),
		const additionalRotTypeEnum &aRot=ROTATION_NONE);
    // Constructor for Discrete Orientations.............
    ptoC_MaterialOrientation( const cow_String &oriName, const rgnC_Region &rgnRef,
        const normalDirectionDefinitionEnum normalDef, const rgnC_Region &nRegion,
        const dtmC_DatumRef &nDatum, const gsl_Vector &nVector, axisEnm nDir, bool nFlip,
        const primaryDirectionDefinitionEnum primaryDef, const rgnC_Region &pRegion,
        const dtmC_DatumRef &pDatum, const gsl_Vector &pVector, axisEnm pDir, bool pFlip,
        ptoC_MaterialOrientation::axisEnm n, double alpha, stackDirectionEnm stack = STACK_3,
        const cow_String &aField=cow_String(), const additionalRotTypeEnum &aRot=ROTATION_NONE);
    ptoC_MaterialOrientation();

    //virtual methods
    virtual ptoC_PartAttribute* Copy() const;
    virtual const rgnC_Region& RegionRef() const;
    virtual rgnC_Region& RegionRef();
    virtual void AssertValid() const; // Consistency checking
    void Suppress() { suppressed = true; };
    void Resume() { suppressed = false; };
    virtual bool IsSuppressed() const { return suppressed; }

    cow_String name, fieldName, addlRotField;
    rgnC_Region region, normalAxisRegion, primaryAxisRegion;
    dtmC_DatumRef csys, normalAxisDatum, primaryAxisDatum;
    axisEnm axis, normalAxisDirection, primaryAxisDirection;
    double angle;
    stackDirectionEnm stackDirection;
    orientationTypeEnum orientationType;
	additionalRotTypeEnum addlRotType;
    bool suppressed, flipNormalDirection, flipPrimaryDirection;
    normalDirectionDefinitionEnum normalAxisDefinition;
    primaryDirectionDefinitionEnum primaryAxisDefinition;
    gsl_PersistentVector normalAxisVector, primaryAxisVector;

// static data members

    static int orientationId;
    static int GetOrientationId();

    static omn_FixedString nameCmd();
    static omn_FixedString regionCmd();
    static omn_FixedString csysCmd();
    static omn_FixedString axisCmd();
    static omn_FixedString angleCmd();
    static omn_FixedString containerCmd();
    static omn_FixedString constructorCmd();
    static omn_FixedString setValuesCmd();
    static omn_FixedString fieldNameCmd();
    static omn_FixedString orientationTypeCmd();
    static omn_FixedString addlRotFieldCmd();
    static omn_FixedString addlRotTypeCmd();
    static omn_FixedString suppressedCmd();
    static omn_FixedString suppressCmd();
    static omn_FixedString resumeCmd();
    static omn_FixedString normalAxisRegionCmd();
    static omn_FixedString normalAxisDatumCmd();
    static omn_FixedString normalAxisDirectionCmd();
    static omn_FixedString flipNormalDirectionCmd();
    static omn_FixedString normalAxisDefinitionCmd();
    static omn_FixedString normalAxisVectorCmd();
    static omn_FixedString primaryAxisRegionCmd();
    static omn_FixedString primaryAxisDatumCmd();
    static omn_FixedString primaryAxisDirectionCmd();
    static omn_FixedString flipPrimaryDirectionCmd();
    static omn_FixedString primaryAxisDefinitionCmd();
    static omn_FixedString primaryAxisVectorCmd();

    static inline axisEnm axisDef();
    static inline double  angleDef();
    static omn_FixedString stackDirectionCmd();
    static inline stackDirectionEnm stackDirectionDef();

// Messaging/database interface

    virtual typ_typeTag     DynTypeId() const;
    static typ_typeTag      TypeId();

    static void* Ctor( cls_ReadVisitor& rv );
    ptoC_MaterialOrientation( const cls_ReadVisitor& rv );
    virtual void DBWrite( const cls_WriteVisitor& wv ) const;
    static void InitializeMetadata( cls_ClassRegistrar& reg );

private:
    cls_Uid m_ClsUid;
};

CLS_TYPEADAPTER_DECL(ptoC_MaterialOrientation, ptoC_MaterialOrientationAdapter);

inline ptoC_MaterialOrientation::axisEnm
ptoC_MaterialOrientation::axisDef() {return  ptoC_MaterialOrientation::AXIS_1;}

inline double ptoC_MaterialOrientation::angleDef() {return 0.0;}

inline ptoC_MaterialOrientation::stackDirectionEnm
ptoC_MaterialOrientation::stackDirectionDef() {
    return ptoC_MaterialOrientation::STACK_3;
}

typedef omu_PrimEnum<ptoC_MaterialOrientation::axisEnm,1> ptoC_MatOriAxisConst;
typedef omu_PrimEnum<ptoC_MaterialOrientation::stackDirectionEnm,1> ptoC_StackDirectionConst;
typedef omu_PrimEnum<ptoC_MaterialOrientation::orientationTypeEnum,1> ptoC_OrientationTypeConst;
typedef omu_PrimEnum<ptoC_MaterialOrientation::additionalRotTypeEnum,1> ptoC_AdditionalRotTypeConst;
typedef omu_PrimEnum<ptoC_MaterialOrientation::normalDirectionDefinitionEnum,1> ptoC_NormalDirectionDefinitionConst;
typedef omu_PrimEnum<ptoC_MaterialOrientation::primaryDirectionDefinitionEnum,1> ptoC_PrimaryDirectionDefinitionConst;

#endif /* ptoC_MaterialOrientation_h */



