#ifndef SMASimIndexSet_h
#define SMASimIndexSet_h

// Begin local includes
#include <mem_AllocationOperatorsTiny.h>

// Forward declarations
class omi_BlkBitVect;
class SMASimRangeListStats;

/**
 * Struct to store index set cardinality and count.
 */
struct SMASimIndexSetHdr : public mem_AllocationOperatorsTiny
{
    int m_cardinality;
    int m_count;
};

/**
 * Struct to store index set range starting position.
 */
struct SMASimRange : public mem_AllocationOperatorsTiny
{
    int m_start;
};

/**
 * An index set class.
 * Used for hyperslab-like operations on HDF5 datasets.
 */
class SMASimIndexSet : private SMASimIndexSetHdr
{
    friend class SMASimIndexSetUtils;
    friend class SMASimCSetIterator;
    // The following are intentionally not implemented.
    SMASimIndexSet();
    SMASimIndexSet(SMASimIndexSet const&);
    SMASimIndexSet& operator=(SMASimIndexSet const&);

    enum { i_locators = sizeof(SMASimIndexSetHdr) >> 2 };
    enum RangeType { t_block=1, t_strided=2, t_stridedBlock=3,
                     t_mask=4, t_repeatedMask=6, t_multiMask=7 };

    void fillCanonicalAndBias(int*,bool) const;
    bool Bisect( int index, int start, int end, int prevAttempt, int& checked ) const;
    int CheckRange( int index, int rangeIndex ) const;

public:
    /// Returns the set cardinality
    int cardinality() const { return m_cardinality; }

    /// Returns the number of ranges in the set
    int numRanges() const { return m_count; }

    /// Sets the bits of the set from an array
    void fillCanonical(int* members) const
    { fillCanonicalAndBias(members, false); }

    /// Sets the bits of the set, offset by 1, from an array
    void fillBiasedCanonical(int* members) const
    { fillCanonicalAndBias(members, true); }

    /// Returns a read only integer pointer to this
    int const* signedBase() const
    { return reinterpret_cast<int const*>(this); }

    /// Returns a read only unsigned integer pointer to this
    unsigned int const* unsignedBase() const
    { return reinterpret_cast<unsigned int const*>(this); }

    /// Returns an unsigned integer offset from the start of this
    unsigned int locator(int k) const { return unsignedBase()[i_locators+k]; }

    /// Returns an integer offset from the start of this
    SMASimRange const* getRange(int offset) const 
    { return reinterpret_cast<SMASimRange const*>(signedBase()+offset); }

    /// Prints the set to cout. For debug purposes.
    void printSet() const;

    /// Collects statistics on the number of each range lists format used in the index set. 
    /// For debug purposes only. Do not export.
    void IndexSetTypeCount(SMASimRangeListStats& stat) const;

    /// Returns true if index is a member of the set
    bool IsMember( int index ) const;

    /// Returns true if index is a member of the set by bisection algorithm
    bool IsMemberBisect( int index ) const;

    /// Returns true if the set is sorted; false otherwise
    bool IsSorted() const;

    /// Returns the index of the given member
    int SeekMember( int member ) const;

    /// Returns the value of a member given the index
    int operator[]( int index ) const;

    /// Sets the bits of the set from a blocked bit vector
    void ScatterCanonical( omi_BlkBitVect& vector ) const;

    /// Sets the starting and ending bounds of the set
    void BoundingBox( int& start, int& end ) const;

    /// Returns the size of index set data in 32-bit words
    int SizeOfPointer() const;

    /// Returns the number of bits set in an integer mask
    static int popOfWord(unsigned int mask);

    /// Returns true if value has range bit set
    static inline bool hasRange( unsigned int );

    /// Returns the type encoding of the value
    static inline int extractType( unsigned int );

    /// Returns the offset encoding of the value
    static inline int extractOffset( unsigned int );
};

/**
 * Struct that adds range width to SMASimRange through derivation.
 */
struct SMASimBlockRange : public SMASimRange
{
    int m_width;
};

/**
 * Struct that adds range stride and count to SMASimRange through derivation.
 */
struct SMASimStridedRange : public SMASimRange
{
    int m_count;
    int m_stride;
};

/**
 * Struct that adds range stride and count to SMASimBlockRange through derivation.
 */
struct SMASimStridedBlockRange : public SMASimBlockRange
{
    int m_count;
    int m_stride;
};

inline bool SMASimIndexSet::hasRange(unsigned int loc) { return loc >> 31; }
inline int SMASimIndexSet::extractType(unsigned int loc) { return (loc >> 28) & 7; }
inline int SMASimIndexSet::extractOffset(unsigned int loc) { return loc & ~(15 << 28); }

#endif
