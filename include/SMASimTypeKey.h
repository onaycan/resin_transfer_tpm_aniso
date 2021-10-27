#ifndef SMASimTypeKey_h
#define SMASimTypeKey_h

// begin local includes
#include <SMASimAssert.h>
#include <SMASimDataTypes.h>
// end local includes


/**
* Keys for types that can be in ranges of distributions
**/

/// Type keys
enum SMASimTypeKey {
  SMASimVoidTypeKey=0,

  SMASimByteKey,
  SMASimIntKey,
  SMASimDoubleKey,
  SMASimFloatKey,
  SMASimBooleanKey,

  dla_ClassKeyOffset,

  SMASimCMemberKey = dla_ClassKeyOffset,
  SMASimCSetKey,
  SMASimOCSetKey,

  SMASimTypeKeyCount
};


// These will help allow people to write generic template functions
// which use SIM drawers.  Instead of SMASimIntKey, write 
// SMASimTypeKeyGet<int>::VALUE,  etc.

// ---------------------------------
template <typename Prim>
struct SMASimTypeKeyGet{};

template <>
struct SMASimTypeKeyGet<int> {
  enum {VALUE=SMASimIntKey};
};

template <>
struct SMASimTypeKeyGet<float> {
  enum {VALUE=SMASimFloatKey};
};

template <>
struct SMASimTypeKeyGet<double> {
  enum {VALUE=SMASimDoubleKey};
};
// ---------------------------------


/// Returns true if type key is unset; false otherwise
inline bool isNull( const SMASimTypeKey k ) {
  return  (k == SMASimVoidTypeKey);
}

/// Returns true if type key is neumeric; false otherwise
inline bool isNumeric( const SMASimTypeKey k ) {
  return  (k < dla_ClassKeyOffset && k > SMASimVoidTypeKey);
}

/// Returns true if type key is relational; false otherwise
inline bool isRelational( const SMASimTypeKey k ) {
  return  (k >= dla_ClassKeyOffset && k < SMASimTypeKeyCount);
}

/// Returns the size in bytes of a type key
inline int sizeBytes( const SMASimTypeKey k ) {
  switch(k)
    {
    case SMASimByteKey: return 1;
    case SMASimIntKey: return sizeof(int);
    case SMASimDoubleKey: return sizeof(double);
    case SMASimFloatKey: return sizeof(float);
    case SMASimBooleanKey: return sizeof(bool);
    case SMASimCMemberKey: return sizeof(int);
    case SMASimCSetKey: return sizeof(int);
    case SMASimOCSetKey: return sizeof(int);
    default:
      SMASimASSERT(!"Illegal SMASimTypeKey");
      return -1;
    };
}

// Convenient name string and write to ostream
const char * SMASimstringNameOf( SMASimTypeKey);

/// Debug output
inline SMASimDebugOut& operator <<( SMASimDebugOut& uos, const SMASimTypeKey& k) {
  uos << SMASimstringNameOf(k);
  return uos;
}

#endif // SMASimTypeKey_h
