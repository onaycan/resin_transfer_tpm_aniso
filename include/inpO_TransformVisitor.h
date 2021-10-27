/*   -*- mode: c++ -*-   */
#ifndef inpO_TransformVisitor_h
#define inpO_TransformVisitor_h

///////////////////////////////////////////////////////////////////////////////
//
// Name: inpO_TransformVisitor
//
// Description: write transform definitions to the ODB
//

// Includes

// Forward declarations

// Begin local includes
#include <cow_String.h>
#include <inp_Visitor.h>
#include <inpO_KeywordParameterReader.h>
#include <odb_Types.h>
// Forward declarations
class odb_Odb;
class odb_Assembly;
// Class definition

class inpO_TransformVisitor: public inp_Visitor, 
                             protected inpO_KeywordParameterReader
{
public:

   inpO_TransformVisitor(odb_Odb& odb);
   virtual ~inpO_TransformVisitor();

   //

protected:
    virtual void VisitTransform(inp_Keyword&);
    virtual void DefaultAction( inp_Keyword& ); // Do nothing 
private:
    odb_Assembly& m_assembly;
};

#endif /* inpO_TransformVisitor_h */
