/*   -*- mode: c++ -*-   */
#ifndef inpO_KeywordSuboptionIterator_h
#define inpO_KeywordSuboptionIterator_h

///////////////////////////////////////////////////////////////////////////////
//
// Class: inpO_KeywordSuboptionIterator
//
// Description:
//

// Includes

// Forward declarations
class inp_Keyword;

// Begin local includes
#include <mem_AllocationOperators.h>
#include <cow_String.h>
#include <inp_keywords.h>


// Class definition

class inpO_KeywordSuboptionIterator  : public mem_AllocationOperators
{
public:
   inpO_KeywordSuboptionIterator(const inp_Keyword& keyword,
                                 inp_KeywordEnm keywordEnm);
   inpO_KeywordSuboptionIterator(const inp_Keyword& keyword,
                                 inp_KeywordEnm keywordEnm,
                                 const cow_String& parameter);
   ~inpO_KeywordSuboptionIterator();

   void First();
   void Next();
   bool IsDone() const;

   const inp_Keyword& CurrentItem() const;

private:

   const inp_Keyword* ReadValidItem();

   // data members
   const inp_Keyword& m_keyword;
   inp_KeywordEnm m_targetKeyword;

   cow_String m_parameter;

   bool m_isDone;
   int m_currentIdx;
};


//---------------------------------------------------------------------------->
inline bool
inpO_KeywordSuboptionIterator::IsDone() const
//---------------------------------------------------------------------------->
{
   return m_isDone;
}



#endif /* inpO_KeywordSuboptionIterator_h */
