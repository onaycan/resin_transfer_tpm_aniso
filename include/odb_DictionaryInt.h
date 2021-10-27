/* -*- mode: c++ -*- */
#ifndef odb_DictionaryInt_h
#define odb_DictionaryInt_h

#if defined(HKS_NTI)
#pragma warning (disable: 4584)
#endif

// Forward Declarations
template <class VALUE>
class odb_DictionaryIntIterator;

template <class Value>
class odb_DictionaryInt;

// Begin local includes
#include <mem_AllocationOperators.h>
#include <odb_Exceptions.h>
#include <cow_IntTable.h>
#include <atr_translate.h>

template <class VALUE>
class odb_DictionaryInt : public mem_AllocationOperators,
                          private cow_IntTable<VALUE>
{
  public:
    VALUE& operator[](int id) { return get(id); }
    int size() const { return cow_IntTable<VALUE>::Size(); }

    VALUE& get(int id) { 
	if (cow_IntTable<VALUE>::IsMember(id))
	    return cow_IntTable<VALUE>::Get(id);
	throw odb_Exception(odb_TEXT_MESSAGE, atr("odb_Dictionary key error"));
    }

    const VALUE& constGet(int id) const { 
	if (cow_IntTable<VALUE>::IsMember(id))
	    return cow_IntTable<VALUE>::ConstGet(id);
	throw odb_Exception(odb_TEXT_MESSAGE, atr("odb_Dictionary key error"));
    }

    bool isMember(int id) const { return cow_IntTable<VALUE>::IsMember(id); }
    bool isEmpty() const { return cow_IntTable<VALUE>::IsEmpty(); }
    void insert(int id, const VALUE& value) { 
	if (!cow_IntTable<VALUE>::Insert(id,value))
	    throw odb_Exception(odb_TEXT_MESSAGE, 
				atr("odb_Dictionary insert failure"));
    }
    void yank(int id) { 
	if (!cow_IntTable<VALUE>::Remove(id))
	    throw odb_Exception(odb_TEXT_MESSAGE,
				atr("odb_Dictionary insert failure"));
    }
    
  private:
    friend class odb_DictionaryIntIterator<VALUE>;
};

template <class VALUE>
class odb_DictionaryIntIterator:private cow_IntTableIterator<VALUE>
{
public:
    odb_DictionaryIntIterator(const odb_DictionaryInt<VALUE> &container)
	:cow_IntTableIterator<VALUE>(container) {}

    void first() {cow_IntTableIterator<VALUE>::First();}

    void next() {cow_IntTableIterator<VALUE>::Next();}

    const VALUE& currentValue() {return cow_IntTableIterator<VALUE>::CurrentValue();}

    int currentKey() {return cow_IntTableIterator<VALUE>::CurrentKey();} 

    bool isDone() const {return cow_IntTableIterator<VALUE>::IsDone();}

};

#define ODB_INTCONTAINER_IMPL(VALUE, NAME) \
COW_INTTABLE_IMPL(VALUE,NAME ## BT); \
template class odb_DictionaryInt<VALUE>; \
template class odb_DictionaryIntIterator<VALUE>;

#define ODB_INTCONTAINER_DECL( VALUE, NAME) \
COW_INTTABLE_DECL(VALUE,NAME ## BT); \
typedef odb_DictionaryInt<VALUE> NAME; \
typedef odb_DictionaryIntIterator<VALUE> NAME  ## IT;

#define ODB_NEWINTCONTAINER_IMPL( VALUE, NAME) \
COW_INTTABLE_IMPL(VALUE,NAME ## BT); \
template class odb_DictionaryInt<VALUE>; \
template class odb_DictionaryIntIterator<VALUE>;

#define ODB_NEWINTCONTAINER_DECL( VALUE, NAME) \
COW_INTTABLE_DECL(VALUE,NAME ## BT); \
typedef odb_DictionaryInt<VALUE> NAME ## IMPL; \
typedef odb_DictionaryIntIterator<VALUE> NAME  ## IT; 

#endif // #ifndef odb_DictionaryInt_h


