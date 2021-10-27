/*   -*- mode: c++ -*-   */
#ifndef inpO_BeamSection_h
#define inpO_BeamSection_h

///////////////////////////////////////////////////////////////////////////////
//
// Class: inpO_BeamSection
//
// Description:
//

// Includes

// Forward declarations
class inp_Keyword;
class inp_DataArray;
class kseO_ApiExtension;
class odb_Section;

// Begin local includes
#include <mem_AllocationOperators.h>
#include <cow_CountedHld.h>
#include <cow_String.h>

#include <inpO_KeywordDataTable.h>

#include <odb_SectionTypes.h>
#include <odb_Union.h>
#include <odb_Types.h>


// Class definition

class inpO_BeamSection : public mem_AllocationOperators
{
public:
   inpO_BeamSection(kseO_ApiExtension& sectApi,
                    const cow_String& sectionName,
                    const cow_String& materialName,
                    const cow_String& profileName);
   ~inpO_BeamSection();

   void Read(const inp_Keyword& keyword);

   void ReadBeamSection(const inp_Keyword& keyword);
   void ReadBeamGeneralSection(const inp_Keyword& keyword);
   void ReadCentroid(const inp_Keyword& keyword);
   void ReadDamping(const inp_Keyword& keyword);
   void ReadSectionPoints(const inp_Keyword& keyword);
   void ReadShearCenter(const inp_Keyword& keyword);
   void ReadBeamFluidInertia(const inp_Keyword& keyword); 

   const odb_SequenceDouble& Orientation() const;

   odb_Section& Create();

   void ReadOrientationData(const inp_Keyword& keyword);

   bool IsSectionMeshed() const;

private:

   void ReadCommonData(const inp_Keyword& keyword);
   void ReadOrientationData(const inp_DataArray& data, int row);

   // data members
   kseO_ApiExtension& m_sectApi;

   bool m_thermalExpansion;
   bool m_meshedSection;
   bool m_useFluidInertia;

   double m_alpha;
   double m_beta;
   double m_composite;
   double m_poissonRatio;
   double m_lateralMassCoef;
   double m_axialMassCoef;
   double m_massOffsetX;
   double m_massOffsetY;

   cow_String m_sectionName;
   cow_String m_materialName;
   cow_String m_profileName;
   cow_String m_integration;
   cow_String m_tempVar;
   cow_String m_submerged;

   odb_Union m_density;
   odb_Union m_refTemp;
   odb_Union m_fluidMassDensity;
   odb_Union m_crossSectionRadius;


   odb_SequenceDouble m_centroid;
   odb_SequenceDouble m_shearCenter;
   odb_SequenceDouble m_orientation;
   odb_SequenceSequenceDouble m_outputPts;

   inpO_KeywordDataTable m_table;
};

COW_COUNTEDHLD_DECL(inpO_BeamSection, inpO_BeamSectionHld)


//---------------------------------------------------------------------------->
inline const odb_SequenceDouble& 
inpO_BeamSection::Orientation() const
//---------------------------------------------------------------------------->
{
   return m_orientation;
}


//---------------------------------------------------------------------------->
inline bool
inpO_BeamSection::IsSectionMeshed() const
//---------------------------------------------------------------------------->
{
   return m_meshedSection;
}


#endif /* inpO_BeamSection_h */
