/*   -*- mode: c++ -*-   */
#ifndef inpO_ElementReader_h
#define inpO_ElementReader_h

///////////////////////////////////////////////////////////////////////////////
//
// Class: inpO_ElementReader
//
// Description:
//

// Includes

// Forward declarations
class inp_Keyword;
class inpO_BasicElemTypeData;

// Begin local includes
#include <inpO_KeywordReader.h>
#include <odb_Types.h>
#include <odb_String.h>
#include <odb_SectionCategory.h>

#include <inpM_Set.h>

// Class definition

class inpO_ElementReader: public inpO_KeywordReader
{
public:

   inpO_ElementReader(const inp_Keyword& keyword,
                      const inpO_BasicElemTypeData& basicElemTypeData);
   ~inpO_ElementReader();

   const odb_SequenceInt&         Labels() const;
   const odb_SequenceSequenceInt& Connectivity() const;
   const cow_String&              Type() const;
   const cow_String&              Elset() const;
   const odb_SectionCategory&     SectionCategory() const;

   void ProcessElement();

   const inpM_SortedSet& Set() const;

private:

   const inpO_BasicElemTypeData& m_basicElemTypeData;

   odb_SequenceInt          m_labels;
   odb_SequenceSequenceInt  m_connectivity;

   cow_String               m_type;
   cow_String               m_elset;

   odb_SectionCategory      m_sectionCategory;

   inpM_SortedSet      m_set;
};


//---------------------------------------------------------------------------->
inline const odb_SequenceInt&
inpO_ElementReader::Labels() const
//---------------------------------------------------------------------------->
{
   return m_labels;
}

//---------------------------------------------------------------------------->
inline const odb_SequenceSequenceInt&
inpO_ElementReader::Connectivity() const
//---------------------------------------------------------------------------->
{
   return m_connectivity;
}

//---------------------------------------------------------------------------->
inline const cow_String&
inpO_ElementReader::Type() const
//---------------------------------------------------------------------------->
{
   return m_type;
}

//---------------------------------------------------------------------------->
inline const cow_String&
inpO_ElementReader::Elset() const
//---------------------------------------------------------------------------->
{
   return m_elset;
}

//---------------------------------------------------------------------------->
inline const odb_SectionCategory&
inpO_ElementReader::SectionCategory() const
//---------------------------------------------------------------------------->
{
   return m_sectionCategory;
}

//---------------------------------------------------------------------------->
inline const inpM_SortedSet&
inpO_ElementReader::Set() const
//---------------------------------------------------------------------------->
{
   return m_set;
}


#endif /* inpO_ElementReader_h */
