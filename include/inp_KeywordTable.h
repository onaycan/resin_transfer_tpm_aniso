//* -*- mode: c++ -*- */
#ifndef inp_KeywordTable_h
#define inp_KeywordTable_h

///////////////////////////////////////////////////////////////////////////////
//
// Name: inp_KeywordTable.h
//
// Description:  Table for holding information on valid keyword name, 
//               valid keyword suboption names, etc...
//

// Includes

// Begin Local Includes

#include <inp_keywords.h>
#include <cow_ListInt.h>
#include <cow_String.h>
#include <cow_Map.h>
#include <cow_MapInt2ListInt.h>
#include <cow_MapInt2String.h>
#include <thr_ThreadSingleton.h>

COW_MAP_ITER_DECL(cow_String, inp_KeywordEnm, inp_MapString2KeywordEnm);

// Class definition

class inp_KeywordTable: public thr_ThreadSingleton<inp_KeywordTable>
{
    friend class thr_ThreadSingleton<inp_KeywordTable>;
    friend class thr_ThrSingletonRegistry;
public:

   ~inp_KeywordTable();

    cow_ListInt AllKeywords() const; // All valid keywords

    cow_ListInt AssemblySuboptions() const;
    cow_ListInt InstanceSuboptions() const;
    cow_ListInt ModelSuboptions() const;
    cow_ListInt PartSuboptions() const;

    cow_ListInt ParentKeywords(inp_KeywordEnm kwenum) const;

    // Keyword name passed in must be in lowercase with no spaces
    bool IsValid(const inp_KeywordEnm& key) const {
	return validKeywordSuboptions.IsMember(key);
    }

    const cow_ListInt& Suboptions(const int& key) const {
	return validKeywordSuboptions.ConstGet(key);
    }

    // Return keyword enum given the keyword name
    cow_String Name(inp_KeywordEnm key) const {
	return enumKeywordMap.ConstGet(key);
    }

    // Return keyword enum given the keyword name
    inp_KeywordEnm Enum(const cow_String& kw) const;

    cow_String FullName(const cow_String& keywordName) const;

    cow_String KeywordEnum2String(cow_ListInt kwIds) const;

    static int Finalize();

  private:

    inp_KeywordTable();
    cow_ListInt AllKeywordsBelow(const int& key) const;
    cow_ListInt AllKeywordsBelow(const cow_ListInt& keys) const;

    // Members

    cow_MapInt2ListInt validKeywordSuboptions;
    inp_MapString2KeywordEnm keywordEnumMap;
    cow_MapInt2String enumKeywordMap;
};

#endif  // #ifdef inp_KeywordTable_h
