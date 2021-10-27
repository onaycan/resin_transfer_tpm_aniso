//-*- mode: c++ -*-//
#ifndef SMABasAlgoGeneric_h
#define SMABasAlgoGeneric_h

// begin local includes
#include <SMABasReplicator.h>
#include <SMABasComparitor.h>
#include <SMABasBinaryPredicate.h>
// end local includes

void SMABasSortGeneric1( void* begin, 
			 void* end, 
			 SMABasReplicatorGeneric,
			 SMABasComparitorGeneric);


void SMABasSortGeneric2( void* begin,
			 void* end,
			 SMABasReplicatorGeneric,
			 const SMABasBinaryPredicateGeneric& lessThanGeneric );


bool SMABasIsSortedGeneric1( const void* begin, 
			     const void* end, 
			     SMABasReplicatorGeneric,
			     SMABasComparitorGeneric);


bool SMABasIsSortedGeneric2( const void* begin,
			     const void* end,
			     SMABasReplicatorGeneric,
			     const SMABasBinaryPredicateGeneric& lessThanGeneric );


#endif // SMABasAlgoGeneric_h
