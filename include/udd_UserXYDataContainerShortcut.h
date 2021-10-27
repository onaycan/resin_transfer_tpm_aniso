/* -*- mode: c++ -*- */
#ifndef udd_UserXYDataContainerShortcut_h
#define udd_UserXYDataContainerShortcut_h

// Begin local includes
#include <ddr_Shortcut.h>

// Forward declarations

class udd_UserData;
class udd_UserXYDataContainer;

ddr_SHORTCUT_DECL(udd_UserXYDataContainer, udd_UserXYDataContainerShortcut);
ddr_MEMBER_SHORTCUT_DECL(udd_UserData, udd_UserXYDataContainer, udd_UserXYDataContainerInUserDataShortcut);

#endif
