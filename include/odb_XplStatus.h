////////////////////////////////////////////////////////////////////////////////
//
// Class       :  odb_XplStatus
//
// Description :  Class odb_XplStatus 
//                See source code comments at the top of odb_DiagnosticBase.h
//                for more details.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef odb_XplStatus_h
#define odb_XplStatus_h

// Begin local includes
#include <mem_AllocationOperators.h>
#include <cow_ArrayCOW.h>
#include <cow_String.h>
#include <odb_Types.h>
// End local includes

// Forward declarations
class dia_XplStatus;
class odb_String;
COW_ARRAYCOW_DECL(dia_XplStatus)

////////////////////////////////////////////////////////////////////////////////

class odb_XplStatus  : public mem_AllocationOperators
{
public:
   int GetIncrementNumber() const;
   int GetCriticalElementLabel() const;
   odb_String GetCriticalElementInst() const;
   odb_SequenceDouble  GetXplStatusRealv() const;

protected:

private:
   dia_XplStatusCOW m_XplStatus;

public:
   // Unsupported
   odb_XplStatus();
   odb_XplStatus(const dia_XplStatus& XplStatus);
   odb_XplStatus(const odb_XplStatus& XplStatus);

};

#endif
