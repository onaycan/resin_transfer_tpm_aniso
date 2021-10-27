/*   -*- mode: c++ -*-   */
#ifndef inpO_SorptionReader_h
#define inpO_SorptionReader_h

///////////////////////////////////////////////////////////////////////////////
//
// Class: inpO_SorptionReader
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

#include <odb_Types.h>


// Class definition

class inpO_SorptionReader  : public mem_AllocationOperators
{
public:

   inpO_SorptionReader();
   ~inpO_SorptionReader();

   void Initialize();
   void Read(const inp_Keyword& keyword);
   void Create(kmaO_Material& material);  // call initialize

private:

   void ReadScanning(const inp_Keyword& keyword);
   void ReadExsorption(const inp_Keyword& keyword);
   void ReadAbsorption(const inp_Keyword& keyword);

   // data members
   bool m_absorption;
   bool m_exsorption;

   double m_scanning;

   cow_String m_lawA;
   cow_String m_lawE;

   odb_SequenceSequenceDouble m_absorpTable;
   odb_SequenceSequenceDouble m_exsorpTable;
};



#endif /* inpO_SorptionReader_h */
