#ifndef SMASimDebugOut_h
#define SMASimDebugOut_h

// Begin local includes
#include <mem_AllocationOperators.h>
// End local includes

class CATString;

/**
* Class for managing debug output .  All DPA IDs and some dpa classes can be written
* for debug purposes to a SMASimDebugOut.  Note: The debug-writing methods should be
* used for the purposes of debugging only;  it is not correct to use them to get a 
* persistent representation of an ID, because no promises are made that the debug output 
* format will persist from version to version or even from build to build of the DPA.
* The right way to get a persistent representation of an id is to use the byte
* array representation of an IDExternal.
**/
class SMASimDebugOut : public mem_AllocationOperators
{
public:
    /// Default constructor
    SMASimDebugOut() {};

    /// Destructor
    virtual ~SMASimDebugOut();

    /// Output operator
    SMASimDebugOut& operator<<(SMASimDebugOut& (*func)(SMASimDebugOut&))
    { 
        return (*func)(*this);
    }

    /// Return a debug output string created from a string
    SMASimDebugOut& WriteCStr(char const* d) { return WriteCStr_v(d); }
    /// Return a debug output string created from a CATString
    SMASimDebugOut& WriteString(CATString const& d) { return WriteString_v(d); }
    /// Return a debug output string for an address
    SMASimDebugOut& WriteAddr(void const* d) { return WriteAddr_v(d); }
    /// Return a debug output string created from a boolean value
    SMASimDebugOut& WriteBool(bool d) { return WriteBool_v(d); }
    /// Return a debug output string created from an integer value
    SMASimDebugOut& WriteInt(int d) { return WriteInt_v(d); }
    /// Return a debug output string created from a unsigned integer value
    SMASimDebugOut& WriteUInt(unsigned int d) { return WriteUInt_v(d); }
    /// Return a debug output string created from a 64-bit integer value
    SMASimDebugOut& WriteInt64(long long d) { return WriteInt64_v(d); }
    /// Return a debug output string created from an unsigned 64-bit integer value
    SMASimDebugOut& WriteUInt64(unsigned long long d) { return WriteUInt64_v(d); }
    /// Return a debug output string created from a double
    SMASimDebugOut& WriteDouble(double d) { return WriteDouble_v(d); }
    /// Return the debug output string
    SMASimDebugOut& Flush() { return Flush_v(); };

private:
    virtual SMASimDebugOut& WriteCStr_v(char const*) = 0;
    virtual SMASimDebugOut& WriteString_v(CATString const&) = 0;
    virtual SMASimDebugOut& WriteAddr_v(void const*) = 0;
    virtual SMASimDebugOut& WriteBool_v(bool) = 0;
    virtual SMASimDebugOut& WriteInt_v(int) = 0;
    virtual SMASimDebugOut& WriteUInt_v(unsigned int) = 0;
    virtual SMASimDebugOut& WriteInt64_v(long long) = 0;
    virtual SMASimDebugOut& WriteUInt64_v(unsigned long long) = 0;
    virtual SMASimDebugOut& WriteDouble_v(double) = 0;
    virtual SMASimDebugOut& Flush_v() = 0;

    SMASimDebugOut(SMASimDebugOut const&);
    SMASimDebugOut const& operator=(SMASimDebugOut const&);
};

inline SMASimDebugOut& operator<<(SMASimDebugOut& dbs, char const* data)
{
    return dbs.WriteCStr(data);
}

inline SMASimDebugOut& operator<<(SMASimDebugOut& dbs, CATString const& data)
{
    return dbs.WriteString(data);
}

inline SMASimDebugOut& operator<<(SMASimDebugOut& dbs, void const* data)
{
    return dbs.WriteAddr(data);
}

inline SMASimDebugOut& operator<<(SMASimDebugOut& dbs, bool data)
{
    return dbs.WriteBool(data);
}

inline SMASimDebugOut& operator<<(SMASimDebugOut& dbs, int data)
{
    return dbs.WriteInt(data);
}

inline SMASimDebugOut& operator<<(SMASimDebugOut& dbs, unsigned int data)
{
    return dbs.WriteUInt(data);
}

inline SMASimDebugOut& operator<<(SMASimDebugOut& dbs, long long data)
{
    return dbs.WriteInt64(data);
}

inline SMASimDebugOut& operator<<(SMASimDebugOut& dbs, unsigned long long data)
{
    return dbs.WriteUInt64(data);
}

inline SMASimDebugOut& operator<<(SMASimDebugOut& dbs, double data)
{
    return dbs.WriteDouble(data);
}

inline SMASimDebugOut& endl(SMASimDebugOut& dbs)
{
    return dbs.WriteCStr("\n").Flush();
}

#endif
