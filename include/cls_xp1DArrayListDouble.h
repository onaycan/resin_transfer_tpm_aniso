#ifndef cls_xp1DArrayListDouble_h
#define cls_xp1DArrayListDouble_h

// Begin local includes

#include <cow_ListDouble.h>

#include <cls_TypeTable.h>
#include <cls_Uid.h>

// End local includes

class cls_ReadVisitor;
class cls_WriteVisitor;

class cls_xp1DArrayListDouble : public cow_ListDouble
{
public:
  inline cls_xp1DArrayListDouble() : m_ExternalUid(NULL) {};
  inline cls_xp1DArrayListDouble(int sz) : cow_ListDouble(cow_EstimateLength, sz), m_ExternalUid(NULL) {};

  // These constructors should be used when writing temporary objects, that have
  // their UIDs stored in the owner class.
  cls_xp1DArrayListDouble( const cls_Uid &uid )
      : m_ClsUid(uid), m_ExternalUid( const_cast<cls_Uid*>(&uid) ) {};
  cls_xp1DArrayListDouble( const cls_Uid &uid, int sz)
      : cow_ListDouble(cow_EstimateLength, sz), m_ClsUid(uid), m_ExternalUid( const_cast<cls_Uid*>(&uid) ) {};
  cls_xp1DArrayListDouble( const cls_Uid &uid, const cow_ListDouble &lst )
      : cow_ListDouble(lst), m_ClsUid(uid), m_ExternalUid( const_cast<cls_Uid*>(&uid) ) {}

  ~cls_xp1DArrayListDouble();

  cls_xp1DArrayListDouble& operator=(const cow_ListDouble& rhs);

  cls_xp1DArrayListDouble(const cls_ReadVisitor& rv, cls_Uid *externalUid = NULL);
  void DBWrite(const cls_WriteVisitor& wv) const;

private:
  cls_Uid m_ClsUid;
  cls_Uid *m_ExternalUid;
};

inline bool operator==(const cls_xp1DArrayListDouble& a, const cls_xp1DArrayListDouble& b) { return a.IsEqual(b); };
inline bool operator!=(const cls_xp1DArrayListDouble& a, const cls_xp1DArrayListDouble& b) { return !(a.IsEqual(b)); };

cls_xp1DArrayListDouble cls_xp1DArrayListDoubleFromCow(const cow_ListDouble& cow);

#define CLS_ATTR_xp1DArrayListDouble(MEMBER) AddAttribute(#MEMBER, cls_ObjectT, TYP_TIX_cls_List, cls_ColListDoubleT)
#define CLS_ATTR_xp1DArrayListDouble_I(MEMBER) AddAttribute(cls_FieldHandle(#MEMBER,e_ ## MEMBER), cls_ObjectT, TYP_TIX_cls_List, cls_ColListDoubleT)

#endif
