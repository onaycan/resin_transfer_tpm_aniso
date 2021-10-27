/*   -*- mode: c++ -*-   */
#ifndef inpO_Inp2OdbConverter_h
#define inpO_Inp2OdbConverter_h

///////////////////////////////////////////////////////////////////////////////
//
// Name: inpO_Inp2OdbConverter
//
// Description: Converter from an input file to the ODB
//

// Includes

// Forward declarations
class odb_Odb;
class eli_eostream;

// Begin local includes
#include <mem_AllocationOperators.h>
#include <inpO_ModelInventory.h>
#include <inp_Keyword.h>
#include <cow_String.h>
#include <omi_Timer.h>


// Class definition

class inpO_Inp2OdbConverter  : public mem_AllocationOperators
{
public:

   inpO_Inp2OdbConverter(const cow_String& jobName, 
                         cow_String input = "",
                         cow_String indir = "",
                         cow_String dbExt = ".odb");
   ~inpO_Inp2OdbConverter();

   odb_Odb& Convert(inp_KeywordList& keywords);
   void     Close();

   inp_KeywordList ParseAndExpand() const;
   inp_KeywordList ReorganizeKeywords(inp_KeywordList&) const;
   void Print(inp_KeywordList&, eli_eostream&) const;

   const cow_String& GetDatabaseName() const;

   void SetPrintFlat(bool value);
   void SetPrintKeywords(bool value);
   void SetPrintModelInventory(bool value);
   void SetTiming(bool value);

   static const char* m_DatabaseExt;  // extension for the binary database file
   static const char* m_InputExt;  // extension for the input file

private:
   void DiscardEmptyKeywords(inp_KeywordList&) const;

   odb_Odb& OpenDatabase();
   void BuildDatabase();
   void CloseDatabase();

   void StartTiming();
   void EndTiming(const cow_String& name);

   // data
   bool        m_printflat;
   bool        m_printkeywords;
   bool        m_printmodelinventory;
   bool        m_timing;

   cow_String  m_jobName;
   cow_String  m_inputName;
   cow_String  m_databaseName;
   cow_String  m_indir;
   cow_String  m_dbExt;

   omi_Timer   m_timer;

   inpO_ModelInventory m_modelInventory;
   inp_KeywordList m_keywords;

   odb_Odb* m_odb;
};

//---------------------------------------------------------------------------->
inline const cow_String&
inpO_Inp2OdbConverter::GetDatabaseName() const
//---------------------------------------------------------------------------->
{
   return m_databaseName;
}

//---------------------------------------------------------------------------->
inline void
inpO_Inp2OdbConverter::SetPrintFlat(bool value)
//---------------------------------------------------------------------------->
{
   m_printflat = value;
}

//---------------------------------------------------------------------------->
inline void
inpO_Inp2OdbConverter::SetPrintKeywords(bool value)
//---------------------------------------------------------------------------->
{
   m_printkeywords = value;
}

//---------------------------------------------------------------------------->
inline void
inpO_Inp2OdbConverter::SetPrintModelInventory(bool value)
//---------------------------------------------------------------------------->
{
   m_printmodelinventory = value;
}

//---------------------------------------------------------------------------->
inline void
inpO_Inp2OdbConverter::SetTiming(bool value)
//---------------------------------------------------------------------------->
{
   m_timing = value;
}


#endif /* inpO_Inp2OdbConverter_h */
