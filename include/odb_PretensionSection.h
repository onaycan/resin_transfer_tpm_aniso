#ifndef odb_PretensionSection_h
#define odb_PretensionSection_h

// Begin local includes
#include <mem_AllocationOperators.h>
#include <odiK_PretensSectShortcut.h>
#include <odb_Types.h>
// Forward declarations
class odb_Set;
class odiK_Model;
typedef ddr_Shortcut<odiK_Model> odiK_ModelShortcut;

class odb_PretensionSection : public mem_AllocationOperators
{
public:
    ~odb_PretensionSection();
    bool hasNormalData() const;
    odb_Set node() const;
    odb_Set element() const;
    odb_Set surface() const;
    bool hasElement() const;
    bool hasSurface() const;
    bool hasNormal() const;
    odb_SequenceDouble normal() const;
    // Undocumented and unsupported
    odb_PretensionSection( const odiK_PretensionSectionShortcut& ,
                           const odiK_ModelShortcut& );    
private:
    odiK_PretensionSectionShortcut m_shortcut;   
    odiK_ModelShortcut m_modelShortcut;
};

#endif // odb_PretensionSection_h
