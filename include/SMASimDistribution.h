#ifndef SMASimDistribution_h
#define SMASimDistribution_h

// Begin local includes
#include <mem_AllocationOperators.h>
#include <SMASimID.h>
#include <SMASimArrayPersistentDrawerDesc.h>
#include <SMASimArrayDimSelection.h>
#include <SMASimArrayDrawerID.h>
#include <SMASimDMember.h>
#include <SMASimGrid.h>
#include <SMABasWeakPtr.h>
#include <SMABasSharedPtr.h>
#include <SMASimCacheState.h>
// End local includes

class SMASimPosition;
class SMASimDistributionRepr;
class SMASimDistributionID;
class SMASimRangeViewArgs;
class SMASimTransferArgs;
class SMASimRangeValue;
class SMASimTransfer;
class SMASimParticipation;
class SMASimDatabaseRepr;
class SMASimDimSelection;

/** 
* Distributions organize bulk data into large rectangular multidimensional dataspaces called compartments.
* The potential domain of the distribution is the set of all entities eligible to be in the 
* distribution, defined as the distribution's grid. Not all members of the potential domain 
* of the distribution need to be mapped by the distribution; the ones which are mapped 
* define the actual domain of the distribution.
**/
class SMASimDistribution : public mem_AllocationOperators
{
public:
    ///  The default constructor creates a null distribution reference, which can be assigned
    ///  from another distribution ref
    SMASimDistribution() {}

    /// Destructor
    ~SMASimDistribution() {}

    /// Return the position of this Distribution.
    SMASimPosition Pos() const;

    /// Create a distribution reference based on the ID
    SMASimDistribution(SMASimDistributionID const& id);

    /// Create a distribution reference from another and masking dimension(s)
    SMASimDistribution(const SMASimDistribution& dref, const SMASimDMember& mask);

    /// Returns true if this distribution is temporary
    bool IsTemp() const;

    /// Returns true if this distribution is a masked distribution
    bool IsMasked() const { return !m_mask.IsNull(); }

    /// Return the ID of the distribution
    SMASimDistributionID ID() const;

    /// Return the grid on which the distribution is based
    SMASimGrid Grid() const;

    /// Return the RangeType of the distribution
    SMASimRangeType RangeType() const;

    /// Return the number of drawers in the distribution
    int NumDrawers() const;

    /// Return the distribution's number of dimensions (same as that of its grid)
    int NumDimensions() const;

    /// Return the the description of a drawer in this distribution 
    SMASimPersistentDrawerDesc DrawerDescription( SMASimDrawerID const& ) const;

    /// Return (in an out-argument) the descriptions of all drawers.
    void QueryDrawers(SMASimArrayPersistentDrawerDesc& out) const;

    /// Set the size of the chunk cache for this distribution.
    size_t SetCacheSize(size_t bytes);

    /// Clear the contents of the cache. Items to be written will be immediately flushed.
    void ClearCache();

    /// Return true if chunk identified by an ordinal selection does not exist; false otherwise
    bool ChunkAllocated(const SMASimDrawerID& drwID, const SMASimArrayDimSelection& selection) const;

    /// Return true if the repr is not set
    bool IsNull() const;

    /// Control secondary cache.
    SMASimCacheState::State SecondaryCache(SMASimCacheState::State state) const;

    /// Populate the supplied drawer ID array with the IDs of all drawers contained in this distribution.
    void DrawerIDArray(SMASimArrayDrawerID& ids) const;

private:
    friend class SMASimViewRepr;
    friend class SMASimTransfer;

    // Constructor.
    // SMASimDistribution(SMABasSharedPtr<SMASimDistributionRepr>(*repr));


    SMASimDrawerID CreateDrawer(const SMASimRangeViewArgs&     rvArgs, 
                                const SMASimTransferArgs&      tArgs,
                                const SMASimDrawerDescription& desc,
                                void*                          buffer);

    SMASimDrawerID InitializeNewDrawer(const SMASimRangeViewArgs&     rvArgs, 
                                       const SMASimTransferArgs&      tArgs,
                                       const SMASimDrawerDescription& desc);

    SMASimDrawerID CreateSparseDrawer(const SMASimRangeViewArgs&     rvArgs, 
                                      const SMASimTransferArgs&      tArgs,
                                      const SMASimDrawerDescription& desc,
                                      const SMASimBufferSet&         bufferSet);

    void Write(const SMASimRangeViewArgs& rvArgs,
               const SMASimTransferArgs&  transferArgs,
               const void*                buffer,
               SMASimCSetID               csetExtensionID);

    void WriteSparse(const SMASimBufferSet& bufferSet);

    void Read(const SMASimRangeViewArgs& rvArgs,
              const SMASimTransferArgs&  transferArgs,
              void*                      buffer,
              SMASimParticipation&       participation) const;

    void ReadSparse(SMASimBufferSet& bufferSet) const;

    /// Extend a drawer. The dimSel parameter specifies the full size of the extended drawer.
    SMASimCSetID ExtendDrawer(const SMASimTransferArgs&      tArgs, 
                              const SMASimArrayDimSelection& dimSel);

    SMASimArrayDimSelection MaskedSelection(const SMASimArrayDimSelection& sel) const;
    SMASimPersistentDrawerDesc MaskedDrawerDescription(SMASimDrawerID const& id) const;

    // members
    SMABasWeakPtr<SMASimDistributionRepr> m_repr;
    SMASimDMember        m_mask;
    SMASimGrid           m_maskedGrid;
};

#endif
