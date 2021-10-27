/*   -*- mode: c++ -*-   */
#ifndef inpM_Utils_h
#define inpM_Utils_h

///////////////////////////////////////////////////////////////////////////////
//
// File Name: inpM_Utils.h
//
// Description:  Map utilities
//

// Includes

// Forward declarations

class atr_String;

// Begin local includes

#include <cow_ListString.h>
#include <cow_ListInt.h>
#include <cow_ListInt64.h>

// Class definition

struct inpM_Utils
{
    static atr_String FormatCollectedErrors(
	const atr_String& title, const cow_ListString& badItems);
    static atr_String FormatCollectedErrors(
	const atr_String& title, const cow_ListInt& badItems);
    static cow_String RemoveQuotes(const cow_String&);
    static bool CompareIgnoreCase(const cow_String&, const cow_String&);
    static int FindIgnoreCase(const cow_String&, const cow_String&,
			      const int start = 0);
    static cow_String AddQuotes(const cow_String&);
    static bool CompareIgnoreQuotes(
	const cow_String&, 
	const cow_String&);
    static bool CompareIgnoreCaseAndQuotes(
	const cow_String&,
	const cow_String&);
    static bool Quotes(const cow_String&);
    static int SortCmp(const void *a, const void *b);
    static void Sort(cow_ListInt& ids);
    static int Sort64Cmp(const void *a, const void *b);
    static void Sort64(cow_ListInt64& ids);
};

#endif /* inpM_Utils_h */
