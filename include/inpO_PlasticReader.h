/*   -*- mode: c++ -*-   */
#ifndef inpO_PlasticReader_h
#define inpO_PlasticReader_h

///////////////////////////////////////////////////////////////////////////////
//
// Class: inpO_PlasticReader
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

class inpO_PlasticReader  : public mem_AllocationOperators
{
public:

   inpO_PlasticReader();
   ~inpO_PlasticReader();

   void Initialize();
   void Read(const inp_Keyword& keyword);
   void Create(kmaO_Material& material);  // call initialize

private:

   // data members
   bool m_active;

   bool m_strainRangeDep;
   bool m_rate;

   double m_gamma;
   double m_strainRate;
   double m_strainRateDefault;

   cow_String m_hardening;
   cow_String m_dataType;

   inpO_KeywordDataTable m_dataTable;
};



#endif /* inpO_PlasticReader_h */
