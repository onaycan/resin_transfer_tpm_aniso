/* -*- mode: c++ -*- */
///////////////////////////////////////////////////////////////////////////////
//
// File Name: ptoC_PartAttribute.h
// 
// Description:
//
//   A ptoC_PartAttribute is a base class for attributes residing on a part
//


#ifndef ptoC_PartAttribute_h
#define ptoC_PartAttribute_h

//
// Includes
//

// Begin local includes
#include <mem_AllocationOperators.h>

#include <typ_typeTag.h>

#include <cow_ArrayCOW.h>
#include <cow_List.h>

#include <cow_String.h>

#include <cls_Uid.h>
#include <cls_IntCOW.h>
#include <cls_xc1DArrayList.h>

// Forward declarations

class rgnC_Region;

class cls_ReadVisitor;
class cls_WriteVisitor;
class cls_ClassRegistrar;

class ptoC_PartAttribute  : public mem_AllocationOperators
{

public:

    ptoC_PartAttribute();
    virtual ~ptoC_PartAttribute();

    virtual ptoC_PartAttribute* Copy() const=0;
    virtual rgnC_Region& RegionRef()=0; 
    virtual const rgnC_Region& RegionRef() const=0; 
    virtual bool IsSuppressed() const=0;

    // if reinf attribute, then it wont be involved in overlap calculations
    bool IsReinforcement()const{return isReinforcement;}  
    bool& IsReinforcement(){return isReinforcement;}  

    // Messaging/database interface

    virtual typ_typeTag     DynTypeId() const;
    static typ_typeTag      TypeId();

    static void* Ctor( cls_ReadVisitor& rv );
    ptoC_PartAttribute( const cls_ReadVisitor& rv );
    virtual void DBWrite( const cls_WriteVisitor& wv ) const;
    static void InitializeMetadata( cls_ClassRegistrar& reg );
    static void CowDtor( cls_IntCOW* cow );
    
protected:
    bool isReinforcement;

private:
    cls_Uid m_ClsUid;
};

COW_ARRAYCOW2_DECL(ptoC_PartAttribute, cow_Virtual);
CLS_xc1DARRAYLIST_DECL(ptoC_PartAttributeCOW, ptoC_PartAttribute, ptoC_PartAttributeArrayImpl);


// Abstract class: do not instantiate


#endif 




