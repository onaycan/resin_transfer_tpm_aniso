/*   -*- mode: c++ -*-   */
#ifndef inpO_NodeGenerator_h
#define inpO_NodeGenerator_h

///////////////////////////////////////////////////////////////////////////////
//
// Class: inpO_NodeGenerator
//
// Description:
//

// Includes

// Forward declarations
class odb_Node;
class odb_Set;
class inp_Keyword;
class inpO_Coord;
class odb_SequenceNode;

// Begin local includes
#include <mem_AllocationOperators.h>
#include <inpO_MessageContainer.h>
#include <inpO_Coord.h>
#include <inpM_OmiSet.h>

#include <cow_String.h>
#include <cow_ListInt.h>

#include <odb_Enum.h>
#include <odb_Types.h>

#include <gsl_Vector.h>

#include <cow_COW.h>


// Class definition

class inpO_NodeGenerator: public inpO_MessageContainer
{
public:
   inpO_NodeGenerator(int numSpaceDim = 3, bool inAssembly = false);
   inpO_NodeGenerator(odb_Enum::odb_DimensionEnum);
   virtual ~inpO_NodeGenerator();

   virtual inpO_NodeGenerator* Copy() const = 0;

   virtual void Generate(const odb_Node& node1, 
                         const odb_Node& node2, 
                         const inpO_Coord& extra,
                         const inpO_Coord& normal,
                         int increment = 1);
   virtual void Generate(odb_Set& setA, 
                         odb_Set& setB,
                         int intervals,
                         int increment = 1);
   int CheckNfillData(const odb_Set& setA, 
                      const odb_Set& setB);

   int NumSpaceDim() const;
   const odb_SequenceInt& Labels() const;
   const odb_SequenceSequenceDouble& Coordinates() const;
   const inpM_OmiSet& Set() const;

protected:
   void AddCoords(int label, double x, double y, double z);
   void AddCoords(double x, double y, double z);
   cow_ListInt Nodes2Labels(const odb_SequenceNode& nodes, 
                                   bool unsorted = false) const;
   void AddEndNodes2Set(const odb_Node& nodeA, const odb_Node& nodeB);
   void ClearCoordinates();

   // data
   int  m_numSpaceDim;
   bool m_inAssembly;

   odb_SequenceInt           m_labels;
   odb_SequenceSequenceDouble m_coords;
   inpM_OmiSet               m_set;
};
COW_COW2_DECL(inpO_NodeGenerator, cow_Virtual);

//---------------------------------------------------------------------------->
inline int
inpO_NodeGenerator::NumSpaceDim() const
//---------------------------------------------------------------------------->
{
   return m_numSpaceDim;
}

//---------------------------------------------------------------------------->
inline const odb_SequenceInt&
inpO_NodeGenerator::Labels() const
//---------------------------------------------------------------------------->
{
   return m_labels;
}

//---------------------------------------------------------------------------->
inline const odb_SequenceSequenceDouble&
inpO_NodeGenerator::Coordinates() const
//---------------------------------------------------------------------------->
{
   return m_coords;
}

//---------------------------------------------------------------------------->
inline const inpM_OmiSet&
inpO_NodeGenerator:: Set() const
//---------------------------------------------------------------------------->
{
   return m_set;
}



class inpO_NodeGeneratorFactory  : public mem_AllocationOperators
{
public:
   inpO_NodeGeneratorFactory(int numSpaceDim = 3);
   inpO_NodeGeneratorFactory(odb_Enum::odb_DimensionEnum dimEnum);
   ~inpO_NodeGeneratorFactory();

   inpO_NodeGeneratorCOW MakeNgen(const cow_String& line,
                                  const cow_String& system);
   inpO_NodeGeneratorCOW MakeNfill(const inp_Keyword& keyword,
                                   double singular,
                                   int bias,
                                   bool twostep);

   void SetNumSpaceDim(int numSpaceDim);

protected:
   int m_numSpaceDim;
};

//---------------------------------------------------------------------------->
inline void
inpO_NodeGeneratorFactory::SetNumSpaceDim(int numSpaceDim)
//---------------------------------------------------------------------------->
{
   m_numSpaceDim = numSpaceDim;
}



class inpO_CircularNodeGenerator: public inpO_NodeGenerator
{
public:
   inpO_CircularNodeGenerator(int numSpaceDim = 3);
   virtual ~inpO_CircularNodeGenerator();

   virtual inpO_NodeGenerator* Copy() const;

   virtual void Generate(const odb_Node& node1, 
                         const odb_Node& node2,
                         const inpO_Coord& extra,
                         const inpO_Coord& normal,
                         int increment = 1);
private:
   bool CheckCircleData(const inpO_Coord& a,
                        const inpO_Coord& b,
                        const inpO_Coord& c,
                        const inpO_Coord& n);
   // data
   double m_radius;
   double m_alfa;

   inpO_Coord m_normVec;
   inpO_Coord m_orthVec;
   inpO_Coord m_y3;
   inpO_Coord m_yt;
};



class inpO_ParabolicNodeGenerator: public inpO_NodeGenerator
{
public:
   inpO_ParabolicNodeGenerator(int numSpaceDim = 3);
   virtual ~inpO_ParabolicNodeGenerator();

   virtual inpO_NodeGenerator* Copy() const;

   virtual void Generate(const odb_Node& node1, 
                         const odb_Node& node2, 
                         const inpO_Coord& extra,
                         const inpO_Coord& normal,
                         int increment = 1);
   virtual void Generate(const odb_Node& node1, 
                         const odb_Node& node2,
                         const inpO_Coord& extra,
                         int increment = 1);
};


class inpO_LineNodeGenerator: public inpO_NodeGenerator
{
public:
   inpO_LineNodeGenerator(int numSpaceDim = 3);
   virtual ~inpO_LineNodeGenerator();

   virtual inpO_NodeGenerator* Copy() const;

   virtual void Generate(const odb_Node& node1, 
                         const odb_Node& node2, 
                         const inpO_Coord& extra,
                         const inpO_Coord& normal,
                         int increment = 1);
   virtual void Generate(const odb_Node& node1, 
                         const odb_Node& node2,
                         int increment = 1);
};


class inpO_SingularNFillGenerator: public inpO_NodeGenerator
{
public:
   inpO_SingularNFillGenerator(double singular, int numSpaceDim = 3);
   virtual ~inpO_SingularNFillGenerator();

   virtual inpO_NodeGenerator* Copy() const;

   virtual void Generate(odb_Set& setA, 
                         odb_Set& setB,
                         int intervals,
                         int increment = 1);
protected:
   double m_singular;
};


class inpO_NFillGenerator: public inpO_NodeGenerator
{
public:
   inpO_NFillGenerator(int bias, bool twostep, int numSpaceDim = 3);
   virtual ~inpO_NFillGenerator();

   virtual inpO_NodeGenerator* Copy() const;

   virtual void Generate(odb_Set& setA, 
                         odb_Set& setB,
                         int intervals,
                         int increment = 1);
protected:
   int  m_bias;
   bool m_twostep;
};


#endif /* inpO_NodeGenerator_h */
