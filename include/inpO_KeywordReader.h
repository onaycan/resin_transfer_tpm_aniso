/*   -*- mode: c++ -*-   */
#ifndef inpO_KeywordReader_h
#define inpO_KeywordReader_h

///////////////////////////////////////////////////////////////////////////////
//
// Class: inpO_KeywordReader
//
// Description:
//

// Includes

// Forward declarations
class inp_Keyword;

// Begin local includes
#include <inpO_KeywordParameterReader.h>
#include <inpO_Message.h>
#include <inpO_MessageContainer.h>
#include <inpO_Enum.h>

// Class definition

class inpO_KeywordReader: public inpO_KeywordParameterReader, public inpO_MessageContainer
{
protected:

   inpO_KeywordReader(const inp_Keyword& keyword);
   ~inpO_KeywordReader();

   virtual void ReadValidItem();
   virtual void FinalizeReading();
   virtual bool ReadItem();

  bool CheckRequiredKeywordParameter(const cow_String& parameterName,
                                     bool throwExc = true) const;

   bool IsTheLastRow() const;
   bool IsTheLastRow(int) const;

   void SkipTrailingBlankLines();


   // Message interface
   virtual void Message(inpO_Enum::MsgType msgType,
                        int                msgId,
                inpO_Enum::MsgSeverity msgSeverity = inpO_Enum::MESSAGE_SEVERITY_UNDEFINED,
                        const inpO_MsgArg* msgArgPtr = 0);
   virtual void Warning(inpO_Enum::MsgType msgType, 
                        int                msgId, 
                        const inpO_MsgArg* msgArgPtr = 0);
   virtual void Error(inpO_Enum::MsgType msgType, 
                      int                msgId, 
                      const inpO_MsgArg* msgArgPtr = 0);

   inpO_Message CreateMessage(inpO_Enum::MsgType msgType,  // keyword data appended
                              int                msgId,
                inpO_Enum::MsgSeverity msgSeverity = inpO_Enum::MESSAGE_SEVERITY_UNDEFINED,
                              const inpO_MsgArg* msgArgPtr = 0);
   inpO_Message CreateError(inpO_Enum::MsgType msgType,  // keyword data appended
                            int                msgId,
                            const inpO_MsgArg* msgArgPtr = 0);
   inpO_Message CreateWarning(inpO_Enum::MsgType msgType, 
                              int                msgId,
                              const inpO_MsgArg* msgArgPtr = 0);

   // data members
   int m_numRows;
   int m_currentRow;   // numbering starts from zero

   const inp_Keyword& m_keyword;
};


//---------------------------------------------------------------------------->
inline bool
inpO_KeywordReader::IsTheLastRow(int lineNumber) const
//---------------------------------------------------------------------------->
{
   return (! (lineNumber < m_numRows));
}



#endif /* inpO_KeywordReader_h */
