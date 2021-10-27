#ifndef kbeO_SequenceConnectorBehaviorOption_h
#define kbeO_SequenceConnectorBehaviorOption_h

// Begin local includes
#include <mem_AllocationOperators.h>
#include <kbeO_ConnectorBehaviorOption.h>
#include <kbeC_ConnectorBehaviorOption.h>
#include <kbeC_BehaviorOptionList.h>
#include <cow_List.h>

// Forward declarations

// Low level list implementation

COW_LIST_DECL(kbeO_ConnectorBehaviorOptionCOW, kbeO_SequenceConnectorBehaviorOptionImpl);

ddr_SHORTCUT_DECL(kbeC_ConnectorBehaviorOptionList, kbeC_ConnectorBehaviorOptionListShortcut);
ddr_SEQUENCE_SHORTCUT_DECL(kbeC_ConnectorBehaviorOptionList, kbeC_ConnectorBehaviorOption, kbeC_ConnectorBehaviorOptionInConnectorBehaviorListShortcut);

class kbeO_SequenceConnectorBehaviorOption  : public mem_AllocationOperators
{
  public:
    
    kbeO_SequenceConnectorBehaviorOption();
   ~kbeO_SequenceConnectorBehaviorOption();
    
    kbeO_ConnectorBehaviorOption& get(int index);
    const kbeO_ConnectorBehaviorOption& constGet(int index) const;
    const kbeO_ConnectorBehaviorOption& operator[](int index) const;
    void append(const kbeO_ConnectorBehaviorOption& option);
    void append(const kbeO_SequenceConnectorBehaviorOption& optionSequence);
    int size() const;
    void clearAll();

    // Undocumented and unsupported
    kbeO_SequenceConnectorBehaviorOption(
	const kbeC_ConnectorBehaviorOptionListShortcut& sc);
    kbeO_SequenceConnectorBehaviorOption& operator=(
	const kbeO_SequenceConnectorBehaviorOption& rhs);
    kbeO_SequenceConnectorBehaviorOption(
	const kbeC_ConnectorBehaviorOptionList& l);
    kbeC_ConnectorBehaviorOptionListShortcut Shortcut() const { 
	return m_shortcut; 
    }
    const kbeO_ConnectorBehaviorOption& GetByReference(int index) const;
    
  private:

    bool m_standalone;
    mutable kbeO_SequenceConnectorBehaviorOptionImpl m_array;
    kbeC_ConnectorBehaviorOptionListShortcut m_shortcut;
};

#endif
