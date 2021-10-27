#ifndef odb_TypeTable_h
#define odb_TypeTable_h

// Begin local includes
#include <typ_TypeTables.h>
#include <typ_Architecture.h>
#include <odb_FacilityTag.h>

extern typ_ArchCompEntry odb_ArchEntry();


#define TYP_TIX_odb_Exception ((TYP_FAC_odb << 16 ) | 0x1)
#define TYP_TIX_odb_ApiExtension  ((TYP_FAC_odb << 16) | 0x2)
#define TYP_TIX_odb_Section  ((TYP_FAC_odb << 16) | 0x3)

#endif
