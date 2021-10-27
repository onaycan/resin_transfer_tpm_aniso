#ifndef SMABasBinaryPredicate_h
#define SMABasBinaryPredicate_h

// A binary predicate operates on two const items and returns a bool.

// begin local includes

// end local includes

struct SMABasBinaryPredicateGeneric {
 public:
  SMABasBinaryPredicateGeneric(){}
  virtual bool operator()( const void*, const void*) const = 0;
};

template <typename T>
struct SMABasBinaryPredicate : public SMABasBinaryPredicateGeneric {
 public:
  SMABasBinaryPredicate(){};

  static const T& Ref(const void*a){return * reinterpret_cast<const T*>(a);}

  /// In the body of the function, use the Ref( ) function to cast the incoming parameters to type T&.
  /// e.g.  sample body:
  /// return Ref(a).m1 < Ref(b).m1;
  virtual bool operator()( const void* a, const void* b) const = 0;

  /// Base() is handy for the derived classes to cast to this class (base) for help for
  /// function template argument deduction (see the doc for convenient syntactic use).
  const SMABasBinaryPredicate& Base() const {return *this;}

};

#endif // SMABasBinaryPredicate_h
