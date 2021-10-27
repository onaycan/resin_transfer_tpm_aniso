#ifndef kbeO_ConnectorOptions_h
#define kbeO_ConnectorOptions_h
///////////////////////////////////////////////////////////////////////////////
// kbeO_ConnectorOptions
//

// Begin local includes
#include <cow_ArrayCOW.h>
#include <odb_Types.h>
#include <mem_AllocationOperators.h>
#include <kbeC_ConnectorOptionsShortcut.h>
#include <odb_String.h>
// Forward declarations
class kbeC_ConnectorOptions;
typedef cow_CountedHld<kbeC_ConnectorOptions> kbeC_ConnectorOptionsHld;

class kbeO_ConnectorOptions: public mem_AllocationOperators
{
  public:
    kbeO_ConnectorOptions( const kbeC_ConnectorOptionsShortcut& shortcut );
    kbeO_ConnectorOptions( bool useBehRegSettings = true,
                           bool regularize = true,
                           bool defaultTolerance = true,
                           double regularization = 0.03,
                           bool defaultRateFactor = true,
                           double rateFactor = 0.9,
                           odb_String interpolation = "LINEAR",
                           bool useBehExtSettings = true,
                           odb_String extrapolation = "CONSTANT" );
    kbeO_ConnectorOptions( const kbeO_ConnectorOptions& copy );
    virtual kbeO_ConnectorOptions* Copy() const;
    kbeO_ConnectorOptions& operator=( const kbeO_ConnectorOptions& rhs );

    virtual ~kbeO_ConnectorOptions();
    bool useBehRegSettings() const;
    bool regularize() const;
    bool defaultTolerance() const;
    double regularization() const;
    bool defaultRateFactor() const;
    double rateFactor() const;
    odb_String interpolation() const;
    bool useBehExtSettings() const;
    odb_String extrapolation() const;
    void SetPointer( kbeC_ConnectorOptions* ptr) { pointer = ptr; }
    const kbeC_ConnectorOptions* GetPointer() const;
    kbeC_ConnectorOptionsShortcut Shortcut() const { return shortcut; } 

    bool hasValue() const { return shortcut.HasValue(); }

    static unsigned int typeIdentifier();
    unsigned int subTypeIdentifier() const;

protected:
    kbeC_ConnectorOptionsShortcut shortcut;
    kbeC_ConnectorOptionsHld pointer;
};

COW_ARRAYCOW2_DECL(kbeO_ConnectorOptions, cow_Virtual);

#endif // kbeO_ConnectorOptions_h
