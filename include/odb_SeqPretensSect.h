#ifndef odb_SequencePretensionSection_h
#define odb_SequencePretensionSection_h

// Begin local includes
#include <mem_AllocationOperators.h>
#include <odiK_PretensSectListShortcut.h>
#include <odb_PretensionSection.h>
// Forward declarations
class odiK_Model;
typedef ddr_Shortcut <odiK_Model> odiK_ModelShortcut;

class odb_SequencePretensionSection : public mem_AllocationOperators
{
public:
    ~odb_SequencePretensionSection();
    
    odb_PretensionSection constGet( int index ) const;
    odb_PretensionSection operator[]( int index ) const;
    int size() const;

    // Undocumented and unsupported
    odb_SequencePretensionSection( const odiK_PretensionSectionListShortcut& rsc,
                                   const odiK_ModelShortcut& msc );

private:
    odiK_PretensionSectionListShortcut m_shortcut;
    odiK_ModelShortcut m_modelShortcut;
};

#endif
