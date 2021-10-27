#ifndef odb_ApiExtension_h
#define odb_ApiExtension_h

// Begin local includes
#include <mem_AllocationOperators.h>
#include <ddr_ModelShortcut.h>
#include <cow_Btree.h>
#include <cow_BtreeCompare.h>
#include <odb_String.h>
#include <odb_Enum.h>

class odb_ApiExtension  : public mem_AllocationOperators
{
public:
    odb_ApiExtension();
    virtual ~odb_ApiExtension();

    void SetModelShortcut( const ddr_ModelShortcut& sc ) { shortcut = sc; }
    const ddr_ModelShortcut& GetModelShortcut() const { return shortcut; }
    
    virtual void ConstructContainer() {};

    static typ_typeTag TypeId();
    virtual typ_typeTag DynTypeId() const;

protected:
    ddr_ModelShortcut shortcut;
};

COW_BTREE_DECL( odb_ApiTypeEnm, odb_ApiExtension, odb_ApiExtensionRepository );

COW_COW_DECL( odb_ApiExtensionRepository );

inline int BtreeCompare( const odb_ApiTypeEnm& key1, const odb_ApiTypeEnm& key2 )
{
    return static_cast<unsigned int>(key2) - static_cast<unsigned int>(key1);
}

#endif
