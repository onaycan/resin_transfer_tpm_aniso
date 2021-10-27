/*   -*- mode: c++ -*-   */
#ifndef inpO_AbaqusName_h
#define inpO_AbaqusName_h

///////////////////////////////////////////////////////////////////////////////
//
// Class: inpO_AbaqusName
//
// Description:
//

// Includes

// Forward declarations

// Begin local includes
#include <mem_AllocationOperators.h>
#include <cow_String.h>


// Class definition

class inpO_AbaqusName  : public mem_AllocationOperators
{
public:
   inpO_AbaqusName(bool inAssembly = false);
   inpO_AbaqusName(const cow_String& name, bool inAssembly = false);
   ~inpO_AbaqusName();

   void Init(const cow_String& name);
   void InitWithId(const cow_String& name);
   void InitWithId(int id);
   void InitWithSet(const cow_String& name);

   const cow_String& AssemblyName() const;
   const cow_String& ComponentName() const;
   const cow_String& SetName() const;

   int Id() const;

   cow_String FullName() const;

   void SetComponentName(const cow_String&);

   bool IsAssemblyDefined() const;
   bool IsComponentDefined() const;
   bool IsSetDefined() const;
   bool IsIdDefined() const;

   bool InAssembly() const;

   bool IsValid() const;
   void AssertValid() const;
   void AssertValidNodeDefined() const;
   void AssertValidSetDefined() const;

private:

   bool IsInt(const cow_String& name) const;
   bool IsValidSetName(const cow_String& name) const;

   bool m_inAssembly;

   cow_String  m_assembly;
   cow_String  m_component;
   cow_String  m_set;

   int         m_id;
};


//---------------------------------------------------------------------------->
inline const cow_String&
inpO_AbaqusName::AssemblyName() const
//---------------------------------------------------------------------------->
{
   return m_assembly;
}

//---------------------------------------------------------------------------->
inline const cow_String&
inpO_AbaqusName::ComponentName() const
//---------------------------------------------------------------------------->
{
   return m_component;
}

//---------------------------------------------------------------------------->
inline const cow_String&
inpO_AbaqusName::SetName() const
//---------------------------------------------------------------------------->
{
   return m_set;
}

//---------------------------------------------------------------------------->
inline int
inpO_AbaqusName::Id() const
//---------------------------------------------------------------------------->
{
   return m_id;
}

//---------------------------------------------------------------------------->
inline bool
inpO_AbaqusName::IsAssemblyDefined() const
//---------------------------------------------------------------------------->
{
   return (! m_assembly.Empty());
}

//---------------------------------------------------------------------------->
inline bool
inpO_AbaqusName::IsComponentDefined() const
//---------------------------------------------------------------------------->
{
   return (! m_component.Empty());
}

//---------------------------------------------------------------------------->
inline bool
inpO_AbaqusName::IsSetDefined() const
//---------------------------------------------------------------------------->
{
   return (! m_set.Empty());
}

//---------------------------------------------------------------------------->
inline bool
inpO_AbaqusName::IsIdDefined() const
//---------------------------------------------------------------------------->
{
   return (m_id != 0);
}

//---------------------------------------------------------------------------->
inline bool
inpO_AbaqusName::InAssembly() const
//---------------------------------------------------------------------------->
{
   return m_inAssembly;
}

//---------------------------------------------------------------------------->
inline void
inpO_AbaqusName::SetComponentName(const cow_String& newName)
//---------------------------------------------------------------------------->
{
   m_component = newName;
}


#endif /* inpO_AbaqusName_h */
