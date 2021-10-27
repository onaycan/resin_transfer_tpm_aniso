#ifndef odb_ContactExp_h
#define odb_ContactExp_h

// Begin local includes
#include <odb_Interaction.h>
#include <odb_Types.h>
#include <cow_COW.h>

// Forward declarations
class ddb_ContactExp;
class odb_ContactProperty;

class odb_ContactExp: public odb_Interaction
{
public:

    // member access

    // Options

private:

public:   // undocumented and unsupported

    // Needed for container
    odb_ContactExp();

    odb_ContactExp(const ddb_ContactExp& interaction);
    
};

#endif // odb_ContactExp_h
