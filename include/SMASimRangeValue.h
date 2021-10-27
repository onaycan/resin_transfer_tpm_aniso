#ifndef SMASimRangeValue_h
#define SMASimRangeValue_h

// begin local includes
#include <mem_AllocationOperators.h>
#include <SMASimTypeKey.h>
#include <SMASimID.h>
#include <SMASimDataTypes.h>
#include <SMASimRpm_Offset.h>
// end local includes

class SMASimRpm_BStreamRead;
class SMASimRpm_BStreamWrite;

/**
* Holds any valid range data
**/
class SMASimRangeValue : public mem_AllocationOperators {
public:
    /// Default constructor
    /// construct then set
    SMASimRangeValue() 
        : m_key( SMASimVoidTypeKey )
    { ClearVal(); }

    /// Construct from a typekey and a value
    SMASimRangeValue(SMASimTypeKey typekey, const char* val) 
    : m_key(typekey) {
        ClearVal();
        Set(val);
    }

    /// Debug output
    SMASimDebugOut& WriteDebug(SMASimDebugOut& uos) const;

    /// Return true if the range value has been set; false otherwise
    bool IsNull() const { return m_key == SMASimVoidTypeKey ; }

    /// Return the data type of the range
    SMASimTypeKey TypeKey() const { return m_key;}

    /// Set the integer range value
    void SetInt( int i) {
        ClearVal(); // clean all unused bits for bit-hygiene
        m_key = SMASimIntKey;
        m_numVal.m_int = i;
    }

    /// Return the integer range value
    int Int() const {
        SMASimVALIDATE( m_key == SMASimIntKey);
        return m_numVal.m_int;
    }

    /// Set the double range value
    void SetDouble( double d) {
        ClearVal(); // clean all unused bits for bit-hygiene
        m_key = SMASimDoubleKey;
        m_numVal.m_double = d;
    }

    /// Return the double range value
    double Double() const {
        SMASimVALIDATE( m_key == SMASimDoubleKey);
        return m_numVal.m_double;
    }

    /// Set the float range value
    void SetFloat( float f) {
        ClearVal(); // clean all unused bits for bit-hygiene
        m_key = SMASimFloatKey;
        m_numVal.m_float = f;
    }

    /// Return the float range value
    float Float() const {
        SMASimVALIDATE( m_key == SMASimFloatKey);
        return m_numVal.m_float;
    }

    /// Set the boolean range value
    void SetBoolean( bool b) {
        ClearVal(); // clean all unused bits for bit-hygiene
        m_key = SMASimBooleanKey;
        m_numVal.m_bool = b;
    }

    /// Return the boolean range value
    bool Boolean() const {
        SMASimVALIDATE( m_key == SMASimBooleanKey);
        return m_numVal.m_bool;
    }

    /// Set the collection member range value
    void SetCMember( SMASimIDMinor  id ) {
        ClearVal(); // clean all unused bits for bit-hygiene
        m_key = SMASimCMemberKey;
        m_idVal = id;
    }

    /// Return the collection member range value
    SMASimIDMinor CMember() const {
        SMASimVALIDATE( m_key == SMASimCMemberKey);
        return m_idVal;
    }

    /// Set the cset range value
    void SetCSet( SMASimIDMinor const & id ) {
        ClearVal(); // clean all unused bits for bit-hygiene
        m_key = SMASimCSetKey;
        m_idVal = id;
    }

    /// Return the cset range value
    SMASimIDMinor CSet() const {
        SMASimVALIDATE( m_key == SMASimCSetKey);
        return m_idVal;
    }

    /// Set the ordered cset range value
    void SetOCSet( SMASimIDMinor const & id ) {
        ClearVal(); // clean all unused bits for bit-hygiene
        m_key = SMASimOCSetKey;
        m_idVal = id;
    }

    /// Retrun the ordered cset range value
    SMASimIDMinor OCSet() const {
        SMASimVALIDATE( m_key == SMASimOCSetKey);
        return m_idVal;
    }

    /// Return the size in bytes of the range value
    int SizeBytes() const {
        if( m_key == SMASimVoidTypeKey)
            return 0;
        else return sizeBytes(m_key);
    }

    /// Return the range value as a generic byte pointer
    const char* Data() const {
        if( m_key == SMASimVoidTypeKey)
            return 0;
        else if( isNumeric(m_key))
            return reinterpret_cast<const char*>(&m_numVal);
        else
            return reinterpret_cast<const char*>(&m_idVal);
    }

    /// Internal - do not use
    SMASimRpm_Offset ExternalSizeImpl() const;
    /// Internal - do not use
    void InternalizeImpl(SMASimRpm_BStreamRead& str);
    /// Internal - do not use
    void ExternalizeImpl(SMASimRpm_BStreamWrite& str) const;

private:
    /// Set the range value from a generic byte pointer
    void Set(const char* val);

    /// This should clear the largest of the union member
    void ClearVal() {
        m_numVal.m_double = 0;
        SMASimIDMinor x;
        m_idVal = x;
    }

    // data members
    union { int m_int; double m_double; float m_float; bool m_bool; } m_numVal;
    SMASimIDMinor m_idVal;
    SMASimTypeKey m_key;

};

inline SMASimDebugOut& operator<<(SMASimDebugOut& uos, SMASimRangeValue const& rval)
{
    return rval.WriteDebug(uos);
}

#endif // SMASimRangeValue_h
