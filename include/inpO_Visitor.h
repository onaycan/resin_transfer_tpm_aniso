/*   -*- mode: c++ -*-   */
#ifndef inpO_Visitor_h
#define inpO_Visitor_h

///////////////////////////////////////////////////////////////////////////////
//
// Name: inpO_Visitor
//
// Description: base class for visitors for the Converter from an input file to the ODB
//

// Includes

// Forward declarations

class odb_Odb;
class odb_Assembly;
class odb_DiscreteEntity;
class odb_Part;
class odb_Instance;
class odb_Node;
class odb_Set;
class odb_AnalyticSurface;

class inpO_AbaqusName;
class inpO_AbaqusName;
class inpO_Coord;

// Begin local includes
#include <inpO_KeywordParameterReader.h>
#include <inpO_MessageContainer.h>
#include <inpO_ModelInventory.h>

#include <inp_Visitor.h>


// Class definition

class inpO_Visitor: public inp_Visitor, 
                    protected inpO_KeywordParameterReader, 
                    protected inpO_MessageContainer
{
public:

   inpO_Visitor(odb_Odb& odb, inpO_ModelInventory& modelInv);
   ~inpO_Visitor();

   virtual void VisitList(inp_KeywordList&);
   virtual void VisitSuboptions(inp_Keyword&);
   virtual void Report() const;
   virtual void VisitListAndReport(inp_KeywordList&);

protected:
   virtual void DefaultAction(inp_Keyword&);

   //
   virtual void VisitAssembly(inp_Keyword&);

   virtual void VisitEndAssembly(inp_Keyword&);
   virtual void VisitEndInstance(inp_Keyword&);
   virtual void VisitEndPart(inp_Keyword&);

   virtual void VisitInstance(inp_Keyword&);
   virtual void VisitPart(inp_Keyword&);

   odb_Assembly& rootAssembly();

   void SetCurrentPart(const cow_String& partName);
   void SetCurrentInstance(const cow_String& instanceName);
   void ClearCurrentComponent();

   bool InPart() const;
   bool InInstance() const;
   bool InAssembly() const;  // outside of a part or instance

   bool IsPartDefined(const cow_String& partName) const;
   bool IsInstanceDefined(const cow_String& instanceName) const;

   odb_Part& GetPart(const cow_String& partName);
   odb_Part& GetPartOfInstance(const cow_String& instanceName);
   odb_Instance& GetInstance(const cow_String& instanceName);

   void AssertValidComponent() const;
   void AssertValidComponent(const odb_DiscreteEntity*) const;
   void AssertValidInstance(const cow_String& instanceName) const;
   void AssertValidPart(const cow_String& partName) const;

   odb_Node GetNode(const inpO_AbaqusName& item) const;
   odb_Set  GetNodeSet(const inpO_AbaqusName& setName);
   odb_Set GetNodeSet(odb_Instance& i, const cow_String& name);
   odb_Set GetNodeSet(odb_Part& p, const cow_String& name);
   odb_Set GetAssemblyLevelNodeSet(const inpO_AbaqusName& item);
   odb_Set GetAssemblyNodeSet(const cow_String& name);

   void AssertValidNodeSet(const odb_DiscreteEntity*, const cow_String&) const;
   void AssertValidNodeSetItem(const odb_DiscreteEntity* comp, const inpO_AbaqusName& setItem);
   void Node2Coord(const inpO_AbaqusName& item, inpO_Coord& coord);
   void Node2Coord(const inpO_AbaqusName& item, double& x, double& y, double& z);

   void AssertValidElementSet(const odb_DiscreteEntity*, const cow_String&) const;
   void AssertValidElementSetItem(const odb_DiscreteEntity* comp, const inpO_AbaqusName& setItem);
   odb_Set GetElementSet(const inpO_AbaqusName& item);  // elementSets() non-const
   odb_Set GetElementSet(odb_Instance& i, const cow_String& name);
   odb_Set GetElementSet(odb_Part& p, const cow_String& name);
   odb_Set GetAssemblyLevelElementSet(const inpO_AbaqusName& item);
   odb_Set GetAssemblyElementSet(const cow_String& name);

   void AssertValidOrientation(const odb_Part*, const cow_String&) const;

   odb_Enum::odb_DimensionEnum GetModelCoorSpace() const;

   bool CheckLengthOfRequiredData(const inp_Keyword& keyword,
                                  int numDataCols,
                                  int numRequiredCols,
                                  int dataLine);

   odb_AnalyticSurface GetPartAnalyticalSurface(odb_Part& part,
                                                const cow_String& surface);
   odb_AnalyticSurface GetAnalyticalSurface(const cow_String& instance,
                                            const cow_String& surface);
   odb_AnalyticSurface GetAssemblyAnalyticalSurface(const inpO_AbaqusName& item);

   // data members
   odb_Odb& m_odb;
   inpO_ModelInventory& m_inventory;

   odb_Assembly*       m_assembly;
   odb_DiscreteEntity* m_component;
   odb_Part*           m_part;

   bool m_inPart;
   bool m_inInstance;
};


//---------------------------------------------------------------------------->
inline bool
inpO_Visitor::InPart() const
//---------------------------------------------------------------------------->
{
   return m_inPart;
}

//---------------------------------------------------------------------------->
inline bool
inpO_Visitor::InInstance() const
//---------------------------------------------------------------------------->
{
   return m_inInstance;
}

//---------------------------------------------------------------------------->
inline bool
inpO_Visitor::InAssembly() const
//---------------------------------------------------------------------------->
{
   return (!m_inPart) && (!m_inInstance);
}



#endif /* inpO_Visitor_h */
