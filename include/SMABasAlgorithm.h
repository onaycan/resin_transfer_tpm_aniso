#ifndef SMABasAlgorithm_h
#define SMABasAlgorithm_h

/*
 *
 * Copyright (c) 1994
 * Hewlett-Packard Company
 *
 * Permission to use, copy, modify, distribute and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation.  Hewlett-Packard Company makes no
 * representations about the suitability of this software for any
 * purpose.  It is provided "as is" without express or implied warranty.
 *
 *
 * Copyright (c) 1996-1998
 * Silicon Graphics Computer Systems, Inc.
 *
 * Permission to use, copy, modify, distribute and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation.  Silicon Graphics makes no
 * representations about the suitability of this software for any
 * purpose.  It is provided "as is" without express or implied warranty.
 */

// begin local includes
#include <SMABasAlgoBase.h>
// end local includes

// This is for a TGEN work-around
#define SMA_XTGEN_INLINE inline

/// Equality and Lexicographical Compare.

template <class _InputIter1, class _InputIter2>
inline bool SMABasEqual(_InputIter1 __first1, _InputIter1 __last1,
                  _InputIter2 __first2) {
  for ( ; __first1 != __last1; ++__first1, ++__first2)
    if (*__first1 != *__first2)
      return false;
  return true;
}

template <class _InputIter1, class _InputIter2, class _BinaryPredicate>
inline bool SMABasEqual(_InputIter1 __first1, _InputIter1 __last1,
			_InputIter2 __first2, _BinaryPredicate __binary_pred) {
  for ( ; __first1 != __last1; ++__first1, ++__first2)
    if (!__binary_pred(*__first1, *__first2))
      return false;
  return true;
}

template <class _InputIter1, class _InputIter2>
SMA_XTGEN_INLINE  bool SMABasLexicographicalCompare(_InputIter1 __first1, _InputIter1 __last1,
						    _InputIter2 __first2, _InputIter2 __last2) {
  for ( ; __first1 != __last1 && __first2 != __last2
	  ; ++__first1, ++__first2) {
    if (*__first1 < *__first2)
      return true;
    if (*__first2 < *__first1)
      return false;
  }
  return __first1 == __last1 && __first2 != __last2;
}

template <class _InputIter1, class _InputIter2, class _Compare>
SMA_XTGEN_INLINE  bool SMABasLexicographicalCompare(_InputIter1 __first1, _InputIter1 __last1,
						    _InputIter2 __first2, _InputIter2 __last2,
						    _Compare __comp) {
  for ( ; __first1 != __last1 && __first2 != __last2
	  ; ++__first1, ++__first2) {
    if (__comp(*__first1, *__first2))
      return true;
    if (__comp(*__first2, *__first1))
      return false;
  }
  return __first1 == __last1 && __first2 != __last2;
}

// Upper-bound, Lower bound and Binary search.

//  For these the STL version(s) are more general; they use a ForwardIterators
//  I have narrowed this to work at least with POINTERS to type T, because I haven't 
//  yet taken the time to make it fully general.


// Lower-bound.

//  Forward-compatible with std::lower_bound.  Binary-search on a SORTED range.
//  Find the highest member in the range which is NOT LESS THAN value.
//  Therefore, If we know the value IS in the range, it will find the lowest occurence.

template <class _ForwardIter, class _Tp>
inline _ForwardIter SMABasLowerBound(_ForwardIter __first, _ForwardIter __last,
                           const _Tp& __val) 
{
  int __len = __last - __first;
  int __half;
  _ForwardIter __middle;

  while (__len > 0) {
    __half = __len >> 1;
    __middle = __first;
    __middle += __half;
    if (*__middle < __val) {
      __first = __middle;
      ++__first;
      __len = __len - __half - 1;
    }
    else
      __len = __half;
  }
  return __first;
}


//  Forward-compatible with std::upper_bound.  Binary-search on a SORTED range.
//  Find the highest member in the range which is GREATER THAN value.

template <class _ForwardIter, class _Tp, class _Distance>
inline _ForwardIter SMABasUpperBound(_ForwardIter __first, _ForwardIter __last,
			      const _Tp& __val)
{
  int __len = __last - __first;
  int __half;
  _ForwardIter __middle;

  while (__len > 0) {
    __half = __len >> 1;
    __middle = __first;
    __middle +=__half;
    if (__val < *__middle)
      __len = __half;
    else {
      __first = __middle;
      ++__first;
      __len = __len - __half - 1;
    }
  }
  return __first;
}


/// Use to Check if the value is in the range.
/// If you want to use the value, you should be either using 
/// SMABasLowerBound (and doing a double-check if it may NOT be there) 
/// or, more conveniently,  using Simulia extension SMABasBinaryFind.
template <class _ForwardIter, class _Tp>
inline bool SMABasBinarySearch(_ForwardIter __first, _ForwardIter __last,
			       const _Tp& __val) {
  _ForwardIter __i = SMABasLowerBound(__first, __last, __val);
  return __i != __last && !(__val < *__i);
}

//SMABasBinaryFind
//  Binary-find on a SORTED range.
//  SMABasBinaryFind IS NOT STL.  This is a SIMULIA extension, 
//  expressible easily in STL.
//  
//  If it finds the desired value, it returns a pointer to it.
//  If it does NOT find the desired value, 
//  then consistent with find (and most of STL) it returns 
//  the off-the-end-of-the range iterator (__last)
//  if it is NOT successful.

template <class _ForwardIter, class _Tp>
inline _ForwardIter SMABasBinaryFind(_ForwardIter __first, _ForwardIter __last,
				     const _Tp& __val) 
{
  _ForwardIter ptr = SMABasLowerBound(__first, __last, __val);
  if( ptr != __last // Redundant but memory-checker can require it!
      && *ptr != __val) 
    ptr = __last;
  return ptr;
}



#endif // SMABasAlgorithm_h
