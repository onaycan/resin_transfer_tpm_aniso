#ifndef SMASimContextID_h
#define SMASimContextID_h

// Begin Local includes
#include <mem_AllocationOperatorsTiny.h>
#include <SMASimDebugOut.h>
// End Local includes

// Forward declarations
class SMASimDatabaseRepr;
class SMASimContextRepr;
class SMASimContext;

/**
   The ID of a context object. 
   Enables accessing in-session Context object
**/
class SMASimContextID : public mem_AllocationOperatorsTiny
{
public:
    /// Creates a NULL context ID.
    SMASimContextID() : m_Database(0) {}

    /// Test for NULL
    bool IsNull() const { return m_Database == 0; } 

    /// Return true if ids are equal, false otherwise 
    bool operator==(const SMASimContextID &that) const { return Equal(that); }

    /// Return true if ids are NOT equal, false otherwise
    bool operator!=(const SMASimContextID &that) const 
        { return !(*this == that); }

    /// Compare IDs
    int Compare(const SMASimContextID& that) const;

public: /// Not exported - for dpa use only

    /// Display on ostream.
    /// For dpa use only - do not export
    SMASimDebugOut& WriteDebug(SMASimDebugOut& uos) const;

private:
    friend class SMASimDatabaseRepr;
    friend class SMASimContextRepr;// required for GetDatabasePtr()
    friend class SMASimContext;//required in Constructor for Context 
    friend class SMASimViewRepr;
    SMASimContextID(SMASimDatabaseRepr* database)
        : m_Database(database){}

    bool Equal(const SMASimContextID &that) const;

    SMASimDatabaseRepr *m_Database;
};

inline SMASimDebugOut& operator<<(SMASimDebugOut& uos, SMASimContextID id)
{
    return id.WriteDebug(uos);
}

#endif
