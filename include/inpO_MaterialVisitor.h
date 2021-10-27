/* -*- mode: c++ -*- */
#ifndef inpO_MaterialVisitor_h
#define inpO_MaterialVisitor_h

////////////////////////////////////////////////////////////////////////
//
//  Name: inpO_MaterialVisitor
//
//  Description: Write material data to ODB using the ODB API
//

// Begin local includes
#include <cow_ArrayCOW.h>
#include <inpO_Visitor.h>
#include <inpO_AcousticMediumReader.h>
#include <inpO_DruckerPragerHardening.h>
#include <inpO_SorptionReader.h>
#include <inpO_UserMaterialReader.h>

#include <kmaO_ApiExtension.h>
#include <kmaO_Material.h>

#include <odb_Types.h>

// Forward Definitions
class odb_Odb;
class kmaO_DamageInitiation;

// Class definitions

////////////////////////////////////////////////////////////////////

class inpO_MaterialVisitor: public inpO_Visitor
{
public:
   inpO_MaterialVisitor(odb_Odb& odb, inpO_ModelInventory& modelInv);
   ~inpO_MaterialVisitor();

   virtual void VisitSuboptions(inp_Keyword&);

   kmaO_ApiExtension& MaterialApiExt();
    
protected:

    void CreateMaterialOptionsFromReaders();
    void CreateGasketThicknessBehavior(inp_Keyword&);
    void CreatePlastic(inp_Keyword&);

    virtual void VisitMaterial(inp_Keyword&);
    virtual void VisitGasketBehavior(inp_Keyword&); 

    virtual void VisitAcousticMedium( inp_Keyword&);
    virtual void VisitAnnealTemperature(inp_Keyword&);
    virtual void VisitBiaxialTestData(inp_Keyword&);
    virtual void VisitBrittleCracking(inp_Keyword&);
    virtual void VisitBrittleFailure(inp_Keyword&);
    virtual void VisitBrittleShear(inp_Keyword&);
    virtual void VisitCapCreep(inp_Keyword&);
    virtual void VisitCapHardening(inp_Keyword&);
    virtual void VisitCapPlasticity(inp_Keyword&);
    virtual void VisitCastIronCompressionHardening(inp_Keyword&);
    virtual void VisitCastIronPlasticity(inp_Keyword&);
    virtual void VisitCastIronTensionHardening(inp_Keyword&);
    virtual void VisitClayHardening(inp_Keyword&);
    virtual void VisitClayPlasticity(inp_Keyword&);
    virtual void VisitConcrete(inp_Keyword&);
    virtual void VisitConcreteCompressionDamage(inp_Keyword&);
    virtual void VisitConcreteCompressionHardening(inp_Keyword&);
    virtual void VisitConcreteDamagedPlasticity(inp_Keyword&);
    virtual void VisitConcreteTensionDamage(inp_Keyword&);
    virtual void VisitConcreteTensionStiffening(inp_Keyword&);
    virtual void VisitConductivity(inp_Keyword&);
    virtual void VisitCombinedTestData(inp_Keyword&);
    virtual void VisitCreep(inp_Keyword&);
    virtual void VisitCrushableFoam(inp_Keyword&);
    virtual void VisitCrushableFoamHardening(inp_Keyword&);
    virtual void VisitCycledPlastic(inp_Keyword&);
    virtual void VisitCyclicHardening(inp_Keyword&);
    virtual void VisitDamping(inp_Keyword&);
    virtual void VisitDamageInitiation(inp_Keyword&);
    void CreateDamageInitiationSuboptions(inp_Keyword& keyword,
                                          kmaO_DamageInitiation& damageInitiation);
    void CreateDamageEvolution(inp_Keyword& keyword,
                               kmaO_DamageInitiation& damageInitiation, cow_String diCriterion);

    virtual void VisitDeformationPlasticity(inp_Keyword&);
    virtual void VisitDensity(inp_Keyword&);
    virtual void VisitDepvar(inp_Keyword&);
    virtual void VisitDetonationPoint(inp_Keyword&);
    virtual void VisitDielectric(inp_Keyword&);
    virtual void VisitDiffusivity(inp_Keyword&);
    virtual void VisitDruckerPrager(inp_Keyword&);
    virtual void VisitDruckerPragerCreep(inp_Keyword&);
    virtual void VisitDruckerPragerHardening(inp_Keyword&);   
    virtual void VisitElastic(inp_Keyword&);
    virtual void VisitElectricalConductivity(inp_Keyword&);
    virtual void VisitEos(inp_Keyword&);
    virtual void VisitEosCompaction(inp_Keyword&);
    virtual void VisitEosShear(inp_Keyword&);
    virtual void VisitExpansion(inp_Keyword&);
    virtual void VisitFailureRatios(inp_Keyword&); 
    virtual void VisitFailStrain(inp_Keyword&);
    virtual void VisitFailStress(inp_Keyword&);   
    virtual void VisitGasketContactArea(inp_Keyword&); 
    virtual void VisitGasketElasticity(inp_Keyword&);     
    virtual void VisitGasketThicknessBehavior(inp_Keyword&); 
    virtual void VisitGel(inp_Keyword&); 
    virtual void VisitHeatGeneration(inp_Keyword&);  
    virtual void VisitHyperelastic(inp_Keyword&); 
    virtual void VisitHyperfoam(inp_Keyword&); 
    virtual void VisitHypoelastic(inp_Keyword&); 
    virtual void VisitHysteresis(inp_Keyword&); 
    virtual void VisitInelasticHeatFraction(inp_Keyword&);
    virtual void VisitKappa(inp_Keyword&); 
    virtual void VisitJouleHeatFraction(inp_Keyword&); 
    virtual void VisitLatentHeat(inp_Keyword&); 
    virtual void VisitMoistureSwelling(inp_Keyword&);
    virtual void VisitMohrCoulomb(inp_Keyword&); 
    virtual void VisitMohrCoulombHardening(inp_Keyword&);  
    virtual void VisitOrnl(inp_Keyword&);
    virtual void VisitPermeability(inp_Keyword&);
    virtual void VisitPiezoelectric(inp_Keyword&);
    virtual void VisitPlanarTestData(inp_Keyword&);
    virtual void VisitPlastic(inp_Keyword&);
    virtual void VisitPorousBulkModuli(inp_Keyword&);
    virtual void VisitPorousElastic(inp_Keyword&);
    virtual void VisitPorousMetalPlasticity(inp_Keyword&);
    virtual void VisitPorousFailureCriteria(inp_Keyword&);
    virtual void VisitPotential(inp_Keyword&);
    virtual void VisitRateDependent(inp_Keyword&);
    virtual void VisitRatios(inp_Keyword&); 
    virtual void VisitShearRetention(inp_Keyword&);
    virtual void VisitShearTestData(inp_Keyword&);
    virtual void VisitSimpleShearTestData(inp_Keyword&);
    virtual void VisitSolubility(inp_Keyword&);
    virtual void VisitSorption(inp_Keyword&);
    virtual void VisitSpecificHeat(inp_Keyword&);
    virtual void VisitSwelling(inp_Keyword&);
    virtual void VisitTensionStiffening(inp_Keyword&); 
    virtual void VisitTriaxialTestData(inp_Keyword&);
    virtual void VisitTrs(inp_Keyword&);
    virtual void VisitUniaxialTestData(inp_Keyword&);
    virtual void VisitUserDefinedField(inp_Keyword&);
    virtual void VisitUserMaterial(inp_Keyword&);
    virtual void VisitUserOutputVariables(inp_Keyword&);
    virtual void VisitViscoelastic(inp_Keyword&);
    virtual void VisitViscous(inp_Keyword&);
    virtual void VisitVoidNucleation(inp_Keyword&);
    virtual void VisitVolumetricTestData(inp_Keyword&);

private: // Data

   kmaO_ApiExtension m_matApi; 
   kmaO_MaterialCOW  m_material;    

   inpO_AcousticMediumReader m_acousticMediumReader;
   inpO_DruckerPragerHardeningHld m_druckerPragerHardeningHld;
   inpO_SorptionReader m_sorptionReader;
   inpO_UserMaterialReader m_userMaterialReader;
};

//---------------------------------------------------------------------------->
inline kmaO_ApiExtension&
inpO_MaterialVisitor::MaterialApiExt()
//---------------------------------------------------------------------------->
{
   return m_matApi;
}



#endif // inpO_MaterialVisitor_h
