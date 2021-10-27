/*   -*- mode: c++ -*-   */
#ifndef inpO_OrientationVisitor_h
#define inpO_OrientationVisitor_h

///////////////////////////////////////////////////////////////////////////////
//
// Name: inpO_OrientationVisitor
//
// Description: create mesh in the database
//

// Includes

// Forward declarations

// Begin local includes
#include <cow_String.h>
#include <inpO_Visitor.h>
#include <odb_Types.h>


// Class definition

class inpO_OrientationVisitor: public inpO_Visitor
{
public:

   inpO_OrientationVisitor(odb_Odb& odb, inpO_ModelInventory&);
   ~inpO_OrientationVisitor();

   //
   virtual void VisitOrientation(inp_Keyword&);

protected:
   void CheckOrientationValidity(const inp_Keyword& keyword,
                                 odb_Enum::odb_DatumCsysTypeEnum,
                                 const double&, const double&, const double&, 
                                 const double&, const double&, const double&, 
                                 const double&, const double&, const double&) const;

   void NormalizeRectangularOrientation(const inp_Keyword& keyword,
                                        const cow_String& system,
                                        odb_Enum::odb_DatumCsysTypeEnum type,
                                        const double& ox, const double& oy, const double& oz,
                                        double& ax, double& ay, double& az, 
                                        double& bx, double& by, double& bz) const;
   void RotateRectangularOrientation(const inp_Keyword& keyword,
                                     odb_Enum::odb_DatumCsysTypeEnum type,
                                     int direction,
                                     double rotation,
                                     const double& ox, const double& oy, const double& oz,
                                     double& ax, double& ay, double& az, 
                                     double& bx, double& by, double& bz) const;
};

#endif /* inpO_OrientationVisitor_h */
