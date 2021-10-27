#ifndef ptoC_PartAttributeShortcut_h
#define ptoC_PartAttributeShortcut_h

// Begin local includes
#include <ddr_Shortcut.h>

// Forward declarations
class ptoC_PartAttributeList;
class ptoC_PartAttribute;

ddr_SHORTCUT_DECL(ptoC_PartAttribute, ptoC_PartAttributeShortcut);
ddr_SEQUENCE_SHORTCUT_DECL(ptoC_PartAttributeList, ptoC_PartAttribute, ptoC_PartAttributeInPartAttributeListShortcut);

#endif
