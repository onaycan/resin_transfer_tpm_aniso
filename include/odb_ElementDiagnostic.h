////////////////////////////////////////////////////////////////////////////////
//
// Class       :  odb_ElementDiagnostic
//
// Description :  Class odb_ElementDiagnostic represents all of the different 
//                types of element diagnostic that are issued by ABAQUS. 
//
//                The type of element diagnostic is indicated by an enum and
//                interpretation of the auxiliary data depends on the type. 
//
//                See source code comments at the top of odb_DiagnosticBase.h
//                for more details.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef odb_ElementDiagnostic_h
#define odb_ElementDiagnostic_h

// Begin local includes
#include <odb_DiagnosticBase.h>
#include <cow_ArrayCOW.h>
// End local includes

// Forward declarations
struct dia_ElementDiagnosticTypeOdbEnum;
class dia_ElementDiagnostic;
class odb_String;
COW_ARRAYCOW_DECL(dia_ElementDiagnostic)

////////////////////////////////////////////////////////////////////////////////

class odb_ElementDiagnostic : public odb_DiagnosticBase
{
public:

   // Symbolic constant indicating the type of element diagnostic
   dia_ElementDiagnosticTypeOdbEnum type() const;

protected:
   // Must implement this...
   virtual dia_MetadataTable& getMetadata() const;

private:
   dia_ElementDiagnosticCOW m_diagnostic;

public:
   // Unsupported
   odb_ElementDiagnostic(const dia_ElementDiagnostic& diagnostic);
   odb_ElementDiagnostic(const odb_ElementDiagnostic& diagnostic);
};


#endif
