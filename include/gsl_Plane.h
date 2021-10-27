/* -*- mode: c++ -*- */
///////////////////////////////////////////////////////////////////////////////
//
// File Name: gsl_Plane.h
// 
// Description:
//
//    This file contains the definition of the gsl_Plane class.
//
// Author: Pramod N Chivate
// 
// Creation date: Thu Oct 26 1995
//


#ifndef gsl_Plane_h
#define gsl_Plane_h

//
// Includes
//


// Begin local includes
#include <mem_AllocationOperators.h>

#include <omi_types.h>
#include <gsl_PersistentVector.h>
#include <typ_typeTag.h>
#include <idb_Utils.h>
#include <cls_xp1DArrayListUint.h>
#include <cow_COW.h>
#include <cow_MapUint2Uint.h>
#include <omu_PrimEnum.h>
#include <cls_IntCOW.h>
#include <cls_Uid.h>
#include <omu_xoObjVarray.h>

class gsl_Plane;
class ftr_FeatureList;
class cls_ClassRegistrar;
class cls_ReadVisitor;
class cls_WriteVisitor;

//
// Constants
//
// Method types
    enum gsl_DirMethod{ gsl_FROM_POINT_VECTOR, 
			gsl_FROM_FACE, 
			gsl_FROM_DATUM_PLANE,
                        gsl_FROM_ELEM_FACE,
                        gsl_PLANE_INVALID };

//
// Define a COW that can be used to hold gsl_Planes. Since this is a base
// class it must be a cow_Virtual.
//

COW_COW2_DECL(gsl_Plane,cow_Virtual);

//
// Class definition
//

class gsl_Plane  : public mem_AllocationOperators
{
public:
// Constructors, Destructor

    gsl_Plane(const gsl_Point&, const gsl_Vector&);     // gsl_FROM_POINT_VECTOR method
    gsl_Plane();			// Default added as dummy ( for Datums )

    virtual ~gsl_Plane();

    // Copy 
    virtual gsl_Plane* Copy() const;

// Member functions

    virtual bool Regenerate(const ftr_FeatureList*);

    virtual int OwnerFeatID() const;
    virtual void SetOwnerFeatID(const int);

    const gsl_Vector& Direction() const;
    const gsl_Point& PointOn() const;

    bool IsParallel(const gsl_Plane& plane) const;
    double GetDistance(const gsl_Plane& plane) const;
    bool IsOn(const gsl_Plane& plane) const;

  // The 'Centroid' is used as origin for sketch in derived classes
    virtual gsl_Point Centroid() const;
    virtual void ResetCentroid(const gsl_Point&,
                               const ftr_FeatureList*) {}

    uint NmrParents() const { return parent_ids.Length(); }
    uint GetNthParentId(int i) const { return parent_ids.ConstGet(i); }
    virtual uint GetParentInstId() const {return 0;};
    virtual void* CreateHitRecord(const ftr_FeatureList* flist)const{return 0;}
    
    // Messaging/database interface

    virtual typ_typeTag     DynTypeId() const;

    static typ_typeTag      TypeId();


    gsl_Plane *             DeepCopy() const {
        return (gsl_Plane*)DDB_DeepCopyPtr(this, DynTypeId());
    }


// Variables.  MUST be declared const since they're public

// Temporarily all members have been made protected. But they should
// be actually private with methods to access. -Pramod 10/25/95
protected:
    bool           	  _ok;
    gsl_Point             _point;
    gsl_PersistentVector  _normal;
    gsl_DirMethod         _method;
    bool           	  _flip;

    cls_xp1DArrayListUint parent_ids; // To store parent ids
    int 	          owner_feat_id;

private:


public:

    // Messaging/Database interface
    static void CowDtor( cls_IntCOW * );
    gsl_Plane( const cls_ReadVisitor & );
    virtual void DBWrite( const cls_WriteVisitor & ) const;
    static void InitializeMetadata( cls_ClassRegistrar & );

private:

    cls_Uid m_ClsUid;
};

OMU_xoOBJVARRAY_DECL(gsl_Plane, gsl_PlaneArray);
typedef omu_PrimEnum<gsl_DirMethod,1> gsl_DirMethodConst;


#endif  // #ifdef gsl_Plane_h


