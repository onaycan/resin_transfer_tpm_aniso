//////////////////////////////////////////////////////////////////////////////
//
// Collection of utility functions used by odb_FieldOutput::addData(odb_Set&)
// 
//
//
//////////////////////////////////////////////////////////////////////////////
#ifndef odb_FieldAddDataUtils_h
#define odb_FieldAddDataUtils_h

// Begin local includes
#include <utf_ResEnum.h>
#include <odb_Enum.h>
#include <cow_ArrayCOW.h>
#include <cow_COW.h>
// End local includes

// Forward declarations 
class cow_String;
template <class T>
class cow_List;
typedef cow_List<cow_String> cow_ListString;
typedef cow_List<float> cow_ListFloat;
typedef cow_List<cow_ListFloat> cow_ListListFloat;

template <class T1, class T2>
class odb_Sequence;
class odb_String;
class odb_Set;

typedef odb_Sequence<odb_String,cow_ListString> odb_SequenceString;
class odb_SequenceFloat;
class odb_SequenceSequenceFloat;
class res_Invariant;
class res_ComponentMap;
class odiK_BaseInstance;
template < class T1>
class ddr_Shortcut;
typedef ddr_Shortcut<odiK_BaseInstance> odiK_BaseInstanceShortcut;

class odiK_Assembly;
class odiK_ElementClass;

class res_FieldDescription;

template <class T1>
class res_Holder;
typedef res_Holder<float> res_FieldDataFloat;
class res_FieldFrame;

class ddb_Assembly;
COW_ARRAYCOW_DECL(ddb_Assembly);
class ddb_FieldStep;
COW_COW_DECL(ddb_FieldStep);

class ddr_Ddb;

template < class A, class B>
class mdl_Container;
typedef mdl_Container<cow_String,ddr_Ddb> ddr_DdbContainer;

// FUNCTION DECLARATIONS
void checkSet(const ddr_DdbContainer& ,const ddb_AssemblyCOW currAssembly, 
              const odb_Set& userSet, odb_Enum::odb_ResultPositionEnum position, 
              int& meshIndex);
int setInvariants(res_Invariant&, const odb_SequenceInvariant&);
void setComponents(res_ComponentMap&, const odb_SequenceString&, res_DataTypeEnm );
int getNumValuesPerElement(const odiK_ElementClass&, res_OutputPositionEnm);
odiK_BaseInstanceShortcut baseInstanceSCFromMeshIndex(const odiK_Assembly&,int );
void setResultsData(ddr_DdbContainer& ,
                    const res_FieldDescription& , 
                    res_FieldFrame& ,
                    const ddb_FieldStep& ,
                    int startIndex,
                    int endIndex,
                    const odb_SequenceSequenceFloat& ,
                    const odb_SequenceSequenceFloat& );
#endif // odb_FieldAddDataUtils_h
