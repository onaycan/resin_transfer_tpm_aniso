#ifndef ddr_Model_h
#define ddr_Model_h

// Begin local includes
#include <cow_String.h>
#include <cow_ArrayCOW.h>
#include <typ_typeTag.h>
#include <cls_Uid.h>
#include <cls_IntCOW.h>
#include <ddr_ExtensionTable.h>
#include <mdl_ExtensionSubject.h>
#include <mdl_Repository.h>
#include <nex_dynamicCast.h>

// Forward declarations
class cls_ClassRegistrar;
class cls_ReadVisitor;
class cls_WriteVisitor;
class ddr_Model;

MDL_EXTENSIONSUBJECT_DECL(ddr_Model, ddr_ExtensionTable, ddr_ModelExtension);

class ddr_Model : public ddr_ModelExtension
{
public:
    ddr_Model();
    ddr_Model( const cow_String  &fileName,
	       const cow_String  &modelName );
    virtual ~ddr_Model();

    virtual ddr_Model* Copy() const = 0;
     
    virtual typ_typeTag DynTypeId() const;
    static typ_typeTag TypeId();

    ddr_Model(const cls_ReadVisitor& rv);
    static void* Ctor(cls_ReadVisitor& rv);
    static void CowDtor(cls_IntCOW* cow);
    virtual void DBWrite(const cls_WriteVisitor& wv) const;
    static void InitializeMetadata(cls_ClassRegistrar& reg);

    cow_String  FileName() const { return  fileName; }
    cow_String  ModelName() const { return  modelName; }

    static omn_FixedString materialCmd();
    static omn_FixedString sectionCmd();
    static omn_FixedString profileCmd();
    static omn_FixedString fieldCmd();
    static omn_FixedString fieldOutputRequestCmd();
    static omn_FixedString historyOutputRequestCmd();
    static omn_FixedString interactionCmd();
    static omn_FixedString interactionPropertyCmd();
    static omn_FixedString stepCmd();
    static omn_FixedString adaptiveMeshControlCmd();
    static omn_FixedString timePointCmd();
    static omn_FixedString adaptiveMeshConstraintCmd();
    static omn_FixedString integratedOutputSectionCmd();
    static omn_FixedString amplitudeCmd();
    static omn_FixedString filterCmd();
    static omn_FixedString contactControlCmd();
    static omn_FixedString contactInitializationCmd();
    static omn_FixedString bcCmd();
    static omn_FixedString loadCmd();
    static omn_FixedString constraintCmd();
    static omn_FixedString connectorCmd();
    static omn_FixedString taskCmd();
    static omn_FixedString objectiveFunctionCmd();
    static omn_FixedString optimizationConstraintCmd();
    static omn_FixedString designResponseCmd();
    static omn_FixedString geometricRestrictionCmd();
    static omn_FixedString stopConditionCmd();

    static void RegisterMaterialContainer(const mdl_Extension& materials) {
	ddr_ModelExtension::RegisterExtension(materialCmd(), materials);
    }
    static void UnRegisterMaterialContainer() {
	ddr_ModelExtension::UnRegisterExtension(materialCmd());
    }

    static void RegisterSectionContainer( const mdl_Extension& sections) {
	ddr_ModelExtension::RegisterExtension(sectionCmd(), sections);
    }
    static void UnRegisterSectionContainer() {
	ddr_ModelExtension::UnRegisterExtension(sectionCmd());
    }

    static void RegisterBeamProfileContainer( const mdl_Extension& profiles) {
	ddr_ModelExtension::RegisterExtension(profileCmd(), profiles);
    }
    static void UnRegisterBeamProfileContainer() {
	ddr_ModelExtension::UnRegisterExtension(profileCmd());
    }

    static void RegisterFieldContainer( const mdl_Extension& fields) {
	ddr_ModelExtension::RegisterExtension(fieldCmd(), fields);
    }
    static void UnRegisterFieldContainer() {
	ddr_ModelExtension::UnRegisterExtension(fieldCmd());
    }

    static void RegisterFieldOutputContainer( const mdl_Extension& foutput) {
	ddr_ModelExtension::RegisterExtension(fieldOutputRequestCmd(), foutput);
    }
    static void UnRegisterFieldOutputContainer() {
	ddr_ModelExtension::UnRegisterExtension(fieldOutputRequestCmd());
    }

    static void RegisterHistoryOutputContainer( const mdl_Extension& houtput) {
	ddr_ModelExtension::RegisterExtension(historyOutputRequestCmd(), houtput);
    }
    static void UnRegisterHistoryOutputContainer() {
	ddr_ModelExtension::UnRegisterExtension(historyOutputRequestCmd());
    }

    static void RegisterInteractionContainer( const mdl_Extension& interactions) {
	ddr_ModelExtension::RegisterExtension(interactionCmd(), interactions);
    }
    static void UnRegisterInteractionContainer() {
	ddr_ModelExtension::UnRegisterExtension(interactionCmd());
    }

    static void RegisterInteractionPropertyContainer( const mdl_Extension& interactionProps) {
	ddr_ModelExtension::RegisterExtension(interactionPropertyCmd(), interactionProps);
    }
    static void UnRegisterInteractionPropertyContainer() {
	ddr_ModelExtension::UnRegisterExtension(interactionPropertyCmd());
    }

    static void RegisterStepContainer( const mdl_Extension& steps) {
	ddr_ModelExtension::RegisterExtension(stepCmd(), steps);
    }
    static void UnRegisterStepContainer() {
	ddr_ModelExtension::UnRegisterExtension(stepCmd());
    }

    static void RegisterAdaptiveMeshControlContainer( const mdl_Extension& amcs) {
	ddr_ModelExtension::RegisterExtension(adaptiveMeshControlCmd(), amcs);
    }
    static void UnRegisterAdaptiveMeshControlContainer() {
	ddr_ModelExtension::UnRegisterExtension(adaptiveMeshControlCmd());
    }

    static void RegisterTimePointContainer( const mdl_Extension& amcs) {
	ddr_ModelExtension::RegisterExtension(timePointCmd(), amcs);
    }
    static void UnRegisterTimePointContainer() {
	ddr_ModelExtension::UnRegisterExtension(timePointCmd());
    }

    static void RegisterAdaptiveMeshConstraintContainer( const mdl_Extension& amcs) {
	ddr_ModelExtension::RegisterExtension(adaptiveMeshConstraintCmd(), amcs);
    }
    static void UnRegisterAdaptiveMeshConstraintContainer() {
	ddr_ModelExtension::UnRegisterExtension(adaptiveMeshConstraintCmd());
    }

    static void RegisterIntegratedOutputSectionContainer( const mdl_Extension& amcs) {
	ddr_ModelExtension::RegisterExtension(integratedOutputSectionCmd(), amcs);
    }
    static void UnRegisterIntegratedOutputSectionContainer() {
	ddr_ModelExtension::UnRegisterExtension(integratedOutputSectionCmd());
    }

    static void RegisterAmplitudeContainer( const mdl_Extension& amplitudes) {
	ddr_ModelExtension::RegisterExtension(amplitudeCmd(), amplitudes);
    }
    static void UnRegisterAmplitudeContainer() {
	ddr_ModelExtension::UnRegisterExtension(amplitudeCmd());
    }

    static void RegisterFilterContainer( const mdl_Extension& filters) {
	ddr_ModelExtension::RegisterExtension(filterCmd(), filters);
    }
    static void UnRegisterFilterContainer() {
	ddr_ModelExtension::UnRegisterExtension(filterCmd());
    }

    static void RegisterContactControlContainer( const mdl_Extension& contactControls) {
	ddr_ModelExtension::RegisterExtension(contactControlCmd(), contactControls);
    }
    static void UnRegisterContactControlContainer() {
	ddr_ModelExtension::UnRegisterExtension(contactControlCmd());
    }

    static void RegisterContactInitContainer( const mdl_Extension& initializations) {
	ddr_ModelExtension::RegisterExtension(contactInitializationCmd(), initializations);
    }
    static void UnRegisterContactInitContainer() {
	ddr_ModelExtension::UnRegisterExtension(contactInitializationCmd());
    }

    static void RegisterBCContainer( const mdl_Extension& bcs) {
	ddr_ModelExtension::RegisterExtension(bcCmd(), bcs);
    }
    static void UnRegisterBCContainer() {
	ddr_ModelExtension::UnRegisterExtension(bcCmd());
    }

    static void RegisterLoadContainer( const mdl_Extension& loads) {
	ddr_ModelExtension::RegisterExtension(loadCmd(), loads);
    }
    static void UnRegisterLoadContainer() {
	ddr_ModelExtension::UnRegisterExtension(loadCmd());
    }

    static void RegisterConstraintContainer( const mdl_Extension& constraints) {
	ddr_ModelExtension::RegisterExtension(constraintCmd(), constraints);
    }
    static void UnRegisterConstraintContainer() {
	ddr_ModelExtension::UnRegisterExtension(constraintCmd());
    }

    static void RegisterConnectorContainer( const mdl_Extension& connectors) {
	ddr_ModelExtension::RegisterExtension(connectorCmd(), connectors);
    }
    static void UnRegisterConnectorContainer() {
	ddr_ModelExtension::UnRegisterExtension(connectorCmd());
    }

    static void RegisterTaskContainer( const mdl_Extension& eos) {
	ddr_ModelExtension::RegisterExtension(taskCmd(), eos);
    }
    static void UnRegisterTaskContainer() {
	ddr_ModelExtension::UnRegisterExtension(taskCmd());
    }

    static void RegisterObjectiveFunctionContainer( const mdl_Extension& eos) {
	ddr_ModelExtension::RegisterExtension(objectiveFunctionCmd(), eos);
    }
    static void UnRegisterObjectiveFunctionContainer() {
	ddr_ModelExtension::UnRegisterExtension(objectiveFunctionCmd());
    }

    static void RegisterOptimizationConstraintContainer( const mdl_Extension& eos) {
	ddr_ModelExtension::RegisterExtension(optimizationConstraintCmd(), eos);
    }
    static void UnRegisterOptimizationConstraintContainer() {
	ddr_ModelExtension::UnRegisterExtension(optimizationConstraintCmd());
    }

    static void RegisterDesignResponseContainer( const mdl_Extension& eos) {
	ddr_ModelExtension::RegisterExtension(designResponseCmd(), eos);
    }
    static void UnRegisterDesignResponseContainer() {
	ddr_ModelExtension::UnRegisterExtension(designResponseCmd());
    }

    static void RegisterGeometricRestrictionContainer( const mdl_Extension& eos) {
	ddr_ModelExtension::RegisterExtension(geometricRestrictionCmd(), eos);
    }
    static void UnRegisterGeometricRestrictionContainer() {
	ddr_ModelExtension::UnRegisterExtension(geometricRestrictionCmd());
    }

    static void RegisterStopConditionContainer( const mdl_Extension& eos) {
	ddr_ModelExtension::RegisterExtension(stopConditionCmd(), eos);
    }
    static void UnRegisterStopConditionContainer() {
	ddr_ModelExtension::UnRegisterExtension(stopConditionCmd());
    }

    inline mdl_Repository& GetMaterials();
    inline const mdl_Repository& ConstGetMaterials() const;
    inline void SetMaterials(const mdl_Repository&);
    inline int NumMaterials() const;

    inline mdl_Repository& GetSections();
    inline const mdl_Repository& ConstGetSections() const;
    inline void SetSections( const mdl_Repository& );
    inline int NumSections() const;

    inline mdl_Repository& GetBeamProfiles();
    inline const mdl_Repository& ConstGetBeamProfiles() const;
    inline void SetBeamProfiles( const mdl_Repository& );
    inline int NumBeamProfiles() const;

    inline mdl_Repository& GetFields();
    inline const mdl_Repository& ConstGetFields() const;
    inline void SetFields( const mdl_Repository& );
    inline int NumFields() const;

    inline mdl_Repository& GetFieldOutputs();
    inline const mdl_Repository& ConstGetFieldOutputs() const;
    inline void SetFieldOutputs( const mdl_Repository& );
    inline int NumFieldOutputs() const;

    inline mdl_Repository& GetHistoryOutputs();
    inline const mdl_Repository& ConstGetHistoryOutputs() const;
    inline void SetHistoryOutputs( const mdl_Repository& );
    inline int NumHistoryOutputs() const;

    inline mdl_Repository& GetInteractions();
    inline const mdl_Repository& ConstGetInteractions() const;
    inline void SetInteractions( const mdl_Repository& );
    inline int NumInteractions() const;

    inline mdl_Repository& GetInteractionProperties();
    inline const mdl_Repository& ConstGetInteractionProperties() const;
    inline void SetInteractionProperties( const mdl_Repository& );
    inline int NumInteractionProperties() const;

    inline mdl_Repository& GetSteps();
    inline const mdl_Repository& ConstGetSteps() const;
    inline void SetSteps( const mdl_Repository& );
    inline int NumSteps() const;

    inline mdl_Repository& GetAdaptiveMeshControls();
    inline const mdl_Repository& ConstGetAdaptiveMeshControls() const;
    inline void SetAdaptiveMeshControls( const mdl_Repository& );
    inline int NumAdaptiveMeshControls() const;

    inline mdl_Repository& GetTimePoints();
    inline const mdl_Repository& ConstGetTimePoints() const;
    inline void SetTimePoints( const mdl_Repository& );
    inline int NumTimePoints() const;

    inline mdl_Repository& GetAdaptiveMeshConstraints();
    inline const mdl_Repository& ConstGetAdaptiveMeshConstraints() const;
    inline void SetAdaptiveMeshConstraints( const mdl_Repository& );
    inline int NumAdaptiveMeshConstraints() const;

    inline mdl_Repository& GetIntegratedOutputSections();
    inline const mdl_Repository& ConstGetIntegratedOutputSections() const;
    inline void SetIntegratedOutputSections( const mdl_Repository& );
    inline int NumIntegratedOutputSections() const;

    inline mdl_Repository& GetAmplitudes();
    inline const mdl_Repository& ConstGetAmplitudes() const;
    inline void SetAmplitudes( const mdl_Repository& );
    inline int NumAmplitudes() const;

    inline mdl_Repository& GetFilters();
    inline const mdl_Repository& ConstGetFilters() const;
    inline void SetFilters( const mdl_Repository& );
    inline int NumFilters() const;

    inline mdl_Repository& GetContactControls();
    inline const mdl_Repository& ConstGetContactControls() const;
    inline void SetContactControls( const mdl_Repository& );
    inline int NumContactControls() const;

    inline mdl_Repository& GetContactInitializations();
    inline const mdl_Repository& ConstGetContactInitializations() const;
    inline void SetContactInitializations( const mdl_Repository& );
    inline int NumContactInitializations() const;

    inline mdl_Repository& GetBCs();
    inline const mdl_Repository& ConstGetBCs() const;
    inline void SetBCs( const mdl_Repository& );
    inline int NumBCs() const;

    inline mdl_Repository& GetLoads();
    inline const mdl_Repository& ConstGetLoads() const;
    inline void SetLoads( const mdl_Repository& );
    inline int NumLoads() const;

    inline mdl_Repository& GetConstraints();
    inline const mdl_Repository& ConstGetConstraints() const;
    inline void SetConstraints( const mdl_Repository& );
    inline int NumConstraints() const;

    inline mdl_Repository& GetConnectors();
    inline const mdl_Repository& ConstGetConnectors() const;
    inline void SetConnectors( const mdl_Repository& );
    inline int NumConnectors() const;

    inline mdl_Repository& GetTasks();
    inline const mdl_Repository& ConstGetTasks() const;
    inline void SetTasks( const mdl_Repository& );
    inline int NumTasks() const;

    inline mdl_Repository& GetObjectiveFunctions();
    inline const mdl_Repository& ConstGetObjectiveFunctions() const;
    inline void SetObjectiveFunctions( const mdl_Repository& );
    inline int NumObjectiveFunctions() const;

    inline mdl_Repository& GetOptimizationConstraints();
    inline const mdl_Repository& ConstGetOptimizationConstraints() const;
    inline void SetOptimizationConstraints( const mdl_Repository& );
    inline int NumOptimizationConstraints() const;

    inline mdl_Repository& GetDesignResponses();
    inline const mdl_Repository& ConstGetDesignResponses() const;
    inline void SetDesignResponses( const mdl_Repository& );
    inline int NumDesignResponses() const;

    inline mdl_Repository& GetGeometricRestrictions();
    inline const mdl_Repository& ConstGetGeometricRestrictions() const;
    inline void SetGeometricRestrictions( const mdl_Repository& );
    inline int NumGeometricRestrictions() const;

    inline mdl_Repository& GetStopConditions();
    inline const mdl_Repository& ConstGetStopConditions() const;
    inline void SetStopConditions( const mdl_Repository& );
    inline int NumStopConditions() const;

    ddr_ModelExtension::RegisterExtension;
    ddr_ModelExtension::Initialize;
    ddr_ModelExtension::Finalize;

protected:
    // Only allow ddr_Ddb to change the names.
    friend class  ddr_Ddb;
    cow_String  fileName, modelName;

private:
    cls_Uid m_ClsUid;
};


inline mdl_Repository& 
ddr_Model::GetMaterials()
{
    mdl_Extension& retval = ddr_ModelExtension::GetExtension(materialCmd()).GetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline const mdl_Repository&
ddr_Model::ConstGetMaterials() const
{
    const mdl_Extension& retval = ddr_ModelExtension::ConstGetExtension(materialCmd()).ConstGetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline void
ddr_Model::SetMaterials( const mdl_Repository& materials )
{
    ddr_ModelExtension::SetExtension(materialCmd(),materials);
}

inline int
ddr_Model::NumMaterials() const
{
    const mdl_Extension& cont = ddr_ModelExtension::ConstGetExtension(materialCmd()).ConstGetValue();
    const mdl_Repository& rep = dynamic_castRef(mdl_Repository,cont);
    return rep.Size();
}

inline mdl_Repository& 
ddr_Model::GetSections()
{
    mdl_Extension& retval = ddr_ModelExtension::GetExtension(sectionCmd()).GetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline const mdl_Repository&
ddr_Model::ConstGetSections() const
{
    const mdl_Extension& retval = ddr_ModelExtension::ConstGetExtension(sectionCmd()).ConstGetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline void
ddr_Model::SetSections( const mdl_Repository& sections )
{
    ddr_ModelExtension::SetExtension(sectionCmd(),sections);
}

inline int
ddr_Model::NumSections() const
{
    const mdl_Extension& cont = ddr_ModelExtension::ConstGetExtension(sectionCmd()).ConstGetValue();
    const mdl_Repository& rep = dynamic_castRef(mdl_Repository,cont);
    return rep.Size();
}

inline mdl_Repository& 
ddr_Model::GetBeamProfiles()
{
    mdl_Extension& retval = ddr_ModelExtension::GetExtension(profileCmd()).GetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline const mdl_Repository&
ddr_Model::ConstGetBeamProfiles() const
{
    const mdl_Extension& retval = ddr_ModelExtension::ConstGetExtension(profileCmd()).ConstGetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline void
ddr_Model::SetBeamProfiles( const mdl_Repository& beamprofiles )
{
    ddr_ModelExtension::SetExtension(profileCmd(),beamprofiles);
}

inline int
ddr_Model::NumBeamProfiles() const
{
    const mdl_Extension& cont = ddr_ModelExtension::ConstGetExtension(profileCmd()).ConstGetValue();
    const mdl_Repository& rep = dynamic_castRef(mdl_Repository,cont);
    return rep.Size();
}

inline mdl_Repository& 
ddr_Model::GetFields()
{
    mdl_Extension& retval = ddr_ModelExtension::GetExtension(fieldCmd()).GetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline const mdl_Repository&
ddr_Model::ConstGetFields() const
{
    const mdl_Extension& retval = ddr_ModelExtension::ConstGetExtension(fieldCmd()).ConstGetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline void
ddr_Model::SetFields( const mdl_Repository& fields )
{
    ddr_ModelExtension::SetExtension(fieldCmd(),fields);
}

inline int
ddr_Model::NumFields() const
{
    const mdl_Extension& cont = ddr_ModelExtension::ConstGetExtension(fieldCmd()).ConstGetValue();
    const mdl_Repository& rep = dynamic_castRef(mdl_Repository,cont);
    return rep.Size();
}

inline mdl_Repository& 
ddr_Model::GetFieldOutputs()
{
    mdl_Extension& retval = ddr_ModelExtension::GetExtension(fieldOutputRequestCmd()).GetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline const mdl_Repository&
ddr_Model::ConstGetFieldOutputs() const
{
    const mdl_Extension& retval = ddr_ModelExtension::ConstGetExtension(fieldOutputRequestCmd()).ConstGetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline void
ddr_Model::SetFieldOutputs( const mdl_Repository& fieldOutputs )
{
    ddr_ModelExtension::SetExtension(fieldOutputRequestCmd(),fieldOutputs);
}

inline int
ddr_Model::NumFieldOutputs() const
{
    const mdl_Extension& cont = ddr_ModelExtension::ConstGetExtension(fieldOutputRequestCmd()).ConstGetValue();
    const mdl_Repository& rep = dynamic_castRef(mdl_Repository,cont);
    return rep.Size();
}

inline mdl_Repository& 
ddr_Model::GetHistoryOutputs()
{
    mdl_Extension& retval = ddr_ModelExtension::GetExtension(historyOutputRequestCmd()).GetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline const mdl_Repository&
ddr_Model::ConstGetHistoryOutputs() const
{
    const mdl_Extension& retval = ddr_ModelExtension::ConstGetExtension(historyOutputRequestCmd()).ConstGetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline void
ddr_Model::SetHistoryOutputs( const mdl_Repository& historyOutputs )
{
    ddr_ModelExtension::SetExtension(historyOutputRequestCmd(),historyOutputs);
}

inline int
ddr_Model::NumHistoryOutputs() const
{
    const mdl_Extension& cont = ddr_ModelExtension::ConstGetExtension(historyOutputRequestCmd()).ConstGetValue();
    const mdl_Repository& rep = dynamic_castRef(mdl_Repository,cont);
    return rep.Size();
}

inline mdl_Repository& 
ddr_Model::GetInteractions()
{
    mdl_Extension& retval = ddr_ModelExtension::GetExtension(interactionCmd()).GetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline const mdl_Repository&
ddr_Model::ConstGetInteractions() const
{
    const mdl_Extension& retval = ddr_ModelExtension::ConstGetExtension(interactionCmd()).ConstGetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline void
ddr_Model::SetInteractions( const mdl_Repository& interactions )
{
    ddr_ModelExtension::SetExtension(interactionCmd(),interactions);
}

inline int
ddr_Model::NumInteractions() const
{
    const mdl_Extension& cont = ddr_ModelExtension::ConstGetExtension(interactionCmd()).ConstGetValue();
    const mdl_Repository& rep = dynamic_castRef(mdl_Repository,cont);
    return rep.Size();
}

inline mdl_Repository& 
ddr_Model::GetInteractionProperties()
{
    mdl_Extension& retval = ddr_ModelExtension::GetExtension(interactionPropertyCmd()).GetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline const mdl_Repository&
ddr_Model::ConstGetInteractionProperties() const
{
    const mdl_Extension& retval = ddr_ModelExtension::ConstGetExtension(interactionPropertyCmd()).ConstGetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline void
ddr_Model::SetInteractionProperties( const mdl_Repository& interactionProperties )
{
    ddr_ModelExtension::SetExtension(interactionPropertyCmd(),interactionProperties);
}

inline int
ddr_Model::NumInteractionProperties() const
{
    const mdl_Extension& cont = ddr_ModelExtension::ConstGetExtension(interactionPropertyCmd()).ConstGetValue();
    const mdl_Repository& rep = dynamic_castRef(mdl_Repository,cont);
    return rep.Size();
}

inline mdl_Repository& 
ddr_Model::GetSteps()
{
    mdl_Extension& retval = ddr_ModelExtension::GetExtension(stepCmd()).GetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline const mdl_Repository&
ddr_Model::ConstGetSteps() const
{
    const mdl_Extension& retval = ddr_ModelExtension::ConstGetExtension(stepCmd()).ConstGetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline void
ddr_Model::SetSteps( const mdl_Repository& steps )
{
    ddr_ModelExtension::SetExtension(stepCmd(),steps);
}

inline int
ddr_Model::NumSteps() const
{
    const mdl_Extension& cont = ddr_ModelExtension::ConstGetExtension(stepCmd()).ConstGetValue();
    const mdl_Repository& rep = dynamic_castRef(mdl_Repository,cont);
    return rep.Size() - 1;
}

inline mdl_Repository& 
ddr_Model::GetAdaptiveMeshControls()
{
    mdl_Extension& retval = ddr_ModelExtension::GetExtension(adaptiveMeshControlCmd()).GetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline const mdl_Repository&
ddr_Model::ConstGetAdaptiveMeshControls() const
{
    const mdl_Extension& retval = ddr_ModelExtension::ConstGetExtension(adaptiveMeshControlCmd()).ConstGetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline void
ddr_Model::SetAdaptiveMeshControls( const mdl_Repository& adaptiveMeshControls )
{
    ddr_ModelExtension::SetExtension(adaptiveMeshControlCmd(),adaptiveMeshControls);
}

inline int
ddr_Model::NumAdaptiveMeshControls() const
{
    const mdl_Extension& cont = ddr_ModelExtension::ConstGetExtension(adaptiveMeshControlCmd()).ConstGetValue();
    const mdl_Repository& rep = dynamic_castRef(mdl_Repository,cont);
    return rep.Size();
}

inline mdl_Repository& 
ddr_Model::GetTimePoints()
{
    mdl_Extension& retval = ddr_ModelExtension::GetExtension(adaptiveMeshControlCmd()).GetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline const mdl_Repository&
ddr_Model::ConstGetTimePoints() const
{
    const mdl_Extension& retval = ddr_ModelExtension::ConstGetExtension(adaptiveMeshControlCmd()).ConstGetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline void
ddr_Model::SetTimePoints( const mdl_Repository& adaptiveMeshControls )
{
    ddr_ModelExtension::SetExtension(adaptiveMeshControlCmd(),adaptiveMeshControls);
}

inline int
ddr_Model::NumTimePoints() const
{
    const mdl_Extension& cont = ddr_ModelExtension::ConstGetExtension(adaptiveMeshControlCmd()).ConstGetValue();
    const mdl_Repository& rep = dynamic_castRef(mdl_Repository,cont);
    return rep.Size();
}

inline mdl_Repository& 
ddr_Model::GetAdaptiveMeshConstraints()
{
    mdl_Extension& retval = ddr_ModelExtension::GetExtension(adaptiveMeshControlCmd()).GetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline const mdl_Repository&
ddr_Model::ConstGetAdaptiveMeshConstraints() const
{
    const mdl_Extension& retval = ddr_ModelExtension::ConstGetExtension(adaptiveMeshControlCmd()).ConstGetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline void
ddr_Model::SetAdaptiveMeshConstraints( const mdl_Repository& adaptiveMeshControls )
{
    ddr_ModelExtension::SetExtension(adaptiveMeshControlCmd(),adaptiveMeshControls);
}

inline int
ddr_Model::NumAdaptiveMeshConstraints() const
{
    const mdl_Extension& cont = ddr_ModelExtension::ConstGetExtension(adaptiveMeshControlCmd()).ConstGetValue();
    const mdl_Repository& rep = dynamic_castRef(mdl_Repository,cont);
    return rep.Size();
}


inline mdl_Repository& 
ddr_Model::GetIntegratedOutputSections()
{
    mdl_Extension& retval = ddr_ModelExtension::GetExtension(integratedOutputSectionCmd()).GetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline const mdl_Repository&
ddr_Model::ConstGetIntegratedOutputSections() const
{
    const mdl_Extension& retval = ddr_ModelExtension::ConstGetExtension(integratedOutputSectionCmd()).ConstGetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline void
ddr_Model::SetIntegratedOutputSections( const mdl_Repository& integratedOutputSections )
{
    ddr_ModelExtension::SetExtension(integratedOutputSectionCmd(),integratedOutputSections);
}

inline int
ddr_Model::NumIntegratedOutputSections() const
{
    const mdl_Extension& cont = ddr_ModelExtension::ConstGetExtension(integratedOutputSectionCmd()).ConstGetValue();
    const mdl_Repository& rep = dynamic_castRef(mdl_Repository,cont);
    return rep.Size();
}

inline mdl_Repository& 
ddr_Model::GetAmplitudes()
{
    mdl_Extension& retval = ddr_ModelExtension::GetExtension(amplitudeCmd()).GetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline const mdl_Repository&
ddr_Model::ConstGetAmplitudes() const
{
    const mdl_Extension& retval = ddr_ModelExtension::ConstGetExtension(amplitudeCmd()).ConstGetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline void
ddr_Model::SetAmplitudes( const mdl_Repository& amplitudes )
{
    ddr_ModelExtension::SetExtension(amplitudeCmd(),amplitudes);
}

inline int
ddr_Model::NumAmplitudes() const
{
    const mdl_Extension& cont = ddr_ModelExtension::ConstGetExtension(amplitudeCmd()).ConstGetValue();
    const mdl_Repository& rep = dynamic_castRef(mdl_Repository,cont);
    return rep.Size();
}

inline mdl_Repository& 
ddr_Model::GetFilters()
{
    mdl_Extension& retval = ddr_ModelExtension::GetExtension(filterCmd()).GetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline const mdl_Repository&
ddr_Model::ConstGetFilters() const
{
    const mdl_Extension& retval = ddr_ModelExtension::ConstGetExtension(filterCmd()).ConstGetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline void
ddr_Model::SetFilters( const mdl_Repository& filters )
{
    ddr_ModelExtension::SetExtension(filterCmd(),filters);
}

inline int
ddr_Model::NumFilters() const
{
    const mdl_Extension& cont = ddr_ModelExtension::ConstGetExtension(filterCmd()).ConstGetValue();
    const mdl_Repository& rep = dynamic_castRef(mdl_Repository,cont);
    return rep.Size();
}

inline mdl_Repository& 
ddr_Model::GetContactControls()
{
    mdl_Extension& retval = ddr_ModelExtension::GetExtension(contactControlCmd()).GetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline const mdl_Repository&
ddr_Model::ConstGetContactControls() const
{
    const mdl_Extension& retval = ddr_ModelExtension::ConstGetExtension(contactControlCmd()).ConstGetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline void
ddr_Model::SetContactControls( const mdl_Repository& contactControls )
{
    ddr_ModelExtension::SetExtension(contactControlCmd(),contactControls);
}

inline int
ddr_Model::NumContactControls() const
{
    const mdl_Extension& cont = ddr_ModelExtension::ConstGetExtension(contactControlCmd()).ConstGetValue();
    const mdl_Repository& rep = dynamic_castRef(mdl_Repository,cont);
    return rep.Size();
}


inline mdl_Repository& 
ddr_Model::GetContactInitializations()
{
    mdl_Extension& retval = ddr_ModelExtension::GetExtension(contactInitializationCmd()).GetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline const mdl_Repository&
ddr_Model::ConstGetContactInitializations() const
{
    const mdl_Extension& retval = ddr_ModelExtension::ConstGetExtension(contactInitializationCmd()).ConstGetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline void
ddr_Model::SetContactInitializations( const mdl_Repository& contactInitializations )
{
    ddr_ModelExtension::SetExtension(contactInitializationCmd(),contactInitializations);
}

inline int
ddr_Model::NumContactInitializations() const
{
    const mdl_Extension& cont = ddr_ModelExtension::ConstGetExtension(contactInitializationCmd()).ConstGetValue();
    const mdl_Repository& rep = dynamic_castRef(mdl_Repository,cont);
    return rep.Size();
}


inline mdl_Repository& 
ddr_Model::GetBCs()
{
    mdl_Extension& retval = ddr_ModelExtension::GetExtension(bcCmd()).GetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline const mdl_Repository&
ddr_Model::ConstGetBCs() const
{
    const mdl_Extension& retval = ddr_ModelExtension::ConstGetExtension(bcCmd()).ConstGetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline void
ddr_Model::SetBCs( const mdl_Repository& bcs )
{
    ddr_ModelExtension::SetExtension(bcCmd(),bcs);
}

inline int
ddr_Model::NumBCs() const
{
    const mdl_Extension& cont = ddr_ModelExtension::ConstGetExtension(bcCmd()).ConstGetValue();
    const mdl_Repository& rep = dynamic_castRef(mdl_Repository,cont);
    return rep.Size();
}

inline mdl_Repository& 
ddr_Model::GetLoads()
{
    mdl_Extension& retval = ddr_ModelExtension::GetExtension(loadCmd()).GetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline const mdl_Repository&
ddr_Model::ConstGetLoads() const
{
    const mdl_Extension& retval = ddr_ModelExtension::ConstGetExtension(loadCmd()).ConstGetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline void
ddr_Model::SetLoads( const mdl_Repository& loads )
{
    ddr_ModelExtension::SetExtension(loadCmd(),loads);
}

inline int
ddr_Model::NumLoads() const
{
    const mdl_Extension& cont = ddr_ModelExtension::ConstGetExtension(loadCmd()).ConstGetValue();
    const mdl_Repository& rep = dynamic_castRef(mdl_Repository,cont);
    return rep.Size();
}

inline mdl_Repository& 
ddr_Model::GetConstraints()
{
    mdl_Extension& retval = ddr_ModelExtension::GetExtension(constraintCmd()).GetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline const mdl_Repository&
ddr_Model::ConstGetConstraints() const
{
    const mdl_Extension& retval = ddr_ModelExtension::ConstGetExtension(constraintCmd()).ConstGetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline void
ddr_Model::SetConstraints( const mdl_Repository& constraints )
{
    ddr_ModelExtension::SetExtension(constraintCmd(),constraints);
}

inline int
ddr_Model::NumConstraints() const
{
    const mdl_Extension& cont = ddr_ModelExtension::ConstGetExtension(constraintCmd()).ConstGetValue();
    const mdl_Repository& rep = dynamic_castRef(mdl_Repository,cont);
    return rep.Size();
}

inline mdl_Repository& 
ddr_Model::GetConnectors()
{
    mdl_Extension& retval = ddr_ModelExtension::GetExtension(connectorCmd()).GetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline const mdl_Repository&
ddr_Model::ConstGetConnectors() const
{
    const mdl_Extension& retval = ddr_ModelExtension::ConstGetExtension(connectorCmd()).ConstGetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline void
ddr_Model::SetConnectors( const mdl_Repository& connectors )
{
    ddr_ModelExtension::SetExtension(connectorCmd(),connectors);
}

inline int
ddr_Model::NumConnectors() const
{
    const mdl_Extension& cont = ddr_ModelExtension::ConstGetExtension(connectorCmd()).ConstGetValue();
    const mdl_Repository& rep = dynamic_castRef(mdl_Repository,cont);
    return rep.Size();
}

inline mdl_Repository& 
ddr_Model::GetTasks()
{
    mdl_Extension& retval = ddr_ModelExtension::GetExtension(taskCmd()).GetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline const mdl_Repository&
ddr_Model::ConstGetTasks() const
{
    const mdl_Extension& retval = ddr_ModelExtension::ConstGetExtension(taskCmd()).ConstGetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline void
ddr_Model::SetTasks( const mdl_Repository& tasks )
{
    ddr_ModelExtension::SetExtension(taskCmd(),tasks);
}

inline int
ddr_Model::NumTasks() const
{
    const mdl_Extension& cont = ddr_ModelExtension::ConstGetExtension(taskCmd()).ConstGetValue();
    const mdl_Repository& rep = dynamic_castRef(mdl_Repository,cont);
    return rep.Size();
}

inline mdl_Repository& 
ddr_Model::GetObjectiveFunctions()
{
    mdl_Extension& retval = ddr_ModelExtension::GetExtension(objectiveFunctionCmd()).GetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline const mdl_Repository&
ddr_Model::ConstGetObjectiveFunctions() const
{
    const mdl_Extension& retval = ddr_ModelExtension::ConstGetExtension(objectiveFunctionCmd()).ConstGetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline void
ddr_Model::SetObjectiveFunctions( const mdl_Repository& objectiveFunctions )
{
    ddr_ModelExtension::SetExtension(objectiveFunctionCmd(),objectiveFunctions);
}

inline int
ddr_Model::NumObjectiveFunctions() const
{
    const mdl_Extension& cont = ddr_ModelExtension::ConstGetExtension(objectiveFunctionCmd()).ConstGetValue();
    const mdl_Repository& rep = dynamic_castRef(mdl_Repository,cont);
    return rep.Size();
}

inline mdl_Repository& 
ddr_Model::GetOptimizationConstraints()
{
    mdl_Extension& retval = ddr_ModelExtension::GetExtension(optimizationConstraintCmd()).GetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline const mdl_Repository&
ddr_Model::ConstGetOptimizationConstraints() const
{
    const mdl_Extension& retval = ddr_ModelExtension::ConstGetExtension(optimizationConstraintCmd()).ConstGetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline void
ddr_Model::SetOptimizationConstraints( const mdl_Repository& optimizationConstraints )
{
    ddr_ModelExtension::SetExtension(optimizationConstraintCmd(),optimizationConstraints);
}

inline int
ddr_Model::NumOptimizationConstraints() const
{
    const mdl_Extension& cont = ddr_ModelExtension::ConstGetExtension(optimizationConstraintCmd()).ConstGetValue();
    const mdl_Repository& rep = dynamic_castRef(mdl_Repository,cont);
    return rep.Size();
}

inline mdl_Repository& 
ddr_Model::GetDesignResponses()
{
    mdl_Extension& retval = ddr_ModelExtension::GetExtension(designResponseCmd()).GetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline const mdl_Repository&
ddr_Model::ConstGetDesignResponses() const
{
    const mdl_Extension& retval = ddr_ModelExtension::ConstGetExtension(designResponseCmd()).ConstGetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline void
ddr_Model::SetDesignResponses( const mdl_Repository& designResponses )
{
    ddr_ModelExtension::SetExtension(designResponseCmd(),designResponses);
}

inline int
ddr_Model::NumDesignResponses() const
{
    const mdl_Extension& cont = ddr_ModelExtension::ConstGetExtension(designResponseCmd()).ConstGetValue();
    const mdl_Repository& rep = dynamic_castRef(mdl_Repository,cont);
    return rep.Size();
}

inline mdl_Repository& 
ddr_Model::GetGeometricRestrictions()
{
    mdl_Extension& retval = ddr_ModelExtension::GetExtension(geometricRestrictionCmd()).GetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline const mdl_Repository&
ddr_Model::ConstGetGeometricRestrictions() const
{
    const mdl_Extension& retval = ddr_ModelExtension::ConstGetExtension(geometricRestrictionCmd()).ConstGetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline void
ddr_Model::SetGeometricRestrictions( const mdl_Repository& geometricRestrictions )
{
    ddr_ModelExtension::SetExtension(geometricRestrictionCmd(),geometricRestrictions);
}

inline int
ddr_Model::NumGeometricRestrictions() const
{
    const mdl_Extension& cont = ddr_ModelExtension::ConstGetExtension(geometricRestrictionCmd()).ConstGetValue();
    const mdl_Repository& rep = dynamic_castRef(mdl_Repository,cont);
    return rep.Size();
}

inline mdl_Repository& 
ddr_Model::GetStopConditions()
{
    mdl_Extension& retval = ddr_ModelExtension::GetExtension(stopConditionCmd()).GetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline const mdl_Repository&
ddr_Model::ConstGetStopConditions() const
{
    const mdl_Extension& retval = ddr_ModelExtension::ConstGetExtension(stopConditionCmd()).ConstGetValue();
    return dynamic_castRef(mdl_Repository, retval);
}

inline void
ddr_Model::SetStopConditions( const mdl_Repository& stopConditions )
{
    ddr_ModelExtension::SetExtension(stopConditionCmd(),stopConditions);
}

inline int
ddr_Model::NumStopConditions() const
{
    const mdl_Extension& cont = ddr_ModelExtension::ConstGetExtension(stopConditionCmd()).ConstGetValue();
    const mdl_Repository& rep = dynamic_castRef(mdl_Repository,cont);
    return rep.Size();
}


COW_ARRAYCOW2_DECL(ddr_Model, cow_Virtual);
#endif


