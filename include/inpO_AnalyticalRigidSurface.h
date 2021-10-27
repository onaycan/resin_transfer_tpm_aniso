/* -*- mode: c++ -*- */
#ifndef inpO_AnalyticalRigidSurface_h
#define inpO_AnalyticalRigidSurface_h

////////////////////////////////////////////////////////////////////////
//
//  Name: inpO_AnalyticalRigidSurface
//
//  Description: Write analytical rigid surfaces to ODB
//

// Forward declaration
class inpO_AnalyticalRigidSurfaceVisitor;
class inp_Keyword;
class odb_SequenceAnalyticSurfaceSegment;

//
// Begin local includes
#include <mem_AllocationOperators.h>
//

#include <cow_List.h>
#include <cow_Map.h>
#include <cow_String.h>
#include <inpO_Enum.h>


class inpO_SurfaceSegment  : public mem_AllocationOperators
{
public:
   inpO_SurfaceSegment() {}
   inpO_SurfaceSegment(inpO_Enum::SurfaceSegmentType segType,
                       double x1, double y1, double x2 = 0.0, double y2 = 0.0);

   double GetX1() const;
   double GetY1() const;
   double GetX2() const;
   double GetY2() const;

   bool IsStart() const;
   bool IsLine() const;
   bool IsCircularArc() const;
   bool IsParabolicArc() const;

private:
   inpO_Enum::SurfaceSegmentType m_type;

   double m_x1;
   double m_y1;
   double m_x2;
   double m_y2;
};

COW_LIST_DECL(inpO_SurfaceSegment, inpO_SurfaceSegmentList);


//---------------------------------------------------------------------------->
inline double
inpO_SurfaceSegment::GetX1() const
//---------------------------------------------------------------------------->
{
   return m_x1;
}

//---------------------------------------------------------------------------->
inline double
inpO_SurfaceSegment::GetY1() const
//---------------------------------------------------------------------------->
{
   return m_y1;
}

//---------------------------------------------------------------------------->
inline double
inpO_SurfaceSegment::GetX2() const
//---------------------------------------------------------------------------->
{
   return m_x2;
}

//---------------------------------------------------------------------------->
inline double
inpO_SurfaceSegment::GetY2() const
//---------------------------------------------------------------------------->
{
   return m_y2;
}

//---------------------------------------------------------------------------->
inline bool
inpO_SurfaceSegment::IsStart() const
//---------------------------------------------------------------------------->
{
   return (m_type == inpO_Enum::START);
}

//---------------------------------------------------------------------------->
inline bool
inpO_SurfaceSegment::IsLine() const
//---------------------------------------------------------------------------->
{
   return (m_type == inpO_Enum::LINE);
}

//---------------------------------------------------------------------------->
inline bool
inpO_SurfaceSegment::IsCircularArc() const
//---------------------------------------------------------------------------->
{
   return (m_type == inpO_Enum::CIRCL);
}

//---------------------------------------------------------------------------->
inline bool
inpO_SurfaceSegment::IsParabolicArc() const
//---------------------------------------------------------------------------->
{
   return (m_type == inpO_Enum::PARAB);
}


class inpO_AnalyticalRigidSurface  : public mem_AllocationOperators
{
public:
   inpO_AnalyticalRigidSurface() {}
   inpO_AnalyticalRigidSurface(inpO_Enum::ARSType surf_type,
                               const cow_String& name,
                               bool internal = false);

   void ReadProfile(const inp_Keyword& keyword);

   void SetFilletRadius(double);
   double GetFilletRadius() const;

   const cow_String& Name() const;
   bool Internal() const;

   bool HasSegmentsType() const;
   bool HasCylinderType() const;
   bool HasRevolutionType() const;
   cow_String GetType() const;

   void ToOdbSurfaceProfile(odb_SequenceAnalyticSurfaceSegment& profile) const;

private:
   inpO_Enum::ARSType m_type;

   cow_String m_name;
   bool m_internal;

   double m_filletRadius;

   inpO_SurfaceSegmentList m_segmentList;
};

COW_MAP_ITER_DECL(cow_String, inpO_AnalyticalRigidSurface, inpO_AnalyticalRigidSurfaceMap);


//---------------------------------------------------------------------------->
inline void
inpO_AnalyticalRigidSurface::SetFilletRadius(double val)
//---------------------------------------------------------------------------->
{
   m_filletRadius = val;
}

//---------------------------------------------------------------------------->
inline double
inpO_AnalyticalRigidSurface::GetFilletRadius() const
//---------------------------------------------------------------------------->
{
   return m_filletRadius;
}

//---------------------------------------------------------------------------->
inline const cow_String&
inpO_AnalyticalRigidSurface::Name() const
//---------------------------------------------------------------------------->
{
   return m_name;
}

//---------------------------------------------------------------------------->
inline bool
inpO_AnalyticalRigidSurface::Internal() const
//---------------------------------------------------------------------------->
{
   return m_internal;
}

//---------------------------------------------------------------------------->
inline bool
inpO_AnalyticalRigidSurface::HasSegmentsType() const
//---------------------------------------------------------------------------->
{
   return (m_type == inpO_Enum::SEGMENTS);
}

//---------------------------------------------------------------------------->
inline bool
inpO_AnalyticalRigidSurface::HasCylinderType() const
//---------------------------------------------------------------------------->
{
   return (m_type == inpO_Enum::CYLINDER);
}

//---------------------------------------------------------------------------->
inline bool
inpO_AnalyticalRigidSurface::HasRevolutionType() const
//---------------------------------------------------------------------------->
{
   return (m_type == inpO_Enum::REVOLUTION);
}


#endif // inpO_AnalyticalRigidSurface_h
