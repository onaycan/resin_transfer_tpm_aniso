#ifndef korC_FieldOutputShortcut_h
#define korC_FieldOutputShortcut_h

// Begin local includes
#include <ddr_Shortcut.h>
#include <korC_FieldContainer.h>

// Forward declarations
class korC_FieldOutput;

ddr_SHORTCUT_DECL(korC_FieldOutput, korC_FieldOutputShortcut);
ddr_DICTIONARY_SHORTCUT_DECL(korC_FieldContainer, korC_FieldOutput, korC_FieldOutputInFieldContainerShortcut);

#endif
