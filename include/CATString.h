#ifndef CATString_H
#define CATString_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include <stdlib.h>

// Begin local includes
#include <CATChar.h>
#include <atr_StringBase.h>
#include <CATDataType.h>
#include <JS0anchor.h>
//-----------------------------------------------------------------------------------

/**
 * Class to use for non language meaningful character strings. 
 * <b>Role</b>: Class for ISO 646 string, i.e. codes from
 * 0 to 127 in decimal:
 * <ul>
 * <li>C0 ASCII control codes (see the unicode standard
 * documentation): 0 to 31 in decimal</li>
 * <li>ASCII (contains digit characters, latin capital
 * letters, latin small letters, punctuation characters ...)</li>  
 * </ul>
 * ISO 646 has been specified by the International Organization for Standardization (http://www.iso.ch ).</br>
 * Thus, this class does not support NLS
 * (National Langage Support), at the opposite of @href CATUnicodeString .
 * Comparing this class to @href CATUnicodeString ,
 * the very simple character set supported here, 
 * once accepted the limitations it implies, enables to supress
 * all the problems that arise with NLS complexity.
 * Before using this class instead of @href CATUnicodeString,
 * check carefully that you will never need the NLS
 * support. 
 * The raw type char* you should never be used.
 */

class CATString : protected atr_StringBase
{ 
  
public:
/** @nodoc ABAQUS
  */
    atr_StringBase::operator new;
    atr_StringBase::operator delete;
    atr_StringBase::operator new[];
    atr_StringBase::operator delete[];

/** 
 * Strip mode.
 * <b>Role</b>: Stripping is the process consisting
 * of removing a peculiar character occurences from a given
 * string. Once the character specified , you can, as you want, 
 * use one of the
 * following options:
 * @param CATStripModeLeading
 *   Remove all the consecutive occurences of the  
 *   character from the beginning of the string 
 *   (of course it supposes that the first character of the 
 *   string is the specified character, if it is not the case, 
 *   nothing is done).
 * @param CATStripModeTrailing
 *   Remove all the consecutive occurences from the end
 *   of the string (It means that the first 
 *   character of the string is really the specified 
 *   character).
 * @param CATStripModeBoth
 *   Remove all the consecutive occurences both from the 
 *   beginning of the string and from the end (this option cumulates
 *   the two preceeding options, it does not affects the 
 *   intermediate consecutive occurences).
 * @param CATStripModeAll
 *   Removes all the occurences of the character
 *   from the string. 
 * <p>
 * Warning : CATStripMode is also defined in CATInternalString.cpp
 */
  enum CATStripMode {CATStripModeLeading = 0x1, CATStripModeTrailing = 0x2,
		     CATStripModeBoth = 0x3, CATStripModeAll=0x4}; // used by strip method

/**
 * Constructs a string object so that it represents an empty 
 * character sequence.
 */
  CATString(): atr_StringBase() { JS0anchor(); }        
/*
 * Copy constructor.
 * @param iString
 *   The string to copy
 */
  CATString(const CATString &iString) : atr_StringBase( iString ) { JS0anchor(); }
/**
 * Construct a CATString from a C string .
 * @param iString
 *   The C string used for initialization
 */  
  CATString(char *iString): atr_StringBase( iString ? iString : "" ) { JS0anchor(); } // Create a string from a char*
/**
 * Construct a CATString from a C string, with C++ protection
 * from writing access from the called method to the
 * calling service string.
 * @param iString
 *   The C string used for initialization
 */ 
  CATString(const char * const iString): atr_StringBase( iString ? iString : "" ) { JS0anchor(); } //    ""      ""     ""     ""  
/**   
 * Construct a CATString from a CATChar, duplicating the
 * character into the result string a specified amount
 * of times.
 * @param iChar
 *   Character
 * @param iRepeatCount
 *   Repeat count
 */ 
  CATString(const CATChar iChar, size_t iRepeatCount) : atr_StringBase() { JS0anchor(); Fill(iChar,iRepeatCount); }
/**   
 * Construct a CATString from a CATString, duplicating the
 * string into the result string a specified amount
 * of times.
 * @param iString
 *   String
 * @param iRepeatCount
 *   Repeat count
 */ 
  // RWO removed
  // CATString(const CATString& iString, size_t iRepeatCount); 
  
/**
 * Destructor.
 */
  ~CATString() ;         

/**
 * Assignment operator.
 * @param iString
 *   The string to assign to the current one
 * @return 
 *   The class resulting from the assignment
 */  
  inline CATString &operator =(const char *iString) ;
/**
 * Assignment operator of a CATString to a CATString.
 * @param iString
 *   The string to assign to the current one
 * @return 
 *   The class resulting from the assignment
 */
  inline CATString &operator =(const CATString &iString) ;
/**
 * String concatenation assignment operator.
 * @param iString
 *   The string to append to the current one
 * @return 
 *   The class resulting from the concatenation
 */
  CATString & operator += ( const CATString & iString );
/**
 * C string concatenation assignment operator.
 * @param iString
 *   The String to append to the current one
 * @return 
 *   The class resulting from the concatenation
 */
  CATString & operator += ( const char *  iString );
/**
 * CATChar concatenation assignment operator.
 * @param iChar
 *   The character to append to the CATString
 * @return 
 *   The CATString resulting from the concatenation
 */
  CATString & operator += ( const CATChar & iChar );
/** @nodoc */
  CATString & Append( const CATString& iStringToAppend );
/**
 * String concatenation operator.
 * @param iString
 *   The String to append to the current one
 * @return 
 *   The CATString resulting from the concatenation
 */  
  CATString operator + (const CATString &iString) const ;
/**
 * C string concatenation operator.
 * @param iString
 *   The String to append to the current one
 * @return 
 *   The CATString resulting from the concatenation
 */  
  CATString operator + (const char *iString) const ;
/** @nodoc */
  friend CATString operator+(const char* iPtrOnCharToAdd,
                             const CATString& iStringToAdd);


/**
 * Converts a CATString into a const char*.
 * Caution: the returned char* must be declared as a const.
 * @return iString
 *   const char* output string
 */
  inline char* const CastToCharPtr() const;
/** @nodoc */
  inline int Init();

  // --- Comparison : 
/**
 * Compares two strings lexicographically.
 * The character sequence represented by the current String 
 * is compared lexicographically to the character sequence 
 * represented by the argument string. 
 * @param iString
 *   The String to be compared
 * @return 
 *   Comparison result.
 *   <br><b>Legal values</b>: <tt>less than 0</tt> 
 *   if the value of the current object string is 
 *   lexicographically less than iString, or 
 *   <tt>greater than 0</tt> if the value of the current object 
 *   string is lexicographically greater than iString,
 *   or <tt>equal to 0</tt> if the value of the current object 
 *   string is lexicographically equal than iString.
 */

  int Compare( const char *     iString ) const ;
/**
 * Compares two strings lexicographically.
 * The character sequence represented by the current String 
 * is compared lexicographically to the character sequence 
 * represented by the argument string. 
 * @param iString
 *   The String to be compared
 * @return 
 *   Comparison result.
 *   <br><b>Legal values</b>: <tt>less than 0</tt> 
 *   if the value of the current object string is 
 *   lexicographically less than iString, or 
 *   <tt>greater than 0</tt> if the value of the current object 
 *   string is lexicographically greater than iString,
 *   or <tt>equal to 0</tt> if the value of the current object 
 *   string is lexicographically equal than iString.
 */

  int Compare( const CATString& iString ) const ;
  
/**
 * Equality operator.
 * @param iString
 *   Operand of the comparison
 * @return 
 *   boolean
 *   <br><b>Legal values</b>: <tt>0: False</tt> 
 *   the condition is not fullfilled, or <tt>Other: True</tt> 
 *   if the condition is fullfilled.
 */
  inline int operator == ( const char *iString ) const ;
/**
 * Inequality operator.
 * @param iString
 *   Operand of the comparison
 * @return 
 *   Boolean
 *   <br><b>Legal values</b>: <tt>0: False</tt> 
 *   the condition is not fullfilled, or <tt>Other: True</tt> 
 *   if the condition is fullfilled.
 */
  inline int operator != ( const char *iString ) const ;

/**
 * Inferior comparison operator between a CATString and a char* .
 * @param iString
 *   Operand of the comparison
 * @return 
 *   Boolean
 *   <br><b>Legal values</b>: <tt>0: False</tt> 
 *   the condition is not fullfilled, or <tt>Other: True</tt> 
 *   if the condition is fullfilled.
 */
  inline int operator <  ( const char *iString ) const ;
/**
 * "Inferior or equal" comparison operator between a CATString 
 * and a char* .
 * @param iString
 *   Operand of the comparison
 * @return 
 *   Boolean
 *   <br><b>Legal values</b>: <tt>0: False</tt> 
 *   the condition is not fullfilled, or <tt>Other: True</tt> 
 *   if the condition is fullfilled.
 */
  inline int operator <= ( const char *iString ) const ;
/**
 * "Superior or equal" comparison operator between a CATString 
 * and a char* .
 * @param iString
 *   Operand of the comparison
 * @return 
 *   Boolean
 *   <br><b>Legal values</b>: <tt>0: False</tt> 
 *   the condition is not fullfilled, or <tt>Other: True</tt> 
 *   if the condition is fullfilled.
 */
  inline int operator >= ( const char *iString ) const ;
/**
 * Superior comparison operator between a CATString and a char* .
 * @param iString
 *   Operand of the comparison
 * @return 
 *   Boolean
 *   <br><b>Legal values</b>: <tt>0: False</tt> 
 *   the condition is not fullfilled, or <tt>Other: True</tt> 
 *   if the condition is fullfilled.
 */
  inline int operator >  ( const char *iString ) const ;
/**
 * Equality comparison operator between two CATString.
 * @param iString
 *   Operand of the comparison
 * @return 
 *   Boolean
 *   <br><b>Legal values</b>: <tt>0: False</tt> 
 *   the condition is not fullfilled, or <tt>Other: True</tt> 
 *   if the condition is fullfilled.
 */
  inline int operator == ( const CATString &iString ) const ;
/**
 * Inequality comparison operator between two CATString.
 * @param iString
 *   Operand of the comparison
 * @return 
 *   Boolean
 *   <br><b>Legal values</b>: <tt>0: False</tt> 
 *   the condition is not fullfilled, or <tt>Other: True</tt> 
 *   if the condition is fullfilled.
 */
  inline int operator != ( const CATString &iString ) const ;
/** 
 * Inequality comparison operator between two CATString.
 * @param iString
 *   Operand of the comparison
 * @return 
 *   Boolean
 *   <br><b>Legal values</b>: <tt>0: False</tt> 
 *   the condition is not fullfilled, or <tt>Other: True</tt> 
 *   if the condition is fullfilled.
 */
  inline int operator <  ( const CATString &iString ) const ;
/** 
 * Less-than or equal comparison operator between two CATString.
 * @param iString
 *   Operand of the comparison
 * @return 
 *   Boolean
 *   <br><b>Legal values</b>: <tt>0: False</tt> 
 *   the condition is not fullfilled, or <tt>Other: True</tt> 
 *   if the condition is fullfilled.
 */
  inline int operator <= ( const CATString &iString ) const ;
/** 
 * Greater-than or equal comparison operator between two CATString.
 * @param iString
 *   Operand of the comparison
 * @return 
 *   Boolean
 *   <br><b>Legal values</b>: <tt>0: False</tt> 
 *   the condition is not fullfilled, or <tt>Other: True</tt> 
 *   if the condition is fullfilled.
 */
  inline int operator >= ( const CATString &iStringToCompare ) const ;
/** 
 * Greater-than comparison operator between two CATString.
 * @param iString
 *   Operand of the comparison
 * @return 
 *   Boolean
 *   <br><b>Legal values</b>: <tt>0: False</tt> 
 *   the condition is not fullfilled, or <tt>Other: True</tt> 
 *   if the condition is fullfilled.
 */
  inline int operator >  ( const CATString &iString ) const ;
  
/** 
 * Get the length of the CATString, as char count.
 * @return 
 *   Char count.
 */
  inline int GetLengthInChar() const;
/** 
 * Get the length of the CATString, as byte count.
 * @return 
 *   Byte count.
 */
  inline int GetLengthInByte() const;
/** 
 * Indicates if the current CATString length is of zero value.
 * @return 
 *   boolean
 *   <br><b>Legal values</b>: <tt>0: False</tt> 
 *   the length is not of zero value, or <tt>Other: True</tt> 
 *   if the length is of zero value.
 */
  inline int IsNull();
  
  
  
/**
 * Set the length of a string to desired length, adding occurences
 * of a given filling character to reach the desired length.
 * If the required length is shorter that the preceeding
 * one, the delivered filling character will not be used.
 * @param iNewSize
 *   The desired length
 * @param iFillingChar
 *   Filling character
 * @param iTruncationAllowed
 *   The truncation is allowed.
 *   If the given value for iTruncationAllowed equals zero, and 
 *   the required length is shorter than the preceeding one, 
 *   nothing is done.
 */
  void Resize(int iNewSize, CATChar iFillingChar, int iTruncationAllowed);
/**
 * Set the length of a string to desired length, adding occurences
 * of a given filling character to reach the desired length.
 * If the required length is shorter that the preceeding
 * one, the delivered filling character will not be used.
 * Compared to the preceeding method, the truncation is considered
 * to be allowed.
 * @param iNewSize
 *   The desired length
 * @param iFillingChar
 *   Filling character
 */
  inline void Resize(int iNewSize, CATChar iFillingChar )  
    {
      Resize(iNewSize, iFillingChar, 1);
    }
/**
 * Put the length of a string to desired length, adding occurences
 * of the space character as a filling character, to reach the 
 * desired length.
 * If the required length is shorter that the preceeding
 * one, the delivered filling character will not be used.
 * @param iNewSize
 *   The desired length
 */  
  inline void Resize(int iNewSize)
    {
      Resize(iNewSize, ' ', 1);
    }
  
/**
 * Converts all of the characters in this String to upper case. 
 */   
  inline void ToUpper() ;
/**
 * Converts all of the characters in this String to lower case.  
 */  
  inline void ToLower() ;
  
  
/**
 * Compare two CATStrings.
 * @param iComparisonString
 *   The string to compare to the current one
 * @return 
 *   Comparison result.
 *   <br><b>Legal values</b>: 
 *   <tt>0: Not equal</tt> 
 *   <tt>1: Strictly equal</tt> 
 *   <tt>2: Equal not speaking of the case. The comparison does 
 *   not take the case into account</tt>
 */
  
  int CompareByCase(const CATString &iComparisonString) const ;
/**
 * Determines the location and existence of strings in the
 * current CATString.
 * @param iLookedForSubString
 *   The string to look for
 * @param iSearchBeginning
 *   The search beginning index
 * @return 
 *   Location of the substring.
 *   <br><b>Legal values</b>: 
 *   <tt>-1: Not found</tt> 
 *   <tt>Other: Location index, from 0 to the current CATString
 *   length minus 1</tt> 
 */
  int FindPosition(const CATString &iLookedForSubString, 
                   int iSearchBeginning = 0) const ;
/**
 * Modify the current CATString, supressing a given part of it
 * and putting instead a given replacement substring.
 * @param iModificationStartingPosition
 *   The modification starting position
 * @param iModificationCharCount
 *   The modification char count
 * @param iReplacementString
 *   The replacement string
 */  
  
  void ReplaceSubString(int iModificationStartingPosition, 
            int iModificationCharCount, 
            const CATString &iReplacementString);
/**
 * Modify the current CATString, supressing a given part of it
 * and putting instead a given replacement substring.
 * @param iModificationStartingPosition
 *   The modification starting position
 * @param iModificationCharCount
 *   The modification char count
 * @param iReplacementString
 *   The replacement string
 * @param iReplacementStringParametering
 *   The replacement string parametering.
 *   Enables to specify not to take the replacement string as is, 
 *   but transformed first by a resizing action. 
 *   This tuning specification is the character count of the
 *   real CATString that will be used for the substitution, 
 *   i.e. the CATString resized through the space filling
 *   character. 
 */  
  void ReplaceSubString(int iModificationStartingPosition, 
            int iModificationCharCount, 
			const CATString &iReplacementString, 
            int iReplacementStringParametering) ;
/**
 * Replace the first occurence of the given substring by the
 * other given substring.
 * @param iLookedForString
 *   The substring whose first occurence must be replaced
 * @param iSubstitutionString
 *   The string to substitute to the previous one
 * @return 
 *   Location of the input substring occurence.
 *   <br><b>Legal values</b>: 
 *   <tt>-1: Not found</tt> 
 *   <tt>Other: Location index, from 0 to the current CATString
 *   length minus 1</tt> 
 */  
  int  ReplaceSubString(const CATString &iLookedForString, 
            const CATString &iSubstitutionString);
/**
 * Modify the current CATString, supressing a given part of it.
 * @param iModificationStartingPosition
 *   The modification starting position
 * @param iModificationCharCount
 *   The modification char count
 */    
  inline void Remove(int iModificationStartingPosition,
                     int iModificationCharCount=1) ;
  
  
/**
 * Modify the current CATString, inserting a given substring
 * at the middle of it.
 * @param iInsertionStartingPosition
 *   The insertion starting position
 * @param iStringToInsert
 *   The string to insert into the current CATString
 */   
  inline void Insert(int iInsertionStartingPosition,
                     const CATString &iStringToInsert) ;
  

/**
 * Returns a hashcode for this string.
 * This hashcoding encoding does work only if the 8 first
 * characters (from 0 to 7) of the related CATString
 * objects are different the one from the other.
 * @return 
 *   The hashcoding key.
 */ 
  unsigned ComputeHashKey() const ;	
  
  

/** 
 * Strips the current CATString.
 * <b>Role</b>: Removes a peculiar character occurences from a 
 * given string.
 * @param iMode
 *   Option parameterizing the action.
 *   <br><b>Legal values</b>: 
 *   <tt>CATStripModeLeading</tt> Removes all the consecutive 
 *   occurences of the given character from the beginning of the 
 *   given string (of course it supposes that the first character 
 *   of the string is the delivered character, if it is not the 
 *   case, nothing is done).
 *   <tt>CATStripModeTrailing</tt> Removes all the consecutive 
 *   occurences of the given character from the end of the string 
 *   (the same way, it means that the first character of the 
 *   delivered string is really the delivered character).
 *   <tt>CATStripModeBoth</tt> Removes all the consecutive 
 *   occurences of the given character both from the beginning 
 *   of the string and from the end (this option cumulates the 
 *   two preceeding options, it does not affects the intermediate 
 *   consecutive occurences).
 *   <tt>CATStripModeAll</tt> Removes all the occurences of the 
 *   given character from the string. 
 * <p>
 * @param iCharacter
 *   The peculiar character whose occurences are to be removed
 *   from the current CATString.
 */
  CATString Strip(CATString::CATStripMode iMode , 
                  CATChar iCharacter) const;
/** 
 * Strips the current CATString through the space character.
 * <b>Role</b>: Removes the space character occurences from a 
 * given string. 
 * @param iMode
 *   See above
 */

  inline CATString Strip(CATString::CATStripMode iMode) const
    {
      return Strip(iMode, ' ');  
    }
/** 
 * Strips the current CATString through the space character,
 * using the CATStripModeLeading mode (see above).
 */  
  inline CATString Strip() const
    {
      return Strip(CATStripModeLeading, ' ');  // To build on HP
    }
/**
 * Returns a new string that is a substring of this string.
 * @param iSubStringFirstIndex
 *   The string to extract first index 
 * @param iSubStringCharCount
 *   The string to extract char count
 * @return 
 *   Extracted substring.
 */  

  CATString SubString ( size_t  iSubStringFirstIndex, 
                        size_t  iSubStringCharCount ) const ;
  
  
/** @nodoc */
  inline int compare( const char *     x ) const ;
/** @nodoc */
  inline int compare( const CATString& x ) const ;
/** @nodoc */
  inline int length() const ;
/** @nodoc */
  inline int Length() const ;
  
  // --- Remplissage de la chaine
/** @nodoc */
  inline void pad(int size, char padChar = ' ', int trunc = 0) ;
  
  // --- Convertion majuscule <-> minuscule
/** @nodoc */
  inline void toUpper() ;
/** @nodoc */
  inline void toLower() ;
  
  // --- Recherche de sous chaine de caracteres
/** @nodoc */
  inline int equal(const CATString &x) const ;
/** @nodoc */
  inline int index(const CATString &oldS, int pos = 0) const ;
  
  // --- Remplacement d'une sous-chaine de caracteres par une autre
/** @nodoc */
  inline void replace(int pos, int del, const CATString &newS) ;
/** @nodoc */
  inline int replace(const CATString &oldS,const CATString &newS) ;
  
  // --- Suppression d'une sous-chaine de caracteres
/** @nodoc */
  inline void remove(int pos,int len=1) ;
  
  // --- Insertion d'une sous-chaine de caracteres
/** @nodoc */
  inline void insert(int pos,const CATString &newS) ;
  
  // --- Calcul d'une cle pour du HashCoding
/** @nodoc */
  inline unsigned hash() const ;	// lby : This method will be suppressed : Don't use it
  
//  Deprecated since the implicit use of the cast is too dangerous
//  (very often the users don't know how to use it)
/** @nodoc */  
  // RWO removed
  // inline operator  const char * () const ;
/**
 * Returns the character at the specified index.
 * Doesn't make any bound checking.
 * @param iIndex
 *   The index of the character
 * @return 
 *   The character at the specified index of this string. 
 *   The first character is at index 0.
 */

  inline const CATChar operator[](int iIndex) const;  
  
/** @nodoc */
  inline CATString strip(char c=' ') ;

/**
 * "()" operator to compute a substring from the current CATString.
 * @param begin
 *   The first index of string to extract 
 * @param end
 *   The last index of string to extract 
 * @return 
 *   Extracted substring.
 */  
  CATString operator()(int begin,int end) const; 

/**
 * "+=" operator to append an integer to a CATString, i.e. 
 * appends the integer to the current CATString after having been
 * converted to a string.
 * @param iInt
 *   The integer to append
 * @return 
 *   The class resulting from the concatenation
 */
  CATString & operator += (          int      iInt ) ;
/**
 * "+=" operator to append a long integer to a CATString, i.e. 
 * appends the long integer to the current CATString after having 
 * been converted to a string.
 * @param iLongInt
 *   The long integer to append
 * @return 
 *   The class resulting from the concatenation
 */
  CATString & operator += (          long     iLongInt ) ;
/**
 * "+=" operator to append an unsigned long integer to a 
 * CATString, i.e. appends the unsigned long integer to the 
 * current CATString after having been converted to a string.
 * @param iUnsLongInt
 *   The unsigned long integer to append
 * @return 
 *   The class resulting from the concatenation
 */
  CATString & operator += ( unsigned long     iUnsLongInt ) ;
/**
 * "+=" operator to append an unsigned integer to a 
 * CATString, i.e. appends the unsigned integer to the 
 * current CATString after having been converted to a string.
 * @param iUnsInt
 *   The unsigned long integer to append
 * @return 
 *   The class resulting from the concatenation
 */
  CATString & operator += ( unsigned int      iUnsInt ) ;

#if defined (PLATEFORME_DS64)
/**
 * "+=" operator to append a 64-bit signed long integer to a 
 * CATString, i.e. appends the 64-bit signed long integer to the 
 * current CATString after having been converted to a string.
 * Defined on 64-bit platforms only.
 * @param i64sINT
 *   The 64-bit signed long integer to append
 * @return 
 *   The class resulting from the concatenation
 */  
  CATString & operator += ( CATLONG64  iInt ) ;

/**
 * "+=" operator to append a 64-bit unsigned long integer to a 
 * CATString, i.e. appends the 64-bit unsigned long integer to the 
 * current CATString after having been converted to a string.
 * Defined on 64-bit platforms only.
 * @param i64UnsInt
 *   The 64-bit unsigned long integer to append
 * @return 
 *   The class resulting from the concatenation
 */  
  CATString & operator += ( CATULONG64 iUnsInt ) ;
#endif


private:
  // The following methods have been made private to prevent implicit conversions
  // from atr_String/cow_String which do not work when in native V6 environment.

/*
 * Copy constructor.
 * @param iString
 *   The string to copy
 */

  CATString(const atr_StringBase &iString): atr_StringBase( iString ) { JS0anchor(); }

/**
 * Assignment operator of a atr_StringBase to a CATString.
 * @param iString
 *   The string to assign to the current one
 * @return 
 *   The class resulting from the assignment
 */
  inline CATString &operator =(const atr_StringBase &iString) ;

/**   
 * Fill a CATString from a CATChar, duplicating the
 * character into the result string a specified amount
 * of times.
 * @param iChar
 *   Character
 * @param iRepeatCount
 *   Repeat count
 */ 
  void Fill(const CATChar iChar, size_t iRepeatCount);     
};

inline CATString & CATString::operator= (const char *s)
{
    JS0anchor();
    atr_StringBase::operator= (s?s:"");   
    return *this; 
}

inline CATString & CATString::operator= (const atr_StringBase &s)
{
    JS0anchor();
    atr_StringBase::operator= (s);
    return *this; 
}

inline CATString & CATString::operator= (const CATString &s)
{ 
    JS0anchor();
    atr_StringBase::operator= (s);
    return *this; 
}

inline int CATString::GetLengthInByte() const
{
    return atr_StringBase::Length();
}

inline int CATString::GetLengthInChar ()const
{
    return atr_StringBase::Length();
}

inline int CATString::IsNull()
{
    return (atr_StringBase::Length() == 0);
}

inline void CATString::ToUpper()
{
    atr_StringBase::ToUpper();
}

inline void CATString::ToLower()
{ 
    atr_StringBase::ToLower();
}

// inline CATString::operator const char * () const
// {
//     return CStr();
// }

inline char * const CATString::CastToCharPtr() const
{
    return (char*) CStr(); // cast away const
}

inline void CATString::Remove( int iStartPos,int iNbCarsToRemove )
{
    ReplaceSubString(iStartPos, iNbCarsToRemove, "" );
}

inline void CATString::Insert(int iPosToInsert, const CATString &iStringToInsert)
{
    ReplaceSubString( iPosToInsert, 0, iStringToInsert);
}

inline int CATString::Init()
{
    return 1;
}

inline const CATChar CATString::operator[]( int  i ) const
{
    return ( atr_StringBase::operator[](i) ); 
}

inline int CATString::compare(const char *x) const
{
  return Compare(x);
}

inline int CATString::compare(const CATString &x) const
{
  return Compare(x);
}

inline int CATString::length() const
{
    return atr_StringBase::Length();
}

inline int CATString::Length() const
{
    return atr_StringBase::Length();
}

inline void CATString::toUpper()
{
    ToUpper();
}

inline void CATString::toLower()
{
    ToLower();
}

inline int CATString::equal( const CATString &x ) const
{
    return CompareByCase( x );
}

inline int CATString::index( const CATString &oldS , int pos ) const
{
    return FindPosition( oldS, pos );
}

inline void CATString::replace( int pos , int del , const CATString &newS )
{
    ReplaceSubString(pos, del, newS);
}

inline int CATString::replace( const CATString &oldS , const CATString &newS )
{
    return ReplaceSubString(oldS, newS);
}

inline void CATString::remove( int pos , int len )
{
    ReplaceSubString(pos, len, "" );
}

inline void CATString::insert( int pos , const CATString &newS )
{
    ReplaceSubString(pos, 0, newS);
}

inline unsigned CATString::hash() const
{
    return ComputeHashKey();
}

inline CATString CATString::strip( char c )
{
    return Strip(CATString::CATStripModeLeading, c);
}

inline void CATString::pad(int size, char padChar, int trunc)
{
    Resize(size, padChar, trunc);
}

//*****************************************************************************
//*                 Operateurs surcharges de comparaison                      *
//*****************************************************************************	    
inline int CATString::operator == (const char *iPtrToChar) const
{
  return !Compare(iPtrToChar) ;
}

inline int CATString::operator != (const char *iPtrToChar) const
{
   return Compare(iPtrToChar);
 }

inline int CATString::operator < (const char *iPtrToChar) const
{
  return Compare(iPtrToChar) < 0;
}

inline int CATString::operator <= (const char *iPtrToChar) const
{
   return Compare(iPtrToChar) <= 0;
}

inline int CATString::operator >= (const char *iPtrToChar) const
{
   return Compare(iPtrToChar) >= 0;
}

inline int CATString::operator > (const char *iPtrToChar) const
{
   return Compare(iPtrToChar) > 0;
}

inline int CATString::operator == (const CATString &iStringToCompare) const
{
   return !Compare(iStringToCompare);
}

inline int CATString::operator != (const CATString &iStringToCompare) const
{
   return Compare(iStringToCompare);
}

inline int CATString::operator < (const CATString &iStringToCompare) const
{
   return Compare(iStringToCompare) < 0;
}

inline int CATString::operator <= (const CATString &iStringToCompare) const
{
   return Compare(iStringToCompare) <= 0;
}

inline int CATString::operator >= (const CATString &iStringToCompare) const
{
   return Compare(iStringToCompare) >= 0;
}

inline int CATString::operator > (const CATString &iStringToCompare) const
{
   return Compare(iStringToCompare) > 0;
}

#endif
