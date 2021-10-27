/* -*- mode: c++ -*- */
///////////////////////////////////////////////////////////////////////////////
//
// File Name: gsl_Matrix.h
// 
// Description:
//
//    This file contains the defintion of the gsl_Matrix class.
//
//    These transform matrices are internally defined by column vectors:
//    this is compatible with g3d_XForm. 
//    It is the transpose of Roger and Adams and older texts
//


#ifndef gsl_Matrix_h
#define gsl_Matrix_h

//
// Includes
//

// Begin local includes
#include <mem_AllocationOperators.h>

#include <omi_types.h>
#include <typ_typeTag.h>
#include <cow_2DArrayDouble.h>
#include <cow_COW.h>

class gsl_Point;
class gsl_Vector;

//
// Class definition
//

class gsl_Matrix  : public mem_AllocationOperators
{
public:

// Constructors, Destructor

    // initializes to identity
    gsl_Matrix();

// Operators 

    bool operator==(const gsl_Matrix&) const;
    bool operator!=(const gsl_Matrix&) const;

// Member functions

    // fill diagonal with 1, rest with 0
    void FillIdentity ();

    // returns true for an identity matrix
    bool IsIdentity() const;

    // transform points and vectors
    void Transform(gsl_Point&) const;
    void Transform(gsl_Vector&) const;

    gsl_Point NewOrigin() const;
    gsl_Vector NewXAxis() const;
    gsl_Vector NewYAxis() const;
    gsl_Vector NewZAxis() const;
    gsl_Vector NewAxis(uint axis) const;

    // set the translation vector. Rotation components are left intact
    void SetTranslation (const gsl_Vector& t);
    void GetTranslation (gsl_Vector& t) const; 

    void SetRow (uint row, const gsl_Vector& t);
    void SetColumn (uint column, const gsl_Vector& t);

    // set the three (covariant) vectors of the rotation
    // Translation components are left intact
    void SetRotationVectors (const gsl_Vector& xaxis,
			const gsl_Vector& yaxis,
			const gsl_Vector& zaxis);

    // get the angles of rotation about X, Y, Z
    // rotations performed in that order would give same matrix
    void GetRotationAngles (double& x, 
			    double& y, 
			    double& z)  const;

    // compute the matrix that rotates of the given angle about the 
    // given axis
    void AxisRotation( const gsl_Point& point,
		       const gsl_Vector& direction,
		       const double radians);
    void AxisRotation( const gsl_Vector& direction,
		       const double radians);

    // inverse of above
    void GetAxisRotation(gsl_Point& point,
			 gsl_Vector& direction,
			 double& radians) const;

    // invert the translation and rotation
    gsl_Matrix InverseRigidTransform () const;

    // concatenate given matrix with this
    void Concatenate (const gsl_Matrix&);

  //  get array (matches constructors to g3d)
    void AsArray(double m[4][4]) const;

    // Get the Eulerian angles Z, Y', X'' (in degrees)
    void GetEulerianAnglesZYX(double& zrot, double& yrot, double& xrot);

protected:

    void From2DArray( const cow_2DArrayDouble &arr, int isIdentity );
    void To2DArray( cow_2DArrayDouble *arr ) const;

private:
    // stored as column vectors (translation is fourth column)
    double _m[4][4];
    // maintained by program (1: identity, 
    //                        0: not identity
    //                        gsl_RECOMPUTE: not yet set)
    int _is_identity;
};

COW_COW_DECL(gsl_Matrix);


#endif  // #ifdef Matrix_h
