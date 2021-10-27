#ifndef cls_AttributeMetadata_h
#define cls_AttributeMetadata_h

///////////////////////////////////////////////////////////////////////////////
//
//
// Description:
//   Metadata descriptions of data members of a class
//
// Modification history:
//      Rob deFriesse 7/99 original
//
////////////////////////////////////////////////////////////////////////// */

// Begin local includes
#include <mem_AllocationOperators.h>

#include <typ_typeTag.h>

#include <cow_String.h>
#include <cls_AttributeType.h>
#include <cls_FieldHandle.h>
#include <cls_CollectionType.h>

// End local includes

class cls_AttributeMetadata  : public mem_AllocationOperators
{
public:
  cls_AttributeMetadata(const cls_FieldHandle& fieldHandle,
                        cls_AttributeType type,
                        typ_typeTag cid = typ_NONE,
                        cls_CollectionType colType = cls_ColNotACollectionT)
    : m_FieldHandle(fieldHandle),
      m_Type(type),
      m_ClassID(cid),
      m_ColType(colType)
    { }

  // Accessors
  inline const cow_String& Name (void) const { return m_FieldHandle.Name(); };
  inline cls_AttributeType Type (void) const { return m_Type; };
  inline typ_typeTag ClassID (void) const { return m_ClassID; };
  inline int FieldID(void) const { return m_FieldHandle.ID(); };
  inline cls_CollectionType CollectionType() const { return m_ColType; };

private:
  // Data members
  cls_FieldHandle m_FieldHandle;
  cls_AttributeType m_Type;
  typ_typeTag m_ClassID;
  cls_CollectionType m_ColType;
};

#endif
