/* -*- mode: c++ -*- */
#ifndef inpO_RigidBody_h
#define inpO_RigidBody_h

////////////////////////////////////////////////////////////////////////
//
//  Name: inpO_RigidBody
//
//  Description:
//

// Forward declaration

//
// Begin local includes
#include <mem_AllocationOperators.h>
//

#include <cow_List.h>
#include <cow_Map.h>
#include <cow_String.h>



class inpO_RigidBody  : public mem_AllocationOperators
{
public:
   inpO_RigidBody();
   inpO_RigidBody(const cow_String& refNodeName);

   void SetAnalyticalSurfaceName(const cow_String&);
   void SetElsetName(const cow_String&);
   void SetIsothermal(bool isothermal = false);
   void SetPinNsetName(const cow_String&);
   void SetTieNsetName(const cow_String&);
   void SetPosition(const cow_String&);

   const cow_String& GetRefNode() const;
   const cow_String& GetAnalyticalSurface() const;
   const cow_String& GetElset() const;
   bool  GetIsothermal() const;
   const cow_String& GetPinNsetName() const;
   const cow_String& GetTieNsetName() const;
   const cow_String& GetPosition() const;

private:
   bool m_isothermal;

   cow_String m_refNodeName;
   cow_String m_analyticalSurfaceName;
   cow_String m_elsetName;

   cow_String m_pinNsetName;
   cow_String m_tieNsetName;
   cow_String m_position;
};

COW_LIST_DECL(inpO_RigidBody, inpO_RigidBodyList);
COW_MAP_ITER_DECL(cow_String, inpO_RigidBodyList, inpO_RigidBodyListMap);


//---------------------------------------------------------------------------->
inline void
inpO_RigidBody::SetAnalyticalSurfaceName(const cow_String& name)
//---------------------------------------------------------------------------->
{
   m_analyticalSurfaceName = name;
}

//---------------------------------------------------------------------------->
inline void
inpO_RigidBody::SetElsetName(const cow_String& name)
//---------------------------------------------------------------------------->
{
   m_elsetName = name;
}

//---------------------------------------------------------------------------->
inline void
inpO_RigidBody::SetIsothermal(bool isothermal)
//---------------------------------------------------------------------------->
{
   m_isothermal = isothermal;
}

//---------------------------------------------------------------------------->
inline void
inpO_RigidBody::SetPinNsetName(const cow_String& name)
//---------------------------------------------------------------------------->
{
    m_pinNsetName = name;
}

//---------------------------------------------------------------------------->
inline void
inpO_RigidBody::SetTieNsetName(const cow_String& name)
//---------------------------------------------------------------------------->
{
   m_tieNsetName = name;
}

//---------------------------------------------------------------------------->
inline void
inpO_RigidBody::SetPosition(const cow_String& pos)
//---------------------------------------------------------------------------->
{
  m_position = pos;
}

//---------------------------------------------------------------------------->
inline const cow_String&
inpO_RigidBody::GetRefNode() const
//---------------------------------------------------------------------------->
{
   return m_refNodeName;
}

//---------------------------------------------------------------------------->
inline const cow_String&
inpO_RigidBody::GetAnalyticalSurface() const
//---------------------------------------------------------------------------->
{
   return m_analyticalSurfaceName;
}

//---------------------------------------------------------------------------->
inline const cow_String&
inpO_RigidBody::GetElset() const
//---------------------------------------------------------------------------->
{
   return m_elsetName;
}

//---------------------------------------------------------------------------->
inline bool
inpO_RigidBody::GetIsothermal() const
//---------------------------------------------------------------------------->
{
   return m_isothermal;
}

//---------------------------------------------------------------------------->
inline const cow_String&
inpO_RigidBody::GetPinNsetName() const
//---------------------------------------------------------------------------->
{
   return m_pinNsetName;
}

//---------------------------------------------------------------------------->
inline const cow_String&
inpO_RigidBody::GetTieNsetName() const
//---------------------------------------------------------------------------->
{
   return m_tieNsetName;
}

//---------------------------------------------------------------------------->
inline const cow_String&
inpO_RigidBody::GetPosition() const
//---------------------------------------------------------------------------->
{
   return m_position;
}


#endif // inpO_RigidBody_h
