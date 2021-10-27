/*   -*- mode: c++ -*-   */
#ifndef inpO_SurfaceGenerator_h
#define inpO_SurfaceGenerator_h

///////////////////////////////////////////////////////////////////////////////
//
// Class: inpO_SurfaceGenerator
//
// Description:
//

// Includes

// Forward declarations
class odb_Set;
class odb_Assembly;
class odb_DiscreteEntity;
class odb_Part;
class inp_Keyword;
class inp_DataArray;


// Begin local includes
#include <inpO_MessageContainer.h>
#include <cow_String.h>

#include <odb_Enum.h>
#include <odb_Types.h>
#include <odb_SequenceElement.h>

#include <cow_COW.h>


// Class definition

class inpO_SurfaceGenerator: public inpO_MessageContainer
{
public:
   inpO_SurfaceGenerator();
   inpO_SurfaceGenerator(odb_Assembly* assembly, odb_Part* part);
   virtual ~inpO_SurfaceGenerator();

   bool InAssembly() const;

   virtual inpO_SurfaceGenerator* Copy() const = 0;

   const odb_SequenceInt& Labels() const;
   const odb_SequenceElement& Elements() const;
   const odb_SequenceElementFace& ElementFaces() const;

   virtual void Read(const inp_Keyword& keyword);

protected:
   odb_Enum::odb_ElementFaceEnum ReadElementFaceEnum(const inp_DataArray&, int, int);

   void AssertValidElementSet(const odb_DiscreteEntity* comp, 
                              const cow_String& setName) const;
   void AssertValidNodeSet(const odb_DiscreteEntity* comp, 
                           const cow_String& setName) const;
   cow_ListInt Elements2Labels(const odb_SequenceElement& elms) const;

   // data
   odb_DiscreteEntity*   m_component;
   odb_Part*             m_part;
   odb_Assembly*         m_assembly;

   odb_SequenceInt          m_labels;
   odb_SequenceElement      m_elements;
   odb_SequenceElementFace  m_elemFaces;
};

COW_COW2_DECL(inpO_SurfaceGenerator, cow_Virtual);

//---------------------------------------------------------------------------->
inline const odb_SequenceInt&
inpO_SurfaceGenerator::Labels() const
//---------------------------------------------------------------------------->
{
   return m_labels;
}

//---------------------------------------------------------------------------->
inline const odb_SequenceElement&
inpO_SurfaceGenerator::Elements() const
//---------------------------------------------------------------------------->
{
   return m_elements;
}

//---------------------------------------------------------------------------->
inline const odb_SequenceElementFace&
inpO_SurfaceGenerator::ElementFaces() const
//---------------------------------------------------------------------------->
{
   return m_elemFaces;
}

//---------------------------------------------------------------------------->
inline bool
inpO_SurfaceGenerator::InAssembly() const
//---------------------------------------------------------------------------->
{
   return (m_part == 0) ? true : false;
}



class inpO_ElementSurfaceGenerator: public inpO_SurfaceGenerator
{
public:
   inpO_ElementSurfaceGenerator(odb_Assembly* assembly, odb_Part* part);
   virtual ~inpO_ElementSurfaceGenerator();

   virtual inpO_SurfaceGenerator* Copy() const;

   virtual void Read(const inp_Keyword& keyword);
};

#endif /* inpO_SurfaceGenerator_h */
