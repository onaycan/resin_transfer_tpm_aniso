/* -*- mode: c++ -*- */
///////////////////////////////////////////////////////////////////////////////
// 
// Description: This template is a high performance integer mapped dictionary.
//              It is implemented using two unsigned integer dictionarys, one
//              for the negative numbers, and one for the positive numbers.
// 

#ifndef omi_IntTable_h
#define omi_IntTable_h

// Includes

// Begin local includes
#include <mem_AllocationOperators.h>
#include <omi_UintTable.h>

// Forward declarations

template <class Value>
struct cow_Direct;

template <class Value>
class omi_IntTableIterator;

// Class definition

template <class Value>
class omi_IntTable : public mem_AllocationOperators
{
    friend struct cow_Direct<omi_IntTable<Value> >;
    friend class omi_IntTableIterator<Value>;

  public:

    omi_IntTable();

    /// Create a table of pre-determined size (to avoid incremental growth),
    /// and populate it from given array of keys and values. 
    /// Use only with positive keys.
    omi_IntTable(size_t numEntries, const int* keys, const Value* values); 

    omi_IntTable(unsigned int high_bit,
         unsigned int mid_bit,  
         unsigned int init_pointer_sz);

    virtual ~omi_IntTable();

    ////////////////////
    // Basic
    bool Remove(int key) {
	return (key < 0) ? negative->Remove(-key) : positive->Remove(key);
    }

    bool Insert(int key, const Value& v) {
	return (key < 0) ? negative->Insert(-key, v) : positive->Insert(key, v);
    }

    ////////////////////
    // Lookup a value:
    const Value& ConstGet(int key) const {
	return (key < 0) ? negative->ConstGet(-key) : positive->ConstGet(key);
    }
    bool ConstGetValue(int key, Value& val) const {
	return (key < 0) ? negative->ConstGetValue(-key, val) : 
	    positive->ConstGetValue(key, val);
    }

    ////////////////////
    // Access a value
    Value& Get(int key) {
	return (key < 0) ? negative->Get(-key) : positive->Get(key);
    }

    ////////////////////
    // Test membership
    bool IsMember(int key) const {
	return (key < 0) ? negative->IsMember(-key) : positive->IsMember(key);
    }

    // Return Size of Map
    int Size() const { return negative->Size() + positive->Size(); }

    // Is Map empty?
    bool IsEmpty() const { return negative->IsEmpty() && positive->IsEmpty(); }

    // Clear the Map
    void Clear() { negative->Clear(); positive->Clear(); }

    //Deep copy of this
    omi_IntTable<Value>* Copy() const;

  protected:

    omi_IntTable(const omi_IntTable<Value>& table);
    omi_IntTable<Value>& operator=( const omi_IntTable<Value>& );
    omi_UintTableBlock<Value>* FindTableBlock(int tkey) const;
    
    omi_UintTable<Value>* negative;
    omi_UintTable<Value>* positive;
};

template <class Value>
class omi_IntTableNode: public omi_UintTableNode<Value>
{
  public:
    
    omi_IntTableNode() {}
    omi_IntTableNode(int k, const Value* v);
};

template <class Value>
class omi_IntTableIterator : public mem_AllocationOperators
{
  public:

    omi_IntTableIterator(const omi_IntTable<Value>& table);
    omi_IntTableIterator(const omi_IntTable<Value>& table,
			 int (*cmpFun)(const void *, const void *));

    void First();
    void Last();
    void Next();
    const Value& CurrentValue() const;
    int CurrentKey() const;
    bool IsDone() const;

  private:

    int numNegative;
    int totalNegative;
    omi_UintTableIterator<Value> niter;
    omi_UintTableIterator<Value> piter;
    int (*compar)(const void *, const void *);
};

#define OMI_INTTABLE_IMPL( VALUE, NAME ) \
template class omi_IntTable<VALUE>; \
template class omi_IntTableIterator<VALUE>; \
OMI_UINTTABLE_IMPL(VALUE, NAME ## UINTTABLE);

#define OMI_INTTABLE_DECL( VALUE, NAME ) \
typedef omi_IntTable<VALUE> NAME;    \
typedef omi_IntTableIterator<VALUE> NAME ## IT; \
typedef omi_IntTableIterator<VALUE> NAME ## SIT; \
OMI_UINTTABLE_DECL(VALUE, NAME ## UINTTABLE);

#endif
