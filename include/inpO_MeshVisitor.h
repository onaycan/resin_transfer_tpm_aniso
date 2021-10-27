/*   -*- mode: c++ -*-   */
#ifndef inpO_MeshVisitor_h
#define inpO_MeshVisitor_h

///////////////////////////////////////////////////////////////////////////////
//
// Name: inpO_MeshVisitor
//
// Description: create mesh in the database
//

// Includes

// Forward declarations
class inpO_NodeData;
class inpO_AbaqusName;
class inpO_Coord;
class inpM_BaseSet;
class inpM_ElementFaceIdSurface;
class inpM_AssemblyInstanceSurface;
class inpM_PartInstanceSurface;

class odb_DiscreteEntity;
class odb_Part;
class odb_Instance;
class odb_Node;
class odb_Set;

// Begin local includes
#include <cow_ListInt.h>
#include <inpO_Visitor.h>
#include <inpO_BasicElemTypeData.h>

#include <odb_SequenceNode.h>
#include <odb_SequenceElement.h>
#include <odb_Types.h>

#include <gsl_Matrix.h>
#include <gsl_Vector.h>


// Class definition

class inpO_MeshVisitor: public inpO_Visitor
{
public:

   inpO_MeshVisitor(odb_Odb& odb, inpO_ModelInventory&);
   ~inpO_MeshVisitor();

   //
   virtual void VisitAssembly(inp_Keyword&);

   virtual void VisitEndAssembly(inp_Keyword&);
   virtual void VisitEndInstance(inp_Keyword&);
   virtual void VisitEndPart(inp_Keyword&);

   virtual void VisitInstance(inp_Keyword&);
   virtual void VisitPart(inp_Keyword&);

protected:
   void AddNodes(const odb_SequenceInt&           labels,
                 const odb_SequenceSequenceDouble& coords,
                 cow_String setName = cow_String());
   void AddNodeSet(const cow_String&   setName,
                   const inpM_BaseSet& newSet,
                   bool                internal = false,
                   bool                unsorted = false);
   void AddInstanceNodeSet(odb_Instance& i,
                           const cow_String&   setName,
                           const inpM_BaseSet& aSet,
                           bool                internal = false,
                           bool                unsorted = false);
   void AddAssemblyLevelNodeSet(odb_Assembly& a,
                                const cow_String&   setName,
                                const inpM_BaseSet& aSet,
                                bool                internal = false,
                                bool                unsorted = false);
   inpM_BaseSetCOW OdbNodeSet2Set(odb_Set&           existingSet, 
                                  const inpM_BaseSet& newSet, 
                                  bool                internal = false,
                                  bool                unsorted = false);
   void UpdateSetWithOdbNodeSet(inpM_BaseSet& aSet,
                                odb_Set&      odbSet,
                                bool inAssembly = false);
   void SetInstanceNamesAndLabels(const inpM_BaseSet&      aSet, 
                                  odb_SequenceString&      setInstanceNames,
                                  odb_SequenceSequenceInt& setLabels);

   void AddElements(const cow_String& etype, 
                    const odb_SequenceInt& labels, 
                    const odb_SequenceSequenceInt& connectivity);
   void AddElementSet(const cow_String&     setName,
                      const inpM_SortedSet& aSet,
                      bool                  internal = false);
   inpM_BaseSetCOW OdbElementSet2Set(odb_Set&              existingSet, 
                                     const inpM_SortedSet& newSet,
                                     bool                  internal = false);
   void UpdateSetWithOdbElementSet(inpM_SortedSet& aSet,
                                   odb_Set&      odbSet,
                                   bool inAssembly = false);

   void AddElementSet(const cow_String&      setName,
                      const odb_SequenceInt& labels,
                      bool                   internal = false);
   void AddElementSet(const cow_String&              setName,
                      const odb_SequenceString&      instanceNames,
                      const odb_SequenceSequenceInt& labels,
                      bool                           internal = false);

   cow_ListInt GetInstanceElemSetLabels(const cow_String& instance,
                                               const cow_String& set) const;
   cow_ListInt GetAssemblyElemSetLabels(const cow_String& set) const;
   cow_ListInt GetElemSetLabels(const odb_DiscreteEntity* comp, 
                                       const cow_String& set) const;

   //void GetAssemblySetLabels(odb_Set& set, 
   //                          odb_SequenceString& instanceNames, 
   //                          odb_SequenceSequenceInt& nodeLabels) const;
   void UpdateAssemblySetLabels(const cow_String& iName,
                                odb_SequenceString& instanceNames, 
                                odb_SequenceSequenceInt& oldLabels, 
                                const odb_SequenceInt& labels) const;
   cow_ListInt UpdateSetLabels(const odb_SequenceInt& oldLabels, 
                                      const odb_SequenceInt& newLabels,
                                      bool                   sorted = true) const;
   cow_ListInt Nodes2Labels(const odb_SequenceNode& nodes) const;
   cow_ListInt Elements2Labels(const odb_SequenceElement& elms) const;
   cow_ListInt SortLabels(const odb_SequenceInt& labels) const;


   odb_Part* CreatePart(const cow_String&);
   odb_Instance* CreateInstance(const cow_String&, const odb_Part&);
   void CreatePartInstance(inp_Keyword& keyword);
   void CreatePostponedInstance();

   void SetInstanceCoordinateData(inp_Keyword& keyword);
   odb_SequenceSequenceDouble GetInstanceCoordinateData() const;

   void PrintNodes(const odb_DiscreteEntity& component) const;

   //
   cow_String CreateReferenceNodeSetFromId(int nodeNumber);
   cow_String CreateReferenceNodeSetFromItem(const inpO_AbaqusName& item);

   // data
   inpO_BasicElemTypeData m_basicElemTypeData;

   bool m_postponeInstanceInit;

   gsl_Vector m_instanceTranslation;
   gsl_Matrix m_instanceRotation;
};

#endif /* inpO_MeshVisitor_h */
