#ifndef SMAFsmSubstructureSystem_h
#define SMAFsmSubstructureSystem_h

// Begin local includes
#include <SMAFsmSystem.h>
// End local includes

// Forward declarations
class SMASimCollectionID;

///
/// SubstructureSystem class for easy access and store of collections, sets, and 
/// distributions associated with the system.
///
class SMAFsmSubstructureSystem : public SMAFsmSystem
{
public:
    /// Create an empty system.
    SMAFsmSubstructureSystem();

    /// Create a substructure system given the position of the system record.
    SMAFsmSubstructureSystem(const SMASimPosition & system);

    ~SMAFsmSubstructureSystem();

};

#endif

