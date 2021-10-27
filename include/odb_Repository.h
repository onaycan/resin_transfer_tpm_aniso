/* -*- mode: c++ -*- */
#ifndef odb_Repository_h
#define odb_Repository_h

#if defined (HKS_NT)
#pragma warning (disable: 4584)
#endif


// Begin local includes
#include <mem_AllocationOperators.h>
#include <cow_Btree.h>
// End local includes
// Forward Declarations
template <class KEY, class VALUE>
class odb_RepositoryIterator;

template <class Key, class Value>
class odb_Repository;


template <class KEY, class VALUE>
class odb_Repository : public mem_AllocationOperators, private cow_Btree<KEY, VALUE>
{
public:
    inline VALUE& operator[](const KEY& name){CheckKey(name); return Get(name);}
    inline int  size() const { return cow_Btree<KEY, VALUE>::Size(); }
    inline VALUE& get(const KEY& name) {CheckKey(name); return Get(name);}
    inline const VALUE& constGet(const KEY& name) const {CheckKey(name); return ConstGet(name);}
    inline bool isMember(const KEY& name) const {return IsMember(name);};
    inline bool isEmpty() const {return cow_Btree<KEY, VALUE>::IsEmpty();};
    inline void insertUnlessMember(const KEY& name, const VALUE& step) {cow_Btree<KEY, VALUE>::InsertUnlessMember(name,step);};
    inline void yank(const KEY& name) {CheckKey(name); cow_Btree<KEY, VALUE>::Remove(name); }
private:
    friend class odb_RepositoryIterator<KEY,VALUE>;
    bool CheckKey( const KEY& name) const;

};

template <class KEY, class VALUE>
class odb_RepositoryIterator: public mem_AllocationOperators, private cow_BtreeIterator<KEY, VALUE>
{
public:
    odb_RepositoryIterator(const odb_Repository<KEY,VALUE> &container)
	:cow_BtreeIterator<KEY,VALUE>(container) {}

    void first() {cow_BtreeIterator<KEY, VALUE>::First();}

    void next() {cow_BtreeIterator<KEY, VALUE>::Next();}

    const VALUE& currentValue() {return cow_BtreeIterator<KEY, VALUE>::CurrentValue();}

    const KEY& currentKey() {return cow_BtreeIterator<KEY, VALUE>::CurrentKey();} 

    bool isDone() const {return cow_BtreeIterator<KEY, VALUE>::IsDone();}

};

#define ODB_CONTAINER_IMPL( KEY, VALUE, NAME) \
COW_BTREE_IMPL(KEY,VALUE,NAME ## BT); \
template class odb_Repository<KEY,VALUE>; \
template class odb_RepositoryIterator<KEY,VALUE>;

#define ODB_CONTAINER_DECL( KEY, VALUE, NAME) \
COW_BTREE_DECL(KEY,VALUE,NAME ## BT); \
typedef odb_Repository<KEY,VALUE> NAME; \
typedef odb_RepositoryIterator<KEY,VALUE> NAME  ## IT;

#define ODB_NEWCONTAINER_IMPL( KEY, VALUE, NAME) \
COW_BTREE_IMPL(KEY,VALUE,NAME ## BT); \
template class odb_Repository<KEY,VALUE>; \
template class odb_RepositoryIterator<KEY,VALUE>;

#define ODB_NEWCONTAINER_DECL( KEY, VALUE, NAME) \
COW_BTREE_DECL(KEY,VALUE,NAME ## BT); \
typedef odb_Repository<KEY,VALUE> NAME ## IMPL; \
typedef odb_RepositoryIterator<KEY,VALUE> NAME  ## IT; 

#endif // #ifndef odb_Repository_h


