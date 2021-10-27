#ifndef SMASimGUID_h
#define SMASimGUID_h
// Begin local includes
#include <mem_AllocationOperatorsTiny.h>

// Forward declarations
class SMASimDebugOut;
class CATString;

/**
   This class implements generation and manipulation of globally unique identifiers.
   The generated identifiers are standard, purely random 128-bit GUIDs, with 122
   random bits.

   For probability of a conflict, see http://en.wikipedia.org/wiki/UUID
*/
class SMASimGUID
    : public mem_AllocationOperatorsTiny
{
public:

    /** Creates an empty (null) GUID. An empty GUID is not unique. */
    SMASimGUID();

    /** Creates a GUID from a string representation of the form:
        XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX
        where each X is a hexadecimal digit. An empty string can be
        passed to this function, and it will initialize this object
        to an empty (null) GUID. */
    explicit SMASimGUID(const CATString &str);

    /** Creates a GUID from a binary representation. The size of the buffer must be
        at least 16 bytes, and only the first 16 bytes will be used. */
    SMASimGUID(const unsigned char *buf, int bufsize);

    /** Returns true if this is a non-null GUID. */
    operator const void *() const { return Compare(SMASimGUID()) ? this : 0; }

    /** Returns true if this is a null GUID. */
    bool operator !() const { return Compare(SMASimGUID()) == 0; }

    /** Returns the string representation of this object. */
    CATString GetString() const;

    /** Retrieves the binary GUID representation into the given buffer.
        The size of the buffer must be 16 bytes or larger. */
    void GetBinary(unsigned char *buf, int bufsize) const;


    /** Compares GUIDs. Returns a value smaller than zero if this < that, larger than zero if this > that,
        or zero if this == that. */
    int Compare(const SMASimGUID &that) const;

    /** Generates and returns a new GUID. Warning: this function is not very efficient. */
    static SMASimGUID Generate();

    /** Write this GUID to the debug stream. */
    SMASimDebugOut& WriteDebug(SMASimDebugOut& uos) const;

private:
    unsigned char m_Data[16];
};

inline SMASimDebugOut& operator<<(SMASimDebugOut& uos, const SMASimGUID &guid) { return guid.WriteDebug(uos); }
inline bool operator ==(const SMASimGUID &a, const SMASimGUID &b) { return a.Compare(b) == 0; }
inline bool operator !=(const SMASimGUID &a, const SMASimGUID &b) { return a.Compare(b) != 0; }
inline bool operator <(const SMASimGUID &a, const SMASimGUID &b) { return a.Compare(b) < 0; }
inline bool operator <=(const SMASimGUID &a, const SMASimGUID &b) { return a.Compare(b) <= 0; }
inline bool operator >(const SMASimGUID &a, const SMASimGUID &b) { return a.Compare(b) > 0; }
inline bool operator >=(const SMASimGUID &a, const SMASimGUID &b) { return a.Compare(b) >= 0; }

#endif
