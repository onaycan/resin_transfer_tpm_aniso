/* -*- mode: c++ -*- */
//
// Purpose:
//
// Native Exception replacement for obj_CommandException.odt
//

#ifndef nex_CommandException_h
#define nex_CommandException_h

//
// Includes
//

// Begin local includes

#include <cow_String.h>
#include <atr_String.h>
#include <nex_Exception.h>
#include <typ_typeTag.h>
#include <cls_Uid.h>

// Forward declarations

class cls_ClassRegistrar;
class cls_ReadVisitor;
class cls_WriteVisitor;

//
// Class definition
//

class nex_CommandException : public nex_Exception
{

public:

    // d3efault is to call JournalMessage()
    virtual atr_String AsString() const;

    virtual ~nex_CommandException();

    virtual void Propagate() const = 0;
    virtual nex_Exception* Copy() const = 0;

    virtual atr_String JournalMessage() const = 0;
    virtual cow_String PythonType() const = 0;

    // Messaging/database interface
    virtual typ_typeTag     DynTypeId() const;
    static typ_typeTag      TypeId();

protected:
    nex_CommandException()
    { }

public:

    // Messaging/Database interface
    nex_CommandException( const cls_ReadVisitor & );
    virtual void DBWrite( const cls_WriteVisitor & ) const;
    static void InitializeMetadata( cls_ClassRegistrar & );

private:

    cls_Uid m_ClsUid;
};

#endif  // #ifdef nex_CommandException_h
