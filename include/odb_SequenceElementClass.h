/* -*- mode: c++ -*- */
#ifndef odb_SequenceElementClass_h
#define odb_SequenceElementClass_h

// Begin local includes
#include <odb_ElementClass.h>
#include <odb_Sequence.h>
#include <cow_List.h>
// End local includes

COW_LIST_DECL(odb_ElementClass, odb_ListElementClass);
ODB_SEQUENCE_DECL(odb_ElementClass, odb_ListElementClass, odb_SequenceElementClass);

#endif // #ifndef odb_SequenceElementClass_h
