#ifndef kbeC_CDCTermListShortcut_h
#define kbeC_CDCTermListShortcut_h

// Begin local includes
#include <ddr_Shortcut.h>
#include <kbeC_CDCTermList.h>

// Forward declarations
class kbeC_DerivedComponent;

ddr_SHORTCUT_DECL(kbeC_CDCTermList, kbeC_CDCTermListShortcut);
ddr_MEMBER_SHORTCUT_DECL(kbeC_DerivedComponent, kbeC_CDCTermList, kbeC_CdcTermsListInDerivedComponentShortcut);

#endif
