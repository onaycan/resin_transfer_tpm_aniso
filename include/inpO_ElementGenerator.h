/*   -*- mode: c++ -*-   */
#ifndef inpO_ElementGenerator_h
#define inpO_ElementGenerator_h

///////////////////////////////////////////////////////////////////////////////
//
// Class: inpO_ElementGenerator
//
// Description:
//

// Includes

// Forward declarations
class odb_Element;
class odb_SequenceElement;
class odb_Set;
class odb_DiscreteEntity;
class inp_Keyword;
class inpO_BasicElemTypeData;

// Begin local includes
#include <mem_AllocationOperators.h>
#include <inpO_MessageContainer.h>
#include <inpM_Set.h>
#include <cow_String.h>

#include <odb_Enum.h>
#include <odb_Types.h>

#include <cow_COW.h>
#include <cow_ListString.h>


// Class definition

class inpO_ElementGenerator: public inpO_MessageContainer
{
public:
   inpO_ElementGenerator();
   inpO_ElementGenerator(const inpO_BasicElemTypeData* basicElemTypeData);
   virtual ~inpO_ElementGenerator();

   virtual inpO_ElementGenerator* Copy() const = 0;

   const odb_SequenceInt& Labels() const;
   const odb_SequenceSequenceInt& Connectivity() const;

   const inpM_SortedSet& Set() const;

protected:
   // data
   const inpO_BasicElemTypeData* m_basicElemTypeData;

   odb_SequenceInt          m_labels;
   odb_SequenceSequenceInt  m_connectivity;

   inpM_SortedSet m_set;
};
COW_COW2_DECL(inpO_ElementGenerator, cow_Virtual);


//---------------------------------------------------------------------------->
inline const odb_SequenceInt&
inpO_ElementGenerator::Labels() const
//---------------------------------------------------------------------------->
{
   return m_labels;
}

//---------------------------------------------------------------------------->
inline const odb_SequenceSequenceInt&
inpO_ElementGenerator::Connectivity() const
//---------------------------------------------------------------------------->
{
   return m_connectivity;
}

//---------------------------------------------------------------------------->
inline const inpM_SortedSet&
inpO_ElementGenerator::Set() const
//---------------------------------------------------------------------------->
{
   return m_set;
}




class inpO_ElementGeneratorFactory  : public mem_AllocationOperators
{
public:
   inpO_ElementGeneratorFactory(odb_DiscreteEntity* comp);
   inpO_ElementGeneratorFactory(const inpO_BasicElemTypeData* basicElemTypeData);
   ~inpO_ElementGeneratorFactory();

   inpO_ElementGeneratorCOW MakeElgen(bool allnodes);

protected:
   const inpO_BasicElemTypeData* m_basicElemTypeData;
   odb_DiscreteEntity*           m_component;
};



class inpO_IncrementalElementGenerator: public inpO_ElementGenerator
{
public:
   inpO_IncrementalElementGenerator(const inpO_BasicElemTypeData* basicElemTypeData,
                                    bool allnodes);
   virtual ~inpO_IncrementalElementGenerator();

   virtual inpO_ElementGenerator* Copy() const;

   void ReadDataArray(const inp_DataArray& data, int rowNum);
   double GetLargestElementNumber() const;
   int GetMasterElementNumber() const;
   void Generate(const odb_Element& element);

private:
   void SetLargestElementNumber();
   // data
   bool m_allnodes;

	int m_masterElementNum;
	int m_numInRow;
	int m_incNodeRow;
	int m_incElemRow;
	int m_numRows;
	int m_incNodeRowToRow;
	int m_incElemRowToRow;
	int m_numLayers;
	int m_incNodeLayerToLayer;
	int m_incElemLayerToLayer;

   double m_maxElnumDbl;
};

//---------------------------------------------------------------------------->
inline double
inpO_IncrementalElementGenerator::GetLargestElementNumber() const
//---------------------------------------------------------------------------->
{
   return m_maxElnumDbl;
}

//---------------------------------------------------------------------------->
inline int
inpO_IncrementalElementGenerator::GetMasterElementNumber() const
//---------------------------------------------------------------------------->
{
   return m_masterElementNum;
}



class inpO_ElcopyElementGenerator: public inpO_ElementGenerator
{
public:
   inpO_ElcopyElementGenerator(const inpO_BasicElemTypeData* basicElemTypeData,
                               int elementShift, 
                               int shiftNodes, 
                               bool reflect);
   virtual ~inpO_ElcopyElementGenerator();

   virtual inpO_ElementGenerator* Copy() const;

   void Generate(const odb_SequenceElement& element);

   const cow_ListString& GetElementTypes() const;
   bool SameElementType() const;

private:
   // data
   int m_elementShift;
   int m_shiftNodes;
   bool m_reflect;
   bool m_sameElemeType;

   cow_ListString m_elemTypes;
};

//---------------------------------------------------------------------------->
inline const cow_ListString&
inpO_ElcopyElementGenerator::GetElementTypes() const
//---------------------------------------------------------------------------->
{
   return m_elemTypes;
}


//---------------------------------------------------------------------------->
inline bool
inpO_ElcopyElementGenerator::SameElementType() const
//---------------------------------------------------------------------------->
{
   return m_sameElemeType;
}



#endif /* inpO_ElementGenerator_h */
