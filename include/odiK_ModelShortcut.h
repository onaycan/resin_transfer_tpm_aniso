#ifndef odiK_ModelShortcut_h
#define odiK_ModelShortcut_h

// Begin local includes
#include <ddr_Shortcut.h>
#include <ddr_ModelContainer.h>

// Forward declarations
class odiK_Model;
class odiK_Assembly;

ddr_SHORTCUT_DECL(odiK_Model, odiK_ModelShortcut);
ddr_DICTIONARY_SHORTCUT_DECL(ddr_ModelContainer, odiK_Model, odiK_ModelInModelContainerShortcut);
ddr_MEMBER_SHORTCUT_DECL(odiK_Assembly, odiK_Model, odiK_ModelInAssemblyShortcut);

#endif
