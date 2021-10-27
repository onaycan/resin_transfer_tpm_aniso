/* _*_ mode: c++ _*_ */
#ifndef inpO_AmplitudeVisitor_h
#define inpO_AmplitudeVisitor_h

//////////////////////////////////////////////////////////////////////
//
// Name: inpO_AmplitudeVisitor
// Description: Write amplitudes to ODB using the ODB API
// Author: Sivakumar Bhaskarapanditha

// Begin local includes
#include <inpO_Visitor.h>
#include <cow_ArrayCOW.h>
#include <odb_String.h>

#include <kamO_ApiExtension.h>
// Forward declarations
class inp_Keyword;
template < class A > class cow_List;
typedef cow_List< inp_Keyword > inp_KeywordList;
class odb_SequenceDouble;
class odb_SequenceSequenceDouble;
class odb_Odb;

COW_ARRAYCOW2_DECL(odb_Amplitude, cow_Virtual);

// Class definition

class inpO_AmplitudeVisitor: public inpO_Visitor{

public:

    inpO_AmplitudeVisitor(odb_Odb& odb, inpO_ModelInventory& modelInv);
    void CreateAmplitudesInOdb( inp_KeywordList& kwList );
    virtual ~inpO_AmplitudeVisitor();

protected: // methods
    virtual void DefaultAction(inp_Keyword & ); // Do nothing

protected: // Data
    odb_Odb& m_odb;
    kamO_ApiExtension m_amplitudeApi;
    odb_AmplitudeCOW m_amplitudeCOW;
    odb_String m_analysisType;
private: // Methods

    virtual void VisitAmplitude(inp_Keyword& );
    virtual void VisitBaselineCorrection(inp_Keyword& );

    //utility methods

    odb_SequenceSequenceDouble AmplitudeTable(inp_DataArray & data, int beginRow=0);
    odb_SequenceDouble AmplitudeTable1D(inp_DataArray & data, int beginRow);

};
#endif // inpO_AmplitudeVisitor_h
