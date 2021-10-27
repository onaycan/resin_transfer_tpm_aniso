/*   -*- mode: c++ -*-   */
#ifndef inpO_DruckerPragerHardening_h
#define inpO_DruckerPragerHardening_h

///////////////////////////////////////////////////////////////////////////////
//
// Class: inpO_DruckerPragerHardening
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
#include <cow_CountedHld.h>

#include <inpO_KeywordDataTable.h>


// Class definition

class inpO_DruckerPragerHardening  : public mem_AllocationOperators
{
public:

   inpO_DruckerPragerHardening();
   ~inpO_DruckerPragerHardening();

   void Initialize();
   void Read(const inp_Keyword& keyword);
   void Create(kmaO_Material& material);  // call initialize

private:

   // data members
   bool m_active;

   bool m_rate;
   double m_strainRate;
   double m_strainRateDefault;

   cow_String m_type;

   inpO_KeywordDataTable m_dataTable;
};

COW_COUNTEDHLD_DECL(inpO_DruckerPragerHardening, inpO_DruckerPragerHardeningHld)



#endif /* inpO_DruckerPragerHardening_h */
