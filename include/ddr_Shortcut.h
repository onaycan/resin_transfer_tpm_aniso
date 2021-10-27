#ifndef ddr_Shortcut_h
#define ddr_Shortcut_h

// Begin local includes
#include <cow_String.h>
#include <cls_IntCOW.h>
#include <cls_Uid.h>
#include <cow_COW.h>
#include <omu_Shortcut.h>

#include <typ_typeTag.h>

// Forward declarations
class cls_ReadVisitor;
class cls_WriteVisitor;
class cls_ClassRegistrar;
class ddr_Ddb;
template <class Key, class Value> class mdl_Container;
typedef mdl_Container<cow_String, ddr_Ddb> ddr_DdbContainer;

//

class ddr_ShortcutBaseImpl : public omu_ShortcutImpl
{
public:
    ddr_ShortcutBaseImpl() {}
    virtual ~ddr_ShortcutBaseImpl();
    
    // Return the path of the object in Python API
    virtual cow_String PythonPath() const;
    
    // Persistent name of the DDB. Empty string if not in a DDB
    virtual cow_String DdbName() const {return cow_String();}
};


template <class Child>
class ddr_ShortcutImpl : public ddr_ShortcutBaseImpl
{
public:
    ddr_ShortcutImpl() {}
    virtual ~ddr_ShortcutImpl();
    virtual const Child& ConstGet(const ddr_DdbContainer&) const = 0;
    virtual Child& Get(ddr_DdbContainer&) const = 0;

    virtual omu_ShortcutImpl* Copy() const = 0;

    bool InModel() const { return false; }
    bool InOdb() const { return true; }
    bool InSession() const { return false; }
    
    // Return the name of the object, see the ddr_Shortcut for description
    virtual cow_String Name() const = 0;
    // Return the path of the object, see the ddr_Shortcut for description
    virtual cow_String Path() const = 0;

    ddr_ShortcutImpl(const cls_ReadVisitor& rv);
    static void* Ctor(cls_ReadVisitor& rv) { return 0; }
    static void CowDtor(cls_IntCOW* cow);
    virtual void DBWrite(const cls_WriteVisitor& wv) const;
    static void InitializeMetadata(cls_ClassRegistrar& reg);

    virtual typ_typeTag DynTypeId() const = 0;
    static typ_typeTag TypeId();

private:
};

template <class Child>
class ddr_Shortcut :  public omu_ShortcutBase
{
    typedef cow_COW<ddr_ShortcutImpl<Child>, cow_Virtual<ddr_ShortcutImpl<Child> > > implCOW;

  public:
    ddr_Shortcut(const ddr_ShortcutImpl<Child> &implSC) 
	: impl(implSC), m_ClsUid(cls_Uid::AllocateUid()) { }

    ddr_Shortcut( const implCOW& cow )
	: impl(cow), m_ClsUid(cls_Uid::AllocateUid()) {}
	
    ddr_Shortcut()
	: impl(0), m_ClsUid(cls_Uid::AllocateUid()) { }

    const Child& ConstGet(const ddr_DdbContainer& ddbCont) const 
    { return impl.ConstGet().ConstGet(ddbCont); }
    Child& Get(ddr_DdbContainer& ddbCont) const
    { return impl.ConstGet().Get(ddbCont); }

    bool HasValue() const { return impl.HasValue(); }

    // Return the name of the object referred to by this shortcut.
    // The name is either:
    //    1. The name of the member in the parent object
    //    2. The name of the object in the repository.
    //    3. The index of the object in a sequence.
    cow_String Name() const {return impl.ConstGet().Name();}

    // Return the path to the object referred to by this shortcut
    // The path is a concatenation of name of all the objects in the
    // parent-child relations that make up this shortcut.
    cow_String Path() const {return impl.ConstGet().Path();} 

    cow_String PythonPath() const {return impl.ConstGet().PythonPath();} 

    // Persistent name of the DDB. Empty string if not in a DDB
    cow_String DdbName() const;

    // equality. Two shortcuts are equal if they have the same path
    bool operator==(const ddr_Shortcut<Child>& rhs) const;

    bool operator!=(const ddr_Shortcut<Child>& rhs) const {
	return ! operator==(rhs);
    }

    // Database interface
    static void* Ctor(cls_ReadVisitor& rv);
    static void CowDtor(cls_IntCOW* cow);
    ddr_Shortcut(const cls_ReadVisitor& rv);
    void DBWrite(const cls_WriteVisitor& wv) const;
    static void InitializeMetadata(cls_ClassRegistrar& reg);

    typ_typeTag DynTypeId() const;
    static typ_typeTag TypeId();

    // return impl
    const implCOW& Impl() const { return impl; }
    
  private:
    implCOW impl;    

    cls_Uid m_ClsUid;
};


// Member

template <class Parent, class Child, int Inst>
class ddr_MemberShortcut: public ddr_ShortcutImpl<Child>
{
  public:
    virtual ~ddr_MemberShortcut();

    ddr_MemberShortcut(const ddr_Shortcut<Parent>& p): parent(p), m_ClsUid(cls_Uid::AllocateUid()) {}

    virtual omu_ShortcutImpl* Copy() const;

    // No implementation of these supplied by the template
    // must be implemented by the instantiation.

    virtual const Child& ConstGet(const ddr_DdbContainer&) const;
    virtual Child& Get(ddr_DdbContainer&) const;

    Parent& GetParent(ddr_DdbContainer& ddbCont) const 
        { return parent.Get(ddbCont); }
    const Parent& ConstGetParent(const ddr_DdbContainer& ddbCont) const 
        { return parent.ConstGet(ddbCont); }

    // Return the name of the object, see the ddr_Shortcut for description
    virtual cow_String Name() const;
    // Return the path of the object, see the ddr_Shortcut for description
    virtual cow_String Path() const;
    // Persistent name of the DDB. Empty string if not in a DDB
    virtual cow_String DdbName() const;

    // Database interface
    static void* Ctor(cls_ReadVisitor& rv);
    ddr_MemberShortcut(const cls_ReadVisitor& rv);
    virtual void DBWrite(const cls_WriteVisitor& wv) const;
    static void InitializeMetadata(cls_ClassRegistrar& reg);

    virtual typ_typeTag DynTypeId() const;
    static typ_typeTag TypeId();

  private:
    ddr_Shortcut<Parent> parent;

    cls_Uid m_ClsUid;
};

// Dictionary member shortcut

template <class Parent, class Child, int Inst>
class ddr_DictionaryShortcut: public ddr_ShortcutImpl<Child>
{
  public:
    virtual ~ddr_DictionaryShortcut();

    ddr_DictionaryShortcut(const ddr_Shortcut<Parent>& p, const cow_String& n)
	: parent(p), name(n), m_ClsUid(cls_Uid::AllocateUid()) {}

    virtual omu_ShortcutImpl* Copy() const;

    // Possible to provide a default implementation here if cow_Map is used

    virtual const Child& ConstGet(const ddr_DdbContainer& ddbCont) const;
    virtual Child& Get(ddr_DdbContainer& ddbCont) const;

    Parent &GetParent(ddr_DdbContainer& ddbCont) const
        { return parent.Get(ddbCont); }
    const Parent& ConstGetParent(const ddr_DdbContainer& ddbCont) const
        { return parent.ConstGet(ddbCont); }

    // Return the name of the object, see the ddr_Shortcut for description
    virtual cow_String Name() const;
    // Return the path of the object, see the ddr_Shortcut for description
    virtual cow_String Path() const;
    // Persistent name of the DDB. Empty string if not in a DDB
    virtual cow_String DdbName() const;

    // Database interface
    static void* Ctor(cls_ReadVisitor& rv);
    ddr_DictionaryShortcut(const cls_ReadVisitor& rv);
    virtual void DBWrite(const cls_WriteVisitor& wv) const;
    static void InitializeMetadata(cls_ClassRegistrar& reg);

    virtual typ_typeTag DynTypeId() const;
    static typ_typeTag TypeId();

  private:
    cow_String name;
    ddr_Shortcut<Parent> parent;

    cls_Uid m_ClsUid;
};

// Sequence member shortcut

template <class Parent, class Child, int Inst>
class ddr_SequenceShortcut: public ddr_ShortcutImpl<Child>
{
  public:
    virtual ~ddr_SequenceShortcut();

    ddr_SequenceShortcut(const ddr_Shortcut<Parent>& p, int n)
	: parent(p), index(n), m_ClsUid(cls_Uid::AllocateUid()) {}

    virtual omu_ShortcutImpl* Copy() const;

    // Possible to provide a default implementation if cow_Sequence is used

    virtual const Child& ConstGet(const ddr_DdbContainer& ddbCont) const;
    virtual Child& Get(ddr_DdbContainer& ddbCont) const;

    Parent &GetParent(ddr_DdbContainer& ddbCont) const
        { return parent.Get(ddbCont); }
    const Parent& ConstGetParent(const ddr_DdbContainer& ddbCont) const
        { return parent.ConstGet(ddbCont); }

    // Return the name of the object, see the ddr_Shortcut for description
    virtual cow_String Name() const;
    // Return the path of the object, see the ddr_Shortcut for description
    virtual cow_String Path() const;
    // Persistent name of the DDB. Empty string if not in a DDB
    virtual cow_String DdbName() const;

    // Database interface
    static void* Ctor(cls_ReadVisitor& rv);
    ddr_SequenceShortcut(const cls_ReadVisitor& rv);
    virtual void DBWrite(const cls_WriteVisitor& wv) const;
    static void InitializeMetadata(cls_ClassRegistrar& reg);

    virtual typ_typeTag DynTypeId() const;
    static typ_typeTag TypeId();

  private:
    int index;
    ddr_Shortcut<Parent> parent;

    cls_Uid m_ClsUid;
};

///////////////////////////////////////////////////////
// Instantiation macros.
//
//    macros are included to simplify the instantiation of these 
//    templates.
//
// Use the *_ADD macros to instantiate a shortcut that has already been 
// typedef'd.  For example, if a class had two data members that were both
// of the same object type, you would use the normal macro to instantiate
// the shortcut to the first object, and the ADD macro with the INST set 
// to 2 to instantiate the shortcut to the second object.
//
#define ddr_SHORTCUT_DECL(CHILD,ALIAS) \
typedef ddr_Shortcut<CHILD> ALIAS;\
typedef ddr_ShortcutImpl<CHILD> CHILD ## IMPLSC;\
COW_COW2_DECL(CHILD ## IMPLSC,cow_Virtual);\
COW_COW2_DECL(ALIAS,cow_Direct);

#define ddr_SHORTCUT_IMPL(CHILD,ALIAS) \
template class ddr_Shortcut<CHILD>;\
template class ddr_ShortcutImpl<CHILD>;\
COW_COW2_IMPL(CHILD ## IMPLSC,cow_Virtual);\
COW_COW2_IMPL(ALIAS,cow_Direct);

// For the MemberShortcut, a macro is included to hide the instantiation
// of the COW used in the implementation.
#define ddr_MEMBER_SHORTCUT_DECL(PARENT,CHILD,ALIAS) \
typedef ddr_MemberShortcut<PARENT,CHILD,1> ALIAS;\
ddr_SHORTCUT_DECL(PARENT,PARENT ## Shortcut)

#define ddr_MEMBER_SHORTCUT_DECL_ADD(PARENT,CHILD,INST,ALIAS) \
typedef ddr_MemberShortcut<PARENT,CHILD,INST> ALIAS;\

#define ddr_MEMBER_SHORTCUT_IMPL(PARENT,CHILD,ALIAS) \
template class ddr_MemberShortcut<PARENT,CHILD,1>;

#define ddr_MEMBER_SHORTCUT_IMPL_ADD(PARENT,CHILD,INST,ALIAS) \
template class ddr_MemberShortcut<PARENT,CHILD,INST>;


// The dictionary shortcut also has a macro included to hide the
// instantiation of the COW used in the implementation.
#define ddr_DICTIONARY_SHORTCUT_DECL(PARENT,CHILD,ALIAS) \
typedef ddr_DictionaryShortcut<PARENT,CHILD,1> ALIAS; \
ddr_SHORTCUT_DECL(PARENT,PARENT ## Shortcut)

#define ddr_DICTIONARY_SHORTCUT_DECL_ADD(PARENT,CHILD,INST,ALIAS) \
typedef ddr_DictionaryShortcut<PARENT,CHILD,INST> ALIAS;\


#define ddr_DICTIONARY_SHORTCUT_IMPL(PARENT,CHILD,ALIAS) \
template class ddr_DictionaryShortcut<PARENT,CHILD,1>;

#define ddr_DICTIONARY_SHORTCUT_IMPL_ADD(PARENT,CHILD,INST,ALIAS) \
template class ddr_DictionaryShortcut<PARENT,CHILD,INST>;

// The sequence shortcut also has a macro included to hide the
// instantiation of the COW used in the implementation.
#define ddr_SEQUENCE_SHORTCUT_DECL(PARENT,CHILD,ALIAS) \
typedef ddr_SequenceShortcut<PARENT,CHILD,1> ALIAS; \
ddr_SHORTCUT_DECL(PARENT,PARENT ## Shortcut);

#define ddr_SEQUENCE_SHORTCUT_DECL_ADD(PARENT,CHILD,INST,ALIAS) \
typedef ddr_SequenceShortcut<PARENT,CHILD,INST> ALIAS; \

#define ddr_SEQUENCE_SHORTCUT_IMPL(PARENT,CHILD,ALIAS) \
template class ddr_SequenceShortcut<PARENT,CHILD,1>;

#define ddr_SEQUENCE_SHORTCUT_IMPL_ADD(PARENT,CHILD,INST,ALIAS) \
template class ddr_SequenceShortcut<PARENT,CHILD,INST>;


#endif

