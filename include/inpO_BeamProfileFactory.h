/*   -*- mode: c++ -*-   */
#ifndef inpO_BeamProfileFactory_h
#define inpO_BeamProfileFactory_h

///////////////////////////////////////////////////////////////////////////////
//
// Class: inpO_BeamProfileFactory
//
// Description:
//

// Includes

// Forward declarations
class inp_Keyword;
class kseO_ApiExtension;

// Begin local includes
#include <mem_AllocationOperators.h>
#include <cow_String.h>


// Class definition

class inpO_BeamProfileFactory  : public mem_AllocationOperators
{
public:

   inpO_BeamProfileFactory(kseO_ApiExtension&);
   ~inpO_BeamProfileFactory();

   cow_String Make(const inp_Keyword& keyword);

private:

   void MakeArbitraryProfile(const cow_String&, const inp_Keyword&);
   void MakeBoxProfile(const cow_String&, const inp_Keyword&);
   void MakeCircularProfile(const cow_String&, const inp_Keyword&);
   void MakeHexProfile(const cow_String&, const inp_Keyword&);
   void MakeIProfile(const cow_String&, const inp_Keyword&);
   void MakeLProfile(const cow_String&, const inp_Keyword&);
   void MakePipeProfile(const cow_String&, const inp_Keyword&);
   void MakeRectangularProfile(const cow_String&, const inp_Keyword&);
   void MakeTrapezoidProfile(const cow_String&, const inp_Keyword&);
   void MakeNonlinearGeneralProfile(const cow_String&, const inp_Keyword&);
   void MakeGeneralProfile(const cow_String&, const inp_Keyword&);

   cow_String MakeProfileName(const inp_Keyword& keyword) const;
   cow_String GetSectionType(const inp_Keyword& keyword) const;

   // data members
   kseO_ApiExtension& m_sectApi;
};



#endif /* inpO_BeamProfileFactory_h */
