/*   -*- mode: c++ -*-   */
#ifndef inpO_KeywordDataArrayReader_h
#define inpO_KeywordDataArrayReader_h

///////////////////////////////////////////////////////////////////////////////
//
// Class: inpO_KeywordDataArrayReader
//
// Description:
//

// Includes

// Forward declarations
class inp_DataArray;

// Begin local includes
#include <mem_AllocationOperators.h>
#include <cow_ListInt.h>
#include <cow_ListDouble.h>

#include <odb_Types.h>


// Class definition

class inpO_KeywordDataArrayReader  : public mem_AllocationOperators
{
public:

   inpO_KeywordDataArrayReader(const inp_DataArray& data,
                           int rowNum = 0,
                           int colNum = 0);
   ~inpO_KeywordDataArrayReader();

   int CurrentRowNum() const;
   int CurrentColNum() const;

   int NumRowsRead() const;

   odb_SequenceDouble ReadDoubleData(int numStartRow,
                                   int numStartCol,
                                   int minNumColsToRead, 
                                   int maxNumColsToReadint = 0);
   odb_SequenceDouble ReadDoubleDataInRow(int numStartRow,
                                        int numStartCol,
                                        int numColsToRead);

   void ReadDoublesInRow(int, int, double&);
   void ReadDoublesInRow(int, int, double&, double&);
   void ReadDoublesInRow(int, int, double&, double&, double&);
   void ReadDoublesInRow(int, int, double&, double&, double&, double&);
   void ReadDoublesInRow(int, int, double&, double&, double&, double&, 
                        double&);
   void ReadDoublesInRow(int, int, double&, double&, double&, double&, 
                        double&, double&);
   void ReadDoublesInRow(int, int, double&, double&, double&, double&, 
                        double&, double&, double&);
   void ReadDoublesInRow(int, int, double&, double&, double&, double&, 
                        double&, double&, double&, double&);
   void ReadDoublesInRow(int, int, double&, double&, double&, double&, 
                        double&, double&, double&, double&, double&);

   bool IsTheLastRow() const;
   void SetNominalDataRowLength(int length);
   void SetDefaultData(const cow_ListInt&, const cow_ListDouble&);
   void SetDefaultData(const int* defCols, const double* defVals, int arrLength);

private:

   int ReadDoubleDataRow(odb_SequenceDouble& dataArray, int, int, int, int);

   // data members
   const inp_DataArray& m_data;

   int m_currentRow;
   int m_startCol;
   int m_currentCol;
   int m_nominalDataLength;

   int m_numDataRows;
   int m_rowsRead;

   cow_ListInt    m_defaultDataCols;
   cow_ListDouble m_defaultDataVals;
};



//---------------------------------------------------------------------------->
inline int
inpO_KeywordDataArrayReader::CurrentRowNum() const
//---------------------------------------------------------------------------->
{
   return m_currentRow;
}

//---------------------------------------------------------------------------->
inline int
inpO_KeywordDataArrayReader::CurrentColNum() const
//---------------------------------------------------------------------------->
{
   return m_currentCol;
}

//---------------------------------------------------------------------------->
inline int
inpO_KeywordDataArrayReader::NumRowsRead() const
//---------------------------------------------------------------------------->
{
   return m_rowsRead;
}

//---------------------------------------------------------------------------->
inline bool
inpO_KeywordDataArrayReader::IsTheLastRow() const
//---------------------------------------------------------------------------->
{
   // the last is (m_currentRow == m_numDataRows -1) when indexing starts from 0
   return (! (m_currentRow < m_numDataRows - 1));
}

//---------------------------------------------------------------------------->
inline void
inpO_KeywordDataArrayReader::SetNominalDataRowLength(int length)
//---------------------------------------------------------------------------->
{
   m_nominalDataLength = length;
}



#endif /* inpO_KeywordDataArrayReader_h */
