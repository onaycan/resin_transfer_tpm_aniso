/*   -*- mode: c++ -*-   */
#ifndef inpO_LabelGenerator_h
#define inpO_LabelGenerator_h

///////////////////////////////////////////////////////////////////////////////
//
// Class: inpO_LabelGenerator
//
// Description:
//

// Includes

// Forward declarations
class odb_DiscreteEntity;
class inp_Keyword;


// Begin local includes
#include <mem_AllocationOperators.h>
#include <cow_String.h>
#include <cow_ListInt.h>
#include <inpM_Set.h>

#include <odb_Types.h>

// Class definition

class inpO_LabelGenerator  : public mem_AllocationOperators
{
public:
   inpO_LabelGenerator(odb_DiscreteEntity* component, 
                       bool inAssembly = false);
   ~inpO_LabelGenerator();

   void GenerateInKeyword(const inp_Keyword& keyword);
   bool IsGenerateDataValid(int first, int second, int increment) const;

   bool InAssembly() const;
   const odb_SequenceInt& Labels() const;
   const inpM_SortedSet& Set() const;

protected:
   bool IsComponentAssembly() const;
   void GenerateLabels(int first, int second, int increment, 
                       const cow_String& componentName);
   cow_ListInt Generate(int first, int second, int increment);

private:
   bool m_inAssembly;
   odb_DiscreteEntity* m_component;
   inpM_SortedSet      m_set;

   odb_SequenceInt         m_labels;
   odb_SequenceString      m_componentNames;
   odb_SequenceSequenceInt m_componentLabels;

   cow_ListInt m_badDataRows;
};


//---------------------------------------------------------------------------->
inline bool
inpO_LabelGenerator::InAssembly() const
//---------------------------------------------------------------------------->
{
   return m_inAssembly;
}

//---------------------------------------------------------------------------->
inline const odb_SequenceInt&
inpO_LabelGenerator:: Labels() const
//---------------------------------------------------------------------------->
{
   return m_labels;
}

//---------------------------------------------------------------------------->
inline const inpM_SortedSet&
inpO_LabelGenerator:: Set() const
//---------------------------------------------------------------------------->
{
   return m_set;
}



#endif /* inpO_LabelGenerator_h */
