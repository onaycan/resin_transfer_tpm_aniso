#ifndef atr_translate_h
#define atr_translate_h

// This function provides an interface to translate a character string.
//#include <stdarg.h>
// Begin local includes
#include <mem_AllocationOperators.h>
#include <mem_AllocationOperatorsTiny.h>
#include <mem_C_Allocation.h>
#include <omi_types.h>
#include <atr_String.h>

class atr_Fmt  : public mem_AllocationOperators
{
  friend class atr_translate;
public:
  enum DataSize { DataSizeDefault, DataSizeShort, DataSizeLong, DataSizeHuge };

  atr_Fmt(char const* fmt);
  ~atr_Fmt();

  bool Ok() const { return m_Fmt; };

  char Letter();
  char const* Format(DataSize dataSize = DataSizeDefault, char letterOverride = 0);
  char const* FormatNoWidth(DataSize dataSize = DataSizeDefault, char letterOverride = 0);

private:
  char const* m_Fmt;
  char m_Letter;
  char* m_OutFmt;

  atr_Fmt(atr_Fmt const&);
  atr_Fmt& operator=(atr_Fmt const&);
};

class atr_translate  : public mem_AllocationOperators
{
public:
  atr_translate(char const* pStr);
  ~atr_translate();

  char const* Format(int pos) const;
  void AddSubstitution(int pos, char const* subst, char const* fmt = 0);

  static void FixExponent(char* buffer);

  atr_String Result() const;

private:
  struct StrArgs : public mem_AllocationOperatorsTiny
  {
    StrArgs() : sFormat(0), sValue(0) {};
    ~StrArgs() { mem_Free(sFormat); mem_Free(sValue); };

    int nPos;
    char* sFormat;
    char* sValue;
  };

  static int compare( const void *arg1, const void *arg2 );
  void ReportIllegalPosition(int pos) const;

  char const* m_OriginalFormat;

  int nCount;
  StrArgs* aArgs;
  StrArgs** ppSortArgs;
  char* psOutput;

  atr_translate(atr_translate const&);
  atr_translate& operator=(atr_translate const&);
};

atr_String atr_raw(const char *pStr);

void atr_SubstituteFormat(atr_translate& format, int position, int data);
void atr_SubstituteFormat(atr_translate& format, int position, uint data);
void atr_SubstituteFormat(atr_translate& format, int position, int64 data);
void atr_SubstituteFormat(atr_translate& format, int position, uint64 data);
void atr_SubstituteFormat(atr_translate& format, int position, float data);
void atr_SubstituteFormat(atr_translate& format, int position, double data);
void atr_SubstituteFormat(atr_translate& format, int position, char const* data);
void atr_SubstituteFormat(atr_translate& format, int position, void const* data);
void atr_SubstituteFormat(atr_translate& format, int position, atr_StringBase const& data);

inline atr_String atr(char const* format)
{
  atr_translate fmt(format);
  return fmt.Result();
}

template <typename T1>
inline atr_String atr(char const* format, T1 data1)
{
  atr_translate fmt(format);
  atr_SubstituteFormat(fmt, 1, data1);
  return fmt.Result();
}

template <typename T1, typename T2>
inline atr_String atr(char const* format, T1 data1, T2 data2)
{
  atr_translate fmt(format);
  atr_SubstituteFormat(fmt, 1, data1);
  atr_SubstituteFormat(fmt, 2, data2);
  return fmt.Result();
}

template <typename T1, typename T2, typename T3>
inline atr_String atr(char const* format, T1 data1, T2 data2, T3 data3)
{
  atr_translate fmt(format);
  atr_SubstituteFormat(fmt, 1, data1);
  atr_SubstituteFormat(fmt, 2, data2);
  atr_SubstituteFormat(fmt, 3, data3);
  return fmt.Result();
}

template <typename T1, typename T2, typename T3, typename T4>
inline atr_String atr(char const* format,
                      T1 data1, T2 data2, T3 data3, T4 data4)
{
  atr_translate fmt(format);
  atr_SubstituteFormat(fmt, 1, data1);
  atr_SubstituteFormat(fmt, 2, data2);
  atr_SubstituteFormat(fmt, 3, data3);
  atr_SubstituteFormat(fmt, 4, data4);
  return fmt.Result();
}

template <typename T1, typename T2, typename T3, typename T4, typename T5>
inline atr_String atr(char const* format,
                      T1 data1, T2 data2, T3 data3, T4 data4, T5 data5)
{
  atr_translate fmt(format);
  atr_SubstituteFormat(fmt, 1, data1);
  atr_SubstituteFormat(fmt, 2, data2);
  atr_SubstituteFormat(fmt, 3, data3);
  atr_SubstituteFormat(fmt, 4, data4);
  atr_SubstituteFormat(fmt, 5, data5);
  return fmt.Result();
}

template <typename T1, typename T2, typename T3, typename T4, typename T5,
          typename T6>
inline atr_String atr(char const* format,
                      T1 data1, T2 data2, T3 data3, T4 data4, T5 data5,
                      T6 data6)
{
  atr_translate fmt(format);
  atr_SubstituteFormat(fmt, 1, data1);
  atr_SubstituteFormat(fmt, 2, data2);
  atr_SubstituteFormat(fmt, 3, data3);
  atr_SubstituteFormat(fmt, 4, data4);
  atr_SubstituteFormat(fmt, 5, data5);
  atr_SubstituteFormat(fmt, 6, data6);
  return fmt.Result();
}

template <typename T1, typename T2, typename T3, typename T4, typename T5,
          typename T6, typename T7>
inline atr_String atr(char const* format,
                      T1 data1, T2 data2, T3 data3, T4 data4, T5 data5,
                      T6 data6, T7 data7)
{
  atr_translate fmt(format);
  atr_SubstituteFormat(fmt, 1, data1);
  atr_SubstituteFormat(fmt, 2, data2);
  atr_SubstituteFormat(fmt, 3, data3);
  atr_SubstituteFormat(fmt, 4, data4);
  atr_SubstituteFormat(fmt, 5, data5);
  atr_SubstituteFormat(fmt, 6, data6);
  atr_SubstituteFormat(fmt, 7, data7);
  return fmt.Result();
}

template <typename T1, typename T2, typename T3, typename T4, typename T5,
          typename T6, typename T7, typename T8>
inline atr_String atr(char const* format,
                      T1 data1, T2 data2, T3 data3, T4 data4, T5 data5,
                      T6 data6, T7 data7, T8 data8)
{
  atr_translate fmt(format);
  atr_SubstituteFormat(fmt, 1, data1);
  atr_SubstituteFormat(fmt, 2, data2);
  atr_SubstituteFormat(fmt, 3, data3);
  atr_SubstituteFormat(fmt, 4, data4);
  atr_SubstituteFormat(fmt, 5, data5);
  atr_SubstituteFormat(fmt, 6, data6);
  atr_SubstituteFormat(fmt, 7, data7);
  atr_SubstituteFormat(fmt, 8, data8);
  return fmt.Result();
}

template <typename T1, typename T2, typename T3, typename T4, typename T5,
          typename T6, typename T7, typename T8, typename T9>
inline atr_String atr(char const* format,
                      T1 data1, T2 data2, T3 data3, T4 data4, T5 data5,
                      T6 data6, T7 data7, T8 data8, T9 data9)
{
  atr_translate fmt(format);
  atr_SubstituteFormat(fmt, 1, data1);
  atr_SubstituteFormat(fmt, 2, data2);
  atr_SubstituteFormat(fmt, 3, data3);
  atr_SubstituteFormat(fmt, 4, data4);
  atr_SubstituteFormat(fmt, 5, data5);
  atr_SubstituteFormat(fmt, 6, data6);
  atr_SubstituteFormat(fmt, 7, data7);
  atr_SubstituteFormat(fmt, 8, data8);
  atr_SubstituteFormat(fmt, 9, data9);
  return fmt.Result();
}

template <typename T1, typename T2, typename T3, typename T4, typename T5,
          typename T6, typename T7, typename T8, typename T9, typename T10>
inline atr_String atr(char const* format,
                      T1 data1, T2 data2, T3 data3, T4 data4, T5 data5,
                      T6 data6, T7 data7, T8 data8, T9 data9, T10 data10)
{
  atr_translate fmt(format);
  atr_SubstituteFormat(fmt, 1, data1);
  atr_SubstituteFormat(fmt, 2, data2);
  atr_SubstituteFormat(fmt, 3, data3);
  atr_SubstituteFormat(fmt, 4, data4);
  atr_SubstituteFormat(fmt, 5, data5);
  atr_SubstituteFormat(fmt, 6, data6);
  atr_SubstituteFormat(fmt, 7, data7);
  atr_SubstituteFormat(fmt, 8, data8);
  atr_SubstituteFormat(fmt, 9, data9);
  atr_SubstituteFormat(fmt, 10, data10);
  return fmt.Result();
}

template <typename T1, typename T2, typename T3, typename T4, typename T5,
          typename T6, typename T7, typename T8, typename T9, typename T10,
          typename T11>
inline atr_String atr(char const* format,
                      T1 data1, T2 data2, T3 data3, T4 data4, T5 data5,
                      T6 data6, T7 data7, T8 data8, T9 data9, T10 data10,
                      T11 data11)
{
  atr_translate fmt(format);
  atr_SubstituteFormat(fmt, 1, data1);
  atr_SubstituteFormat(fmt, 2, data2);
  atr_SubstituteFormat(fmt, 3, data3);
  atr_SubstituteFormat(fmt, 4, data4);
  atr_SubstituteFormat(fmt, 5, data5);
  atr_SubstituteFormat(fmt, 6, data6);
  atr_SubstituteFormat(fmt, 7, data7);
  atr_SubstituteFormat(fmt, 8, data8);
  atr_SubstituteFormat(fmt, 9, data9);
  atr_SubstituteFormat(fmt, 10, data10);
  atr_SubstituteFormat(fmt, 11, data11);
  return fmt.Result();
}

template <typename T1, typename T2, typename T3, typename T4, typename T5,
          typename T6, typename T7, typename T8, typename T9, typename T10,
          typename T11, typename T12>
inline atr_String atr(char const* format,
                      T1 data1, T2 data2, T3 data3, T4 data4, T5 data5,
                      T6 data6, T7 data7, T8 data8, T9 data9, T10 data10,
                      T11 data11, T12 data12)
{
  atr_translate fmt(format);
  atr_SubstituteFormat(fmt, 1, data1);
  atr_SubstituteFormat(fmt, 2, data2);
  atr_SubstituteFormat(fmt, 3, data3);
  atr_SubstituteFormat(fmt, 4, data4);
  atr_SubstituteFormat(fmt, 5, data5);
  atr_SubstituteFormat(fmt, 6, data6);
  atr_SubstituteFormat(fmt, 7, data7);
  atr_SubstituteFormat(fmt, 8, data8);
  atr_SubstituteFormat(fmt, 9, data9);
  atr_SubstituteFormat(fmt, 10, data10);
  atr_SubstituteFormat(fmt, 11, data11);
  atr_SubstituteFormat(fmt, 12, data12);
  return fmt.Result();
}

template <typename T1, typename T2, typename T3, typename T4, typename T5,
          typename T6, typename T7, typename T8, typename T9, typename T10,
          typename T11, typename T12, typename T13>
inline atr_String atr(char const* format,
                      T1 data1, T2 data2, T3 data3, T4 data4, T5 data5,
                      T6 data6, T7 data7, T8 data8, T9 data9, T10 data10,
                      T11 data11, T12 data12, T13 data13)
{
  atr_translate fmt(format);
  atr_SubstituteFormat(fmt, 1, data1);
  atr_SubstituteFormat(fmt, 2, data2);
  atr_SubstituteFormat(fmt, 3, data3);
  atr_SubstituteFormat(fmt, 4, data4);
  atr_SubstituteFormat(fmt, 5, data5);
  atr_SubstituteFormat(fmt, 6, data6);
  atr_SubstituteFormat(fmt, 7, data7);
  atr_SubstituteFormat(fmt, 8, data8);
  atr_SubstituteFormat(fmt, 9, data9);
  atr_SubstituteFormat(fmt, 10, data10);
  atr_SubstituteFormat(fmt, 11, data11);
  atr_SubstituteFormat(fmt, 12, data12);
  atr_SubstituteFormat(fmt, 13, data13);
  return fmt.Result();
}

template <typename T1, typename T2, typename T3, typename T4, typename T5,
          typename T6, typename T7, typename T8, typename T9, typename T10,
          typename T11, typename T12, typename T13, typename T14>
inline atr_String atr(char const* format,
                      T1 data1, T2 data2, T3 data3, T4 data4, T5 data5,
                      T6 data6, T7 data7, T8 data8, T9 data9, T10 data10,
                      T11 data11, T12 data12, T13 data13, T14 data14)
{
  atr_translate fmt(format);
  atr_SubstituteFormat(fmt, 1, data1);
  atr_SubstituteFormat(fmt, 2, data2);
  atr_SubstituteFormat(fmt, 3, data3);
  atr_SubstituteFormat(fmt, 4, data4);
  atr_SubstituteFormat(fmt, 5, data5);
  atr_SubstituteFormat(fmt, 6, data6);
  atr_SubstituteFormat(fmt, 7, data7);
  atr_SubstituteFormat(fmt, 8, data8);
  atr_SubstituteFormat(fmt, 9, data9);
  atr_SubstituteFormat(fmt, 10, data10);
  atr_SubstituteFormat(fmt, 11, data11);
  atr_SubstituteFormat(fmt, 12, data12);
  atr_SubstituteFormat(fmt, 13, data13);
  atr_SubstituteFormat(fmt, 14, data14);
  return fmt.Result();
}

template <typename T1, typename T2, typename T3, typename T4, typename T5,
          typename T6, typename T7, typename T8, typename T9, typename T10,
          typename T11, typename T12, typename T13, typename T14, typename T15>
inline atr_String atr(char const* format,
                      T1 data1, T2 data2, T3 data3, T4 data4, T5 data5,
                      T6 data6, T7 data7, T8 data8, T9 data9, T10 data10,
                      T11 data11, T12 data12, T13 data13, T14 data14, T15 data15)
{
  atr_translate fmt(format);
  atr_SubstituteFormat(fmt, 1, data1);
  atr_SubstituteFormat(fmt, 2, data2);
  atr_SubstituteFormat(fmt, 3, data3);
  atr_SubstituteFormat(fmt, 4, data4);
  atr_SubstituteFormat(fmt, 5, data5);
  atr_SubstituteFormat(fmt, 6, data6);
  atr_SubstituteFormat(fmt, 7, data7);
  atr_SubstituteFormat(fmt, 8, data8);
  atr_SubstituteFormat(fmt, 9, data9);
  atr_SubstituteFormat(fmt, 10, data10);
  atr_SubstituteFormat(fmt, 11, data11);
  atr_SubstituteFormat(fmt, 12, data12);
  atr_SubstituteFormat(fmt, 13, data13);
  atr_SubstituteFormat(fmt, 14, data14);
  atr_SubstituteFormat(fmt, 15, data15);
  return fmt.Result();
}

template <typename T1, typename T2, typename T3, typename T4, typename T5,
          typename T6, typename T7, typename T8, typename T9, typename T10,
          typename T11, typename T12, typename T13, typename T14, typename T15,
          typename T16>
inline atr_String atr(char const* format,
                      T1 data1, T2 data2, T3 data3, T4 data4, T5 data5,
                      T6 data6, T7 data7, T8 data8, T9 data9, T10 data10,
                      T11 data11, T12 data12, T13 data13, T14 data14, T15 data15,
                      T16 data16)
{
  atr_translate fmt(format);
  atr_SubstituteFormat(fmt, 1, data1);
  atr_SubstituteFormat(fmt, 2, data2);
  atr_SubstituteFormat(fmt, 3, data3);
  atr_SubstituteFormat(fmt, 4, data4);
  atr_SubstituteFormat(fmt, 5, data5);
  atr_SubstituteFormat(fmt, 6, data6);
  atr_SubstituteFormat(fmt, 7, data7);
  atr_SubstituteFormat(fmt, 8, data8);
  atr_SubstituteFormat(fmt, 9, data9);
  atr_SubstituteFormat(fmt, 10, data10);
  atr_SubstituteFormat(fmt, 11, data11);
  atr_SubstituteFormat(fmt, 12, data12);
  atr_SubstituteFormat(fmt, 13, data13);
  atr_SubstituteFormat(fmt, 14, data14);
  atr_SubstituteFormat(fmt, 15, data15);
  atr_SubstituteFormat(fmt, 16, data16);
  return fmt.Result();
}

template <typename T1, typename T2, typename T3, typename T4, typename T5,
          typename T6, typename T7, typename T8, typename T9, typename T10,
          typename T11, typename T12, typename T13, typename T14, typename T15,
          typename T16, typename T17>
inline atr_String atr(char const* format,
                      T1 data1, T2 data2, T3 data3, T4 data4, T5 data5,
                      T6 data6, T7 data7, T8 data8, T9 data9, T10 data10,
                      T11 data11, T12 data12, T13 data13, T14 data14, T15 data15,
                      T16 data16, T17 data17)
{
  atr_translate fmt(format);
  atr_SubstituteFormat(fmt, 1, data1);
  atr_SubstituteFormat(fmt, 2, data2);
  atr_SubstituteFormat(fmt, 3, data3);
  atr_SubstituteFormat(fmt, 4, data4);
  atr_SubstituteFormat(fmt, 5, data5);
  atr_SubstituteFormat(fmt, 6, data6);
  atr_SubstituteFormat(fmt, 7, data7);
  atr_SubstituteFormat(fmt, 8, data8);
  atr_SubstituteFormat(fmt, 9, data9);
  atr_SubstituteFormat(fmt, 10, data10);
  atr_SubstituteFormat(fmt, 11, data11);
  atr_SubstituteFormat(fmt, 12, data12);
  atr_SubstituteFormat(fmt, 13, data13);
  atr_SubstituteFormat(fmt, 14, data14);
  atr_SubstituteFormat(fmt, 15, data15);
  atr_SubstituteFormat(fmt, 16, data16);
  atr_SubstituteFormat(fmt, 17, data17);
  return fmt.Result();
}

template <typename T1, typename T2, typename T3, typename T4, typename T5,
          typename T6, typename T7, typename T8, typename T9, typename T10,
          typename T11, typename T12, typename T13, typename T14, typename T15,
          typename T16, typename T17, typename T18>
inline atr_String atr(char const* format,
                      T1 data1, T2 data2, T3 data3, T4 data4, T5 data5,
                      T6 data6, T7 data7, T8 data8, T9 data9, T10 data10,
                      T11 data11, T12 data12, T13 data13, T14 data14, T15 data15,
                      T16 data16, T17 data17, T18 data18)
{
  atr_translate fmt(format);
  atr_SubstituteFormat(fmt, 1, data1);
  atr_SubstituteFormat(fmt, 2, data2);
  atr_SubstituteFormat(fmt, 3, data3);
  atr_SubstituteFormat(fmt, 4, data4);
  atr_SubstituteFormat(fmt, 5, data5);
  atr_SubstituteFormat(fmt, 6, data6);
  atr_SubstituteFormat(fmt, 7, data7);
  atr_SubstituteFormat(fmt, 8, data8);
  atr_SubstituteFormat(fmt, 9, data9);
  atr_SubstituteFormat(fmt, 10, data10);
  atr_SubstituteFormat(fmt, 11, data11);
  atr_SubstituteFormat(fmt, 12, data12);
  atr_SubstituteFormat(fmt, 13, data13);
  atr_SubstituteFormat(fmt, 14, data14);
  atr_SubstituteFormat(fmt, 15, data15);
  atr_SubstituteFormat(fmt, 16, data16);
  atr_SubstituteFormat(fmt, 17, data17);
  atr_SubstituteFormat(fmt, 18, data18);
  return fmt.Result();
}

template <typename T1, typename T2, typename T3, typename T4, typename T5,
          typename T6, typename T7, typename T8, typename T9, typename T10,
          typename T11, typename T12, typename T13, typename T14, typename T15,
          typename T16, typename T17, typename T18, typename T19>
inline atr_String atr(char const* format,
                      T1 data1, T2 data2, T3 data3, T4 data4, T5 data5,
                      T6 data6, T7 data7, T8 data8, T9 data9, T10 data10,
                      T11 data11, T12 data12, T13 data13, T14 data14, T15 data15,
                      T16 data16, T17 data17, T18 data18, T19 data19)
{
  atr_translate fmt(format);
  atr_SubstituteFormat(fmt, 1, data1);
  atr_SubstituteFormat(fmt, 2, data2);
  atr_SubstituteFormat(fmt, 3, data3);
  atr_SubstituteFormat(fmt, 4, data4);
  atr_SubstituteFormat(fmt, 5, data5);
  atr_SubstituteFormat(fmt, 6, data6);
  atr_SubstituteFormat(fmt, 7, data7);
  atr_SubstituteFormat(fmt, 8, data8);
  atr_SubstituteFormat(fmt, 9, data9);
  atr_SubstituteFormat(fmt, 10, data10);
  atr_SubstituteFormat(fmt, 11, data11);
  atr_SubstituteFormat(fmt, 12, data12);
  atr_SubstituteFormat(fmt, 13, data13);
  atr_SubstituteFormat(fmt, 14, data14);
  atr_SubstituteFormat(fmt, 15, data15);
  atr_SubstituteFormat(fmt, 16, data16);
  atr_SubstituteFormat(fmt, 17, data17);
  atr_SubstituteFormat(fmt, 18, data18);
  atr_SubstituteFormat(fmt, 19, data19);
  return fmt.Result();
}

template <typename T1, typename T2, typename T3, typename T4, typename T5,
          typename T6, typename T7, typename T8, typename T9, typename T10,
          typename T11, typename T12, typename T13, typename T14, typename T15,
          typename T16, typename T17, typename T18, typename T19, typename T20>
inline atr_String atr(char const* format,
                      T1 data1, T2 data2, T3 data3, T4 data4, T5 data5,
                      T6 data6, T7 data7, T8 data8, T9 data9, T10 data10,
                      T11 data11, T12 data12, T13 data13, T14 data14, T15 data15,
                      T16 data16, T17 data17, T18 data18, T19 data19, T20 data20)
{
  atr_translate fmt(format);
  atr_SubstituteFormat(fmt, 1, data1);
  atr_SubstituteFormat(fmt, 2, data2);
  atr_SubstituteFormat(fmt, 3, data3);
  atr_SubstituteFormat(fmt, 4, data4);
  atr_SubstituteFormat(fmt, 5, data5);
  atr_SubstituteFormat(fmt, 6, data6);
  atr_SubstituteFormat(fmt, 7, data7);
  atr_SubstituteFormat(fmt, 8, data8);
  atr_SubstituteFormat(fmt, 9, data9);
  atr_SubstituteFormat(fmt, 10, data10);
  atr_SubstituteFormat(fmt, 11, data11);
  atr_SubstituteFormat(fmt, 12, data12);
  atr_SubstituteFormat(fmt, 13, data13);
  atr_SubstituteFormat(fmt, 14, data14);
  atr_SubstituteFormat(fmt, 15, data15);
  atr_SubstituteFormat(fmt, 16, data16);
  atr_SubstituteFormat(fmt, 17, data17);
  atr_SubstituteFormat(fmt, 18, data18);
  atr_SubstituteFormat(fmt, 19, data19);
  atr_SubstituteFormat(fmt, 20, data20);
  return fmt.Result();
}

#endif // atr_translate_h
