////////////////////////////////////////////////////////////////////////////////
//
// Class       :  odb_SequenceElementDiagnostic
//
// Description :  A sequence of odb_ElementDiagnostic objects
//
////////////////////////////////////////////////////////////////////////////////

#ifndef odb_SequenceElementDiagnostic_h
#define odb_SequenceElementDiagnostic_h


// Begin local includes
#include <mem_AllocationOperators.h>
#include <cow_ArrayCOW.h>
#include <cls_ListObj.h>
// End local includes

// Forward Declarations
class odb_ElementDiagnostic;
class dia_ElementDiagnostic;
COW_ARRAYCOW_DECL(dia_ElementDiagnostic);
CLS_LISTOBJ_DECL(dia_ElementDiagnostic, dia_ElementDiagnosticList);


class odb_SequenceElementDiagnostic : public mem_AllocationOperators
{
public:
   // Returns the number of odb_ElementDiagnostic objects contained in
   // the sequence
   int size() const;

   // Returns an odb_ElementDiagnostic object by zero-based index. If 
   // the index is out of bounds then an exception of type odb_Exception 
   // will be thrown.  
   odb_ElementDiagnostic get(int index) const;
   odb_ElementDiagnostic operator[](int index) const;

private:
   dia_ElementDiagnosticList m_list;

public: 
   // Unsupported
   odb_SequenceElementDiagnostic();
   odb_SequenceElementDiagnostic(const dia_ElementDiagnosticList& list);
   odb_SequenceElementDiagnostic(const odb_SequenceElementDiagnostic& sequence);
};


#endif
