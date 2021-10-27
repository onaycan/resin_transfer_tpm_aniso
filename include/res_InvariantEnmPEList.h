#ifndef res_InvariantEnmPEList_h
#define res_InvariantEnmPEList_h

// Begin local includes
#include <mem_AllocationOperators.h>

#include <cow_List.h>

#include <utf_ResEnum.h>

#include <cls_Uid.h>
#include <cls_TypeTable.h>
#include <cls_CollectionType.h>
#include <cls_FieldHandle.h>

// End local includes

COW_LIST_DECL(res_InvariantEnmPE,res_IEPL);

class cls_ReadVisitor;
class cls_WriteVisitor;

class res_InvariantEnmPEList  : public mem_AllocationOperators
{
public:
  inline res_InvariantEnmPEList() : m_ClsUid(cls_Uid::AllocateUid()) {};

  res_InvariantEnmPEList(const cls_ReadVisitor& rv);
  void DBWrite(const cls_WriteVisitor& wv) const;

  // This list of methods may need to be extended.  I've only provided
  // what was used when this class was written.
  inline bool IsMember(const res_InvariantEnmPE& item) const { return m_List.IsMember(item); };
  inline const res_InvariantEnmPE& ConstGet(unsigned int i) const { return m_List.ConstGet(i); };
  inline int Size() const { return m_List.Length(); };
  inline bool IsEmpty() const { return m_List.IsEmpty(); };
  inline void Append(const res_InvariantEnmPE& enm) { m_List.Append(enm); };
  inline void AppendUnlessMember(const res_InvariantEnmPE& enm) { m_List.AppendUnlessMember(enm); };
  inline void ClearAll() { m_List.Clear(); };

  inline bool operator==(const res_InvariantEnmPEList& rhs) const { return this == &rhs || m_List == rhs.m_List; };

private:
  res_IEPL m_List;
  cls_Uid m_ClsUid;
};

#define RES_ATTR_InvariantEnmPEList(MEMBER) AddAttribute(#MEMBER, cls_ObjectT, TYP_TIX_cls_List, cls_ColListObjT) 
#define RES_ATTR_InvariantEnmPEList_I(MEMBER) AddAttribute(cls_FieldHandle(#MEMBER,e_ ## MEMBER), cls_ObjectT, TYP_TIX_cls_List, cls_ColListObjT)

#endif
