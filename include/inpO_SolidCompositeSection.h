/*   -*- mode: c++ -*-   */
#ifndef inpO_SolidCompositeSection_h
#define inpO_SolidCompositeSection_h

///////////////////////////////////////////////////////////////////////////////
//
// Class: inpO_SolidCompositeSection
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

class inpO_SolidCompositeSection  : public mem_AllocationOperators
{
public:

   inpO_SolidCompositeSection(kseO_ApiExtension& sectApi,
                     const inp_Keyword& keyword,
                     const cow_String& sectionName );
   ~inpO_SolidCompositeSection();

   void Read();
   odb_Section& Create();

private:


   // data members
   const inp_Keyword& m_keyword;
   kseO_ApiExtension& m_sectApi;

   int m_numIntPts;

   cow_String m_sectionName;
   cow_String m_layupName;
   odb_SequenceSectionLayer m_layup;
  bool m_symmetric;
};


COW_COUNTEDHLD_DECL(inpO_SolidCompositeSection, inpO_SolidCompositeSectionHld)


#endif /* inpO_SolidCompositeSection_h */
