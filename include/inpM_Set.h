/*   -*- mode: c++ -*-   */
#ifndef inpM_Set_h
#define inpM_Set_h

///////////////////////////////////////////////////////////////////////////////
//
// Name: inpM_Set
//

// Includes

// Forward declarations

class inpM_IdMap;
class inpM_SortedSet;
class aio_istream;

// Begin local includes
#include <mem_AllocationOperators.h>

#include <cow_ListInt.h>
#include <cow_ListString.h>
#include <cow_Map.h>
#include <cow_MapInt2String.h>
#include <cow_MapString2ListInt.h>
#include <inpM_OmiSet.h>
#include <cow_ArrayCOW.h>
#include <inpM_Utils.h>

// Class definitions

///////////////////////////////////////////////////////////////////////////////
enum inpM_SetTypeFlag {USER, INTERNAL, INTERNAL_PRE_SET, INTERNAL_MEMBERS };

struct inpM_StringIntPair : public mem_AllocationOperators
{
    cow_String name;
    int id;
};

COW_LIST_DECL(inpM_StringIntPair, inpM_StringIntPairList);

/////////////////////////////////////////////////////////////////
// Shawn's vision of recursive unsorted set

enum inpM_SetTypeEnm
{
    inpM_BASE_SET,
    inpM_INTEGER_SET,
    inpM_SET_NAME_PAIR,
    inpM_UNSORTED_SET,
    inpM_SORTED_SET
};

class inpM_BaseSet  : public mem_AllocationOperators
{
  public:
    virtual ~inpM_BaseSet() {}
    virtual void Print(aio_ostream&) const = 0; 
    virtual inpM_BaseSet* Copy() const = 0;
    virtual void Add(const inpM_BaseSet&) = 0;
    virtual void Add(const inpM_OmiSet&);
    virtual void Add(const cow_String& instanceName,
		     const inpM_BaseSet&) = 0;
    virtual void Add(const cow_ListInt&) = 0;
    virtual void Add(const cow_String& instanceName,
		     const cow_ListInt&) = 0;
    virtual void Add(const cow_String& instanceName,
		     const inpM_OmiSet&);
    virtual void Add(int) = 0;
    virtual void Add(const cow_String& instanceName, int) = 0;
    virtual bool Remove(const int id) = 0;
    virtual void Renumber(const inpM_IdMap&, bool inverse = false) = 0;
    bool IsPicked() const { return (setTypeFlag != USER ? true : false); }
    inpM_SetTypeFlag SetType() const { return setTypeFlag; }
    virtual bool IsUnsorted() const = 0;
    virtual cow_ListInt ConstGetIds() const = 0;
    virtual cow_ListInt ConstGetTopLevelIds() const = 0;
    virtual cow_ListInt ConstGetSecondLevelIds(const cow_String&
					        instanceName) const = 0;
    cow_ListInt ConstGetAssemblyLevelIds() const {
	return ConstGetTopLevelIds(); 
    }
    virtual cow_MapString2ListInt ConstGetInstanceIdsMap() const = 0;
    virtual void Cleanup(const inpM_IdMap&) = 0;
    void Merge(const inpM_BaseSet& set) { Add(set); }
    void InsertDuplicateOffsetIds(int offset, int repeatCount) {}
    virtual void ChangeInstanceName(const cow_String& from,
				    const cow_String& to) = 0;
    virtual bool IsEmpty() const = 0;

    static inpM_SetTypeEnm TypeId() { return inpM_BASE_SET; }
    virtual inpM_SetTypeEnm DynTypeId() const { return inpM_BaseSet::TypeId(); }
    virtual cow_ListString GatherRootLevelInstanceNames() const = 0;
    virtual inpM_SortedSet GetSortedSetEquivalent() const = 0;

    void AssignSetType(inpM_SetTypeFlag flag) { setTypeFlag = flag; }

    void SetImported() { _imported = true; }
    bool IsImported() const { return _imported; }

    virtual void RemoveQuotes() = 0;

  protected:
    inpM_BaseSet() : _imported(false) {}

    bool _imported;
    inpM_SetTypeFlag setTypeFlag;
};

class inpM_IntegerSet : public inpM_BaseSet
{
  public:
    inpM_IntegerSet(const cow_ListInt&);  
    inpM_IntegerSet(aio_istream&);
    virtual void Print(aio_ostream&) const; 
    virtual inpM_BaseSet* Copy() const;
    virtual void Add(const inpM_BaseSet&);
    virtual void Add(const cow_String& instanceName,
		     const inpM_BaseSet&);
    virtual void Add(const cow_ListInt&);
    virtual void Add(const cow_String& instanceName,
		     const cow_ListInt&);
    virtual void Add(int);
    virtual void Add(const cow_String& instanceName, int);
    virtual bool Remove(const int id);
    virtual void Renumber(const inpM_IdMap&, bool inverse = false);
    virtual bool IsUnsorted() const { return true; }
    virtual cow_ListInt ConstGetIds() const;
    virtual cow_ListInt ConstGetTopLevelIds() const;
    virtual cow_ListInt ConstGetSecondLevelIds(const cow_String&
					            instanceName) const;
    virtual cow_MapString2ListInt ConstGetInstanceIdsMap() const;
    virtual void Cleanup(const inpM_IdMap&);
    virtual void ChangeInstanceName(const cow_String& from,
				    const cow_String& to) {}
    virtual bool IsEmpty() const;

    static inpM_SetTypeEnm TypeId() { return inpM_INTEGER_SET; }
    virtual inpM_SetTypeEnm DynTypeId() const {
	return inpM_IntegerSet::TypeId();
    }
    virtual cow_ListString GatherRootLevelInstanceNames() const;
    virtual inpM_SortedSet GetSortedSetEquivalent() const;

    virtual void RemoveQuotes() {};

  private:
    cow_ListInt ids;
};

COW_ARRAYCOW2_DECL(inpM_BaseSet, cow_Virtual);

class inpM_SetNamePair : public inpM_BaseSet
{
  public:
    inpM_SetNamePair(const cow_String&, const inpM_BaseSet&);
    inpM_SetNamePair(aio_istream&);
    virtual void Print(aio_ostream&) const;
    virtual inpM_BaseSet* Copy() const;
    virtual void Add(const inpM_BaseSet&);
    virtual void Add(const cow_String& instanceName,
		     const inpM_BaseSet&);
    virtual void Add(const cow_ListInt&);
    virtual void Add(const cow_String& instanceName,
		     const cow_ListInt&);
    virtual void Add(int);
    virtual void Add(const cow_String& instanceName, int);
    virtual bool Remove(const int id);
    virtual void Renumber(const inpM_IdMap&, bool inverse = false);
    virtual bool IsUnsorted() const { return true; }
    virtual cow_ListInt ConstGetIds() const;
    virtual cow_ListInt ConstGetTopLevelIds() const;
    virtual cow_ListInt ConstGetSecondLevelIds(const cow_String&
					            instanceName) const;
    virtual cow_MapString2ListInt ConstGetInstanceIdsMap() const;
    virtual void Cleanup(const inpM_IdMap&);
    virtual void ChangeInstanceName(const cow_String& from,
				    const cow_String& to);
    virtual bool IsEmpty() const;

    static inpM_SetTypeEnm TypeId() { return inpM_SET_NAME_PAIR; }
    virtual inpM_SetTypeEnm DynTypeId() const {
	return inpM_SetNamePair::TypeId();
    }
    virtual cow_ListString GatherRootLevelInstanceNames() const;
    virtual inpM_SortedSet GetSortedSetEquivalent() const;

    virtual void RemoveQuotes() { 
	instanceName = inpM_Utils::RemoveQuotes(instanceName);
	set.Get().RemoveQuotes();
    };

  private:
    cow_String instanceName;
    inpM_BaseSetCOW set;
};

COW_LIST_DECL(inpM_BaseSetCOW, inpM_BaseSetList);

class inpM_UnsortedSet : public inpM_BaseSet
{
    friend class inpM_SortedSet;
  public:
    inpM_UnsortedSet() {}
    inpM_UnsortedSet(const cow_ListInt&);
    inpM_UnsortedSet(const inpM_SortedSet&);
    inpM_UnsortedSet(aio_istream&);
    virtual void Print(aio_ostream&) const;
    virtual inpM_BaseSet* Copy() const;
    virtual void Add(const inpM_BaseSet&);
    virtual void Add(const inpM_OmiSet&);
    virtual void Add(const cow_String& instanceName,
		     const inpM_BaseSet&);
    virtual void Add(const cow_ListInt&);
    void Add(const inpM_UnsortedSet&);
    void Add(const cow_String& instanceName,
	     const inpM_UnsortedSet&);
    virtual void Add(const cow_String& instanceName,
		     const cow_ListInt&);
    virtual void Add(const cow_String& instanceName,
		     const inpM_OmiSet&);
    virtual void Add(int);
    virtual void Add(const cow_String& instanceName, int);
    virtual bool Remove(const int id);
    virtual void Renumber(const inpM_IdMap&, bool inverse = false);
    virtual bool IsUnsorted() const { return true; }
    virtual cow_ListInt ConstGetIds() const;
    virtual cow_ListInt ConstGetTopLevelIds() const;
    virtual cow_ListInt ConstGetSecondLevelIds(const cow_String&
					            instanceName) const;
    virtual cow_MapString2ListInt ConstGetInstanceIdsMap() const;
    virtual void Cleanup(const inpM_IdMap&);
    virtual void ChangeInstanceName(const cow_String& from,
				    const cow_String& to);
    virtual bool IsEmpty() const;

    static inpM_SetTypeEnm TypeId() { return inpM_UNSORTED_SET; }
    virtual inpM_SetTypeEnm DynTypeId() const {
	return inpM_UnsortedSet::TypeId();
    }
    virtual cow_ListString GatherRootLevelInstanceNames() const;
    virtual inpM_SortedSet GetSortedSetEquivalent() const;

    virtual void RemoveQuotes() { 
	for (int i = 0; i < list.Length(); i++)
	    list.Get(i).Get().RemoveQuotes();
    };

  private:
    inpM_BaseSetList list;
};

/////////////////////////////////////////////////////////////////

COW_ARRAYCOW_DECL(inpM_SortedSet);
COW_MAP_SORTED_ITER_DECL(cow_String, inpM_SortedSetCOW, inpM_MapString2SortedSet);
typedef cow_ConstMapIterator<cow_String, inpM_SortedSetCOW> inpM_MapString2SortedSetIT;

class inpM_SortedSet : public inpM_BaseSet
{
  public:
    inpM_SortedSet() {}
    inpM_SortedSet(aio_istream&);
    inpM_SortedSet(const cow_ListInt&);
    inpM_SortedSet(const inpM_UnsortedSet&);
    inpM_SortedSet(const inpM_OmiSet&);
    virtual void Print(aio_ostream&) const;
    virtual inpM_BaseSet* Copy() const;
    virtual void Add(const inpM_BaseSet&);
    virtual void Add(const inpM_OmiSet&);
    virtual void Add(const cow_String& instanceName,
		     const inpM_BaseSet&);
    virtual void Add(const cow_ListInt&);
    void Add(const inpM_SortedSet& set);
    void Add(const cow_String& instanceName,
	     const inpM_SortedSet& set);
    virtual void Add(const cow_String& instanceName,
		     const cow_ListInt&);
    virtual void Add(const cow_String& instanceName,
		     const inpM_OmiSet&);
    virtual void Add(int);
    virtual void Add(const cow_String& instanceName, int);
    virtual bool Remove(const int id);
    virtual void Renumber(const inpM_IdMap& idMap, bool inverse = false);
    virtual bool IsUnsorted() const { return false; }
    virtual cow_ListInt ConstGetIds() const;
    virtual cow_ListInt ConstGetTopLevelIds() const;
    virtual cow_ListInt ConstGetSecondLevelIds(const cow_String&
						      instanceName) const;
    virtual cow_MapString2ListInt ConstGetInstanceIdsMap() const;
    virtual void Cleanup(const inpM_IdMap& idMap);
    virtual void ChangeInstanceName(const cow_String& from,
				    const cow_String& to);
			    
    const inpM_OmiSet& ConstGetIdsGrid() const { return idsGrid; }
    const inpM_MapString2BlkBitVect& ConstGetInstance2IdGridMap() const {
	return instanceIdsMap;
    }
    const inpM_MapString2SortedSet& ConstGetInstanceMap() const {
	return instanceMap;
    }
    bool IsEmpty() const;
    int SmallestID() const;

    static inpM_SetTypeEnm TypeId() { return inpM_SORTED_SET; }
    virtual inpM_SetTypeEnm DynTypeId() const {
	return inpM_SortedSet::TypeId();
    }
    virtual cow_ListString GatherRootLevelInstanceNames() const;
    virtual inpM_SortedSet GetSortedSetEquivalent() const;

    virtual void RemoveQuotes();

  private:
    inpM_OmiSet idsGrid;
    inpM_MapString2BlkBitVect instanceIdsMap;
    inpM_MapString2SortedSet instanceMap;
};

/////////////////////////////////////////////////////////////////

inpM_BaseSetCOW CreateSet(bool pickedSet, bool unsorted = false);
inpM_BaseSetCOW CreateSet(const inpM_SetTypeFlag setTypeFlag = USER,
			 bool unsorted = false);
inpM_BaseSetCOW CreateSet(aio_istream&, bool unsorted = false);
inpM_BaseSetCOW CreateSet(const cow_ListInt& ids,
			 bool pickedSet, bool unsorted = false);
inpM_BaseSetCOW CreateSet(const cow_ListInt& ids,
			 const inpM_SetTypeFlag setTypeFlag = USER,
			 bool unsorted = false);
inpM_BaseSetCOW CreateSet(const inpM_BaseSet& set);

////////////////////////////////////////////////////////////

// Since inpM_BaseSet is an abstract class, a cow_Map cannot
// be formed directly.  The following is a behavioral imitation.
COW_MAP_SORTED_ITER_DECL(cow_String, inpM_BaseSetCOW,
			 inpM_MapString2BaseSetCOW);
typedef cow_ConstMapIterator<cow_String, inpM_BaseSetCOW> inpM_MapString2BaseSetCOWIT;
			 
class inpM_BaseSetMapSIT; // Forward declaration
class inpM_BaseSetMapIT;

class inpM_BaseSetMap  : public mem_AllocationOperators
{
    friend class inpM_BaseSetMapSIT;
    friend class inpM_BaseSetMapIT;
  public:
    inpM_BaseSetMap() {};
    int Size() const { return map.Size(); }
    void Insert(const cow_String& name, const inpM_BaseSet& set) {
	map.Insert(name, set);
    }
    void Remove(const cow_String& name) { map.Remove(name); }
    bool IsMember(const cow_String& name) const { return map.IsMember(name); }
    inpM_BaseSet& Get(const cow_String& name) { return map.Get(name).Get(); }
    const inpM_BaseSet& ConstGet(const cow_String& name) const {
	return map.ConstGet(name).ConstGet();
    }

  private:
    inpM_MapString2BaseSetCOW map;
};

// The following imitation iterators are needed because
// inpM_BaseSetMap is not a real cow_Map.
class inpM_BaseSetMapSIT  : public mem_AllocationOperators
{
  public:
    inpM_BaseSetMapSIT(const inpM_BaseSetMap& setMap): iter(setMap.map) {}
    void First() { iter.First(); }
    void Next() { iter.Next(); }
    bool IsDone() const { return iter.IsDone(); }

    const cow_String& CurrentKey() const { return iter.CurrentKey(); }
    const inpM_BaseSet& CurrentValue() const {
	return iter.CurrentValue().ConstGet(); 
    }
  private:
    inpM_MapString2BaseSetCOWSIT iter;
};

class inpM_BaseSetMapIT  : public mem_AllocationOperators
{
  public:
    inpM_BaseSetMapIT(const inpM_BaseSetMap& setMap): iter(setMap.map) {}
    void First() { iter.First(); }
    void Next() { iter.Next(); }
    bool IsDone() const { return iter.IsDone(); }

    const cow_String& CurrentKey() const { return iter.CurrentKey(); }
    const inpM_BaseSet& CurrentValue() const {
	return iter.CurrentValue().ConstGet(); 
    }
  private:
    inpM_MapString2BaseSetCOWIT iter;
};

/////////////////////////////////////////////////////////////////
// numerically sorted iterator: instances are sorted in ascending order
// based on the smallest ID in each instance
class inpM_MapString2SortedSetNSIT  : public mem_AllocationOperators
{
  public:
    inpM_MapString2SortedSetNSIT(const inpM_MapString2SortedSet&);
    ~inpM_MapString2SortedSetNSIT();
    void First();
    void Next();
    bool IsDone() const;
    const cow_String& CurrentKey() const;
    inpM_SortedSetCOW CurrentValue() const;

  private:
    inpM_MapString2SortedSet newMap;
    inpM_MapString2SortedSetIT* ptr2Iterator;
};

#endif
