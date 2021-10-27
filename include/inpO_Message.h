/*   -*- mode: c++ -*-   */
#ifndef inpO_Message_h
#define inpO_Message_h

///////////////////////////////////////////////////////////////////////////////
//
// Class: inpO_Message
//
// Description:
//

// Includes

// Forward declarations

// Begin local includes
#include <mem_AllocationOperators.h>
#include <inpO_Enum.h>
#include <inp_Keyword.h>
#include <cow_String.h>
#include <cow_List.h>
#include <atr_String.h>

#include <omn_FixedString.h>

// Class definition

class inpO_MsgArg  : public mem_AllocationOperators
{
public:
   
   inpO_MsgArg();
   inpO_MsgArg(int);
   inpO_MsgArg(bool);
   inpO_MsgArg(double);
   inpO_MsgArg(const cow_String&);
   inpO_MsgArg(const omn_FixedString&);

   inpO_Enum::MsgArgType Type() const;
   const cow_String & AsString() const;

private:
 
   inpO_Enum::MsgArgType m_type;
   cow_String            m_value;
};

COW_LIST_DECL(inpO_MsgArg, inpO_MsgArgList);


//---------------------------------------------------------------------------->
inline const cow_String &
inpO_MsgArg::AsString() const
//---------------------------------------------------------------------------->
{
   return m_value;
}

//---------------------------------------------------------------------------->
inline inpO_Enum::MsgArgType
inpO_MsgArg::Type() const
//---------------------------------------------------------------------------->
{
   return m_type;
}

class inpO_Message  : public mem_AllocationOperators
{
   friend class inpO_I18MessageDictionary;
   friend class inpO_MessageReporter;
   friend class inpO_MessageContainer;

public:

   inpO_Message();  // cow_List.T requires

   inpO_Message(inpO_Enum::MsgType     msgType,
                int                    msgId,
                inpO_Enum::MsgSeverity msgSeverity = inpO_Enum::MESSAGE_SEVERITY_UNDEFINED);
   inpO_Message(const atr_String&      msg,
                inpO_Enum::MsgSeverity msgSeverity = inpO_Enum::MESSAGE_SEVERITY_UNDEFINED);

   inpO_Message(const inp_Keyword&     keyword,
                inpO_Enum::MsgType     msgType,
                int                    msgId,
                inpO_Enum::MsgSeverity msgSeverity = inpO_Enum::MESSAGE_SEVERITY_UNDEFINED,
                int                    dataLineNumber = -1);
   inpO_Message(const inp_Keyword&     keyword,
                const atr_String&      msg,
                inpO_Enum::MsgSeverity msgSeverity = inpO_Enum::MESSAGE_SEVERITY_UNDEFINED,
                int                    dataLineNumber = -1);

   ~inpO_Message();

   void SetMessageSeverity(inpO_Enum::MsgSeverity msgSeverity);
   inpO_Enum::MsgSeverity MessageSeverity() const;

   void AppendArg(const inpO_MsgArg& arg);
   void AppendArgList(const inpO_MsgArgList& argList);
   const atr_String& Text() const;
   void SubstituteArgs();

   // without keyword and data line (non-keyword message factory)
   static inpO_Message CreateMessage       (inpO_Enum::MsgType     msgType, 
                                            int                    msgId,
                                            inpO_Enum::MsgSeverity msgSeverity,
                                            const inpO_MsgArg*     msgArgPtr = 0);
   static inpO_Message CreateFatalErrorMessage (inpO_Enum::MsgType msgType, 
                                                int                msgId, 
                                                const inpO_MsgArg* msgArgPtr = 0);
   static inpO_Message CreateErrorMessage  (inpO_Enum::MsgType msgType, 
                                            int                msgId, 
                                            const inpO_MsgArg* msgArgPtr = 0);
   static inpO_Message CreateErrorMessage  (inpO_Enum::MsgType msgType, 
                                            int                msgId, 
                                            const inpO_MsgArgList& msgArgList);
   static inpO_Message CreateWarningMessage(inpO_Enum::MsgType msgType, 
                                            int                msgId, 
                                            const inpO_MsgArg* msgArgPtr = 0);

   // keyword message interface
   static inpO_Message CreateMessage       (const inp_Keyword&     keyword,
                                            inpO_Enum::MsgType     msgType, 
                                            int                    msgId,
                                            inpO_Enum::MsgSeverity msgSeverity,
                                            int                    dataLineNumber = -1,
                                            const inpO_MsgArg*     msgArgPtr = 0);
   static inpO_Message CreateErrorMessage  (const inp_Keyword&  keyword,
                                            inpO_Enum::MsgType  msgType, 
                                            int                 msgId, 
                                            int                 dataLineNumber = -1,
                                            const inpO_MsgArg*  msgArgPtr = 0);
   static inpO_Message CreateErrorMessage  (const inp_Keyword&      keyword,
                                            inpO_Enum::MsgType      msgType, 
                                            int                     msgId,
                                            const inpO_MsgArgList&  msgArgList,
                                            int                     dataLineNumber = -1);
   static inpO_Message CreateFatalErrorMessage (const inp_Keyword&  keyword,
                                                inpO_Enum::MsgType  msgType, 
                                                int                 msgId, 
                                                int                 dataLineNumber = -1,
                                                const inpO_MsgArg*  msgArgPtr = 0);
   static inpO_Message CreateWarningMessage(const inp_Keyword&  keyword,
                                            inpO_Enum::MsgType  msgType, 
                                            int                 msgId, 
                                            int                 dataLineNumber = -1,
                                            const inpO_MsgArg*  msgArgPtr = 0);

   // throw exceptions
   static void ThrowErrorMessage (const inp_Keyword& keyword,
                                  inpO_Enum::MsgType msgType, 
                                  int                msgId, 
                                  int                dataLineNumber = -1,
                                  const inpO_MsgArg* msgArgPtr = 0);
   static void ThrowErrorMessage (const inp_Keyword& keyword,
                                  inpO_Enum::MsgType msgType, 
                                  int                msgId,
                                  const inpO_MsgArgList& msgArgList,
                                  int                dataLineNumber = -1);
   static void ThrowFatalErrorMessage(const inp_Keyword& keyword,
                                      inpO_Enum::MsgType msgType, 
                                      int                msgId, 
                                      int                dataLineNumber = -1,
                                      const inpO_MsgArg* msgArgPtr = 0);

   static void ThrowErrorMessage  (inpO_Enum::MsgType msgType, 
                                   int                msgId, 
                                   const inpO_MsgArg* msgArgPtr = 0);
   static void ThrowErrorMessage  (inpO_Enum::MsgType msgType, 
                                   int                msgId, 
                                   const inpO_MsgArgList& msgArgList);
   static void ThrowFatalErrorMessage (inpO_Enum::MsgType msgType, 
                                       int                msgId, 
                                       const inpO_MsgArg* msgArgPtr = 0);

private:

   inp_KeywordEnm m_keyword;
   cow_String     m_fileName;
   int            m_kwdLineNumber;
   int            m_dataLineNumber;

   inpO_Enum::MsgType     m_msgType;
   inpO_Enum::MsgSeverity m_msgSeverity;
   int                    m_msgId;

   atr_String      m_message;
   inpO_MsgArgList m_argList;
};

COW_LIST_DECL(inpO_Message, inpO_MessageList);


//---------------------------------------------------------------------------->
inline const atr_String &
inpO_Message::Text() const
//---------------------------------------------------------------------------->
{
   return m_message;
}

//---------------------------------------------------------------------------->
inline void
inpO_Message::AppendArg(const inpO_MsgArg& arg)
//---------------------------------------------------------------------------->
{
   m_argList.Append(arg);
}

//---------------------------------------------------------------------------->
inline void
inpO_Message::AppendArgList(const inpO_MsgArgList& argList)
//---------------------------------------------------------------------------->
{
   m_argList.Concatenate(argList);
}

//---------------------------------------------------------------------------->
inline void
inpO_Message::SetMessageSeverity(inpO_Enum::MsgSeverity msgSeverity)
//---------------------------------------------------------------------------->
{
   m_msgSeverity = msgSeverity;
}

//---------------------------------------------------------------------------->
inline inpO_Enum::MsgSeverity
inpO_Message::MessageSeverity() const
//---------------------------------------------------------------------------->
{
   return m_msgSeverity;
}



#endif /* inpO_Message_h */
