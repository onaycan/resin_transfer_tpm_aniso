/*   -*- mode: c++ -*-   */
#ifndef inpO_KwdDataTable_h
#define inpO_KwdDataTable_h

///////////////////////////////////////////////////////////////////////////////
//
// Class: inpO_KwdDataTable
//
// Description:
//

// Includes

// Forward declarations
class inp_Keyword;

// Begin local includes
#include <mem_AllocationOperators.h>
#include <cow_ListInt.h>
#include <cow_ListDouble.h>

#include <odb_Types.h>


// Class definition

class inpO_KwdDataTable  : public mem_AllocationOperators
{
public:

   inpO_KwdDataTable();
   inpO_KwdDataTable(const inp_Keyword& keyword,
                     int  nbasic   = 0,
                     int  startRow = 0,
                     bool hasTempData = true);
   ~inpO_KwdDataTable();

   void Read(int startCol = 0);
   void ReadValidData(int startCol = 0);  // throw
   void Initialize(const inp_Keyword& keyword,
                   int nbasic = 0,
                   int startRow = 0,
                   bool hasTempData = true);

   const odb_SequenceSequenceDouble& Table() const;

   int  Dependencies() const;
   bool TempDependent() const;

   bool Empty() const;
   void ClearAll();

   void AssertValid() const;
   bool IsDependentOnColumn(int) const;

   void RemoveColumn(int);
   void RemoveTempColumnIfIndependent();

   void SetDefaultData(const cow_ListInt&, const cow_ListDouble&);
   void SetDefaultData(const int* defCols, const double* defVals, int arrLength);
   void AllowEmptyFirstRow(bool flag = true);

   void Print(cow_String header = "") const;

private:

   void AppendDefaultValues(odb_SequenceDouble& dataRow, 
                            int numMissingEntries,
                            double defaultValue = 0.0) const;
   bool IsTempDependent() const;

   // data members
   bool m_hasTempData;
   bool m_tempDependent;
   bool m_allowEmptyFirstRow;

   int m_nbasic;      // number of entries for data without temperature
   int m_startRow;

   int m_currentRow;
   int m_numCols;
   int m_numDependencies;

   const inp_Keyword*        m_keyword;
   odb_SequenceSequenceDouble m_table;

   cow_ListInt    m_defaultDataCols;
   cow_ListDouble m_defaultDataVals;
};


//---------------------------------------------------------------------------->
inline const odb_SequenceSequenceDouble&
inpO_KwdDataTable::Table() const
//---------------------------------------------------------------------------->
{
   return m_table;
}

//---------------------------------------------------------------------------->
inline int
inpO_KwdDataTable::Dependencies() const
//---------------------------------------------------------------------------->
{
   return m_numDependencies;
}

//---------------------------------------------------------------------------->
inline bool
inpO_KwdDataTable::TempDependent() const
//---------------------------------------------------------------------------->
{
   return m_tempDependent;
}

//---------------------------------------------------------------------------->
inline bool
inpO_KwdDataTable::Empty() const
//---------------------------------------------------------------------------->
{
   return (m_table.Length() == 0);
}

//---------------------------------------------------------------------------->
inline void
inpO_KwdDataTable::AllowEmptyFirstRow(bool flag)
//---------------------------------------------------------------------------->
{
   m_allowEmptyFirstRow = flag;
}

//---------------------------------------------------------------------------->
inline void
inpO_KwdDataTable::ReadValidData(int startCol)
//---------------------------------------------------------------------------->
{
   Read(startCol);
   RemoveTempColumnIfIndependent();
   // AssertValid();
}



#endif /* inpO_KwdDataTable_h */
