/*   -*- mode: c++ -*-   */
#ifndef inpO_ElementTopologyReader_h
#define inpO_ElementTopologyReader_h

///////////////////////////////////////////////////////////////////////////////
//
// Class: inpO_ElementTopologyReader
//
// Description:
//

// Includes

// Forward declarations
class inpO_ElementParameters;

// Begin local includes
#include <inpO_KwdDataIterator.h>
#include <inpO_KeywordReader.h>
#include <odb_Types.h>


// Class definition

class inpO_ElementTopologyReader: public inpO_KeywordReader, public inpO_KwdDataIterator
{
public:

   inpO_ElementTopologyReader(const inp_Keyword& keyword,
                              inpO_ElementParameters& elemTypeData);
   ~inpO_ElementTopologyReader();

   int Label() const;
   const odb_SequenceInt& Connectivity() const;

   virtual void First();
   virtual void Next();
   virtual bool IsDone() const;

   virtual void FinalizeReading();
   virtual bool ReadItem();

   void ResetElementData();

private:

   bool CheckElementValidity(int label, const odb_SequenceInt& connectivity);
   bool CheckLabel(int label);
   bool CheckConnectivity(int label, const odb_SequenceInt& connectivity);

   void Error(int msgId, const inpO_MsgArg* msgArgPtr = 0);
   void Warning(int msgId, const inpO_MsgArg* msgArgPtr = 0);

   inpO_ElementParameters& m_elemTypeData;

   int             m_label;
   odb_SequenceInt m_connectivity;
};


//---------------------------------------------------------------------------->
inline int
inpO_ElementTopologyReader::Label() const
//---------------------------------------------------------------------------->
{
   return m_label;
}


//---------------------------------------------------------------------------->
inline const odb_SequenceInt&
inpO_ElementTopologyReader::Connectivity() const
//---------------------------------------------------------------------------->
{
   return m_connectivity;
}



#endif /* inpO_ElementTopologyReader_h */
