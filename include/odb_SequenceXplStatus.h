////////////////////////////////////////////////////////////////////////////////
//
// Class       :  odb_SequenceXplStatus
//
// Description :  A sequence of odb_XplStatus objects
//
////////////////////////////////////////////////////////////////////////////////

#ifndef odb_SequenceXplStatus_h
#define odb_SequenceXplStatus_h


// Begin local includes
#include <mem_AllocationOperators.h>
#include <cow_ArrayCOW.h>
#include <cls_ListObj.h>
// End local includes

// Forward Declarations
class odb_XplStatus;
class dia_XplStatus;
COW_ARRAYCOW_DECL(dia_XplStatus);
CLS_LISTOBJ_DECL(dia_XplStatus, dia_XplStatusList);


class odb_SequenceXplStatus  : public mem_AllocationOperators
{
public:
   // Returns the number of odb_XplStatus objects contained in
   // the sequence
   int size() const;

   // Returns an odb_XplStatus object by zero-based index. If 
   // the index is out of bounds then an exception of type odb_Exception 
   // will be thrown.  
   odb_XplStatus get(int index) const;
   odb_XplStatus operator[](int index) const;

private:
   dia_XplStatusList m_list;

public: 
   // Unsupported
   odb_SequenceXplStatus();
   odb_SequenceXplStatus(const dia_XplStatusList& list);
   odb_SequenceXplStatus(const odb_SequenceXplStatus& sequence);
};


#endif
