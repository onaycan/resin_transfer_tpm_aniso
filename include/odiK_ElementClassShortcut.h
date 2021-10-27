#ifndef odiK_ElementClassShortcut_h
#define odiK_ElementClassShortcut_h

// Begin local includes
#include <ddr_Shortcut.h>
#include <bme_ElementClassList.h>

// Forward delcarations

class odiK_ElementClass;

ddr_SHORTCUT_DECL(odiK_ElementClass, odiK_ElementClassShortcut);
ddr_SEQUENCE_SHORTCUT_DECL(bme_ElementClassList, odiK_ElementClass, odiK_ElementClassInElementClassListShortcut);

#endif
