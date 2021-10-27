#ifndef cls_MapName2AttrMD_h
#define cls_MapName2AttrMD_h

// Begin local includes

#include <omi_Btree.h>
#include <cow_BtreeCompare.h>
#include <cow_String.h>
#include <cls_AttributeMetadata.h>

// End local includes

OMI_BTREE_DECL(cow_String, cls_AttributeMetadata, cls_MapName2AttrMD);

#endif
