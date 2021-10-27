/*   -*- mode: c++ -*-   */
#ifndef inpO_ShellSection_h
#define inpO_ShellSection_h

///////////////////////////////////////////////////////////////////////////////
//
// Class: inpO_ShellSection
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

class inpO_ShellSection  : public mem_AllocationOperators
{
public:

   inpO_ShellSection(kseO_ApiExtension& sectApi,
                     const inp_Keyword& keyword,
                     const cow_String& sectionName,
                     const cow_String& materialName,
                     bool preintegrate);
   ~inpO_ShellSection();

   void Read();
   odb_Section& Create();

private:

   void ReadCompositeSection();
   void ReadHomogeneousSection();

   // data members
   const inp_Keyword& m_keyword;
   kseO_ApiExtension& m_sectApi;

   bool m_composite;
   bool m_preIntegrate;
   bool m_symmetric;

   int m_numIntPts;

   double m_poisson;
   double m_thickness;

   cow_String m_sectionName;
   cow_String m_materialName;
   cow_String m_layupName;
   cow_String m_integrationRule;
   cow_String m_poissonDefinition;
   cow_String m_temperature;

   odb_Union m_thicknessModulus;
   odb_Union m_nTemp;

   odb_SequenceSectionLayer m_layup;
};


COW_COUNTEDHLD_DECL(inpO_ShellSection, inpO_ShellSectionHld)


#endif /* inpO_ShellSection_h */
