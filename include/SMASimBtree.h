#ifndef SMASimBtree_h
#define SMASimBtree_h
// Begin local includes
#include <mem_AllocationOperators.h>
// Forward declarations

template <class Key, class Value> class SMASimBtreeIterator;
template <class Key, class Value> class SMASimBtreeNode;
template <class Key, class Value> class SMASimBtreeNodeLink;


template <class Key, class Value>
class SMASimBtree : public mem_AllocationOperators
{
    friend class SMASimBtreeIterator<Key,Value>;

public:
    SMASimBtree();
    SMASimBtree(const SMASimBtree<Key,Value>& tree);
    ~SMASimBtree();

    void operator =(SMASimBtree<Key,Value> other) { Swap(other); }
    void Swap(SMASimBtree<Key,Value> &other);

    int  Size() const { return nodeCount; }; 
    bool IsEmpty() const { return nodeCount == 0; }

    bool Remove(const Key &key);
    bool Insert(const Key &key, const Value &value, bool overwrite=false);
    const Value &Get(const Key &key) const;
    Value& Get(const Key &key);
    const Value *Find(const Key &key) const;
    Value *Find(const Key &key);
    bool IsMember(const Key &key) const;

    void Clear();

private:
    SMASimBtreeNode<Key,Value> *treeNode;
    int nodeCount;
};

template <class Key, class Value>
class SMASimBtreeIterator : public mem_AllocationOperators
{
public:
    SMASimBtreeIterator( const SMASimBtree<Key,Value> &tree );
    ~SMASimBtreeIterator();

    void First();
    void Next();
    void Last();
    void Previous();
    bool IsDone() const { return nodeStack == 0; }

    const Value& CurrentValue();
    const Key& CurrentKey();

private:
    const SMASimBtree<Key,Value> &treeRef;
    SMASimBtreeNodeLink<Key,Value> *nodeStack;

    void Push(SMASimBtreeNode<Key,Value> *node);
    void Pop();
    void ClearStack();
};

#define DPA_BTREE_IMPL( KEY, VALUE, NAME )              \
    template class SMASimBtreeNode<KEY,VALUE>;            \
    template class SMASimBtree<KEY,VALUE>;                \
    template class SMASimBtreeNodeLink<KEY,VALUE>;        \
    template class SMASimBtreeIterator<KEY,VALUE>;

#define DPA_BTREE_DECL( KEY, VALUE, NAME )              \
    typedef SMASimBtree<KEY,VALUE> NAME;                  \
    typedef SMASimBtreeIterator<KEY,VALUE> NAME ## IT

#endif
