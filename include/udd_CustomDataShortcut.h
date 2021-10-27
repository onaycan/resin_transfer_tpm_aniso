/* -*- Mode: c++ -*- */
#ifndef udd_CustomDataShortcut_h
#define udd_CustomDataShortcut_h

// Begin local includes
#include <ddr_Shortcut.h>
#include <ddr_CustomDataContainerFwd.h>

// Forward declarations
class udd_CustomData;

// Shortcut

ddr_SHORTCUT_DECL(udd_CustomData, udd_CustomDataShortcut);
ddr_DICTIONARY_SHORTCUT_DECL(ddr_CustomDataContainer, udd_CustomData, udd_CustomDataInCustomDataContainerShortcut);

#endif
