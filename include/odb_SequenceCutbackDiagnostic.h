/* -*- mode: c++ -*- */
#ifndef odb_SequenceCutbackDiagnostic_h
#define odb_SequenceCutbackDiagnostic_h


// Begin local includes
#include <mem_AllocationOperators.h>
#include <odb_DiagnosticAttempt.h>
// End local includes

////////////////////////////////////////////////////////////////////////////////
// Sequence of cutback diagnostic enums.

class odb_SequenceCutbackDiagnostic : public mem_AllocationOperators
{
public:
   // Returns the number of cutback diagnostics in the sequence
   int size() const;

   // Returns an dia_CutbackDiagnosticEnum by zero-based index. 
   // If the index is out of bounds then an exception of type odb_Exception 
   // will be thrown.  
   dia_CutbackDiagnosticOdbEnum get(int index) const;
   dia_CutbackDiagnosticOdbEnum operator[](int index) const;

private:
   odb_DiagnosticAttempt m_attempt;

public: 
   // Unsupported
   odb_SequenceCutbackDiagnostic(const odb_DiagnosticAttempt& attempt);
   odb_SequenceCutbackDiagnostic(const odb_SequenceCutbackDiagnostic& sequence);
};


#endif
