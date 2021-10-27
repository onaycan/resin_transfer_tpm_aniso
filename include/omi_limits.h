#ifndef omi_LIMITS_h
#define omi_LIMITS_h

#include <limits.h>

// Begin local includes
#include <omi_types.h>

//uint64:
#ifdef UINT64_MAX
#undef UINT64_MAX
#endif
#ifdef HKS_NT
#define UINT64_MAX 0xffffffffffffffffui64
#else
#define UINT64_MAX 0xffffffffffffffffULL
#endif

// Work around weird anomaly in limits.h
#ifdef HP11
#undef ULONG_LONG_MAX
#define ULONG_LONG_MAX 18446744073709551615ULL
#endif

#if UINT64_MAX == ULONGLONG_MAX || UINT64_MAX == ULONG_MAX || UINT64_MAX == ULLONG_MAX || UINT64_MAX == _UI64_MAX || UINT64_MAX == ULONG_LONG_MAX
#else
#error "omi_limits.h: Unable to find exact match for unsigned integer type uint64!"
#endif

//int64:
#ifdef INT64_MAX
#undef INT64_MAX
#endif

#ifdef HKS_NT
#define INT64_MAX 0x7fffffffffffffffi64
#else
#define INT64_MAX 0x7fffffffffffffffLL
#endif

#if INT64_MAX == LONGLONG_MAX || INT64_MAX == LONG_MAX || INT64_MAX == LLONG_MAX || INT64_MAX == _I64_MAX || INT64_MAX == LONG_LONG_MAX
#else
#error "omi_limits.h: Unable to find exact match for integer type int64!"
#endif

//size_t
#ifdef SIZET_MAX
#undef SIZET_MAX
#endif

#if defined(ABQ_WIN86_64)
#define SIZET_MAX _UI64_MAX
#else
#define SIZET_MAX ULONG_MAX
#endif

#endif
