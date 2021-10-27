#ifndef odiK_AssemblyShortcut_h
#define odiK_AssemblyShortcut_h

// Begin local includes
#include <ddr_Shortcut.h>
#include <odiK_AssemblyContainerFwd.h>

// Forward declarations
class odiK_Assembly;

ddr_SHORTCUT_DECL(odiK_Assembly, odiK_AssemblyShortcut);
ddr_DICTIONARY_SHORTCUT_DECL(odiK_AssemblyContainer, odiK_Assembly, odiK_AssemblyInAssemblyContainerShortcut);

#endif
