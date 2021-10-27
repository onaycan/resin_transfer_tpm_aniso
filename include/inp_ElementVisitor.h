/*   -*- mode: c++ -*-   */
#ifndef inp_ElementVisitor_h
#define inp_ElementVisitor_h

///////////////////////////////////////////////////////////////////////////////
//
// File Name: inp_ElementVisitor.h
//
// Description:  Accumulate element labels and connectivity.
//

// Includes

// Forward declarations

// Begin local includes
#include <cow_Map.h>
#include <cow_String.h>

#include <inp_SetVisitor.h>

#include <inp_elements.h>
#include <inp_Element.h>
#include <inpM_InstancePartNameMap.h>
#include <cow_ListInt.h>
#include <cow_MapString2Int.h>
#include <cow_MapString2ListInt.h>


// Class definition

// Define a map cow_String(element name) to corresponding inp_ElementInfo
COW_MAP_ITER_DECL(cow_String, inp_ElementInfo, inp_ValidElementInfoMap);


class inp_ElementVisitor: public inp_SetVisitor
{
  public:

    inp_ElementVisitor(bool processConnectivities = true);
    inp_ElementVisitor(const inpM_SetMap& inheritedElsets, bool processConnectivities = true);
    virtual ~inp_ElementVisitor();
    virtual cow_String KeywordName() const;

    const inp_ElementMap& ConstGetElementMap() const { return elementMap; }
    inp_KeywordList unresolvedElsetKeywords;

    void setInstancePartNames(const inpM_InstancePartNameMap& names) { instancePartNames = names; }
    void setCAECompatible(bool CAECompatible) { m_CAECompatible = CAECompatible;}

  protected:

    void VisitElcopy(inp_Keyword&);
    void VisitElgen(inp_Keyword&);
    void VisitElement(inp_Keyword&);
    void VisitElset(inp_Keyword&);
    void VisitUserElement(inp_Keyword&);
    void VisitFastener(inp_Keyword&);
    inpM_BaseSetCOW ReadAssyElsetIdsAndSetNames(
        const inpM_SetMap&,
	const inp_Keyword&,
	bool pickedSet = false,
	bool unsortedSet = false);
    virtual bool IsValidInstanceName(const cow_String& name) const;

    // Members

    inp_ElementMap          elementMap;
    inpM_InstancePartNameMap instancePartNames;

    inp_ValidElementInfoMap validElements, obsoleteElements;
    // cow_MapString2Int validElements; // TEMPORARY - Use eqc when available
    cow_MapString2ListInt elcopyInfo;  // for *ELCOPY, REFLECT
    bool isRestartJob;
    bool processConnectivities;
    cow_MapString2Int userElemTypeNodeMap;
    bool m_CAECompatible;

  private:

    void RenumberTopologyDueToReflection(const cow_String& elemType,
					 cow_ListInt& topology);
    bool CheckExistenceOfOldSet(const cow_String& oldSet,
				cow_String& instanceContainingOldSet);
};

#endif /* inp_Visitor_h */
