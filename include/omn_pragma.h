#ifndef OMN_PRAGMA_H
#define OMN_PRAGMA_H
#ifdef HKS_NT

// We define default values for the following macros the convenience
// of building AFC (Abaqus For Catia). The values are overridden in
// the config files.

#ifndef WARNING_IGNORE
#define WARNING_IGNORE 4355 4786
#endif

#ifndef WARNING_ERROR
#define WARNING_ERROR 4530 4706
#endif

#pragma warning( disable : WARNING_IGNORE; error : WARNING_ERROR )

#endif // HKS_NT
#endif // OMN_PRAGMA_H
