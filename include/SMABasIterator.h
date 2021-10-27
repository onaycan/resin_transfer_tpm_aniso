//-*- mode: c++ -*-//
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

#ifndef SMABasIterator_h
#define SMABasIterator_h

#include <stddef.h> // for ptrdiff_t

// Begin local includes
#include <SMABasGenerics.h>
// End local includes

#if SMA_USE_NATIVE_STL

#include <iterator>
#define SMABasBackInsertIterator  std::back_insert_iterator
#define SMABasFrontInsertIterator std::front_insert_iterator

#else

// iterator tags

struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};

// iterator classes

template <class _Tp, class _Distance> 
struct input_iterator {
  typedef input_iterator_tag iterator_category;
  typedef _Tp                value_type;
  typedef _Distance          difference_type;
  typedef _Tp*               pointer;
  typedef _Tp&               reference;
};

struct output_iterator {
  typedef output_iterator_tag iterator_category;
  typedef void                value_type;
  typedef void                difference_type;
  typedef void                pointer;
  typedef void                reference;
};

template <class _Tp, class _Distance> 
struct forward_iterator {
  typedef forward_iterator_tag iterator_category;
  typedef _Tp                  value_type;
  typedef _Distance            difference_type;
  typedef _Tp*                 pointer;
  typedef _Tp&                 reference;
};


template <class _Tp, class _Distance> 
struct bidirectional_iterator {
  typedef bidirectional_iterator_tag iterator_category;
  typedef _Tp                        value_type;
  typedef _Distance                  difference_type;
  typedef _Tp*                       pointer;
  typedef _Tp&                       reference;
};

template <class _Tp, class _Distance> 
struct random_access_iterator {
  typedef random_access_iterator_tag iterator_category;
  typedef _Tp                        value_type;
  typedef _Distance                  difference_type;
  typedef _Tp*                       pointer;
  typedef _Tp&                       reference;
};

// iterator category

template <class _Tp, class _Distance> 
inline input_iterator_tag 
iterator_category(const input_iterator<_Tp, _Distance>&) { 
  return input_iterator_tag(); 
}

inline output_iterator_tag iterator_category(const output_iterator&) { 
  return output_iterator_tag(); 
}

template <class _Tp, class _Distance> 
inline forward_iterator_tag
iterator_category(const forward_iterator<_Tp, _Distance>&) { 
  return forward_iterator_tag(); 
}

template <class _Tp, class _Distance> 
inline bidirectional_iterator_tag
iterator_category(const bidirectional_iterator<_Tp, _Distance>&) { 
  return bidirectional_iterator_tag(); 
}

template <class _Tp, class _Distance> 
inline random_access_iterator_tag
iterator_category(const random_access_iterator<_Tp, _Distance>&){ 
  return random_access_iterator_tag(); 
}

template <class _Tp>
inline random_access_iterator_tag iterator_category(const _Tp*){ 
  return random_access_iterator_tag(); 
}


//------------------ SMABasIteratorBase ------------------------


// TGEN cannot process default template arguments.
// We will have to make everything explicit.


template <class _Category, 
          class _Tp, 
          class _Distance,  // = ptrdiff_t,
          class _Pointer,   // = _Tp*, 
          class _Reference  // = _Tp&
         >
class SMABasIteratorBase 
{
  typedef _Category  iterator_category;
  typedef _Tp        value_type;
  typedef _Distance  difference_type;
  typedef _Pointer   pointer;
  typedef _Reference reference;
};


template <class _Category, class _Tp>
class SMABasIterator : public SMABasIteratorBase<_Category, _Tp, ptrdiff_t, _Tp*, _Tp&>
{ };


// iterator traits

template <class _Iterator>
class iterator_traits 
{
  typedef typename _Iterator::iterator_category iterator_category;
  typedef typename _Iterator::value_type        value_type;
  typedef typename _Iterator::difference_type   difference_type;
  typedef typename _Iterator::pointer           pointer;
  typedef typename _Iterator::reference         reference;
};

template <class _Tp>
class iterator_traits<_Tp*> 
{
  typedef random_access_iterator_tag  iterator_category;
  typedef _Tp                         value_type;
  typedef ptrdiff_t                   difference_type;
  typedef _Tp*                        pointer;
  typedef _Tp&                        reference;
};

template <class _Tp>
class iterator_traits<const _Tp*> 
{
  typedef random_access_iterator_tag  iterator_category;
  typedef _Tp                         value_type;
  typedef ptrdiff_t                   difference_type;
  typedef const _Tp*                  pointer;
  typedef const _Tp&                  reference;
};

// distance_type

template <class _Tp, class _Distance> 
inline _Distance* distance_type(const input_iterator<_Tp, _Distance>&)
{
  return (_Distance*)(0);
}

template <class _Tp, class _Distance> 
inline _Distance* distance_type(const forward_iterator<_Tp, _Distance>&)
{
  return (_Distance*)(0);
}

template <class _Tp, class _Distance> 
inline _Distance* 
distance_type(const bidirectional_iterator<_Tp, _Distance>&)
{
  return (_Distance*)(0);
}

template <class _Tp, class _Distance> 
inline _Distance* 
distance_type(const random_access_iterator<_Tp, _Distance>&)
{
  return (_Distance*)(0);
}

template <class _Tp>
inline ptrdiff_t* distance_type(const _Tp*) { return (ptrdiff_t*)(0); }



/// unidirectional distance calculation

template <class _InputIterator, class _Distance>
inline void __distance(_InputIterator __first, 
					   _InputIterator __last,
                       _Distance& __n, 
                       input_iterator_tag)
{
  while (__first != __last) { ++__first; ++__n; }
}

/// randon-access distance calculation
template <class _RandomAccessIterator, class _Distance>
inline void __distance(_RandomAccessIterator __first, 
                       _RandomAccessIterator __last, 
                       _Distance& __n, 
                       random_access_iterator_tag)
{
  __n += __last - __first;
}

/// returns distance between the two iterators in __n

template <class _InputIterator, class _Distance>
inline void distance(_InputIterator __first, 
                     _InputIterator __last, 
                     _Distance& __n)
{
  // we will only use input_iterator_tag -- until we fully support traits
  // __distance(__first, __last, __n, iterator_category(__first));
  __distance(__first, __last, __n, input_iterator_tag() );
}

template <class _InputIterator>
inline typename iterator_traits<_InputIterator>::difference_type
__distance(_InputIterator __first, _InputIterator __last, input_iterator_tag)
{
  typename iterator_traits<_InputIterator>::difference_type __n = 0;
  while (__first != __last) {
    ++__first; ++__n;
  }
  return __n;
}

template <class _RandomAccessIterator>
inline typename iterator_traits<_RandomAccessIterator>::difference_type
__distance(_RandomAccessIterator __first, _RandomAccessIterator __last,
           random_access_iterator_tag) 
{
  return __last - __first;
}

template <class _InputIterator>
inline typename iterator_traits<_InputIterator>::difference_type
distance(_InputIterator __first, _InputIterator __last) 
{
  typedef typename iterator_traits<_InputIterator>::iterator_category 
    _Category;
  return __distance(__first, __last, _Category());
}


template <typename CONTAINERTYPE>
class SMABasBackInsertIterator 
{
public:
  typedef CONTAINERTYPE       container_type;
  typedef output_iterator_tag iterator_category;
  typedef void                value_type;
  typedef void                difference_type;
  typedef void                pointer;
  typedef void                reference;

  explicit 
  SMABasBackInsertIterator(CONTAINERTYPE& __c): 
       m_container(&__c) 
  { }

  SMABasBackInsertIterator<CONTAINERTYPE>& 
  operator= (const typename CONTAINERTYPE::value_type& __val) 
  { 
    m_container->push_back(__val);
    return *this;
  }

  SMABasBackInsertIterator<CONTAINERTYPE>& 
  operator* () 
  {  
	return *this; 
  }

  SMABasBackInsertIterator<CONTAINERTYPE>& 
  operator++() 
  { 
	return *this; 
  }

  SMABasBackInsertIterator<CONTAINERTYPE>& 
  operator++(int) 
  { 
	return *this; 
  }

protected:
  CONTAINERTYPE*              m_container;

};

template <typename CONTAINERTYPE>
inline output_iterator_tag
iterator_category(const SMABasBackInsertIterator<CONTAINERTYPE>&)
{
  return output_iterator_tag();
}

template <typename CONTAINERTYPE>
inline SMABasBackInsertIterator<CONTAINERTYPE> 
back_inserter(CONTAINERTYPE& __x) 
{
  return SMABasBackInsertIterator<CONTAINERTYPE>(__x);
}

template <typename CONTAINERTYPE>
class SMABasFrontInsertIterator 
{
public:
  typedef CONTAINERTYPE       container_type;
  typedef output_iterator_tag iterator_category;
  typedef void                value_type;
  typedef void                difference_type;
  typedef void                pointer;
  typedef void                reference;

  explicit SMABasFrontInsertIterator(CONTAINERTYPE& __x) : 
	m_container(&__x) 
  { }

  SMABasFrontInsertIterator<CONTAINERTYPE>& 
  operator= (const typename CONTAINERTYPE::value_type& __val) 
  { 
    m_container->push_front(__val);
    return *this;
  }

  SMABasFrontInsertIterator<CONTAINERTYPE>& 
  operator* () 
  { 
	return *this; 
  }
  
  SMABasFrontInsertIterator<CONTAINERTYPE>& 
  operator++ () 
  { 
	return *this; 
  }

  SMABasFrontInsertIterator<CONTAINERTYPE>& 
  operator++ (int) 
  { 
	return *this; 
  }

protected:
  CONTAINERTYPE* m_container;
};

template <typename CONTAINERTYPE>
inline output_iterator_tag
iterator_category(const SMABasFrontInsertIterator<CONTAINERTYPE>&)
{
  return output_iterator_tag();
}

template <typename CONTAINERTYPE>
inline SMABasFrontInsertIterator<CONTAINERTYPE> 
front_inserter(CONTAINERTYPE& __x) 
{
  return SMABasFrontInsertIterator<CONTAINERTYPE>(__x);
}

template <typename CONTAINERTYPE>
class SMABasInsertIterator 
{
  typename CONTAINERTYPE::iterator iter;
public:
  typedef CONTAINERTYPE       container_type;
  typedef output_iterator_tag iterator_category;
  typedef void                value_type;
  typedef void                difference_type;
  typedef void                pointer;
  typedef void                reference;

  // Constructor

  SMABasInsertIterator( CONTAINERTYPE& __x, 
                        typename CONTAINERTYPE::iterator __i) 
    : m_container(&__x), iter(__i) 
  { }

  // Assignment

  SMABasInsertIterator<CONTAINERTYPE>& 
  operator= (const typename CONTAINERTYPE::value_type& __val) 
  { 
    iter = m_container->insert(iter, __val);
    ++iter;
    return *this;
  }

  // Dereference

  SMABasInsertIterator<CONTAINERTYPE>& 
  operator* () 
  { 
	return *this; 
  }

  // Pre Increment

  SMABasInsertIterator<CONTAINERTYPE>& 
  operator++() 
  { 
	return *this; 
  }

  // Post Increment

  SMABasInsertIterator<CONTAINERTYPE>& 
  operator++(int) 
  { 
	return *this; 
  }

protected:
  CONTAINERTYPE*  m_container;

};

template <typename CONTAINERTYPE>
inline output_iterator_tag
iterator_category(const SMABasInsertIterator<CONTAINERTYPE>&)
{
  return output_iterator_tag();
}

template <typename CONTAINERTYPE, typename _Iterator>
inline 
SMABasInsertIterator<CONTAINERTYPE> 
inserter(CONTAINERTYPE& __x, _Iterator __i)
{
  typedef typename CONTAINERTYPE::iterator __iter;
  return SMABasInsertIterator<CONTAINERTYPE>(__x, __iter(__i));
}

#endif // SMA_USE_NATIVE_STL

#endif // SMABasIterator_h

