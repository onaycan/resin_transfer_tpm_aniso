#ifndef __CATDataType
#define __CATDataType

/* COPYRIGHT DASSAULT SYSTEMES 1999                       */

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#if defined( _IRIX_SOURCE ) || defined( _AIX ) 
 #include <inttypes.h>
#elif _SUNOS_SOURCE 
 #include <sys/int_types.h>
#elif _HPUX_SOURCE  
 #include <inttypes.h>
#elif _WINDOWS_SOURCE
/**
 * @nodoc
 */
	typedef int LONG32, INT32 ;
/**
 * @nodoc
 */
	typedef unsigned int ULONG32, UINT32 ;
#elif _LINUX_SOURCE
 #include <stdint.h>
#endif


/**
  *========================================================
  * Fixed Length Data types
  *
  * 			CATINT32  - CATUINT32
  * 			CATLONG64 - CATULONG64
  *
  * The Length of these Data Types remains the same, 
  * regardless of the OS and the machine.
  *========================================================
  */

    /**
        * 32-bit signed integer (32 and 64-Unix, Windows).
	*/
  typedef int CATINT32 ;

    /**
        * 32-bit unsigned integer (32 and 64-Unix, Windows).
	*/
  typedef unsigned int CATUINT32 ;



#if defined (_WINDOWS_SOURCE)

/**
* 64-bit signed long.
* <br>Typedef valid on Windows platforms
*/
typedef __int64 CATLONG64 ; 

/**
* 64-bit unsigned long.
* <br>Typedef valid on Windows platforms
*/
typedef unsigned __int64 CATULONG64 ; 

#else

/**
* 64-bit signed long.
* <br>Typedef valid on Unix platforms
*/
typedef long long CATLONG64 ; 

/**
* 64-bit unsigned long.
* <br>Typedef valid on Unix platforms
*/
typedef unsigned long long CATULONG64 ; 

#endif
 
 
/**
 *========================================================
 * printf() format strings
 *
 *   FMTLONGI64 : Flag for platform independent way of 
 *     formatting strings in the printf family of 
 *     statements
 *
 *   Usage : CATINTPTR a64bitint;
 *	     printf("The value is " FMTLONGI64 "d\n", 
 *                  a64bitint);
 *========================================================
*/	

/**
  * @nodoc
*/	
#if defined(_WINDOWS_SOURCE)
	#define FMTLONGI64 "%I64"
#else
	#define FMTLONGI64 "%ll"
#endif

#endif
