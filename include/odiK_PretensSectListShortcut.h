#ifndef odiK_PretensionSectionListShortcut_h
#define odiK_PretensionSectionListShortcut_h

// Begin local includes
#include <ddr_Shortcut.h>
#include <odiK_PretensSectList.h>
// Forward declarations
class odiK_Assembly;

ddr_SHORTCUT_DECL(odiK_PretensionSectionList, odiK_PretensionSectionListShortcut);
ddr_MEMBER_SHORTCUT_DECL(odiK_Assembly, odiK_PretensionSectionList, odiK_PretensionSectionListInAssemblyShortcut);

#endif
