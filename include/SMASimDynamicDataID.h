#ifndef SMASimDynamicDataID_h
#define SMASimDynamicDataID_h
// Begin local includes
#include <SMASimIDMinor.h>
#include <mem_AllocationOperatorsTiny.h>
// End local includes

// Forward declarations
class SMASimDynamicID;

/**
   This class represents an identifier for a piece of data within a SIM database.
*/
class SMASimDynamicDataID
    : public mem_AllocationOperatorsTiny
{
    friend class SMASimDynamicID;

public:
    /** Creates a data ID object. */
    explicit SMASimDynamicDataID(SMASimIDMinor minor1 = SMASimIDMinor(), SMASimIDMinor minor2 = SMASimIDMinor())
        : m_Minor1(minor1), m_Minor2(minor2) {}

    /** Returns the first minor ID number. */
    SMASimIDMinor Minor1() const { return m_Minor1; }

    /** Returns the second minor ID number. */
    SMASimIDMinor Minor2() const { return m_Minor2; }

    /** Compares this ID with another one. The return value indicates relative order of the IDs. */
    int Compare(SMASimDynamicDataID const& that) const;

    /** Returns true if this ID refers to the same data as the other one. */
    bool Equal(SMASimDynamicDataID const& that) const;

private:
    static int ExternalSize();
    int Externalize(char* buffer) const;
    int Internalize(const char* buffer);

    SMASimIDMinor m_Minor1;
    SMASimIDMinor m_Minor2;
};

inline bool operator ==(const SMASimDynamicDataID &a, const SMASimDynamicDataID &b) { return a.Compare(b) == 0; }
inline bool operator !=(const SMASimDynamicDataID &a, const SMASimDynamicDataID &b) { return a.Compare(b) != 0; }
inline bool operator < (const SMASimDynamicDataID &a, const SMASimDynamicDataID &b) { return a.Compare(b) < 0; }
inline bool operator <=(const SMASimDynamicDataID &a, const SMASimDynamicDataID &b) { return a.Compare(b) <= 0; }
inline bool operator > (const SMASimDynamicDataID &a, const SMASimDynamicDataID &b) { return a.Compare(b) > 0; }
inline bool operator >=(const SMASimDynamicDataID &a, const SMASimDynamicDataID &b) { return a.Compare(b) >= 0; }

#endif
