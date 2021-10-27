/* -*- mode: c++ -*- */
#ifndef inpO_ConnectorDerivedComponent_h
#define inpO_ConnectorDerivedComponent_h

////////////////////////////////////////////////////////////////////////
//
//  Name: inpO_ConnectorDerivedComponent
//
//  Description: Wrapper class to hold connector derived component  
//  data in input file  

// Forward declaration
class inpO_ConnectorSectionVisitor;
class inp_Keyword;

//
// Begin local includes
#include <mem_AllocationOperators.h>
//

#include <odb_String.h>
#include <cow_Map.h>
#include <odb_Types.h>
#include <odb_ConnBehaviorTypes.h>

class inpO_ConnectorDerivedComponent  : public mem_AllocationOperators
{
    // friend class inpO_ConnectorFriction;
    // friend class inpO_ConnectorSectionVisitor;
public:
    inpO_ConnectorDerivedComponent() {}
    static odb_CDCTerm CreateCDCTerm(const inp_Keyword& keyword);
    odb_SequenceCDCTerm cdcTerms;
private:
    // odb_SequenceCDCTerm cdcTerms;
};

COW_MAP_ITER_DECL(cow_String, inpO_ConnectorDerivedComponent, inpO_ConnectorDerivedComponentMap);


#endif // inpO_ConnectorDerivedComponent_h

