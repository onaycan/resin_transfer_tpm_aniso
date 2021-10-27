#ifndef cls_ClassMetadata_h
#define cls_ClassMetadata_h

// Begin local includes
#include <mem_AllocationOperators.h>

#include <typ_typeTag.h>

#include <cow_String.h>

#include <cls_FieldHandle.h>
#include <cls_CtorDtorDefs.h>
#include <cls_AttributeType.h>
#include <cls_AttributeMetadata.h>
#include <cls_MapName2AttrMD.h>
#include <cls_IntCOW.h>
#include <cls_CollectionType.h>
// End local includes

// Forward declarations
template <class A>
class omi_BlockedArray;


#define CLS_ATTR_CHAR(MEMBER) AddAttribute(#MEMBER,cls_CharT)
#define CLS_ATTR_CHAR_I(MEMBER) AddAttribute(cls_FieldHandle(#MEMBER,e_ ## MEMBER),cls_CharT,typ_NONE)

#define CLS_ATTR_UCHAR(MEMBER) AddAttribute(#MEMBER,cls_UCharT)
#define CLS_ATTR_UCHAR_I(MEMBER) AddAttribute(cls_FieldHandle(#MEMBER,e_ ## MEMBER),cls_UCharT,typ_NONE)

#define CLS_ATTR_SHORT(MEMBER) AddAttribute(#MEMBER,cls_ShortT)
#define CLS_ATTR_SHORT_I(MEMBER) AddAttribute(cls_FieldHandle(#MEMBER,e_ ## MEMBER),cls_ShortT,typ_NONE)

#define CLS_ATTR_USHORT(MEMBER) AddAttribute(#MEMBER,cls_UShortT)
#define CLS_ATTR_USHORT_I(MEMBER) AddAttribute(cls_FieldHandle(#MEMBER,e_ ## MEMBER),cls_UShortT,typ_NONE)

#define CLS_ATTR_INT(MEMBER) AddAttribute(#MEMBER,cls_IntT)
#define CLS_ATTR_INT_I(MEMBER) AddAttribute(cls_FieldHandle(#MEMBER,e_ ## MEMBER),cls_IntT,typ_NONE)

#define CLS_ATTR_INT64(MEMBER) AddAttribute(#MEMBER,cls_Int64T)
#define CLS_ATTR_INT64_I(MEMBER) AddAttribute(cls_FieldHandle(#MEMBER,e_ ## MEMBER),cls_Int64T,typ_NONE)

#define CLS_ATTR_UINT(MEMBER) AddAttribute(#MEMBER,cls_UIntT)
#define CLS_ATTR_UINT_I(MEMBER) AddAttribute(cls_FieldHandle(#MEMBER,e_ ## MEMBER),cls_UIntT,typ_NONE)

#define CLS_ATTR_UINT64(MEMBER) AddAttribute(#MEMBER,cls_UInt64T)
#define CLS_ATTR_UINT64_I(MEMBER) AddAttribute(cls_FieldHandle(#MEMBER,e_ ## MEMBER),cls_UIntT,typ_NONE)

#define CLS_ATTR_FLOAT(MEMBER) AddAttribute(#MEMBER,cls_FloatT)
#define CLS_ATTR_FLOAT_I(MEMBER) AddAttribute(cls_FieldHandle(#MEMBER,e_ ## MEMBER),cls_FloatT,typ_NONE)

#define CLS_ATTR_DOUBLE(MEMBER) AddAttribute(#MEMBER,cls_DoubleT)
#define CLS_ATTR_DOUBLE_I(MEMBER) AddAttribute(cls_FieldHandle(#MEMBER,e_ ## MEMBER),cls_DoubleT,typ_NONE)

#define CLS_ATTR_STRING(MEMBER) AddAttribute(#MEMBER,cls_StringT)
#define CLS_ATTR_STRING_I(MEMBER) AddAttribute(cls_FieldHandle(#MEMBER,e_ ## MEMBER),cls_StringT,typ_NONE)

#define CLS_ATTR_TRSTRING(MEMBER) AddAttribute(#MEMBER,cls_TRStringT)
#define CLS_ATTR_TRSTRING_I(MEMBER) AddAttribute(cls_FieldHandle(#MEMBER,e_ ## MEMBER),cls_TRStringT,typ_NONE)

#define CLS_ATTR_BOOL(MEMBER) AddAttribute(#MEMBER,cls_BoolT)
#define CLS_ATTR_BOOL_I(MEMBER) AddAttribute(cls_FieldHandle(#MEMBER,e_ ## MEMBER),cls_BoolT,typ_NONE)

#define CLS_ATTR_ENUM(MEMBER) AddAttribute(#MEMBER,cls_EnumT)
#define CLS_ATTR_ENUM_I(MEMBER) AddAttribute(cls_FieldHandle(#MEMBER,e_ ## MEMBER),cls_EnumT,typ_NONE)

#define CLS_ATTR_ENUM_AS_INT(MEMBER) CLS_ATTR_INT(MEMBER)
#define CLS_ATTR_ENUM_AS_INT_I(MEMBER) CLS_ATTR_INT_I(MEMBER)

#define CLS_ATTR_OBJ(MEMBER,CLASS) AddAttribute(#MEMBER,cls_ObjectT,CLASS::TypeId())
#define CLS_ATTR_OBJ_I(MEMBER,CLASS) AddAttribute(cls_FieldHandle(#MEMBER,e_ ## MEMBER),cls_ObjectT,CLASS::TypeId())

#define CLS_ATTR_OBJP(MEMBER,CLASS) CLS_ATTR_OBJ(MEMBER,CLASS)
#define CLS_ATTR_OBJP_I(MEMBER,CLASS) CLS_ATTR_OBJ_I(MEMBER,CLASS)

#define CLS_ATTR_COLOBJ(MEMBER,CLASS,COLTYPE) AddAttribute(#MEMBER,cls_ObjectT,CLASS::TypeId(),COLTYPE)
#define CLS_ATTR_COLOBJ_I(MEMBER,CLASS,COLTYPE) AddAttribute(cls_FieldHandle(#MEMBER,e_ ## MEMBER),cls_ObjectT,CLASS::TypeId(),COLTYPE)

#define CLS_ATTR_COW(MEMBER,CLASS) AddAttribute(#MEMBER,cls_ObjectT,CLASS::TypeId())
#define CLS_ATTR_COW_I(MEMBER,CLASS) AddAttribute(cls_FieldHandle(#MEMBER,e_ ## MEMBER),cls_ObjectT,CLASS::TypeId())

#define CLS_ATTR_BLOB(MEMBER) AddAttribute(#MEMBER,cls_BlobT,TYP_TIX_cls_Blob,cls_ColBlobT)
#define CLS_ATTR_BLOB_I(MEMBER) AddAttribute(cls_FieldHandle(#MEMBER,e_ ## MEMBER),cls_BlobT,TYP_TIX_cls_Blob,cls_ColBlobT)

class cls_AttributeMetadata;
class cls_ReadVisitor;
class cls_WriteVisitor;

class cls_ClassMetadata  : public mem_AllocationOperators
{
  friend class omi_BlockedArray<cls_ClassMetadata>;
public:

  cls_ClassMetadata(const cow_String& name,
                     typ_typeTag cid,int version=1,
                     cls_Ctor ctor = NULL,
                     typ_typeTag bcid = typ_NONE);

  virtual ~cls_ClassMetadata();

  cls_ClassMetadata& AddAttribute(const cls_FieldHandle& fieldHandle,
                                  cls_AttributeType type,
                                  typ_typeTag cid = typ_NONE,
                                  cls_CollectionType colType = cls_ColNotACollectionT);

  cls_ClassMetadata& AddDtor(cls_Dtor dtor);
  cls_ClassMetadata& AddTableExtentQuantum(int extentQuantum);

  inline typ_typeTag ClassID() const { return m_ClassID; };
  inline typ_typeTag BaseClassID() const { return m_BaseClassID; };
  inline int TableExtentQuantum() const { return m_ExtentQuantum; };
  inline const cow_String&  Name() const { return m_Name; };
  inline int GetVersion() const { return m_Version;}; 
  inline bool HasDtor() const { return m_Dtor != NULL; };

  inline const cls_MapName2AttrMD& AttrMDMap (void) const { return m_Map; };

  int MaxFieldID() const;

  // virtual methods to enable template derivation for type safe method forwarding
  virtual void DBWrite(const void *ptr, const cls_WriteVisitor &wv ) const ;
  virtual void Delete(void *ptr) const ;
  virtual void DeleteCow(cls_IntCOW*) const ;
  virtual void* Ctor(const cls_ReadVisitor& rv) const;


private:
  // Disabled.
  cls_ClassMetadata& operator= (const cls_ClassMetadata&);
  cls_ClassMetadata (const cls_ClassMetadata&);
  cls_ClassMetadata();

  cow_String m_Name;
  typ_typeTag m_ClassID;
  typ_typeTag m_BaseClassID;
  cls_Ctor m_Ctor;
  cls_Dtor m_Dtor;

  int m_ExtentQuantum;

  int m_Version;
  cls_MapName2AttrMD m_Map;
};

#endif
