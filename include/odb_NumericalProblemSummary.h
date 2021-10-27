////////////////////////////////////////////////////////////////////////////////
//
// Class       :  odb_NumericalProblemSummary
//
// Description :  Class odb_NumericalProblemSummary represents a summary of 
//                numerical problem warnings. Numerical problems consist of 
//                negative eigenvalues, numerical singularities, and zero 
//                pivots. The summary includes the number of numerical 
//                problems that occurred during a given scope and flags 
//                indicating if any numerical problems occurred during a 
//                converged iteration (that was performed during the scope). 
//                A scope could be a step, an iteration, the whole job, etc.
//
////////////////////////////////////////////////////////////////////////////////


#ifndef odb_NumericalProblemSummary_h
#define odb_NumericalProblemSummary_h


////////////////////////////////////////////////////////////////////////////////

class odb_NumericalProblemSummary
{
public:
   // Number of negative eigenvalues
   int numberOfNegativeEigenvalues() const;

   // Number of numerical singularities
   int numberOfNumericalSingularities() const;

   // Number of zero pivots
   int numberOfZeroPivots() const;

   // True if negative eigenvalues occurred during a converged iteration
   bool convergedNegativeEigenvalues() const;

   // True if numerical singurlarities occurred during a converged iteration
   bool convergedNumericalSingularities() const;

   // True if zero pivots occurred during a converged iteration
   bool convergedZeroPivots() const;

   // Contructor
   odb_NumericalProblemSummary(int  numberOfNegativeEigenvalues,
                               int  numberOfNumericalSingularities,
                               int  numberOfZeroPivots,
                               bool convergedNegativeEigenvalues,
                               bool convergedNumericalSingularities,
                               bool convergedZeroPivots);
private:
   int  m_numberOfNegativeEigenvalues;
   int  m_numberOfNumericalSingularities;
   int  m_numberOfZeroPivots;
   bool m_convergedNegativeEigenvalues;
   bool m_convergedNumericalSingularities;
   bool m_convergedZeroPivots;
};


#endif
