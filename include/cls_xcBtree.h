// -*- Mode: C++ -*-
#ifndef cls_xcBtree_h
#define cls_xcBtree_h

// Begin local includes

#include <cow_String.h>
#include <cow_Btree.h>

#include <cls_Uid.h>
#include <cls_TypeTable.h>
#include <cls_CollectionType.h>
#include <cls_FieldHandle.h>

// End local includes

class cls_ReadVisitor;
class cls_WriteVisitor;

#undef TYPENAME
#if defined(ABQ_LINUX) && ! defined(ABQ_LNXPWR)
#define TYPENAME typename
#else
#define TYPENAME
#endif

template <class KEY, class CTYPE, class TYPE>
class cls_xcBtree : public cow_Btree<KEY,CTYPE>
{
public:
  inline cls_xcBtree() : m_ClsUid(cls_Uid::AllocateUid()) {};

  cls_xcBtree<KEY,CTYPE,TYPE>& operator=(const cow_Btree<KEY,CTYPE>& rhs);

  cls_xcBtree(const cls_ReadVisitor& rv);
  void DBWrite(const cls_WriteVisitor& wv) const;

private:
  cls_Uid m_ClsUid;
};

template <class KEY, class CTYPE, class TYPE>
cls_xcBtree<KEY,CTYPE,TYPE> cls_xcBtreeFromCow(const cow_Btree<KEY,CTYPE>& cow, TYPE*);

#define CLS_xcBTREE_DECL(K,C,T,N)\
typedef cls_xcBtree<K,C,T> N;\
COW_BTREE_DECL(K,C,N ## COWBTREE);

#define CLS_xcBTREE_DECL_ADD(K,C,T,N)\
typedef cls_xcBtree<K,C,T> N;

#define CLS_xcBTREE_IMPL(K,C,T,N)\
template class cls_xcBtree<K,C,T>;\
template cls_xcBtree<K,C,T> cls_xcBtreeFromCow(const cow_Btree<K,C>& cow, T*);\
COW_BTREE_IMPL(K,C,N ## COWBTREE);

#define CLS_xcBTREE_IMPL_ADD(K,C,T,N)\
template class cls_xcBtree<K,C,T>;

#define CLS_ATTR_xcBtree(MEMBER) AddAttribute(#MEMBER,cls_ObjectT,TYP_TIX_cls_Map,cls_ColMapString2ObjT) 
#define CLS_ATTR_xcBtree_I(MEMBER) AddAttribute(cls_FieldHandle(#MEMBER,e_ ## MEMBER),cls_ObjectT,TYP_TIX_cls_Map,cls_ColMapString2ObjT)

#define CLS_ATTR_xcBtreeInt2Obj(MEMBER) AddAttribute(#MEMBER,cls_ObjectT,TYP_TIX_cls_Map,cls_ColMapInt2ObjT) 
#define CLS_ATTR_xcBtreeInt2Obj_I(MEMBER) AddAttribute(cls_FieldHandle(#MEMBER,e_ ## MEMBER),cls_ObjectT,TYP_TIX_cls_Map,cls_ColMapInt2ObjT)

#endif
