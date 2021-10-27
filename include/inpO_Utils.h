/*   -*- mode: c++ -*-   */
#ifndef inpO_Utils_h
#define inpO_Utils_h

///////////////////////////////////////////////////////////////////////////////
//
// File Name: inpO_Utils.h
//
// Description:  utility functions for the converter
//

// Includes

// Begin local includes

// Forward definitions
class odb_String;
class inp_Keyword;
template < class A > class cow_List;
typedef cow_List< inp_Keyword > inp_KeywordList;
class odb_SequenceDouble;
class odb_SequenceSequenceDouble;

// Class definition

struct inpO_Utils
{
    static bool CheckTemperatureDependency( const inp_Keyword & keyword,
                                            const int& nbasic,
                                            const int& beginLine = 0 );
    static odb_SequenceSequenceDouble TableProperty( const inp_Keyword & keyword,
                                                    const int& nbasic, 
                                                    int& numDep, 
                                                    bool& tempDep,
                                                    const bool& hasTempDep = true,
                                                    int numDefaultCols = 0,
                                                    const int* defaultCols = 0,
                                                    const double* defaultVals = 0,
                                                    const int& beginLine = 0 );

    static odb_String GetAnalysisType( inp_KeywordList& kwList );

};

#endif /* inpO_Utils_h */
