#ifndef rgnC_SetDataShortcut_h
#define rgnC_SetDataShortcut_h

// Begin local includes
#include <ddr_Shortcut.h>
#include <rgnC_SetDataList.h>

// Forward declarations
class rgnC_SetData;

#if defined(ABQ_LINUX) || defined(HP)
#if !defined(ABQ_LNXPWR)
// NOTE the DBWrite method in the base template is overwritten and thus this 
// specialization must be declared before the template is instantiated.
template <>
void ddr_ShortcutImpl<rgnC_SetData>::
                                    DBWrite(const cls_WriteVisitor& wv) const;
#endif
#endif

ddr_SHORTCUT_DECL(rgnC_SetData, rgnC_SetDataShortcut);
ddr_SEQUENCE_SHORTCUT_DECL(rgnC_SetDataList, rgnC_SetData, rgnC_SetDataInSetDataListShortcut);

#endif
