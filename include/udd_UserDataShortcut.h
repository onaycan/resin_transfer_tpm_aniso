/* -*- Mode: c++ -*- */
#ifndef udd_UserDataShortcut_h
#define udd_UserDataShortcut_h

// Begin local includes
#include <ddr_Shortcut.h>
#include <ddr_UserDataContainerFwd.h>

// Forward declarations
class udd_UserData;

// Shortcut

ddr_SHORTCUT_DECL(udd_UserData, udd_UserDataShortcut);
ddr_DICTIONARY_SHORTCUT_DECL(ddr_UserDataContainer, udd_UserData, udd_UserDataInUserDataContainerShortcut);

#endif
