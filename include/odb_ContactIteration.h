////////////////////////////////////////////////////////////////////////////////
//
// Class       :  odb_ContactIteration
//
// Description :  Class odb_ContactIteration represents a single contact
//                iteration. Contact iterations are "sub-iterations" that
//                are performed within the context of global Newton
//                iterations. Within the context of a global iteration
//                contact iterations are numbered consecutively starting
//                from one. 
//
//                Contact iteration objects serve as a container for the
//                various types of diagnostic that are issued during the
//                course of a contact iteration.
//
////////////////////////////////////////////////////////////////////////////////


#ifndef odb_ContactIteration_h
#define odb_ContactIteration_h


// Begin local includes
#include <mem_AllocationOperators.h>
#include <odb_Types.h>
#include <cow_ArrayCOW.h>
// End local includes

// Forward declarations
class dia_ContactIteration;
class odb_ContactDiagnostic;
class odb_SequenceContactDiagnostic;
COW_ARRAYCOW_DECL(dia_ContactIteration)


////////////////////////////////////////////////////////////////////////////////

class odb_ContactIteration  : public mem_AllocationOperators
{
public:
   // ------------------------------------------
   // Iteration identification

   // Iteration number. Contact iterations are numbered consecutively
   // starting from one within the context of a given global iteration.
   int number() const;

   // ------------------------------------------
   // Convergence

   // True if the contact iteration is converged.
   bool isConverged() const;

   // -------------------------------------------
   // Contact diagnostics

   // Number of contact diagnostics associated with the iteration.
   int numberOfContactDiagnostics() const;

   // Access contact diagnostic by zero-based index. If the index
   // is out of bounds then an exception of type odb_Exception
   // will be thrown.
   odb_ContactDiagnostic getContactDiagnostic(int i) const;

   // Sequence of odb_ContactDiagnostic objects
   odb_SequenceContactDiagnostic contactDiagnostics() const;

private:
   dia_ContactIterationCOW m_iteration;

public:
   // Unsupported
   odb_ContactIteration(const dia_ContactIteration& iteration);
   odb_ContactIteration(const odb_ContactIteration& iteration);
};

#endif
