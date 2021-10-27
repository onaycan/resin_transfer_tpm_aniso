//-*- mode: c++ -*-//
#ifndef SMABasComparitor_h
#define SMABasComparitor_h

// begin local includes

// end local includes


// interpreted as 'less than'
typedef bool (* SMABasPredicatePtr)(  const void* a, const void* b, const void* dictionary);


// The 'dictionary' object is ignored in this comparison.
// Does a comparison using the '<' function, whether global or class-local.
template <typename T>
inline bool SMABasStandardComparitor( const void* a, const void* b, const void* dictionary){
  return *reinterpret_cast<const T*>(a) < *reinterpret_cast<const T*>(b);
}

template <typename T>
class SMABasComparitor {
public:
  static SMABasPredicatePtr GetComparitor(){ return &SMABasStandardComparitor<T>;}
};

//---------------------------------------------------------------------------
// Specialization of const char* AS IF A STRING.
// TODO: REMOVE THIS SPECIALIZATION.   const char*s are not strings
// -- NOTE: I don't think this is a good idea... but right now it needs to be here
// to make current tests run...
// So I've put the specialization function in the test facility where it is NOT EXPORTED.
bool SMABasCompareConstCharStar(const void* a, const void* b, const void* dictionary);
template <>
class SMABasComparitor<const char*> {
public:
  static SMABasPredicatePtr GetComparitor(){ return & SMABasCompareConstCharStar;}
};
// ---------------------------------------------------------------------------------

class SMABasComparitorGeneric {

 public:

  typedef bool (*LessFunc)  ( const void*, const void*);
  typedef bool (*EqualFunc) ( const void* , const void*);

  SMABasComparitorGeneric()
    :
    m_less(0),
    m_equal(0){}

  LessFunc m_less;
  EqualFunc m_equal;
};


#endif // SMABasComparitor_h
