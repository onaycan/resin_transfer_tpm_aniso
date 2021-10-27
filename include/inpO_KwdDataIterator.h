/*   -*- mode: c++ -*-   */
#ifndef inpO_KwdDataIterator_h
#define inpO_KwdDataIterator_h

///////////////////////////////////////////////////////////////////////////////
//
// Class: inpO_KwdDataIterator - base class for keyword data reader classes
//
// Description:
//

// Includes

// Forward declarations

// Begin local includes
#include <mem_AllocationOperators.h>

// Class definition

class inpO_KwdDataIterator  : public mem_AllocationOperators
{
public:

   inpO_KwdDataIterator() : m_isDone(false) {}
   ~inpO_KwdDataIterator() {}

   virtual void First() = 0;
   virtual void Next()  = 0;
   virtual bool IsDone() const = 0;

protected:

   bool m_isDone;
};


#endif /* inpO_KwdDataIterator_h */
