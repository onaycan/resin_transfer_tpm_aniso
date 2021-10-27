/* -*- mode: c++ -*- */

#ifndef omi_Btree_h
#define omi_Btree_h

//
// Includes
//

// Begin local includes
#include <mem_AllocationOperators.h>
#include <omi_types.h>

//
// Forward declarations
//
template <class Key, class Value>
class omi_BtreeIterator;

template <class Key, class Value>
class omi_Btree;


//
// Class definition
//

/////////////////////////////////////////////
// DNOTE: This class represent a Many:One omi_Btree.
/////////////////////////////////////////////
template <class Key, class Value>
class omi_BtreeNode : public mem_AllocationOperators
{
public:
    omi_BtreeNode(const Key &key, const Value &value );
    ~omi_BtreeNode();

    bool Insert( const Key &key, const Value &value );
    bool Remove( const Key &key, omi_BtreeNode<Key,Value> &parent );

    omi_BtreeNode<Key,Value>* Find( const Key& ) const;

    int MaxDepth() const { return maxDepth; }

    omi_BtreeNode<Key,Value>* Balance();

    const Value& ConstGetValue() const { return nodeValue; }
    Value&       GetValue() { return nodeValue; }

    const Key& ConstGetKey() const { return nodeKey; }

private:
    omi_BtreeNode( const omi_BtreeNode<Key,Value>& );

    Value  nodeValue;
    Key    nodeKey;
    omi_BtreeNode<Key,Value>* leftNode;
    omi_BtreeNode<Key,Value>* rightNode;
    int                      maxDepth;

    void RemoveNode( omi_BtreeNode<Key,Value>* ptr,
		     omi_BtreeNode<Key,Value>* replacement );

    void SetMaxDepth()
    {
	int depth = leftNode != 0 ? leftNode->MaxDepth() + 1 : 0;
	maxDepth = rightNode != 0 ? rightNode->MaxDepth() + 1 : 0;
	if( depth > maxDepth ) maxDepth = depth;
    }
    
    friend class omi_Btree<Key,Value>;
    friend class omi_BtreeIterator<Key,Value>;

};


template <class Key, class Value>
class omi_Btree : public mem_AllocationOperators
{

public:

    omi_Btree();
    omi_Btree( const omi_Btree<Key,Value>& tree );
    ~omi_Btree();

    ////////////////////
    // Basic
    bool Remove(const Key&);
    bool Insert(const Key&, const Value&);

    ////////////////////
    // Lookup a value:
    const Value& ConstGet(const Key &key) const
    {
	omi_BtreeNode<Key,Value> *node;
        if( treeNode ){
	  node = treeNode->Find(key);
          if (node)
	    return node->ConstGetValue();
        }
	return nullValue;
    }

    ////////////////////
    // Access a value
    Value& Get(const Key &key)
    {
	omi_BtreeNode<Key,Value> *node;
        if( treeNode ){
	  node = treeNode->Find(key);
	  if ( node )
	    return node->GetValue();
	}
	return nullValue;
    }

    ////////////////////
    // Test membership
    bool IsMember(const Key &key) const
    {
	 if(treeNode && treeNode->Find(key))
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
    Value GetNullValue() ;

    int Depth() { return treeNode != 0 ? treeNode->MaxDepth() : 0; }

    //Deep copy of this
    omi_Btree<Key,Value>* Copy() const;
    omi_Btree<Key,Value>& operator=( const omi_Btree<Key,Value>& );

private:

    friend class omi_BtreeIterator<Key,Value>;

    typedef omi_BtreeNode<Key,Value> omi_BtreeNodeInst;

    omi_BtreeNode<Key,Value> *treeNode;
    int nodeCount;
    Value nullValue;

};

template <class Key, class Value>
class omi_BtreeNodeLink : public mem_AllocationOperators
{
public:
    omi_BtreeNodeLink(  omi_BtreeNode<Key,Value> *node,
                         omi_BtreeNodeLink<Key,Value> *link ) :
        theNode(node),
	nextLink(link)
    {
    }
    ~omi_BtreeNodeLink() {}

    omi_BtreeNode<Key,Value> *Node() { return theNode; }

    omi_BtreeNodeLink<Key,Value> *Next() { return nextLink; }
private:
    omi_BtreeNode<Key,Value> *theNode;
    omi_BtreeNodeLink<Key,Value> *nextLink;
};



template <class Key, class Value>
class omi_BtreeIterator : public mem_AllocationOperators
{

public:
    omi_BtreeIterator( const omi_Btree<Key,Value> &tree );

    ~omi_BtreeIterator();

    void First();

    void Next();

    void Last();

    void Previous();

    const Value& CurrentValue() { return nodeStack->Node()->ConstGetValue(); }

    const Key& CurrentKey() { return nodeStack->Node()->ConstGetKey(); }

    bool IsDone() const 
    { 
	 if(nodeStack == 0) 
	      return true;
	 else
	      return false;
    }
     

private:
    const omi_Btree<Key,Value> &treeRef;

    omi_BtreeNodeLink<Key,Value> *nodeStack;

    void Push( omi_BtreeNode<Key,Value> *node )
    {
        nodeStack = new omi_BtreeNodeLink<Key,Value>(node,nodeStack);
    }
    void Pop()
    {
       omi_BtreeNodeLink<Key,Value> *tmp = nodeStack;
	 
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

#define OMI_BTREE_IMPL( KEY, VALUE, NAME ) \
template class omi_BtreeNode<KEY,VALUE>; \
template class omi_Btree<KEY,VALUE>; \
template class omi_BtreeNodeLink<KEY,VALUE>; \
template class omi_BtreeIterator<KEY,VALUE>;

#define OMI_BTREE_DECL( KEY, VALUE, NAME ) \
typedef omi_Btree<KEY,VALUE> NAME; \
typedef omi_BtreeIterator<KEY,VALUE> NAME ## IT; \
typedef omi_BtreeIterator<KEY,VALUE> NAME ## SIT;

#endif
