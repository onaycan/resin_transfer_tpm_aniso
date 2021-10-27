#ifndef odb_FilmConditionProp_h
#define odb_FilmConditionProp_h

// Begin local includes
#include <odb_InteractionProperty.h>

// Forward declarations
class ddb_FilmConditionProp;

class odb_FilmConditionProp: public odb_InteractionProperty
{

public:   // Undocumented and unsupported

    // Needed for container
    odb_FilmConditionProp();

    odb_FilmConditionProp(const ddb_FilmConditionProp& ip);

    ddb_FilmConditionProp filmConditionProp() const;
};

#endif // odb_FilmConditionProp_h
