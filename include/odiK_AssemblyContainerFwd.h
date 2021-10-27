#ifndef odiK_AssemblyContainerFwd_h
#define odiK_AssemblyContainerFwd_h

class odiK_Assembly;
class cow_String;
template <class Type> struct cow_Virtual;
typedef cow_Virtual<odiK_Assembly> odiK_AssemblyDup;
template <class T, class DUP> class cow_ArrayCOW;
typedef cow_ArrayCOW<odiK_Assembly, odiK_AssemblyDup> odiK_AssemblyCOW;
template <class KEY, class ITEM, class COW> class cls_Map2Obj;
typedef cls_Map2Obj<cow_String, odiK_Assembly, odiK_AssemblyCOW> odiK_AssemblyContainer;

#endif
