#ifndef odiK_ElemCtrlParamsShortcut_h
#define odiK_ElemCtrlParamsShortcut_h

// Begin local includes
#include <ddr_Shortcut.h>

// Forward declarations
class odiK_ElementClass;
class bme_ElemCtrlParams;

ddr_SHORTCUT_DECL(bme_ElemCtrlParams, odiK_ElemCtrlParamsShortcut);
ddr_MEMBER_SHORTCUT_DECL(odiK_ElementClass, bme_ElemCtrlParams, odiK_ElemCtrlParamsInElementClassShortcut);

#endif
