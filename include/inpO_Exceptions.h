/*   -*- mode: c++ -*-   */
#ifndef inpO_Exceptions_h
#define inpO_Exceptions_h

///////////////////////////////////////////////////////////////////////////////
//
// File Name: inpO_Exceptions.h
//
// Description: exceptions for the ABAQUS Database Converter
//

// Includes

// Forward declarations

// Begin local includes

#include <nex_TextException.h>
#include <inpO_Message.h>

// Constants

// Class definitions

class inpO_Exception: public nex_TextException
{
public:

   inpO_Exception(atr_String msg);
   virtual ~inpO_Exception();

   virtual void Propagate() const;
   virtual nex_Exception* Copy() const;
};


class inpO_MessageException: public inpO_Exception
{
public:

  inpO_MessageException(const inpO_Message& msg);
  virtual ~inpO_MessageException();

  const inpO_Message& Message() const { return m_msg; }

  virtual void Propagate() const;
  virtual nex_Exception* Copy() const;

protected:

  inpO_Message m_msg;
};


class inpO_FatalMessageException: public inpO_MessageException
{
public:

  inpO_FatalMessageException(const inpO_Message& msg);
  virtual ~inpO_FatalMessageException();

  virtual void Propagate() const;
  virtual nex_Exception* Copy() const;
};


class inpO_FatalException: public inpO_Exception
{
public:

   inpO_FatalException(atr_String msg);
   virtual ~inpO_FatalException();

   virtual void Propagate() const;
   virtual nex_Exception* Copy() const;
};


class inpO_MemoryException: public inpO_FatalException
{
public:

   inpO_MemoryException();
   virtual ~inpO_MemoryException();

   virtual void Propagate() const;
   virtual nex_Exception* Copy() const;
};

#endif /* inpO_Exceptions_h */
