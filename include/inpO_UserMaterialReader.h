/*   -*- mode: c++ -*-   */
#ifndef inpO_UserMaterialReader_h
#define inpO_UserMaterialReader_h

///////////////////////////////////////////////////////////////////////////////
//
// Class: inpO_UserMaterialReader
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

class inpO_UserMaterialReader  : public mem_AllocationOperators
{
public:

   inpO_UserMaterialReader();
   ~inpO_UserMaterialReader();

   void Initialize();
   void Read(const inp_Keyword& keyword);
   void Create(kmaO_Material& material);  // call initialize

private:

   void ReadMechanicalType(const inp_Keyword& keyword);
   void ReadThermalType(const inp_Keyword& keyword);

   // data members
   bool m_active;

   bool m_mechanicalActive;
   bool m_mechanicalUnsymm;
   int  m_mechanicalConstants;

   bool m_thermalActive;
   bool m_thermalUnsymm;
   int  m_thermalConstants;

   odb_SequenceDouble m_mechanicalTable;
   odb_SequenceDouble m_thermalTable;
};



#endif /* inpO_UserMaterialReader_h */
