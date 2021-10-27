/* -*- mode: c++ -*- */
#ifndef cow_Btree_T
#define cow_Btree_T
//
// Includes
//

#include <assert.h>
#include <memory.h>


// Begin local includes

#include <cow_Btree.h>
#include <cow_BtreeCompare.h>

template <class Key, class Value>
cow_BtreeNode<Key,Value>::~cow_BtreeNode()
{
    if( leftNode ) delete leftNode;
    if( rightNode ) delete rightNode;
}

template <class Key, class Value>
cow_Btree<Key,Value>::~cow_Btree() 
{
    if( treeNode ) delete treeNode;
}

template <class Key, class Value>
cow_BtreeNode<Key,Value>::cow_BtreeNode(const Key &key, const Value &value ) :
    nodeKey(key),
    nodeValue(value),
    leftNode(0),
    rightNode(0),
    maxDepth(0)
{
}

template <class Key, class Value>
cow_BtreeNode<Key,Value>::cow_BtreeNode(const cow_BtreeNode<Key,Value> &node ) :
    nodeKey(node.nodeKey),
    nodeValue(node.nodeValue),
    leftNode(0),
    rightNode(0),
    maxDepth(node.maxDepth)
{
    if( node.leftNode ) leftNode = new cow_BtreeNodeCow( *(node.leftNode) );
    if( node.rightNode ) rightNode = new cow_BtreeNodeCow( *(node.rightNode) );
}


#include <cow_COW.T>

template <class Key, class Value>
cow_COW<cow_BtreeNode<Key,Value>, cow_Direct<cow_BtreeNode<Key,Value> > >*
cow_BtreeNode<Key,Value>::Balance( cow_BtreeNodeCow* cowofthis )
{
    int leftdepth = leftNode != 0 ? leftNode->ConstGet().MaxDepth() : 0;
    int rightdepth = rightNode != 0 ? rightNode->ConstGet().MaxDepth() : 0;

    int delta = rightdepth - leftdepth;

    if( delta > 1 )
    {
        //shift to the left
        cow_BtreeNodeCow* ptr = rightNode;
	cow_BtreeNode<Key,Value> &node = ptr->Get();
	rightNode = node.leftNode;
	node.leftNode = cowofthis;
	SetMaxDepth();
	node.SetMaxDepth();
	return ptr;
    }
    else if( delta < -1 )
    {
        //shift to the right
        cow_BtreeNodeCow* ptr = leftNode;
	cow_BtreeNode<Key,Value> &node = ptr->Get();
	leftNode = node.rightNode;
	node.rightNode = cowofthis;
	SetMaxDepth();
	node.SetMaxDepth();
	return ptr;
    }
    return 0;
}

template <class Key, class Value>
bool
cow_BtreeNode<Key,Value>::InsertUnlessMember(const Key &key, const Value &value)
{
    int comparison =  BtreeCompare( nodeKey, key );
    
    if( ! comparison ) return false; //cannot insert duplicate keys

    cow_BtreeNodeCow* &childptr = (comparison > 0 ) ? rightNode : leftNode;
    bool retval;

    if( ! childptr )
    {
        childptr = new cow_BtreeNodeCow(new cow_BtreeNode<Key,Value>( key, value ));
	SetMaxDepth();
	return true;
    }

    cow_BtreeNode<Key,Value> &child = childptr->Get(); //copy on non-const
    retval = child.InsertUnlessMember( key, value );	
    if( retval )
    {
        cow_BtreeNodeCow* ptr = 0;
	ptr = child.Balance(childptr);
	if( ptr )
	    childptr = ptr;
	SetMaxDepth();
    }

    return retval;
}

template <class Key, class Value>
void
cow_BtreeNode<Key,Value>::RemoveNode(cow_BtreeNode<Key,Value>* ptr,
				     cow_BtreeNodeCow* replacement)
{
    if( rightNode && ((void *)ptr == ((void *)&(rightNode->ConstGet()))))
    {
	 delete rightNode;
	 rightNode = replacement;
    }
    else
    {
	 delete leftNode;
	 leftNode = replacement;
    }
    
    SetMaxDepth();
}

template <class Key, class Value>
bool
cow_BtreeNode<Key,Value>::Remove(const Key &key,
                                 cow_BtreeNode<Key,Value> &parent )
{
    int comparison =  BtreeCompare( nodeKey, key );
    
    if( ! comparison ) {
        //this is the node to remove
        cow_BtreeNodeCow* replacement;
	if( rightNode )
	{
	     if( ! leftNode )
		  replacement = rightNode;
	     else
	     {
		  // descend to the farthest left node of rightNode
		  replacement = rightNode;
		  cow_BtreeNode<Key,Value> *node = this;
		  cow_BtreeNode <Key,Value> *repnode = &replacement->Get();
		  while( repnode->leftNode )
		  {
		       node = repnode;
		       replacement = repnode->leftNode;
		       repnode = &replacement->Get();
		  }
		  if( node != this )
		  {
		       node->leftNode = repnode->rightNode;
		       repnode->rightNode = rightNode;
		       node->SetMaxDepth();
		  }
		  repnode->leftNode = leftNode;
		  repnode->SetMaxDepth();
	     }
	     
	}
	else
	     replacement = leftNode;
	
	leftNode = rightNode = 0;
	parent.RemoveNode(this, replacement);
	return true;
    }

    cow_BtreeNodeCow* &childptr = (comparison > 0 ) ? rightNode : leftNode;

    if( childptr )
    {
	cow_BtreeNode<Key,Value> &child = childptr->Get(); //copy on non-const
	bool retval;
	cow_BtreeNodeCow* ptr;
        retval = child.Remove( key, *this );
	if( retval )
	{
	    if( childptr )
	    {
	      ptr = childptr->Get().Balance(childptr);
	        if ( ptr ) 
  	          childptr = ptr;
	    }
	    SetMaxDepth();
        }
        return retval;
    }

    return false;
}

template <class Key, class Value>
cow_BtreeNode<Key,Value>*
cow_BtreeNode<Key,Value>::Find( const Key &key )
{
    int comparison =  BtreeCompare( nodeKey, key );
    
    if( ! comparison ) 
        return this;  //found!!

    cow_BtreeNodeCow* &childptr = (comparison > 0 ) ? rightNode : leftNode;

    if( childptr ) 
        return childptr->Get().Find( key );

    return 0;
}

template <class Key, class Value>
const cow_BtreeNode<Key,Value>*
cow_BtreeNode<Key,Value>::ConstFind( const Key &key ) const
{
    int comparison =  BtreeCompare( nodeKey, key );
    
    if( ! comparison ) 
        return this;  //found!!

    cow_BtreeNodeCow *const &childptr = (comparison > 0 ) ? rightNode : leftNode;

    if( childptr ) 
        return childptr->ConstGet().ConstFind( key );

    return 0;
}



//
// cow_Btree class methods
//

template <class Key, class Value>
cow_Btree<Key,Value>::cow_Btree() :
    treeNode(0),
    nodeCount(0),
    nullValue()
{
}

template <class Key, class Value>
cow_Btree<Key,Value>::cow_Btree( const cow_Btree<Key,Value> &tree) :
    treeNode(0),
    nodeCount(tree.nodeCount),
    nullValue(tree.nullValue)
{

    if (tree.treeNode)
    {
        treeNode = new cow_BtreeNodeCow(*tree.treeNode);
    }
}

template <class Key, class Value>
const cow_Btree<Key,Value>&
cow_Btree<Key,Value>::operator=(const cow_Btree<Key,Value>& tree)
{
    if (&tree == this){
        return *this;
    }

    if (tree.treeNode)
    {
        if (treeNode == 0)
            treeNode = new cow_BtreeNodeCow(*tree.treeNode);
        else
            *treeNode = *(tree.treeNode);
    }
    else
        treeNode = 0;

    nodeCount = tree.nodeCount;
    nullValue = tree.nullValue;
    return *this;
}

template <class Key, class Value>
cow_Btree<Key,Value>*
cow_Btree<Key,Value>::Copy() const
{
    return new cow_Btree<Key,Value>(*this);
}




template <class Key, class Value>
bool
cow_Btree<Key,Value>::Remove( const Key &key )
{
    if( ! treeNode ) return false;
    bool retval;
    Key tempKey;
    cow_BtreeNodeInst tmpnode(tempKey, nullValue);
    tmpnode.leftNode = treeNode;
    retval = treeNode->Get().Remove(key,tmpnode);
    if( retval )
    {
        nodeCount--;
	treeNode = tmpnode.leftNode; //in case root node was removed
	tmpnode.leftNode = 0;
	if( treeNode )
	{
	     cow_BtreeNodeCow *ptr;
	     cow_BtreeNode<Key,Value> &node = treeNode->Get();
             ptr = node.Balance(treeNode);	
	     if( ptr ) treeNode = ptr;
	}
	
    }
    return retval;
}

template <class Key, class Value>
bool
cow_Btree<Key,Value>::InsertUnlessMember( const Key &key, const Value &value )
{
    if( ! treeNode ) 
    {
       treeNode = new cow_BtreeNodeCow(new cow_BtreeNode<Key,Value>(key,value));
       nodeCount = 1;
       return true;
    }
    cow_BtreeNode<Key,Value> &node = treeNode->Get();

    bool retval = node.InsertUnlessMember(key,value);
    if( retval )
    {
	 nodeCount++;
	 cow_BtreeNodeCow* ptr = node.Balance(treeNode);
	 if( ptr )
	      treeNode = ptr;
    }
    return retval;
}

template <class Key, class Value>
const cow_BtreeNode<Key,Value>*
cow_Btree<Key,Value>::ConstFind( const Key &key ) const
{
     if( ! treeNode ) return 0;
     const cow_BtreeNode<Key,Value>* ptr = &treeNode->ConstGet();
     int comparison;
     while((comparison = BtreeCompare( ptr->nodeKey, key )) != 0 )
     {
	  cow_BtreeNodeCow *const &childPtr = (comparison > 0 ) ? ptr->rightNode : ptr->leftNode;
	  if( ! childPtr ) return 0;
	  ptr = &childPtr->ConstGet();
     }
     return ptr;
}

template <class Key, class Value>
cow_BtreeNode<Key,Value>*
cow_Btree<Key,Value>::Find( const Key &key )
{
     if( ! treeNode ) return 0;
     cow_BtreeNode<Key,Value>* ptr = &treeNode->Get();
     int comparison;
     while((comparison = BtreeCompare( ptr->nodeKey, key )) != 0 )
     {
	  cow_BtreeNodeCow * &childPtr = (comparison > 0 ) ? ptr->rightNode : ptr->leftNode;
	  if( ! childPtr ) return 0;
	  ptr = &childPtr->Get();
     }
     return ptr;
}


//
// cow_BtreeInterator  implementation
//
template <class Key, class Value>
cow_BtreeIterator<Key,Value>::cow_BtreeIterator( const cow_Btree<Key,Value> &tree ) :
    treeRef(tree),
    nodeStack(0)
{
}

template <class Key, class Value>
cow_BtreeIterator<Key,Value>::~cow_BtreeIterator( )
{
    ClearStack();
}

template <class Key, class Value>
void
cow_BtreeIterator<Key,Value>::First()
{
    ClearStack();
    if( ! treeRef.treeNode ) return;
    Push( treeRef.treeNode );

    //push the stack and drop the the left-most node
    const cow_BtreeNodeCow *node;
    while( (node = nodeStack->Node()->ConstGet().leftNode) != 0 )
        Push( node );
}

template <class Key, class Value>
void
cow_BtreeIterator<Key,Value>::Next()
{
    const cow_BtreeNodeCow *node = nodeStack->Node()->ConstGet().rightNode;
    if( node )
    {
	//push the stack and drop the the left-most node
	do
	    Push( node );
	while( (node = nodeStack->Node()->ConstGet().leftNode)!= 0 );
    }
    else
    {
        //Pop the stack until popping from the left
	do
	{
	    node = nodeStack->Node();
	    Pop();
	}
	while( nodeStack && (node == nodeStack->Node()->ConstGet().rightNode) );

    }
}

template <class Key, class Value>
void
cow_BtreeIterator<Key,Value>::Last()
{
    ClearStack();
    if( ! treeRef.treeNode ) return;
    Push( treeRef.treeNode );

    //push the stack and drop the the right-most node
    const cow_BtreeNodeCow *node;
    while( (node = nodeStack->Node()->ConstGet().rightNode) != 0 )
        Push( node );
}

template <class Key, class Value>
void
cow_BtreeIterator<Key,Value>::Previous()
{
    const cow_BtreeNodeCow *node = nodeStack->Node()->ConstGet().leftNode;
    if( node )
    {
	//push the stack and drop the the right-most node
	do
	    Push( node );
	while( (node = nodeStack->Node()->ConstGet().rightNode) != 0 );
    }
    else
    {
        //Pop the stack until popping from the right
	do
	{
	    node = nodeStack->Node();
	    Pop();
	}
	while( nodeStack && (node == nodeStack->Node()->ConstGet().leftNode) );

    }
}

#endif
