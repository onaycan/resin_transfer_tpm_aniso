#ifndef kseC_LayerShortcut_h
#define kseC_LayerShortcut_h

// Begin local includes
#include <ddr_Shortcut.h>
#include <kseC_SectionLayerList.h>

// Forward declarations
class kseC_Layer;

ddr_SHORTCUT_DECL(kseC_Layer, kseC_LayerShortcut);
ddr_SEQUENCE_SHORTCUT_DECL(kseC_SectionLayerList, kseC_Layer, kseC_LayerInLayerListShortcut);

#endif
