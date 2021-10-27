/* -*- mode: c++ -*- */
#ifndef inpO_FilterVisitor_h
#define inpO_FilterVisitor_h

////////////////////////////////////////////////////////////////////////
//
//  Name: inpK_DdbFilter
//
//  Description: Write filter data to DDB
//

// Begin local includes

#include <inp_Visitor.h>

//Forward Definitions
class inp_Keyword;
template < class A > class cow_List;
typedef cow_List< inp_Keyword > inp_KeywordList;
class odb_Odb;
class kflO_ApiExtension;
// Class definitions

class inpO_FilterVisitor: public inp_Visitor
{
public:
    inpO_FilterVisitor( odb_Odb& odb, 
                           kflO_ApiExtension& filterApi);    
    virtual ~inpO_FilterVisitor();
    void CreateFiltersInOdb(inp_KeywordList& kwList );

protected: 

    virtual void DefaultAction( inp_Keyword& ); // Do nothing 
   
    odb_Odb& _odb;
    kflO_ApiExtension& _filterApi;

private: // Methods
    virtual void VisitFilter( inp_Keyword& );
};

#endif // inpO_FilterVisitor_h
