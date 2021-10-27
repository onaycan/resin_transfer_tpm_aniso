#ifndef kcoC_ConstraintShortcut_h
#define kcoC_ConstraintShortcut_h

// Begin local includes
#include <ddr_Shortcut.h>
#include <kcoC_ConstraintContainer.h>

// Forward declarations
class kcoC_Constraint;

ddr_SHORTCUT_DECL(kcoC_Constraint, kcoC_ConstraintShortcut);
ddr_DICTIONARY_SHORTCUT_DECL(kcoC_ConstraintContainer, kcoC_Constraint, kcoC_ConstraintInConstraintContainerShortcut);

#endif
