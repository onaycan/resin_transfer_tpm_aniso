#ifndef kflO_OperatorFilter_h
#define kflO_OperatorFilter_h

// Begin local includes
#include <kflO_Filter.h>
#include <odb_Types.h>
#include <odb_String.h>
#include <odb_Union.h>
// Forward declarations
class kflC_OperatorFilter;

class kflO_OperatorFilter : public kflO_Filter
{
public:
    kflO_OperatorFilter( const kflC_FilterShortcut& shortcut );
    kflO_OperatorFilter();

    kflO_OperatorFilter(double cutoffFrequency,
                        int order=2,
                        odb_String operation="NONE",
                        bool halt=false,
                        odb_Union limit="NONE",
                        odb_String invariant="NONE");

    kflO_OperatorFilter( const kflO_OperatorFilter& copy );

    virtual ~kflO_OperatorFilter();
    double cutoffFrequency() const;
    int order() const;
    odb_String operation() const;
    bool halt() const;
    odb_Union limit() const;
    odb_String invariant() const;
    kflO_OperatorFilter& operator=( const kflO_OperatorFilter& rhs );

    const kflC_OperatorFilter* GetPointer() const;

    static unsigned int typeIdentifier();

    virtual kflO_Filter* Copy() const;

};

#endif
