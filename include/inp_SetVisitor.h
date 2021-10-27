/*   -*- mode: c++ -*-   */
#ifndef inp_SetVisitor_h
#define inp_SetVisitor_h

///////////////////////////////////////////////////////////////////////////////
//
// File Name: inp_SetVisitor.h
//
// Description:  Generate set from keyword (if possible)
//

// Includes

// Forward declarations

class inp_DataArray;

// Begin local includes

#include <inpM_Set.h>
#include <inpM_SetMap.h>
#include <inp_Visitor.h>
#include <cow_ListInt.h>

// Class definition

class inp_SetVisitor: public inp_Visitor
{
  public:

    inp_SetVisitor();
    inp_SetVisitor(const inpM_SetMap& previouslyDefinedSets,
		   const cow_String& instanceName);
    virtual ~inp_SetVisitor();

    virtual cow_String KeywordName() const = 0;
    const inpM_SetMap& ConstGetSetMap() const { return setMap; }

    virtual void DefaultAction(inp_Keyword&);

    void SetValidInstanceNames(const cow_ListString& names) {
	validInstanceNames = names; }
    void SetImportedInstanceNames(const cow_ListString& names) {
	_importedInstanceNames = names; }
    void SetImportedSets(const inpM_SetMap& sets) {
	_importedSets = sets; }

  protected:

    // Methods

    void AddPartSet(const cow_String& setName, const inpM_BaseSet&,
		    bool overwrite = false);
    void AddAssySet(const cow_String& setName, const inpM_BaseSet&,
		    bool overwrite = false);
    void AddPartSet(const cow_String& setName, const inpM_BaseSet&,
		inpM_SetMap& targetSetMap, bool overwrite = false);
    void AddAssySet(const cow_String& setName, const inpM_BaseSet&,
		inpM_SetMap& targetSetMap, bool overwrite = false);

    inpM_BaseSetCOW GenerateAssemblySet(const inp_Keyword&,
				       bool pickedSet = false,
				       bool unsortedSet = false);
    inpM_BaseSetCOW GenerateAssemblySetAccumulate(const cow_String& setName,
						 const inp_Keyword&,
						 bool pickedSet = false,
						 bool unsortedSet = false);
    inpM_BaseSetCOW GenerateSet(const inp_DataArray&, 
			       bool pickedSet = false,
			       bool unsortedSet = false);
    inpM_BaseSetCOW GenerateSetAccumulate(const cow_String& setName,
					 const inp_DataArray&, 
					 bool pickedSet = false,
					 bool unsortedSet = false);

    inpM_BaseSetCOW ReadAssemblyIdsAndSetNames(
	const inpM_SetMap&,
	const inp_Keyword&,
	bool pickedSet = false);
    inpM_BaseSetCOW ReadUnsortedAssemblyIdsAndSetNames(
	const inpM_SetMap&,
	const inp_Keyword&,
	bool pickedSet = false);
    inpM_BaseSetCOW ReadAssemblyIdsAndSetNamesAccumulate(
	const cow_String& setName,
	const inpM_SetMap&,
	const inp_Keyword&,
	bool pickedSet = false,
	bool unsortedSet = false);
    inpM_BaseSetCOW ReadIdsAndSetNames(const inp_Keyword&,
				      bool pickedSet = false,
				      bool isRestartJob = false);
    inpM_BaseSetCOW ReadUnsortedIdsAndSetNames(const inp_Keyword&,
                                              bool pickedSet = false,
                                              bool isRestartJob = false);
    inpM_BaseSetCOW ReadIdsAndSetNamesAccumulate(const cow_String& setName,
						const inp_Keyword&,
					   bool pickedSet = false,
					   bool unsortedSet = false,
					   bool isRestartJob = false);
    void ProcessInstanceParameter(inp_Keyword&);

    virtual bool IsValidInstanceName(const cow_String& name) const;

    // Members

    inpM_SetMap setMap;
    inpM_SetMap _importedSets;

    cow_ListString validInstanceNames;
    cow_ListString _importedInstanceNames;
};

#endif /* inp_SetVisitor_h */
