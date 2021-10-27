/*   -*- mode: c++ -*-   */
#ifndef inpO_NodeReader_h
#define inpO_NodeReader_h

///////////////////////////////////////////////////////////////////////////////
//
// Class: inpO_NodeReader
//
// Description:
//

// Includes

// Forward declarations
class inp_Keyword;
class odb_SequenceNode;
class odb_DiscreteEntity;

// Begin local includes
#include <inpO_MessageContainer.h>
#include <inpO_KeywordParameterReader.h>
#include <inpM_OmiSet.h>

#include <odb_Enum.h>
#include <odb_Types.h>
#include <odb_String.h>


// Class definition

class inpO_NodeReader: protected inpO_KeywordParameterReader, protected inpO_MessageContainer
{
public:
   
   inpO_NodeReader(const inp_Keyword&, 
                   odb_DiscreteEntity* component,
                   bool inAssembly = false,
                   odb_Enum::odb_DimensionEnum coorSpace = odb_Enum::THREE_D);
   ~inpO_NodeReader();

   const odb_SequenceInt& Labels() const;
   const odb_SequenceSequenceDouble& Coordinates() const;
   const odb_String& SetName() const;
   const inpM_OmiSet& Set() const;

   void ProcessNfill();
   void ProcessNgen();
   void ProcessNmap();
   void ProcessNode();
   void ProcessNormal();
   void ProcessNcopy();
   void ProcessNset();

private:

   void AddNode(int label, double x, double y, double z);
   void AssertNodeSetExists(const cow_String& setName) const;

   // data
   bool m_inAssembly;
   odb_Enum::odb_DimensionEnum  m_coordSpace;

   const inp_Keyword&  m_keyword;
   odb_DiscreteEntity* m_component;

   odb_SequenceInt            m_labels;
   odb_SequenceSequenceDouble  m_coords;

   odb_String                 m_setName;

   inpM_OmiSet                m_set;
};


//---------------------------------------------------------------------------->
inline const odb_SequenceInt&
inpO_NodeReader::Labels() const
//---------------------------------------------------------------------------->
{
   return m_labels;
}

//---------------------------------------------------------------------------->
inline const odb_SequenceSequenceDouble&
inpO_NodeReader::Coordinates() const
//---------------------------------------------------------------------------->
{
   return m_coords;
}

//---------------------------------------------------------------------------->
inline const odb_String&
inpO_NodeReader::SetName() const
//---------------------------------------------------------------------------->
{
   return m_setName;
}

//---------------------------------------------------------------------------->
inline const inpM_OmiSet&
inpO_NodeReader::Set() const
//---------------------------------------------------------------------------->
{
   return m_set;
}


#endif /* inpO_NodeReader_h */
