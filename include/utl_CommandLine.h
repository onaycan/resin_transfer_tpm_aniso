/*   -*- mode: c++ -*-   */
#ifndef utl_CommandLine_h
#define utl_CommandLine_h

///////////////////////////////////////////////////////////////////////////////
//
// Name: utl_CommandLine
//
// Description: Parse and store command line arguments.  Arguments must be in
//              the form: "-key value" if they are to be retrieved using the
//              map interface.  All arguments may be retrieved using the list
//              interface.
//
//              This singleton can only be initialized in HKSmain.
//

// Includes

// Begin local includes

#include <atr_String.h>
#include <cow_ListString.h>
#include <cow_MapString2String.h>
#include <omi_types.h>
#include <nex_TextException.h>
#include <thr_GlobalSingleton.h>

// Class definition

class utl_CommandLine: public thr_GlobalSingleton<utl_CommandLine>
{
    friend class thr_GlobalSingleton<utl_CommandLine>;
    friend int ABQmain(int argc, char** argv);
    friend void utl_CommandLineSetup(int argc, char** argv);

  public:

    ~utl_CommandLine();

    cow_String ConstGetValue(const cow_String& key);
    cow_String ConstGetValue(const cow_String& key, 
			     const cow_String& vdefault);
    int ConstGetValueAsInt(const cow_String& key);
    int ConstGetValueAsInt(const cow_String& key, int vdefault);
    size_t ConstGetValueAsSizeT(const cow_String& key);
    size_t ConstGetValueAsSizeT(const cow_String& key, size_t vdefault);
    cow_MapString2String ConstGetValueAsDictionary(const cow_String& key);
    cow_String ConstGet(int position);
    bool IsMember(const cow_String& key);
    int Size();

    const cow_MapString2String& ConstGetArgumentMap() const { return map; }

  private:

    utl_CommandLine();
    void SetArgs(int argc, char** argv);
    void SetArgsList(cow_ListString);
    void SetDebugFlags(); // Called from SetArgs and SetArgsList
    cow_MapString2String map;
    cow_ListString args;
};

class utl_MissingCmdLineArgException : public nex_TextException
{
  public:
    utl_MissingCmdLineArgException(const atr_String& value):
        nex_TextException(value) {}
    virtual ~utl_MissingCmdLineArgException() {}

    virtual atr_String     AsString() const;
    virtual void           Propagate() const;
    virtual nex_Exception* Copy() const;
};

class utl_CmdLineArgFormatException : public nex_TextException
{
  public:
    utl_CmdLineArgFormatException(const atr_String& arg, 
				  const atr_String& vtype):
        nex_TextException(vtype), argument(arg) {}
    virtual ~utl_CmdLineArgFormatException() {}

    virtual atr_String     AsString() const;
    virtual void           Propagate() const;
    virtual nex_Exception* Copy() const;

  private:
    atr_String argument;
};

#endif

