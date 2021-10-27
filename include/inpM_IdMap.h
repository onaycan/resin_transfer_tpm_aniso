/*   -*- mode: c++ -*-   */
#ifndef inpM_IdMap_h
#define inpM_IdMap_h

///////////////////////////////////////////////////////////////////////////////
//
// File Name: inpM_IdMap.h
//

// Includes

// Forward declarations

class inpM_IdMap;
class aio_istream;

// Begin local includes
#include <mem_AllocationOperators.h>

#include <cow_ListInt.h>
#include <cow_ListString.h>
#include <cow_Map.h>
#include <cow_IntTableInt.h>

// Macros

COW_COW_DECL(inpM_IdMap);
COW_MAP_ITER_DECL(cow_String, inpM_IdMapCOW, inpM_MapString2IdMap);

// Class definition

struct inpM_InstanceMaps : public mem_AllocationOperators
{
    cow_IntTableInt global2Local;
    cow_IntTableInt local2Global;

    inpM_InstanceMaps() {}
    inpM_InstanceMaps(aio_istream&, bool noRenumbering);
    inpM_InstanceMaps(const inpM_IdMap&);
    void Print(aio_ostream&, bool noRenumbering) const;
};

COW_MAP_SORTED_ITER_DECL(cow_String, inpM_InstanceMaps,
			 inpM_MapString2InstanceMaps);
typedef cow_ConstMapIterator<cow_String,inpM_InstanceMaps> inpM_MapString2InstanceMapsIT;

// This is an imitation cow map. It contains a real cow map for
// storing the instance level inpM_InstanceMaps, as well as a top
// level inpM_InstanceMaps for storing the assembly level one.
class inpM_InstanceIdMaps  : public mem_AllocationOperators
{
    friend class inpM_InstanceIdMapsSIT;
    friend class inpM_InstanceIdMapsIT;
  public:
    inpM_InstanceIdMaps() {};

    int Size() const { return idMap.Size(); }
    void Insert(const cow_String& name, const inpM_InstanceMaps& imap) {
	idMap.Insert(name, imap);
    }
    void Remove(const cow_String& name) { idMap.Remove(name); }
    bool IsMember(const cow_String& name) const {
	return idMap.IsMember(name);
    }
    inpM_InstanceMaps& Get(const cow_String& name) {
	return idMap.Get(name);
    }
    const inpM_InstanceMaps& ConstGet(const cow_String& name) const {
	return idMap.ConstGet(name);
    }
    inpM_InstanceMaps& Get() { return remap; }
    const inpM_InstanceMaps& ConstGet() const { return remap; }

    void RemoveQuotes();

  private:
    inpM_MapString2InstanceMaps idMap;
    inpM_InstanceMaps remap;
};

// imitation iterator for imitation cow map
class inpM_InstanceIdMapsSIT  : public mem_AllocationOperators
{
  public:
    inpM_InstanceIdMapsSIT(const inpM_InstanceIdMaps& instIdMap):
	iter(instIdMap.idMap) {}

    void First() { iter.First(); }
    void Next() { iter.Next(); }
    bool IsDone() const { return iter.IsDone(); }

    const cow_String& CurrentKey() const { return iter.CurrentKey(); }
    const inpM_InstanceMaps& CurrentValue() const {
	return iter.CurrentValue();
    }

  private:
    inpM_MapString2InstanceMapsSIT iter;
};

class inpM_InstanceIdMapsIT  : public mem_AllocationOperators
{
  public:
    inpM_InstanceIdMapsIT(const inpM_InstanceIdMaps& instIdMap):
	iter(instIdMap.idMap) {}

    void First() { iter.First(); }
    void Next() { iter.Next(); }
    bool IsDone() const { return iter.IsDone(); }

    const cow_String& CurrentKey() const { return iter.CurrentKey(); }
    const inpM_InstanceMaps& CurrentValue() const {
	return iter.CurrentValue();
    }

  private:
    inpM_MapString2InstanceMapsIT iter;
};


class inpM_IdMap  : public mem_AllocationOperators
{
  public:

    inpM_IdMap();
    inpM_IdMap(const inpM_InstanceIdMaps&);

    const inpM_IdMap& ConstGet(const cow_ListString& instancePath) const;
    const inpM_IdMap& ConstGet(const cow_String& instanceName) const;
    int ConstGet(int id) const;
    const cow_IntTableInt& ConstGetMap() const {	return remap; }

    void Insert(const cow_String& instanceName, const inpM_IdMap& map)
        { idMap.Insert(instanceName, map); }
    void Insert(int i, int j) { remap.Insert(i, j); }

    bool IsMember(const cow_String& instanceName) const {
	return idMap.IsMember(instanceName);
    }
    bool IsMember(int i) const { return remap.IsMember(i); }

    int NumberIds() const;
    cow_ListString Instances() const;

    void Renumber(int*, int nids) const;
    cow_ListInt Renumber(const cow_ListInt&,
				bool inverse = false) const;
    cow_ListInt CleanupAndRenumber(const cow_ListInt&,
				bool inverse = false) const;
    cow_ListInt Cleanup(const cow_ListInt&) const;

    void Print(aio_ostream&, bool noRenumbering) const;
    void Merge(const inpM_IdMap&);
    int LargestId() const;
    int SmallestId() const;
    void InsertDuplicateOffsetIds(int offset, int repeatCount);

  private:

    inpM_MapString2IdMap idMap;
    cow_IntTableInt remap;
};

#endif
