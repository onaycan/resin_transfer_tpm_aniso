#ifndef cls_AttributeType_h
#define cls_AttributeType_h

enum cls_AttributeType
{
  cls_NoneT = 0
  , cls_CharT
  , cls_UCharT
  , cls_ShortT
  , cls_UShortT
  , cls_IntT
  , cls_Int64T
  , cls_UIntT
  , cls_UInt64T
  , cls_FloatT
  , cls_DoubleT
  , cls_StringT
  , cls_TRStringT
  , cls_BoolT
  , cls_EnumT
  , cls_ObjectT
  , cls_CollectionT
  , cls_BlobT

  // Collection (and COW) as object tables.
  // These are not used by client code.
  , cls_InternalListT
  , cls_InternalMapT
  , cls_InternalBlobT
  , cls_InternalCowT
  , cls_InternalDblColT
};


#endif
