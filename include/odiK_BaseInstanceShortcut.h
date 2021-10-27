#ifndef odiK_BaseInstanceShortcut_h
#define odiK_BaseInstanceShortcut_h

// Begin local includes
#include <ddr_Shortcut.h>
#include <odiK_InstanceContainerFwd.h>

// Forward declarations
class odiK_BaseInstance;

ddr_SHORTCUT_DECL(odiK_BaseInstance, odiK_BaseInstanceShortcut);
ddr_DICTIONARY_SHORTCUT_DECL(odiK_InstanceContainer, odiK_BaseInstance, odiK_BaseInstanceInInstanceContainerShortcut);

#endif
