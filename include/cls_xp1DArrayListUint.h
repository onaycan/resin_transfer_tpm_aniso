#ifndef cls_xp1DArrayListUint_h
#define cls_xp1DArrayListUint_h

// Begin local includes

#include <cow_ListUint.h>

#include <cls_TypeTable.h>
#include <cls_Uid.h>

// End local includes

class cls_ReadVisitor;
class cls_WriteVisitor;

class cls_xp1DArrayListUint : public cow_ListUint
{
public:
  inline cls_xp1DArrayListUint() : m_ExternalUid(NULL) {};
  inline cls_xp1DArrayListUint(int sz) : cow_ListUint(cow_EstimateLength, sz), m_ExternalUid(NULL) {};

  // These constructors should be used when writing temporary objects, that have
  // their UIDs stored in the owner class.
  inline cls_xp1DArrayListUint( const cls_Uid &uid )
      : m_ClsUid(uid), m_ExternalUid( const_cast<cls_Uid*>(&uid) ) {};
  inline cls_xp1DArrayListUint( const cls_Uid &uid, int sz)
      : cow_ListUint(cow_EstimateLength, sz), m_ClsUid(uid), m_ExternalUid( const_cast<cls_Uid*>(&uid) ) {};
  cls_xp1DArrayListUint( const cls_Uid &uid, const cow_ListUint &lst )
      : cow_ListUint(lst), m_ClsUid(uid), m_ExternalUid( const_cast<cls_Uid*>(&uid) ) {}

  ~cls_xp1DArrayListUint();

  cls_xp1DArrayListUint& operator=(const cow_ListUint& rhs);

  cls_xp1DArrayListUint(const cls_ReadVisitor& rv, cls_Uid *externalUid = NULL);
  void DBWrite(const cls_WriteVisitor& wv) const;

private:
  cls_Uid m_ClsUid;
  cls_Uid *m_ExternalUid;
};

inline bool operator==(const cls_xp1DArrayListUint& a, const cls_xp1DArrayListUint& b) { return a.IsEqual(b); };
inline bool operator!=(const cls_xp1DArrayListUint& a, const cls_xp1DArrayListUint& b) { return !(a.IsEqual(b)); };

cls_xp1DArrayListUint cls_xp1DArrayListUintFromCow(const cow_ListUint& cow);

#define CLS_ATTR_xp1DArrayListUint(MEMBER) AddAttribute(#MEMBER, cls_ObjectT, TYP_TIX_cls_List, cls_ColListUintT)
#define CLS_ATTR_xp1DArrayListUint_I(MEMBER) AddAttribute(cls_FieldHandle(#MEMBER,e_ ## MEMBER), cls_ObjectT, TYP_TIX_cls_List, cls_ColListUintT)

#endif
