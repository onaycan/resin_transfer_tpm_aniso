#ifndef kmaC_MaterialShortcut_h
#define kmaC_MaterialShortcut_h

// Begin local includes
#include <ddr_Shortcut.h>
// Forward declarations
class kmaC_Material;

template <class A> class mdl_MapString2ObjCow;
typedef class mdl_MapString2ObjCow<kmaC_Material> kmaC_MaterialContainer;

ddr_SHORTCUT_DECL(kmaC_Material, kmaC_MaterialShortcut);
ddr_DICTIONARY_SHORTCUT_DECL(kmaC_MaterialContainer, kmaC_Material, kmaC_MaterialInMaterialContainerShortcut);

#endif
