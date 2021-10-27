/*   -*- mode: c++ -*-   */
#ifndef inpO_EulerianSection_h
#define inpO_EulerianSection_h

///////////////////////////////////////////////////////////////////////////////
//
// Class: inpO_EulerianSection
//
// Description:
//

// Includes

// Forward declarations
class inp_Keyword;
class kseO_ApiExtension;
class odb_Section;

// Begin local includes
#include <mem_AllocationOperators.h>
#include <cow_CountedHld.h>
#include <cow_String.h>


#include <odb_SectionTypes.h>
#include <odb_Union.h>
#include <odb_Types.h>


// Class definition

class inpO_EulerianSection  : public mem_AllocationOperators
{
public:

   inpO_EulerianSection(kseO_ApiExtension& sectApi,
                     const inp_Keyword& keyword,
                     const cow_String& sectionName );
   ~inpO_EulerianSection();

   void Read();
   odb_Section& Create();

private:


   // data members
   const inp_Keyword& m_keyword;
   kseO_ApiExtension& m_sectApi;

   cow_String m_sectionName;
   odb_String m_defaultMaterial;
   odb_SequenceString m_materialMapKeys;
   odb_SequenceString m_materialMapValues;
};


COW_COUNTEDHLD_DECL(inpO_EulerianSection, inpO_EulerianSectionHld)


#endif /* inpO_EulerianSection_h */
