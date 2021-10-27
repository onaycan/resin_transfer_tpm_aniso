#ifndef kseC_TransverseShearBeamShortcut_h
#define kseC_TransverseShearBeamShortcut_h

// Begin local includes
#include <ddr_Shortcut.h>

// Forward declarations
class kseC_TransverseShearBeam;
class kseC_Section;

ddr_SHORTCUT_DECL(kseC_TransverseShearBeam, kseC_TransverseShearBeamShortcut);
ddr_MEMBER_SHORTCUT_DECL(kseC_Section, kseC_TransverseShearBeam, kseC_TransverseShearBeamInSectionShortcut);

#endif
