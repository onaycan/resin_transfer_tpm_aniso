/* -*- mode: c++ -*- */

#ifndef cow_Btree_h
#define cow_Btree_h

//
// Includes
//
#include <assert.h>

// Begin local includes
#include <mem_AllocationOperators.h>
#include <omi_types.h>
#include <cow_COW.h>

//
// Forward declarations
//
template <class Key, class Value>
class cow_BtreeIterator;

template <class Key, class Value>
class cow_Btree;


//
// Class definition
//

/////////////////////////////////////////////
// DNOTE: This class represent a Many:One cow_Btree.
/////////////////////////////////////////////
template <class Key, class Value>
class cow_BtreeNode : public mem_AllocationOperators
{
public:

    typedef cow_COW<cow_BtreeNode<Key,Value>,
                cow_Direct<cow_BtreeNode<Key,Value> > > cow_BtreeNodeCow;

    cow_BtreeNode(const Key &key, const Value &value );
    cow_BtreeNode(const cow_BtreeNode<Key,Value> &node );
    ~cow_BtreeNode();

    bool InsertUnlessMember( const Key &key, const Value &value );
    bool Remove( const Key &key, cow_BtreeNode<Key,Value> &parent );

    const cow_BtreeNode<Key,Value>* ConstFind( const Key& ) const;
    cow_BtreeNode<Key,Value>* Find( const Key& );

    int MaxDepth() const { return maxDepth; }

    cow_BtreeNodeCow* Balance( cow_BtreeNodeCow* cowofthis );

    const Value& ConstGetValue() const { return nodeValue; }
    Value&       GetValue() { return nodeValue; }
    const Key& ConstGetKey() const { return nodeKey; }

private:
    Value  nodeValue;
    Key    nodeKey;
    cow_BtreeNodeCow* leftNode;
    cow_BtreeNodeCow* rightNode;
    int                      maxDepth;

    void RemoveNode( cow_BtreeNode<Key,Value>* ptr,
		     cow_BtreeNodeCow* replacement);

    void SetMaxDepth()
    {
	int depth = leftNode != 0 ? leftNode->ConstGet().MaxDepth() + 1 : 0;
	maxDepth = rightNode != 0 ? rightNode->ConstGet().MaxDepth() + 1 : 0;
	if( depth > maxDepth ) maxDepth = depth;
    }
    
    friend class cow_Btree<Key,Value>;
    friend class cow_BtreeIterator<Key,Value>;

};


template <class Key, class Value>
class cow_Btree : public mem_AllocationOperators
{

public:

    cow_Btree();
    cow_Btree( const cow_Btree<Key,Value>& );
    ~cow_Btree();

    const cow_Btree<Key,Value>& operator=( const cow_Btree<Key,Value>& );
    cow_Btree<Key,Value>* Copy() const;

    ////////////////////
    // Basic
    bool Remove(const Key&);
    bool InsertUnlessMember(const Key&, const Value&);

    ////////////////////
    // Lookup a value:
    const Value& ConstGet(const Key &key) const
    {
	 const cow_BtreeNode<Key,Value>* node = ConstFind(key);
        if( node )
	    return node->ConstGetValue();
	return nullValue;
    }

    ////////////////////
    // Access a value
    Value& Get(const Key &key)
    {
	 cow_BtreeNode<Key,Value>* node = Find(key);
	 
        if( node )
	    return node->GetValue();
	return nullValue;
    }

    ////////////////////
    // Test membership
    bool IsMember(const Key &key) const
    {
	 if(ConstFind(key) != 0)
	      return true;
	 else
	      return false;
    }

    // Return Size of Map
    int  Size() const { return nodeCount; }; 

    // Is Map empty?
    bool IsEmpty() const 
    { 
	 if(nodeCount == 0)
	      return true; 
	 else
	      return false;
    }
     

    // Clear the Map
    void Clear()
    {
        delete treeNode;
	treeNode = 0;
	nodeCount = 0;
    }

    void SetNullValue( const Value &value ) { nullValue = value; }

    int Depth() const { return treeNode ? treeNode->ConstGet().MaxDepth() : 0; }

private:
    typedef cow_COW<cow_BtreeNode<Key,Value>,
                cow_Direct<cow_BtreeNode<Key,Value> > > cow_BtreeNodeCow;

    typedef cow_BtreeNode<Key,Value> cow_BtreeNodeInst;

    friend class cow_BtreeIterator<Key,Value>;

    const cow_BtreeNode<Key,Value>* ConstFind( const Key &key) const;
     
    cow_BtreeNode<Key,Value>* Find( const Key &key );

    cow_BtreeNodeCow* treeNode;
    int nodeCount;
    Value nullValue;

};

template <class Key, class Value>
class cow_BtreeNodeLink : public mem_AllocationOperators
{
public:
    typedef cow_COW<cow_BtreeNode<Key,Value>,
                cow_Direct<cow_BtreeNode<Key,Value> > > cow_BtreeNodeCow;

    cow_BtreeNodeLink(  const cow_BtreeNodeCow* node,
                         cow_BtreeNodeLink<Key,Value> *link ) :
        theNodeCow(node),
	nextLink(link)
    {
    }
    ~cow_BtreeNodeLink() {}

    const cow_BtreeNodeCow* Node() { return theNodeCow; }

    cow_BtreeNodeLink<Key,Value> *Next() { return nextLink; }
private:
    const cow_BtreeNodeCow* theNodeCow;
    cow_BtreeNodeLink<Key,Value> *nextLink;
};



template <class Key, class Value>
class cow_BtreeIterator : public mem_AllocationOperators
{

public:
    cow_BtreeIterator( const cow_Btree<Key,Value> &tree );

    ~cow_BtreeIterator();

    void First();

    void Next();

    void Last();

    void Previous();

    const Value& CurrentValue() const { return nodeStack->Node()->ConstGet().ConstGetValue(); }

    const Key& CurrentKey() const { return nodeStack->Node()->ConstGet().ConstGetKey(); }

    bool IsDone() const 
    {
	 if(nodeStack == 0)
	      return true;
	 else
	      return false;
    }
     

private:
    typedef cow_COW<cow_BtreeNode<Key,Value>,
                cow_Direct<cow_BtreeNode<Key,Value> > > cow_BtreeNodeCow;

    const cow_Btree<Key,Value> &treeRef;

    cow_BtreeNodeLink<Key,Value> *nodeStack;

    void Push( const cow_BtreeNodeCow* node )
    {
        nodeStack = new cow_BtreeNodeLink<Key,Value>(node,nodeStack);
    }
    void Pop()
    {
       cow_BtreeNodeLink<Key,Value> *tmp = nodeStack;
	 
       if( tmp )
       {
          nodeStack = tmp->Next();
	  delete tmp;
       }
    }
    void ClearStack()
    {
        while( nodeStack ) Pop();
    }

};


#define COW_BTREE_IMPL( KEY, VALUE, NAME ) \
template class cow_BtreeNode<KEY,VALUE>; \
COW_COW_IMPL( NAME ## ND ); \
template class cow_Btree<KEY,VALUE>; \
template class cow_BtreeNodeLink<KEY,VALUE>; \
template class cow_BtreeIterator<KEY,VALUE>;

#define COW_BTREE_DECL( KEY, VALUE, NAME ) \
typedef cow_BtreeNode<KEY,VALUE> NAME ## ND; \
COW_COW_DECL( NAME ## ND ); \
typedef cow_Btree<KEY,VALUE> NAME; \
typedef cow_BtreeIterator<KEY,VALUE> NAME ## IT; \
typedef cow_BtreeIterator<KEY,VALUE> NAME ## SIT;

#endif
