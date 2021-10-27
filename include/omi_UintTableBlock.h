/* -*- mode: c++ -*- */

#ifndef omi_UintTableBlock_h
#define omi_UintTableBlock_h

#if defined (HKS_NT)
#pragma warning (disable: 4584)
#endif


//
// Includes
//
#include <assert.h>

// Begin local includes
#include <mem_AllocationOperators.h>
#include <omi_types.h>
#include <omi_BlockedArray.h>
#include <omi_BlkBitVect.h>

//
// Forward declarations
//
template <class Value>
class omi_IntTableIterator;

template <class Value>
class omi_UintTableIterator;

//
// Class definition
//

/////////////////////////////////////////////
// DNOTE: This class represent a Many:One omi_UintTableBlock.
/////////////////////////////////////////////

template <class Value>
class omi_UintTableBlock 
    : public mem_AllocationOperators, private omi_BlockedArray<Value>
{

public:

    omi_UintTableBlock( unsigned int init_pointer_sz, unsigned int block_size );

    omi_UintTableBlock( const omi_UintTableBlock<Value>& tableblock );

    ~omi_UintTableBlock();

    ////////////////////
    // Basic
    inline bool Remove(unsigned int key)
    {
	unsigned int cnt = tableMask.BitCount();
	tableMask.UnsetBit(key);
	return (cnt != tableMask.BitCount());
    }
    inline bool Insert(unsigned int key, const Value &val)
    {
	unsigned int cnt = tableMask.BitCount();
	tableMask.SetBit(key);	
	SetCell( key, val );
	return (cnt != tableMask.BitCount());
    }

    ////////////////////
    // Lookup a value:
    // This method is not key safe!!! don't call with !IsMember(key)
    inline const Value& ConstGet(unsigned int key) const
    {
	return omi_BlockedArray<Value>::blockPointers[key>>omi_BlockedArray<Value>::blockOrder][key&omi_BlockedArray<Value>::blockModulus];
    }

    ////////////////////
    // Access a value
    // This method is not key safe!!! don't call with !IsMember(key)
    inline Value& Get(unsigned int key)
    {
	return omi_BlockedArray<Value>::blockPointers[key>>omi_BlockedArray<Value>::blockOrder][key&omi_BlockedArray<Value>::blockModulus];
    }

    ////////////////////
    // Test membership
    inline bool IsMember(unsigned int key) const
    {
	return tableMask.GetBit(key);
    }

    // Return Size of Map
    int  Size() const { return tableMask.BitCount(); }

    // Is Map empty?
    bool IsEmpty() const { return tableMask.BitCount() == 0; }

    // Clear the Map
    void Clear();

private:

    omi_BlkBitVect tableMask;
    friend class omi_IntTableIterator<Value>;
    friend class omi_UintTableIterator<Value>;
};

#define OMI_TABLEBLOCK_IMPL( VALUE, NAME ) \
template class omi_UintTableBlock<VALUE>;

#define OMI_TABLEBLOCK_DECL( VALUE, NAME ) \
typedef omi_UintTableBlock<VALUE> NAME;

#endif
