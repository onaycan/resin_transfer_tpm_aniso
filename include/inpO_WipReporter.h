/* -*- mode: c++ -*- */
#ifndef inpO_WipReporter_h
#define inpO_WipReporter_h

///////////////////////////////////////////////////////////////////////////////
//
// Name: inpO_WipReporter
//
// Description: WIP Reporter for the Converter program.
//

// Forward declarations


// Begin local includes

#include <wip_WipReporter.h>
class aio_ostream;

// Class Definition

class inpO_WipReporter: public wip_WipReporter
{
public:

   inpO_WipReporter(aio_ostream& reporter);

   virtual void Error  (const atr_String&, 
                        wip_errorLevelEnm errLevel = wip_ERROR_DEFAULT);
   virtual void Warning(const atr_String&);
   virtual void ErrorList  (const cow_ListTranslatedString&, 
                            wip_errorLevelEnm errLevel = wip_ERROR_DEFAULT);
   virtual void WarningList(const cow_ListTranslatedString&);

   virtual void Verbose(const atr_String&);
   virtual void Milestone(const atr_String&);
   virtual void Landmark (const atr_String&);
   virtual void Milestone(const atr_String&, const atr_String&, int, int);
   virtual void Milestone(const atr_String&, int);
   virtual void Print    (const atr_String&);
   virtual void Display  (const atr_String&);

   virtual int  Interrupted();
   virtual void CommandDone();
   virtual void InterruptedThrow();

protected:

   atr_String FormatMessage(const atr_String& message,
                            const atr_String& prefix,
                            const atr_String& empty,
                            int               width);
private:

   aio_ostream& reporter;
};

#endif //ifdef inpO_WipReporter_h
