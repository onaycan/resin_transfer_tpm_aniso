// -*- Mode: C++ -*-
#ifndef gsl_PersistentVector_h
#define gsl_PersistentVector_h
// Begin local includes
#include <gsl_Vector.h>
#include <cls_Uid.h>
#include <gsl_TypeTable.h>
#include <typ_typeTag.h>

class cls_ReadVisitor;
class cls_WriteVisitor;
class cls_ClassRegistrar;

class gsl_PersistentVector
    : public gsl_Vector
{
public:

    // unit vector aligned with Z-axis
    gsl_PersistentVector()
        {}

    // vector from 1st point to 2nd one
    gsl_PersistentVector( const gsl_Point &a, const gsl_Point &b )
        : gsl_Vector( a, b ) {}

    // vector from 3 reals
    gsl_PersistentVector(const double x, const double y, const double z)
        : gsl_Vector( x, y, z ) {}

    // unit normal to plane through 3 points, (0,0,0) if degenerate
    gsl_PersistentVector(const gsl_Point &a, const gsl_Point &b, const gsl_Point &c)
        : gsl_Vector( a, b, c ) {}

    explicit gsl_PersistentVector( const gsl_Vector &v )
        : gsl_Vector( v ) {}

    void operator = ( const gsl_Vector &v ) {
        *static_cast<gsl_Vector*>(this) = v; }

public: // Database interface

    typ_typeTag DynTypeId() const;
    static typ_typeTag TypeId() { return TYP_TIX_gsl_Vector; }

    gsl_PersistentVector(const cls_ReadVisitor& rv);
    static void InitializeMetadata(cls_ClassRegistrar& reg);
    virtual void DBWrite(const cls_WriteVisitor& wv) const;

private:

    cls_Uid m_ClsUid;
};

#endif
