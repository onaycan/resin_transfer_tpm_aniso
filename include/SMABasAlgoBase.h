#ifndef SMABasAlgoBase_h
#define SMABasAlgoBase_h

// begin local includes

// end local includes

// For algorithms needed in certain container code.

#if SMA_USING_NATIVE_STL

#define SMABasSwap std::swap

#else

/// requires that type T have an assignment operator

template <typename T>
inline void SMABasSwap(T& a, T& b) 
{
  T tmp = a;
  a = b;
  b = tmp;
}

#endif // SMA_USE_NATIVE_STL

#endif // SMABasAlgoBase_h
