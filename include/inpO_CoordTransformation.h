/*   -*- mode: c++ -*-   */
#ifndef inpO_CoordTransformation_h
#define inpO_CoordTransformation_h

#if defined (HKS_NT)
#pragma warning (disable: 4584)
#endif

///////////////////////////////////////////////////////////////////////////////
//
// Class: inpO_CoordTransformation
//
// Description:
//

// Includes

// Forward declarations
class odb_DiscreteEntity;
class inp_Keyword;


// Begin local includes
#include <mem_AllocationOperators.h>
#include <inpO_MessageContainer.h>
#include <inpO_KeywordParameterReader.h>

#include <gsl_Point.h>
#include <gsl_StLine.h>
#include <gsl_Plane.h>
#include <gsl_Matrix.h>

#include <cow_COW.h>


// Class definition

class inpO_CoordTransformation
    : public mem_AllocationOperators, protected inpO_MessageContainer
{
public:
   inpO_CoordTransformation();
   ~inpO_CoordTransformation();

   virtual void Transform(double& x, double& y, double& z) = 0;
   virtual bool IsValid() const { return m_valid; }

   virtual inpO_CoordTransformation* Copy() const = 0;

private:
   bool m_valid;
};

COW_COW2_DECL(inpO_CoordTransformation, cow_Virtual);




class inpO_CoordTransformationFactory: protected inpO_KeywordParameterReader
{
public:
   inpO_CoordTransformationFactory(odb_DiscreteEntity* component = 0);
   ~inpO_CoordTransformationFactory();

   inpO_CoordTransformationCOW Make(const inp_Keyword& keyword);

protected:
   inpO_CoordTransformation* CreatePoleTransformation(const inp_Keyword&);
   inpO_CoordTransformation* CreateShiftTransformation(const inp_Keyword&);
   inpO_CoordTransformation* CreateReflectTransformation(const inp_Keyword&);

   bool HasLabel(int label) const;
   void ReadPointFromKeywordData(const inp_Keyword& keyword, int, int, gsl_Point&) const;
   void UpdatePointCoordinates(int nodeLabel, gsl_Point& point) const;

private:
   odb_DiscreteEntity* m_component;
};




class inpO_ShiftTransformation: public inpO_CoordTransformation
{
public:
   inpO_ShiftTransformation(const gsl_Point& translation);
   ~inpO_ShiftTransformation();

   virtual void Transform(double& x, double& y, double& z);

   virtual inpO_CoordTransformation* Copy() const;

protected:
   gsl_Matrix m_transformation;
};



class inpO_ShiftAndRotateTransformation: public inpO_ShiftTransformation
{
public:
   inpO_ShiftAndRotateTransformation(const gsl_Point& translation,
                            const gsl_Point& rotationPointA,
                            const gsl_Point& rotationPointB,
                            double angle);
   ~inpO_ShiftAndRotateTransformation();

   virtual inpO_CoordTransformation* Copy() const;
};



class inpO_MirrorLineTransformation: public inpO_CoordTransformation
{
public:
   inpO_MirrorLineTransformation(const gsl_Point& point1,
                                 const gsl_Point& point2);
   ~inpO_MirrorLineTransformation();

   virtual void Transform(double& x, double& y, double& z);
   virtual inpO_CoordTransformation* Copy() const;

protected:
   double     m_distance;
   gsl_StLine m_line;
   gsl_Point  m_projection;
};



class inpO_MirrorPlaneTransformation: public inpO_CoordTransformation
{
public:
   inpO_MirrorPlaneTransformation(const gsl_Point& pointA,
                                  const gsl_Point& pointB,
                                  const gsl_Point& pointC);
   ~inpO_MirrorPlaneTransformation();

   virtual void Transform(double& x, double& y, double& z);
   virtual inpO_CoordTransformation* Copy() const;

protected:
   double     m_distance;

   gsl_Point  m_pointA;
   gsl_Point  m_pointB;
   gsl_Point  m_pointC;
   
   gsl_Plane  m_plane;
   gsl_Point  m_projection;
};



class inpO_MirrorPointTransformation: public inpO_CoordTransformation
{
public:
   inpO_MirrorPointTransformation(const gsl_Point& pivot);
   ~inpO_MirrorPointTransformation();

   virtual void Transform(double& x, double& y, double& z);
   virtual inpO_CoordTransformation* Copy() const;

protected:
   double     m_distance;

   gsl_Point  m_pivot;
};



class inpO_PoleTransformation: public inpO_CoordTransformation
{
public:
   inpO_PoleTransformation(const gsl_Point& pole);
   ~inpO_PoleTransformation();

   virtual void Transform(double& x, double& y, double& z);
   virtual inpO_CoordTransformation* Copy() const;

protected:
   gsl_Point  m_pole;
};



#endif /* inpO_CoordTransformation_h */
