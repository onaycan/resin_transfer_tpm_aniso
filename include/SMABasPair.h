//-*- mode: c++ -*-//
#ifndef SMABasPair_h
#define SMABasPair_h

/// SMABasPair -- is the equivalent of std::pair.
/// This is struct that holds two objects, called "first" and "second".
/// Those objects may be of any type that is copyable.
/// Note that both "first" and "second" are directly accessible, in compliance 
/// with the STL conventions.

// Begin local includes
#include <SMABasGenerics.h>
// End local includes

#if SMA_USE_NATIVE_STL

#if defined(_MSC_VER)
#include <utility>
#endif

#define SMABasPair      std::pair
#define SMABasMakePair  std::make_pair

#else

// Not of public interest
struct SMABasPairGenericParams
{
  SMABasPairGenericParams(int secondOffset, int sizeInBytes):
  m_secOffset(secondOffset), m_pairSize(sizeInBytes) 
  { }

  ~SMABasPairGenericParams() {}
  
  int m_secOffset; /// offset from the start of the pair to its second member (value)
  int m_pairSize;  /// size of the pair object
};


template <typename KEY, typename VAL>
class SMABasPair
{
 public:
  typedef KEY first_type;
  typedef VAL second_type;

  /// default constructor: key is created using its default constructor, and so is value 

  SMABasPair() : 
	first (KEY()), 
	second(VAL())  
  { }

  /// construct a pair out of two values

  SMABasPair(const KEY& a, const VAL& b) : 
        first(a), 
        second(b) 
  { }

  /// construct a pair as a copy of another pair

  SMABasPair( const SMABasPair<const KEY,VAL>& other) : 
         first ( other.first ), 
         second( other.second ) 
  { }

  /// assigment operator 
        
  SMABasPair<const KEY,VAL>& operator=(const SMABasPair<const KEY,VAL>& other ) 
  {
      first.~KEY();
      second.~VAL();
      first = other.first;
      second = other.second;
      return *this; 
  }

  // Data members

  KEY first;  // data member one
  VAL second; // data member two

};

/// SMABasMakePair(a,b)
/// This is a utility function, used to simplify coding of inserting elements
/// into a map. It takes two arguments of any type, and returns a pair constructed 
/// from copies of them. For example:
///     SMABasMakePair(1,11); // creates a pair holding 2 integers

template <typename KEY, typename VAL>
inline 
SMABasPair<const KEY,VAL> 
SMABasMakePair (const KEY& a, const VAL& b )
{
  return SMABasPair<const KEY,VAL>(a,b);
}

/// == ( Equal ) 
/// Returns true if a.first == b.first and a.second == b.second

template <typename KEY, typename VAL>
inline bool 
operator== ( const SMABasPair<KEY, VAL>& a, 
             const SMABasPair<KEY, VAL>& b )
{ 
  return (a.first == b.first) && (a.second == b.second); 
}

/// != ( Not-Equal ) 

template <typename KEY, typename VAL>
inline bool 
operator!=  ( const SMABasPair<KEY,VAL>& a, 
              const SMABasPair<KEY,VAL>& b ) 
{
  return !(a == b);
}

/// < ( Less Than )  *first* has priority over *second*

template <typename KEY, typename VAL>
inline bool 
operator< ( const SMABasPair<KEY,VAL>& a, 
            const SMABasPair<KEY,VAL>& b )
{ 
  return ( a.first < b.first ) || 
         ( !(b.first < a.first) && a.second < b.second); 
}

/// > ( Greater Than )

template <typename KEY, typename VAL>
inline bool 
operator> ( const SMABasPair<KEY,VAL>& a, 
            const SMABasPair<KEY,VAL>& b ) 
{
  return b < a;
}

/// <= ( Less Than or Equal )

template <typename KEY, typename VAL>
inline bool 
operator<= (  const SMABasPair<KEY,VAL>& a, 
              const SMABasPair<KEY,VAL>& b ) 
{
  return !(b < a);
}

/// => ( Greater Than or Equal )

template <typename KEY, typename VAL>
inline bool 
operator>= ( const SMABasPair<KEY,VAL>& a, 
             const SMABasPair<KEY,VAL>& b ) 
{
  return !(a < b);
}

#endif // SMA_USE_NATIVE_STL
#endif // SMABasPair_h 


