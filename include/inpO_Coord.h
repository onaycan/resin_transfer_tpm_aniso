/*   -*- mode: c++ -*-   */
#ifndef inpO_Coord_h
#define inpO_Coord_h

///////////////////////////////////////////////////////////////////////////////
//
// Class: inpO_Coord
//
// Description:
//

// Includes

// Forward declarations
class odb_Node;

// Begin local includes
#include <mem_AllocationOperators.h>

// Class definition

class inpO_Coord  : public mem_AllocationOperators
{
public:
   double x, y, z;
   // double nx, ny, nz;

   inpO_Coord() { x = y = z = 0.0; }
   inpO_Coord(double xx, double yy, double zz);
   inpO_Coord(const odb_Node&);
   ~inpO_Coord() {}

   inpO_Coord& operator=(const odb_Node&);

   void Cylindrical2Rectangular();
   void Spherical2Rectangular();

   void ZeroSmallerThanTolerance();

private:

   void CylindricalConversion(double&, double&) const;
   void SphericalConversion(double&, double&, double&) const;
};


#endif /* inpO_Coord_h */
