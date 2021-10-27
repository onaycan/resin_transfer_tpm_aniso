/* -*- mode: c++ -*- */
#ifndef odb_SequenceContactIteration_h
#define odb_SequenceContactIteration_h


// Begin local includes
#include <mem_AllocationOperators.h>
#include <odb_DiagnosticIteration.h>
// End local includes

// Forward Declarations
class odb_ContactIteration;


class odb_SequenceContactIteration : public mem_AllocationOperators
{
public:
   // Returns the number of odb_ContctIteration objects contained in
   // the sequence
   int size() const;

   // Returns an odb_ContactIteration object by zero-based index. If
   // the index is out of bounds then an exception of type odb_Exception 
   // will be thrown.  
   odb_ContactIteration get(int index) const;
   odb_ContactIteration operator[](int index) const;

private:
   odb_DiagnosticIteration m_iteration;

public: 
   // Unsupported
   odb_SequenceContactIteration(const odb_DiagnosticIteration& iteration);
   odb_SequenceContactIteration(const odb_SequenceContactIteration& sequence);
};


#endif
