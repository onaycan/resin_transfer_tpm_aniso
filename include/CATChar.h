#ifndef CATChar_H
#define CATChar_H

// RWO commented out for ADE
//#ifdef _WINDOWS_SOURCE 
//#ifdef __JS0STR
///** @nodoc */
//#define ExportedByJS0STR  __declspec(dllexport) 
//#else
///** @nodoc */
//#define ExportedByJS0STR  __declspec(dllimport) 
//#endif
//#else
///** @nodoc */
//#define ExportedByJS0STR
//#endif



// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

/**
 * Class to represent non-NLS Characters.
 * <b>Role</b>: Class for ISO 646 characters, i.e. codes from
 * 0 to 127 in decimal:
 *   - C0 ASCII control codes (see the unicode standard
 *     documentation): 0 to 31 in decimal
 *   - ASCII (contains digit characters, latin capital
 *     letters, latin small letters, punctuation characters ...)       
 * Thus, this class does not support NLS
 * (National Langage Support), at the opposite of
 * @href CATUnicodeChar.
 * Comparing this class to @href CATUnicodeChar,
 * the very simple character set supported here, 
 * once accepted the limitations it implies, enables to supress
 * all the problems that arise with NLS complexity.
 * Before using this class instead of CATUnicodeChar,
 * check carefully that you will never need the NLS
 * support. 
 */

// Begin local includes
#include <mem_AllocationOperators.h>

class /* RWO ExportedByJS0STR */  CATChar  : public mem_AllocationOperators
{
public:
/**
 * Construct a ISO 646 char from a char.
 */
	CATChar( const char );
/**
 * Construct an empty CATChar.
 */
	CATChar();
/*
 * Copy constructor.
 * @param iChar
 *   The character to copy
 */
	CATChar( const CATChar& iChar);
/**
 * Destructor.
 */
	virtual ~CATChar();


/**
 * Assignment operator.
 * @param iChar
 *   The character to assign to the current one
 * @return 
 *   The class resulting from the assignment
 */
	CATChar&	operator=(const char iChar);	
/**
 * Assignment operator.
 * @param iChar
 *   The character to assign to the current one
 * @return 
 *   The class resulting from the assignment
 */
	CATChar&	operator=(const CATChar& iChar);	// Replace string
 

/**
 * Equality operator.
 * @param iChar1
 *   First operand of the comparison
 * @param iChar2
 *   Second operand of the comparison
 * @return 
 *   boolean
 *   <br><b>Legal values</b>: <tt>0: False</tt> 
 *   the condition is not fullfilled, or <tt>Other: True</tt> 
 *   if the condition is fullfilled.
 */
	/* RWO ExportedByJS0STR */ friend  int operator==(const CATChar& iChar1, 
                                            const CATChar& iChar2);

/**
 * Inequality operator.
 * @param iChar1
 *   First operand of the comparison
 * @param iChar2
 *   Second operand of the comparison
 * @return 
 *   boolean
 *   <br><b>Legal values</b>: <tt>0: False</tt> 
 *   the condition is not fullfilled, or <tt>Other: True</tt> 
 *   if the condition is fullfilled.
 */
	/* RWO ExportedByJS0STR */ friend int operator!=(const CATChar& iChar1, 
                                           const CATChar& iChar2);

/**
 * Less than operator.
 * @param iChar1
 *   First operand of the comparison
 * @param iChar2
 *   Second operand of the comparison
 * @return 
 *   boolean
 *   <br><b>Legal values</b>: <tt>0: False</tt> 
 *   the condition is not fullfilled, or <tt>Other: True</tt> 
 *   if the condition is fullfilled.
 */
	/* RWO ExportedByJS0STR */ friend  int operator<(const CATChar& iChar1, 
                                           const CATChar& iChar2);

/**
 * Less than or equal to operator.
 * @param iChar1
 *   First operand of the comparison
 * @param iChar2
 *   Second operand of the comparison
 * @return 
 *   boolean
 *   <br><b>Legal values</b>: <tt>0: False</tt> 
 *   the condition is not fullfilled, or <tt>Other: True</tt> 
 *   if the condition is fullfilled.
 */
	/* RWO ExportedByJS0STR */ friend int operator<=(const CATChar& iChar1, 
                                           const CATChar& iChar2);

/**
 * Greater than operator.
 * @param iChar1
 *   First operand of the comparison
 * @param iChar2
 *   Second operand of the comparison
 * @return 
 *   boolean
 *   <br><b>Legal values</b>: <tt>0: False</tt> 
 *   the condition is not fullfilled, or <tt>Other: True</tt> 
 *   if the condition is fullfilled.
 */
	/* RWO ExportedByJS0STR */ friend int operator>(const CATChar& iChar1, 
                                          const CATChar& iChar2);

/**
 * Greater than or equal operator.
 * @param iChar1
 *   First operand of the comparison
 * @param iChar2
 *   Second operand of the comparison
 * @return 
 *   boolean
 *   <br><b>Legal values</b>: <tt>0: False</tt> 
 *   the condition is not fullfilled, or <tt>Other: True</tt> 
 *   if the condition is fullfilled.
 */
	/* RWO ExportedByJS0STR */ friend int operator>=(const CATChar& iChar1, 
                                           const CATChar& iChar2);
/**
 * Cast operator.
 * @param iChar
 *   char* character
 */
	operator  const char() const;


  protected:

  private:
/** @nodoc */ 
	char _Character;
};

// RWO commented out for ADE
//#ifdef _CAT_ANSI_STREAMS
///** @nodoc */
//#include <iosfwd.h>
//
///* RWO ExportedByJS0STR */ ostream& operator<<(ostream&, const CATChar&);
//#endif

#endif

