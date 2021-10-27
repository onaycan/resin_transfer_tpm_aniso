/* -*- mode: c++ -*- */
///////////////////////////////////////////////////////////////////////////////
//
// File Name: gsl_StLine.h
// 
// Description:
//
//    This file contains the definition of the gsl_StLine class.
//
// Author: Pramod Chivate
// 
// Creation date: Thu Oct 12 1995
//


#ifndef gsl_StLine_h
#define gsl_StLine_h

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
#include <omu_xoObjVarray.h>
#include <omu_PrimEnum.h>
#include <cls_IntCOW.h>
#include <cls_Uid.h>


class ftr_FeatureList;
class gsl_StLine;
class cls_ClassRegistrar;
class cls_ReadVisitor;
class cls_WriteVisitor;

//
// Constants
//
// Method types
    enum gsl_LineMethod{gsl_FROM_PNT_VECTOR, 
			gsl_FROM_EDGE, 
			gsl_FROM_REVFACE, 
			gsl_FROM_DATUM_AXIS,
                        gsl_FROM_ELEM_EDGE,
			gsl_FROM_PNT_PNT,
                        gsl_STLINE_INVALID,
			gsl_FROM_DATUM_CSYS // after invalid because of 
			                    // database compatibility
};

//
// Define a COW that can be used to hold gsl_StLines. Since this is a base
// class it must be a cow_Virtual.
//

COW_COW2_DECL(gsl_StLine,cow_Virtual);  // class name is gsl_StLineCOW

//
// Class definition
//

class gsl_StLine  : public mem_AllocationOperators
{
public:
// Constructors, Destructor

    // gsl_FROM_POINT_VECTOR method
    gsl_StLine(const gsl_Point&, const gsl_Vector&);  

    gsl_StLine(const gsl_Point&, const gsl_Point&);  

    gsl_StLine();			// Default added as dummy ( for Datums )

    virtual ~gsl_StLine();

    // Copy 
    virtual gsl_StLine* Copy() const;

// Member functions

    virtual bool      Regenerate(const ftr_FeatureList*);
    virtual int     OwnerFeatID() const;
    virtual void      SetOwnerFeatID(const int);
    virtual uint    GetParentInstId() const {return 0;};

    // returns a gdy_HitRecord*
    virtual void* CreateHitRecord(const ftr_FeatureList* fl)const{return 0;} 

    const gsl_Vector& Direction() const;
    const gsl_Point&  PointOn() const;
    gsl_LineMethod    Method() const;

    bool PointAtDistance(double iDistance, gsl_Point& oPoint) const;
    void FlipDirection();

    uint NmrParents() const { return parent_ids.Length(); }
    uint GetNthParentId(int i) const { return parent_ids.ConstGet(i); }

    double GetDistance(const gsl_StLine& line) const;
    double GetSignedDistance(const gsl_Plane& plane) const;
    double GetDistance(const gsl_Plane& plane) const;

    bool IsParallel(const gsl_StLine& line) const;
    bool IsParallel(const gsl_Plane& plane) const;
    bool IsSkewed(const gsl_StLine& line) const;

    bool IsOn(const gsl_StLine& line) const;
    bool IsOn(const gsl_Plane& plane) const;

    // Intersect with plane
    bool Intersect(const gsl_Plane& plane, //plane
                   gsl_Point& res) const; // result

    // Returns FALSE if "this" and "line" are parallel
    // Otherwise, "res" is a point on "this" closest to "line"
    // ALWAYS returns "dist" the as minimum distance between "this" and "line"
    bool Intersect(const gsl_StLine& line, //line
                   gsl_Point& res, // result
                   double& dist) const;

    /// Datums require reverse direction at some times.
    virtual gsl_Vector DirectionForDatum() const;

    ///Direction from point
    virtual gsl_Vector DirFromPtForStraightEdge(
	const ftr_FeatureList* fl,
	const gsl_Point & pnt) const { return _dir;}
    
    // Messaging/database interface

    virtual typ_typeTag     DynTypeId() const;

    static typ_typeTag      TypeId();
    bool                    IsA(typ_typeTag) const;


    gsl_StLine *             DeepCopy() const {
        return (gsl_StLine*)DDB_DeepCopyPtr(this, DynTypeId());
    }


// Variables.  MUST be declared const since they're public

// Temporarily all members have been made protected. But they should
// be actually private with methods to access. -Pramod 10/25/95
protected:

    gsl_Point             _point;
    gsl_PersistentVector  _dir;
    gsl_LineMethod        _method;
    bool                  _flip;

    bool                  _ok;
    cls_xp1DArrayListUint parent_ids; // To store parent ids

    int	          owner_feat_id;

private:
    // "this" and "line" must be non-parallel
    // "res" is a point on "this" closest to "line". 
    // Returns distance from "res" to "line" which is 0e0 for 
    // true intersection and non-zero for skewed lines
    double IntersectNonParallel(const gsl_StLine& line, //line
                                gsl_Point& res) const; // result



public:

    // Messaging/Database interface
    static void CowDtor( cls_IntCOW * );
    gsl_StLine( const cls_ReadVisitor & );
    virtual void DBWrite( const cls_WriteVisitor & ) const;
    static void InitializeMetadata( cls_ClassRegistrar & );

private:

    cls_Uid m_ClsUid;
};

OMU_xoOBJVARRAY_DECL(gsl_StLine,gsl_LineArray);
typedef omu_PrimEnum<gsl_LineMethod,1> gsl_LineMethodConst;




// Instantiators for Line Array

#endif  // #ifdef gsl_StLine_h


