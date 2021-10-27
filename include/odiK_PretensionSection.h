/* -*- mode: c++ -*- */
///////////////////////////////////////////////////////////////////////////////
//
// File Name: odiK_PretensionSection.h
//
// Description:
//

#ifndef odiK_PretensionSection_h
#define odiK_PretensionSection_h

// Begin Local includes
#include <mem_AllocationOperators.h>
#include <rgnC_Region.h>
#include <cls_xp1DArrayListDouble.h>

class odiK_PretensionSection : public mem_AllocationOperators
{
public:
    odiK_PretensionSection();
    void AssertValid() const;//consistency check
    ~odiK_PretensionSection();
    odiK_PretensionSection* Copy() const;
    // ODB database interface
    odiK_PretensionSection(const cls_ReadVisitor& rv);
    static void CowDtor(cls_IntCOW* cow);
    static void InitializeMetadata(cls_ClassRegistrar& reg);
    virtual void DBWrite(const cls_WriteVisitor& wv) const;

    virtual typ_typeTag DynTypeId() const;
    static typ_typeTag TypeId();

    // Data members
    rgnC_Region node;
    rgnC_Region element;
    rgnC_Region surface;
    cls_xp1DArrayListDouble normal;
private:

    cls_Uid m_ClsUid;
};

COW_COW_DECL(odiK_PretensionSection);

#endif // #ifndef odiK_PretensionSection_h
