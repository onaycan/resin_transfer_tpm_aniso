/* -*- mode: c++ -*- */
///////////////////////////////////////////////////////////////////////////////
//
// File Name: gsl_Vector.h
// 
// Description:
//
//    This file contains the defintion of the gsl_Vector class.
//
// Author: Julio Carrera
// 
// Creation date: Thu May 20 1993
//


#ifndef gsl_Vector_h
#define gsl_Vector_h

//
// Includes
//


// Begin local includes
#include <mem_AllocationOperators.h>

#include <omi_types.h>
#include <cow_List.h>
#include <gsl_Point.h>

class aio_ostream;
class gsl_Matrix;
class gsl_Plane;

//
// Constants
//

//
// Class definition
//
class gsl_Vector  : public mem_AllocationOperators
{

  bool Intersection( const gsl_Vector& v1,
				const gsl_Point& p1,
				const gsl_Vector& v2,
				const gsl_Point& p2,
				gsl_Point&);

public:

// Constructors, Destructor

    // unit vector aligned with Z-axis
    gsl_Vector():_x(0.0),_y(0.0),_z(1.0),_magnitude(1.0){}


    // vector from 3 reals
    gsl_Vector(const double x, const double y, const double z)
      :_x(x),_y(y),_z(z),_magnitude(-1.0){}


    // vector from 1st point to 2nd one
    gsl_Vector(const gsl_Point& start, const gsl_Point& end)
    {
    _x = end.GetX() - start.GetX();
    _y = end.GetY() - start.GetY();
    _z = end.GetZ() - start.GetZ();
    // Defer square root until actually needed
    _magnitude = -1.0;
    }
    // unit normal to plane through 3 points, (0,0,0) if degenerate
    gsl_Vector(const gsl_Point&, 
	       const gsl_Point&, 
	       const gsl_Point&); 

    // needed for messaging

// Operators 

    bool operator==(const gsl_Vector&) const;
    bool operator!=(const gsl_Vector&) const;
    gsl_Vector operator-(const gsl_Vector& vec) const;
    gsl_Vector operator+(const gsl_Vector& vec) const;
    gsl_Vector operator*(const double) const;
    double operator[](uint) const;
    double& operator[](uint);

// Member functions

    void Negate();

    double DeltaX() const { return _x; }
    double DeltaY() const { return _y; }
    double DeltaZ() const { return _z; }

    double UnitX() const {
	return (Length() ? _x/_magnitude : 0);}
    double UnitY() const{
	return (Length() ? _y/_magnitude : 0);}
    double UnitZ() const{
	return (Length() ? _z/_magnitude : 0);}

    double Length() const {
        if(_magnitude < 0.0)
            ComputeMagnitude();
        return (_magnitude);
    }

    double LengthSq() const {
        if (_magnitude < 0.0)
            return _x*_x + _y*_y + _z*_z;
        return _magnitude*_magnitude;
    }

    double DotProduct (const gsl_Vector&) const;
    gsl_Vector CrossProduct (const gsl_Vector&) const;
    double TripleProduct(const gsl_Vector& v2,
                         const gsl_Vector& v3) const;

    void Scale (const double);
    bool Normalize(void);
    bool Normalize (const double len_tol);
    gsl_Vector NormalizedCopy(void) const;
    gsl_Vector ScaledCopy(const double) const;
    //tolerance is equal to angular tolerance
    bool IsOn(const gsl_Vector&, const double TOL = 10E-10)const;
    bool IsOrthogonal(const gsl_Vector&) const; 
    gsl_Vector AnyOrthogonalUnit() const; 
    gsl_Vector BestAlignedOrthogonalUnit() const; 
    gsl_Vector ProjectOn(gsl_Plane& plane) const; 
    double AngleWith(const gsl_Vector& vect, bool both_unit) const; 
    double AngleWith(const gsl_Vector& vect, bool both_unit, gsl_Vector& norm_dir) const; 
    bool AngleBetween(gsl_Vector vec1, gsl_Vector vec2, double& angle); 

    void RotateAndTransform (const gsl_Matrix&);
    void Print (aio_ostream&, int = 0) const;

    // methods to test whether two vector have the same direction
    // and whether they are parallel (same direction or opposite direction)
    bool SameDirection(const gsl_Vector&, const double TOL = 10E-6)const;
    bool IsParallel(const gsl_Vector&, const double TOL = 10E-6)const;
  
protected:

    void FromCoordinates( double x, double y, double z, double magnitude );
    void ToCoordinates( double &x, double &y, double &z, double &magnitude ) const;

private:
    void ComputeMagnitude() const;

    // the stored values are the raw values (not normalized)
    double _x, _y, _z;

    // the Euclidean norm of the vector
    mutable double _magnitude;
};

COW_LIST_DECL( gsl_Vector, gsl_ArrayVector );

#endif  // #ifdef Vector_h
