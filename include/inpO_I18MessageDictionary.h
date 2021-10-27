/*   -*- mode: c++ -*-   */
#ifndef inpO_I18MessageDictionary_h
#define inpO_I18MessageDictionary_h

///////////////////////////////////////////////////////////////////////////////
//
// Class: inpO_I18MessageDictionary
//
// Description:
//

// Includes

// Forward declarations
class inpO_Message;


// Begin local includes
#include <mem_AllocationOperators.h>


// Class definition


class inpO_I18MessageDictionary  : public mem_AllocationOperators
{
public:

   inpO_I18MessageDictionary();
   ~inpO_I18MessageDictionary();

   void Convert(inpO_Message& msg) const;
};



#endif /* inpO_I18MessageDictionary_h */
