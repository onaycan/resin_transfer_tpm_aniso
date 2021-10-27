/*   -*- mode: c++ -*-   */
#ifndef inpO_MessageContainer_h
#define inpO_MessageContainer_h

///////////////////////////////////////////////////////////////////////////////
//
// Class: inpO_MessageContainer
//
// Description:
//

// Includes

// Forward declarations

// Begin local includes
#include <mem_AllocationOperators.h>
#include <inpO_Enum.h>
#include <inpO_Message.h>

// Class definition

class inpO_MessageContainer  : public mem_AllocationOperators
{
public:

   inpO_MessageContainer();
   virtual ~inpO_MessageContainer();

   // by msgType, msgId
   virtual void Message(inpO_Enum::MsgType msgType,
                        int msgId,
                inpO_Enum::MsgSeverity msgSeverity = inpO_Enum::MESSAGE_SEVERITY_UNDEFINED,
                        const inpO_MsgArg* msgArgPtr = 0);

   virtual void Warning(inpO_Enum::MsgType msgType, 
                        int msgId, 
                        const inpO_MsgArg* msgArgPtr = 0);

   virtual void Error(inpO_Enum::MsgType msgType, 
                      int msgId, 
                      const inpO_MsgArg* msgArgPtr = 0);

   virtual void FatalError(inpO_Enum::MsgType msgType, 
                           int msgId, 
                           const inpO_MsgArg* msgArgPtr = 0);

   // by keyword, msgType, msgId
   void Message(const inp_Keyword& keyword,
                inpO_Enum::MsgType msgType,
                int msgId,
                inpO_Enum::MsgSeverity msgSeverity = inpO_Enum::MESSAGE_SEVERITY_UNDEFINED,
                int dataLineNumber = -1,
                const inpO_MsgArg* msgArgPtr = 0);

   void Warning(const inp_Keyword& keyword,
                inpO_Enum::MsgType msgType, 
                int msgId,
                int dataLineNumber = -1,
                const inpO_MsgArg* msgArgPtr = 0);

   void Error(const inp_Keyword& keyword,
              inpO_Enum::MsgType msgType, 
              int msgId, 
              int dataLineNumber = -1,
              const inpO_MsgArg* msgArgPtr = 0);

   void FatalError(const inp_Keyword& keyword,
                   inpO_Enum::MsgType msgType, 
                   int msgId, 
                   int dataLineNumber = -1,
                   const inpO_MsgArg* msgArgPtr = 0);

   // by atr_String
   void Message(const inp_Keyword& keyword,
                const atr_String& msgText,
                inpO_Enum::MsgSeverity msgSeverity = inpO_Enum::MESSAGE_SEVERITY_UNDEFINED);

   void Warning(const inp_Keyword& keyword, const atr_String& msgText);
   void Error(const inp_Keyword& keyword, const atr_String& msgText);
   void FatalError(const inp_Keyword& keyword, const atr_String& msgText);

   // by inpO_Message
   void Warning(inpO_Message& msg, const inpO_MsgArg* msgArgPtr = 0);
   void Error(inpO_Message& msg, const inpO_MsgArg* msgArgPtr = 0);
   void FatalError(inpO_Message& msg, const inpO_MsgArg* msgArgPtr = 0);

   void AddMessage(const inpO_Message& msg);
   void AddMessage(const inpO_Message& msg, const inp_Keyword& kwd);
   const inpO_MessageList& GetMessageList() const;
   inpO_MessageList& GetMessageList();

private:

   inpO_MessageList  m_msgList;
};


//---------------------------------------------------------------------------->
inline const inpO_MessageList &
inpO_MessageContainer::GetMessageList() const
//---------------------------------------------------------------------------->
{
   return m_msgList;
}

//---------------------------------------------------------------------------->
inline inpO_MessageList &
inpO_MessageContainer::GetMessageList()
//---------------------------------------------------------------------------->
{
   return m_msgList;
}


#endif /* inpO_MessageContainer_h */
