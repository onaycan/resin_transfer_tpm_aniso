#ifndef ptoC_BeamOrientation_h
#define ptoC_BeamOrientation_h

// Begin local includes
#include <cls_TypeAdapter.h>
#include <cls_Uid.h>
#include <gsl_PersistentVector.h>
#include <omu_PrimEnum.h>
#include <ptoC_PartAttribute.h>
#include <rgnC_Region.h>

class cls_ReadVisitor;
class cls_WriteVisitor;
class cls_ClassRegistrar;

class ptoC_BeamOrientation: public ptoC_PartAttribute
{
public:

    enum methodEnm { N1_COSINES, CSYS, VECTOR };

    ptoC_BeamOrientation( const rgnC_Region&, methodEnm t, const gsl_Vector& n1Dir);

    virtual ptoC_PartAttribute* Copy() const;
    virtual const rgnC_Region& RegionRef() const;
    virtual rgnC_Region& RegionRef();
    virtual const gsl_Vector& NormalRef() const;
    virtual gsl_Vector& NormalRef();
    void Suppress() { suppressed = true; };
    void Resume() { suppressed = false; };
    virtual bool IsSuppressed() const { return suppressed; } 

    rgnC_Region region;
    methodEnm method;
    gsl_PersistentVector n1;
    bool suppressed;

    // static data members
    static omn_FixedString containerCmd();
    static omn_FixedString constructorCmd();
    static omn_FixedString setValuesCmd();
    static omn_FixedString regionCmd();
    static omn_FixedString methodCmd();
    static omn_FixedString n1Cmd();
    static omn_FixedString suppressedCmd();
    static omn_FixedString suppressCmd();
    static omn_FixedString resumeCmd();

    virtual typ_typeTag     DynTypeId() const;
    static typ_typeTag      TypeId();
    static void* Ctor( cls_ReadVisitor& rv );
    ptoC_BeamOrientation( const cls_ReadVisitor& rv );
    virtual void DBWrite( const cls_WriteVisitor& wv ) const;
    static void InitializeMetadata( cls_ClassRegistrar& reg );

private:
    cls_Uid m_ClsUid;
};

CLS_TYPEADAPTER_DECL(ptoC_BeamOrientation, ptoC_BeamOrientationAdapter);

typedef omu_PrimEnum<ptoC_BeamOrientation::methodEnm,1> ptoC_BeamOrientationMethodConst;

#endif








