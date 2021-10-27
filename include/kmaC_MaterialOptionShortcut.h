#ifndef kmaC_MaterialOptionShortcut_h
#define kmaC_MaterialOptionShortcut_h

// Begin local includes
#include <ddr_Shortcut.h>

// Forward declarations
class kmaC_Material;
class kmaC_MaterialOption;

ddr_SHORTCUT_DECL(kmaC_MaterialOption, kmaC_MaterialOptionShortcut);
ddr_DICTIONARY_SHORTCUT_DECL(kmaC_Material, kmaC_MaterialOption, kmaC_MaterialOptionInMaterialShortcut);
ddr_DICTIONARY_SHORTCUT_DECL(kmaC_MaterialOption, kmaC_MaterialOption, kmaC_MaterialOptionInMaterialOptionShortcut);

#endif
