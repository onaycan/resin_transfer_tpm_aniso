/*   -*- mode: c++ -*-   */
#ifndef inpO_AcousticMediumReader_h
#define inpO_AcousticMediumReader_h

///////////////////////////////////////////////////////////////////////////////
//
// Class: inpO_AcousticMediumReader
//
// Description:
//

// Includes

// Forward declarations
class inp_Keyword;
class kmaO_Material;

// Begin local includes
#include <mem_AllocationOperators.h>
#include <inpO_KeywordDataTable.h>


// Class definition

class inpO_AcousticMediumReader  : public mem_AllocationOperators
{
public:

   inpO_AcousticMediumReader();
   ~inpO_AcousticMediumReader();

   void Initialize();
   void Read(const inp_Keyword& keyword);
   void Create(kmaO_Material& material);  // calls Initialize

private:

   void ReadBulkModulus(const inp_Keyword& keyword);
   void ReadVolumetricDrag(const inp_Keyword& keyword);

   // data members
   bool m_active;
   bool m_drag;

   inpO_KeywordDataTable m_bulkTable;
   inpO_KeywordDataTable m_volumetricTable;
};



#endif /* inpO_AcousticMediumReader_h */
