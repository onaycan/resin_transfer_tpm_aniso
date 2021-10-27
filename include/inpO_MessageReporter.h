/*   -*- mode: c++ -*-   */
#ifndef inpO_MessageReporter_h
#define inpO_MessageReporter_h

///////////////////////////////////////////////////////////////////////////////
//
// Class: inpO_MessageReporter
//
// Description:
//

// Includes

// Forward declarations
class inpO_MessageContainer;
class inpO_Message;

// Begin local includes
#include <mem_AllocationOperators.h>
#include <atr_String.h>


// Class definition

class inpO_MessageReporter  : public mem_AllocationOperators
{
public:

   inpO_MessageReporter(inpO_MessageContainer& messages);
   virtual ~inpO_MessageReporter();

   void Report();

private:

   void ReportMessage(const inpO_Message& msg);
   void ReportMessage(const atr_String& prefix, const inpO_Message& msg);
   void ReportDefaultMessage(const inpO_Message& msg);
   void ReportWarningMessage(const inpO_Message& msg);
   void ReportErrorMessage(const inpO_Message& msg);
   void ReportFatalErrorMessage(const inpO_Message& msg);

   void Report(const atr_String& prefix, const inpO_Message& msg);

   void OutputMessagge(const atr_String& prefix, const atr_String&);
   void OutputErrorMessagge(const atr_String& prefix, const atr_String&);

   atr_String FormatMessage(const atr_String& message,
                            const atr_String& prefix,
                            const atr_String& empty,
                            int               width);

   atr_String FormMessageHeader(const atr_String& prefix,
                                const inpO_Message& msg) const;

   // data
   int         m_messageWidth;
   atr_String  m_indentString;

   inpO_MessageContainer& m_messages;
};


#endif /* inpO_MessageReporter_h */
