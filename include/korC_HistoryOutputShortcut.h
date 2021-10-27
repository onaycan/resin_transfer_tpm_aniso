#ifndef korC_HistoryOutputShortcut_h
#define korC_HistoryOutputShortcut_h

// Begin local includes
#include <ddr_Shortcut.h>
#include <korC_HistoryContainer.h>

// Forward declarations
class korC_HistoryOutput;

ddr_SHORTCUT_DECL(korC_HistoryOutput, korC_HistoryOutputShortcut);
ddr_DICTIONARY_SHORTCUT_DECL(korC_HistoryContainer, korC_HistoryOutput, korC_HistoryOutputInHistoryContainerShortcut);

#endif
