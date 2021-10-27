/* -*- mode: c++ -*- */
/////////////////////////////////////////////
// DNOTE: This class represent a Many:One omi_UintTable.
/////////////////////////////////////////////

#ifndef omi_UintTable_h
#define omi_UintTable_h

// Includes

#include <assert.h>

// Begin local includes
#include <mem_AllocationOperators.h>
#include <omi_types.h>
#include <omi_BlkBitVectTrav.h>
#include <omi_BlockedArray.h>
#include <omi_UintTableBlock.h>

// Forward declarations

template <class Value>
class omi_UintTableIterator;

template <class Value>
struct cow_Direct;

// Class definition

template <class Value>
class omi_UintTable : public mem_AllocationOperators
{
    friend struct cow_Direct<omi_UintTable<Value> >;
    friend class omi_UintTableIterator<Value>;

  public:

    omi_UintTable();

    /// Create a table of pre-determined size (to avoid incremental growth)
    omi_UintTable(size_t numEntries); 

    /// Create a table of pre-determined size (to avoid incremental growth),
    /// and populate it from given arrays of keys and values.
    omi_UintTable(size_t numEntries, const unsigned int* keys, const Value* values); 

    omi_UintTable(unsigned int high_bit, 
		 unsigned int mid_bit,  
		 unsigned int init_pointer_sz);
    ~omi_UintTable();

    ////////////////////
    // Basic
    bool Remove(unsigned int);
    bool Insert(unsigned int, const Value&);

    ////////////////////
    // Lookup a value:
    inline const Value& ConstGet(unsigned int key) const {
	return FindTableBlock(key)->ConstGet(key & keyModulus);
    }

    inline bool ConstGetValue(unsigned int key, Value &value ) const {
	 unsigned int keymod = key & keyModulus;
	 const omi_UintTableBlock<Value>* tblk = FindTableBlock(key);
	 if( (tblk != 0) && tblk->IsMember(keymod) )
	 {
	      value = tblk->ConstGet(keymod);
	      return true;
	 }
	 return false;
    }

    ////////////////////
    // Access a value
    inline Value& Get(unsigned int key) {
	return FindTableBlock(key)->Get(key & keyModulus);
    }

    ////////////////////
    // Test membership
    inline bool IsMember(unsigned int key) const {
	const omi_UintTableBlock<Value>* tblk = FindTableBlock(key);
	return (tblk != 0) ? tblk->IsMember(key & keyModulus) : false;
    }

    // Return Size of Map
    int Size() const { return tableSize; }

    // Is Map empty?
    bool IsEmpty() const { return tableSize == 0; }

    // Clear the Map
    void Clear();

    //Deep copy of this
    omi_UintTable<Value>* Copy() const;

    omi_UintTableBlock<Value>* FindTableBlock(unsigned int tkey) const {
	unsigned int index = tkey >> keyShift;
	return (index < currentBlockSize) ? tableBlocks[index] : 0;
    }

    unsigned int KeyModulus() const { return keyModulus; }

  private:

    void Initialize( unsigned int high_bit, 
		     unsigned int mid_bit,  
		     unsigned int init_pointer_sz);

    omi_UintTable( const omi_UintTable<Value>& table );
    omi_UintTable<Value>& operator=( const omi_UintTable<Value>& );
    omi_UintTableBlock<Value> **tableBlocks;
    int tableSize;
    int currentBlockSize;
    unsigned int keyModulus;
    unsigned int keyShift;
    unsigned int initPointerSz;
    unsigned int blockOrder;
};

template <class Value>
class omi_UintTableNode : public mem_AllocationOperators
{
  public:
    
    omi_UintTableNode(): key(0), value(0) {}
    omi_UintTableNode(unsigned int k, const Value* v): key(k), value(v) {}
    unsigned int key;
    const Value* value;
};

template <class Value>
class omi_UintTableIterator : public mem_AllocationOperators
{
  public:

    omi_UintTableIterator(const omi_UintTable<Value>& table);
    omi_UintTableIterator(const omi_UintTable<Value>& table,
			 int (*cmpFun)(const void *, const void *));

    ~omi_UintTableIterator();

    void First();

    void Next();
    void Last();

    void Previous();
    const Value& CurrentValue() const;

    unsigned int CurrentKey() const;

    bool IsDone() const;

    bool NextBlock();
    bool PreviousBlock();

  private:

    const omi_UintTable<Value>& tableRef;
    unsigned int currentKey;
    unsigned int currentOffset;
    int currentIndex;
    const omi_UintTableBlock<Value>* currentBlock;
    omi_BlkBitVectTrav* currentBlockTrav;
    bool isDone;
    int (*compar)(const void *, const void *);
    omi_UintTableNode<Value>** tmpArray;
};

#define OMI_UINTTABLE_IMPL( VALUE, NAME ) \
template class omi_UintTable<VALUE>; \
template class omi_UintTableIterator<VALUE>; \
template class omi_UintTableNode<VALUE>; \
OMI_BLOCKEDARRAY_IMPL(VALUE); \
OMI_TABLEBLOCK_IMPL(VALUE, NAME ## TABLEBLOCK);

#define OMI_UINTTABLE_DECL( VALUE, NAME ) \
typedef omi_UintTable<VALUE> NAME;    \
typedef omi_UintTableIterator<VALUE> NAME ## IT; \
typedef omi_UintTableIterator<VALUE> NAME ## SIT; \
OMI_BLOCKEDARRAY_DECL(VALUE, NAME ## BLOCKEDARRAY ); \
OMI_TABLEBLOCK_DECL(VALUE, NAME ## TABLEBLOCK);

#endif
