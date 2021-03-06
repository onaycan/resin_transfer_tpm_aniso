#ifndef kbeC_ConnectorOptionsShortcut_h
#define kbeC_ConnectorOptionsShortcut_h

// Begin local includes
#include <ddr_Shortcut.h>
#include <kbeC_ConnectorOptions.h>
#include <kbeC_CDCTerm.h>
//#include <kseC_ConnectorSection.h>

// Forward declarations
class kbeC_ConnectorBehaviorOption;

ddr_SHORTCUT_DECL(kbeC_ConnectorOptions, kbeC_ConnectorOptionsShortcut);

ddr_MEMBER_SHORTCUT_DECL(kbeC_ConnectorBehaviorOption, kbeC_ConnectorOptions, kbeC_ConnectorOptionsInConnectorBehaviorOptionShortcut);
ddr_MEMBER_SHORTCUT_DECL_ADD(kbeC_ConnectorBehaviorOption, kbeC_ConnectorOptions, 2, kbeC_InitiationOptionsInConnectorBehaviorOptionShortcut);
ddr_MEMBER_SHORTCUT_DECL_ADD(kbeC_ConnectorBehaviorOption, kbeC_ConnectorOptions, 3, kbeC_EvolutionOptionsInConnectorBehaviorOptionShortcut);
ddr_MEMBER_SHORTCUT_DECL_ADD(kbeC_ConnectorBehaviorOption, kbeC_ConnectorOptions, 4, kbeC_IsotropicOptionsInConnectorBehaviorOptionShortcut);
ddr_MEMBER_SHORTCUT_DECL_ADD(kbeC_ConnectorBehaviorOption, kbeC_ConnectorOptions, 5, kbeC_KinematicOptionsInConnectorBehaviorOptionShortcut);

ddr_MEMBER_SHORTCUT_DECL(kbeC_CDCTerm, kbeC_ConnectorOptions, kbeC_ConnectorOptionsInCDCTermShortcut);
//ddr_MEMBER_SHORTCUT_DECL(kseC_ConnectorSection, kbeC_ConnectorOptions, kbeC_ConnectorOptionsInSectionShortcut);

#endif
