/*   -*- mode: c++ -*-   */
#ifndef inp_Keyword_h
#define inp_Keyword_h

///////////////////////////////////////////////////////////////////////////////
//
// File Name: inp_Keyword.h
//
// Description:  
//

// Includes

// Forward declarations

class inp_Keyword;
class inp_Visitor;
class eli_eostream;
class aio_ostream;

// Begin local includes
#include <mem_AllocationOperators.h>

#include <inp_Data.h>
#include <inp_keywords.h>
#include <inp_KeywordTable.h>
#include <cow_ListString.h>

// Class definition

class inp_Item  : public mem_AllocationOperators
{
  public:

    inp_Item();
    inp_Item(int);
    inp_Item(bool);
    inp_Item(double);
    inp_Item(const cow_String&);

    inp_Types::typeEnm Type() const { return type; }
    cow_String AsString() const;
    int AsInt() const;
    double AsDouble() const;

  private:
 
    inp_Types::typeEnm type;
   
    int ival;
    bool bval;
    double dval;
    cow_String sval;
};


COW_MAP_ITER_DECL(cow_String, inp_Item, inp_ParameterMap);
COW_LIST_DECL(inp_Keyword, inp_KeywordList);
COW_LIST_DECL(inp_Item, inp_ItemList);
COW_MAP_ITER_DECL(cow_String, inp_ItemList, inp_ItemListMap);

class inp_Keyword  : public mem_AllocationOperators
{
  public:

    inp_Keyword();
    inp_Keyword(const cow_String& keywordName);
    inp_Keyword(const inp_KeywordEnm& key);
    inp_Keyword(const inp_KeywordEnm& key, const cow_String& fileName);
    inp_Keyword DeepCopy() const;

    inp_KeywordEnm key;
    inp_KeywordEnm parentKey;
    inp_ParameterMap parameters;
    inp_DataArray data;
    inp_KeywordList suboptions;

    cow_String  m_fileName;
    int         m_lineNumber;
    bool m_encrypted;
    cow_ListString m_comments;

    cow_String Name() const;
    void Print(eli_eostream&, bool printSuboptions = true) const;
    void Print(aio_ostream&, bool printSuboptions = true) const;
    cow_String Print(bool printSuboptions = true) const;
    void Accept(inp_Visitor&);
    bool hasSuboption(const inp_KeywordEnm& key);
    bool HasParameter(const cow_String& name) const;
    bool Is(inp_KeywordEnm keyEnm) const { return (key == keyEnm); }

    int GetParameterAsInt(const cow_String& name, int defaultValue = 0) const;
    double GetParameterAsDouble(const cow_String& name, double defaultValue = 0.0) const;
    cow_String GetParameterAsString(const cow_String& name, cow_String defaultValue = "") const;
    bool isEncrypted() const { return m_encrypted; }
    int lineNumber() const { return m_lineNumber; }
    cow_String fileName() const { return m_fileName; }
};

COW_MAP_ITER_DECL(cow_String, inp_KeywordList, inp_KeywordListMap);

#endif /* inp_Keyword_h */
