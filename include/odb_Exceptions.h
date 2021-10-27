/*   -*- mode: c++ -*-   */
#ifndef odb_Exceptions_h
#define odb_Exceptions_h

// Begin local includes

#include <cow_String.h>
#include <nex_CommandException.h>
#include <typ_typeTag.h>
#include <cls_Uid.h>

// Forward declarations

class cls_ClassRegistrar;
class cls_ReadVisitor;
class cls_WriteVisitor;


typedef nex_Exception odb_BaseException;

//////// class odb_Exception ////////

enum odb_ErrorNoEnm {
    odb_INCORRECT_VERSION,
    odb_MORE_RECENT_VERSION,
    odb_UPGRADE_FAILED,
    odb_UPGRADE_REQUIRED_FAILED,
    odb_NOT_ENOUGH_DISK_SPACE,
    odb_UPGRADE_NOT_SUPPORTED,
    odb_TEXT_MESSAGE,
    odb_INVALID_VERSION
};

class odb_Exception : public nex_CommandException
{
private:
    cow_String         m_FileName;
    odb_ErrorNoEnm     m_ErrorNo;
    atr_String         m_ErrMsg;
    int                m_VersionNumber;
    int                m_AbaqusVersion;
    bool               m_ReadOnly;

public: 

    odb_Exception(odb_ErrorNoEnm error, const atr_String &errMsg)
	: nex_CommandException(),
      m_ErrorNo(error), m_ErrMsg(errMsg),
	  m_VersionNumber(0), m_AbaqusVersion(0), m_ReadOnly(true)
    { }

    odb_Exception(const cow_String &filename, odb_ErrorNoEnm error)
	: nex_CommandException(),m_FileName(filename), m_ErrorNo(error),
	  m_VersionNumber(0), m_AbaqusVersion(0), m_ReadOnly(true)
    { }

    odb_Exception(const cow_String &filename, odb_ErrorNoEnm error,
			   int version)
	: nex_CommandException(),m_FileName(filename), m_ErrorNo(error),
	  m_VersionNumber(version), m_AbaqusVersion(0), m_ReadOnly(true)
    { }

    odb_Exception(const cow_String &filename, odb_ErrorNoEnm error,
			   const atr_String &errMsg)
	: nex_CommandException(),
      m_FileName(filename), m_ErrorNo(error), m_ErrMsg(errMsg),
	  m_VersionNumber(0), m_AbaqusVersion(0), m_ReadOnly(true)
    { }

    odb_Exception(odb_ErrorNoEnm error)
	: nex_CommandException(),
      m_ErrorNo(error), m_VersionNumber(0), m_AbaqusVersion(0), m_ErrMsg(),m_ReadOnly(true)
    { }

    odb_Exception(const cow_String &filename, odb_ErrorNoEnm error,
		      int version, int abaqusVersion)
	: nex_CommandException(), m_FileName(filename), m_ErrorNo(error),
	  m_VersionNumber(version), m_AbaqusVersion(abaqusVersion), 
	  m_ReadOnly(true)
    { }
     
    odb_Exception(const cow_String &filename, odb_ErrorNoEnm error,
		      int version, int abaqusVersion, bool readOnlyFlag)
	: nex_CommandException(), m_FileName(filename), m_ErrorNo(error),
	  m_VersionNumber(version), m_AbaqusVersion(abaqusVersion), 
	  m_ReadOnly(readOnlyFlag)
    { }

    odb_Exception(const cow_String &filename, odb_ErrorNoEnm error,
		      const atr_String &errMsg, int version, int abaqusVersion)
	: nex_CommandException(), m_FileName(filename), m_ErrorNo(error), m_ErrMsg(errMsg),
	  m_VersionNumber(version), m_AbaqusVersion(abaqusVersion), m_ReadOnly(true)
    { }

    int MajorReleaseVersion(const int &) const;
    
    int MinorReleaseVersion(const int &) const;
    
    cow_String AbaqusCAEReleaseVersion() const;
    
    cow_String CurrentCAEReleaseVersion() const;

    virtual ~odb_Exception();

    virtual void Propagate() const;
    virtual nex_Exception* Copy() const;

    // Accessors
    cow_String         FileName() const      { return m_FileName; }
    odb_ErrorNoEnm     ErrorNo() const       { return m_ErrorNo; }
    const atr_String&  ErrMsg() const        { return m_ErrMsg; }
    int                VersionNumber() const { return m_VersionNumber; }
    int                AbaqusVersion() const { return m_AbaqusVersion; }
    bool               IsReadOnly() const    { return m_ReadOnly;} 

    virtual atr_String JournalMessage() const;
    virtual cow_String PythonType() const;

    // Messaging/database interface
    virtual typ_typeTag     DynTypeId() const;
    static typ_typeTag      TypeId();

public:

    // Messaging/Database interface
    odb_Exception( const cls_ReadVisitor & );
    virtual void DBWrite( const cls_WriteVisitor & ) const;
    static void InitializeMetadata( cls_ClassRegistrar & );

private:

    cls_Uid m_ClsUid;
};





#endif /* odb_Exceptions_h */

