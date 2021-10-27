/*   -*- mode: c++ -*-   */
#ifndef inpO_GasketThicknessBehavior_h
#define inpO_GasketThicknessBehavior_h

///////////////////////////////////////////////////////////////////////////////
//
// Class: inpO_GasketThicknessBehavior
//
// Description:
//

// Includes

// Forward declarations
class inp_Keyword;
class kmaO_Material;

// Begin local includes
#include <mem_AllocationOperators.h>
#include <cow_String.h>

#include <inpO_KeywordDataTable.h>


// Class definition

class inpO_GasketThicknessBehavior  : public mem_AllocationOperators
{
public:

   inpO_GasketThicknessBehavior();
   ~inpO_GasketThicknessBehavior();

   void Initialize();
   void Read(const inp_Keyword& keyword);
   void Create(kmaO_Material& material);  // call initialize

private:

   // data members
   bool m_active;

   double m_yieldOnset;
   double m_tensileStiffnessFactor;

   cow_String m_direction;
   cow_String m_variableUnits;
   cow_String m_type;
   cow_String m_yieldOnsetMethod;

   inpO_KeywordDataTable m_unloadingTable;
   inpO_KeywordDataTable m_loadingTable;
};



#endif /* inpO_GasketThicknessBehavior_h */
