////////////////////////////////////////////////////////////////////////////////
//
// Class       :  odb_SequenceContactDiagnostic
//
// Description :  A sequence of odb_ContactDiagnostic objects
//
////////////////////////////////////////////////////////////////////////////////

#ifndef odb_SequenceContactDiagnostic_h
#define odb_SequenceContactDiagnostic_h


// Begin local includes
#include <mem_AllocationOperators.h>
#include <cow_ArrayCOW.h>
#include <cls_ListObj.h>
// End local includes

// Forward Declarations
class odb_ContactDiagnostic;
class dia_ContactDiagnostic;
COW_ARRAYCOW_DECL(dia_ContactDiagnostic);
CLS_LISTOBJ_DECL(dia_ContactDiagnostic, dia_ContactDiagnosticList);


class odb_SequenceContactDiagnostic : public mem_AllocationOperators
{
public:
   // Returns the number of odb_ContactDiagnostic objects contained in
   // the sequence
   int size() const;

   // Returns an odb_ContactDiagnostic object by zero-based index. If 
   // the index is out of bounds then an exception of type odb_Exception 
   // will be thrown.  
   odb_ContactDiagnostic get(int index) const;
   odb_ContactDiagnostic operator[](int index) const;

private:
   dia_ContactDiagnosticList m_list;

public: 
   // Unsupported
   odb_SequenceContactDiagnostic();
   odb_SequenceContactDiagnostic(const dia_ContactDiagnosticList& list);
   odb_SequenceContactDiagnostic(const odb_SequenceContactDiagnostic& sequence);
};


#endif
