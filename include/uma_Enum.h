#ifndef uma_Enum_h
#define uma_Enum_h
//
// Principle enumerations for User Matrix API
//

class uma_Enum
{
public:
    // Map rows and columns TO-types
    enum uma_MapTypeEnum { 
        DOFS, 
        MODES,
        NODES, 
        ELEMENTS, 
        ORDINALS // == undefined
    };
    
    // Skip masks   - powers of 2 as may be used in combination
    enum uma_SkipMaskEnum { 
        INTERNAL_NODES  = 1, 
        RETAINED_DOFS   = 2, 
        LOAD_MODES      = 4 
    };
};

#endif // uma_Enum_h

