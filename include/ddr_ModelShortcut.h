#ifndef ddr_ModelShortcut_h
#define ddr_ModelShortcut_h

// Begin local includes
#include <ddr_Shortcut.h>
#include <ddr_ModelContainer.h>

// Forward declarations
class ddr_Model;

ddr_SHORTCUT_DECL(ddr_Model, ddr_ModelShortcut);
ddr_DICTIONARY_SHORTCUT_DECL(ddr_ModelContainer, ddr_Model, ddr_ModelInModelContainerShortcut);

#endif
