/*   -*- mode: c++ -*-   */
#ifndef inpO_KeywordParameterReader_h
#define inpO_KeywordParameterReader_h

///////////////////////////////////////////////////////////////////////////////
//
// Class: inpO_KeywordParameterReader
//
// Description:
//

// Includes

// Forward declarations
class inp_Keyword;

// Begin local includes
#include <mem_AllocationOperators.h>
#include <cow_String.h>
#include <cow_ListString.h>

// Class definition


class inpO_KeywordParameterReader  : public mem_AllocationOperators
{
protected:

   inpO_KeywordParameterReader();
   ~inpO_KeywordParameterReader();

   bool CheckRequiredKeywordParameter(const inp_Keyword& keyword,
                                      const cow_String&  parameterName,
                                      bool throwExc = true) const;
   cow_String KeywordParameterSwitch(const inp_Keyword& keyword,
                                     const cow_String&  parameterName,
                                     const cow_String&  valueYes,
                                     const cow_String&  valueNo) const;
   cow_String CheckRequiredMutuallyExclusiveParameters(const inp_Keyword& keyword,
                                                       const cow_String& arg1, 
                                                       const cow_String& arg2,
                                                       const cow_String& arg3) const;
   cow_String CheckMutuallyExclusiveParameters(const inp_Keyword& keyword,
                                               const cow_String& arg1, 
                                               const cow_String& arg2,
                                               bool oneRequired = false) const;
   void CheckUnsupportedParameters(const inp_Keyword& keyword,
                                   const cow_ListString& itemsNotSupported) const;
   void CheckUnsupportedParameterValues(const inp_Keyword& keyword,
                                        const cow_String& parameter,
                                        const cow_ListString& itemsNotSupported) const;

private:
   cow_String ListString2String(const cow_ListString& list) const;
};



#endif /* inpO_KeywordParameterReader_h */
