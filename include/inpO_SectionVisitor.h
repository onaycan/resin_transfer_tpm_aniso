/* -*- mode: c++ -*- */
#ifndef inpO_SectionVisitor_h
#define inpO_SectionVisitor_h

////////////////////////////////////////////////////////////////////////
//
//  Name: inpO_SectionVisitor
//
//  Description: Write section data to ODB using ODB API 
//

// Begin local includes
#include <cow_String.h>
#include <cow_ArrayCOW.h>
#include <inp_keywords.h>
#include <inpO_Visitor.h>
#include <inpO_ShellSection.h>
#include <inpO_BeamSection.h>

#include <kmaO_ApiExtension.h>
#include <kseO_ApiExtension.h>

#include <odb_Types.h>
#include <odb_Enum.h>

// Forward declaration
class inp_Keyword;
class inpO_BeamProfileFactory;

class odb_Section;
COW_ARRAYCOW2_DECL(odb_Section,cow_Virtual);

class odb_Odb;
class odb_String;
class odb_Union;
class odb_DiscreteEntity;
class odb_Set;

// Class definitions
class inpO_SectionVisitor: public inpO_Visitor
{ 
public:
   inpO_SectionVisitor(odb_Odb& odb, 
                       inpO_ModelInventory& modelInv,
                       bool assignSectionsFlag = false);
   ~inpO_SectionVisitor();

   virtual void VisitSuboptions(inp_Keyword&);

   void SetAssignSectionsFlag(bool assignFlag = true);

protected:    

   virtual void DefaultAction(inp_Keyword &); // Do nothing

   cow_String MakeSectionName(const inp_Keyword& keyword) const;
   cow_String MakeMaterialName(const inp_Keyword& keyword) const;
   void AssertMaterialExists(const cow_String& materialName);
   void CheckMaterial(const inp_Keyword& keyword,
                      const cow_String& materialName);
   inpO_BeamProfileFactory& GetBeamProfileFactory();

   // Only the following keywords are processed
   virtual void VisitBeamGeneralSection(inp_Keyword& keyword);
   virtual void VisitBeamSection(inp_Keyword& keyword);
   virtual void VisitCentroid(inp_Keyword& keyword);
   virtual void VisitCohesiveSection(inp_Keyword& keyword);
   virtual void VisitDamping(inp_Keyword&);
   virtual void VisitFrameSection(inp_Keyword& keyword);
   virtual void VisitGasketSection(inp_Keyword& keyword);
   virtual void VisitHeatCap(inp_Keyword& keyword);
   virtual void VisitMass(inp_Keyword& keyword);
   virtual void VisitMembraneSection(inp_Keyword& keyword);
   virtual void VisitShearCenter(inp_Keyword& keyword);
   virtual void VisitShellGeneralSection(inp_Keyword& keyword);
   virtual void VisitShellSection(inp_Keyword& keyword);
   virtual void VisitSolidSection(inp_Keyword& keyword);
   virtual void VisitEulerianSection(inp_Keyword& keyword);
   virtual void VisitSurfaceSection(inp_Keyword& keyword);
   virtual void VisitTransverseShearStiffness(inp_Keyword& keyword);
   virtual void VisitRebarLayer(inp_Keyword& keyword);
   virtual void VisitRotaryInertia(inp_Keyword& keyword);
   virtual void VisitSectionPoints(inp_Keyword& keyword);
   virtual void VisitBeamFluidInertia(inp_Keyword&);

private:
   void AssignSection(const odb_Section& section, 
                      const cow_String& setName);
   void AssignMaterialOrientation(const inp_Keyword& keyword);
   void AssignBeamOrientation(const cow_String& setName,
                              const odb_SequenceDouble& orient);
   void AssignRebarOrientation(const inp_Keyword& sectionKeyword);
   void AssignSection2Elset(const inp_Keyword& keyword);
   void AssertValidElementSet(const odb_DiscreteEntity* comp, 
                              const cow_String& setName) const;
   cow_String GetElsetName(const inp_Keyword& keyword) const;
   const odb_Set& GetElementSet(const odb_DiscreteEntity* comp, 
                                const cow_String& setName) const;

   void ReadAdditionalRotation(const inp_Keyword& keyword,
                               int& direction,
                               double& rotation);
   odb_Enum::odb_AxisEnum Direction2AxisEnum(int direction) const;
   // Data
   bool m_assignSections;

   kseO_ApiExtension m_sectApi;
   kmaO_ApiExtension m_matApi;

   odb_SectionCOW m_section;

   inpO_ShellSectionHld m_shellSectionHld;
   inpO_BeamSectionHld m_beamSectionHld;

   inpO_BeamProfileFactory* m_beamProfileFactory;
};

//---------------------------------------------------------------------------->
inline void
inpO_SectionVisitor::SetAssignSectionsFlag(bool assignFlag)
//---------------------------------------------------------------------------->
{
   m_assignSections = assignFlag;
}


#endif

