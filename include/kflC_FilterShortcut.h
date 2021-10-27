#ifndef kflC_FilterShortcut_h
#define kflC_FilterShortcut_h

// Begin local includes
#include <ddr_Shortcut.h>
#include <kflC_FilterContainer.h>

// Forward declarations
class kflC_Filter;

ddr_SHORTCUT_DECL(kflC_Filter,kflC_FilterShortcut);
ddr_DICTIONARY_SHORTCUT_DECL(kflC_FilterContainer, kflC_Filter, kflC_FilterInFilterContainerShortcut);

#endif
