/*   -*- mode: c++ -*-   */
#ifndef inpM_SetMap_h
#define inpM_SetMap_h

///////////////////////////////////////////////////////////////////////////////
//
// Name: inpM_SetMap
//

// Includes

// Forward declarations

class inpM_IdMap;
class inpM_SetMap;
class inpM_SetMapSIT;
class aio_istream;

// Begin local includes
#include <mem_AllocationOperators.h>

#include <inpM_Set.h>
#include <cow_ListString.h>
#include <cow_ListTranslatedString.h>
#include <cow_Map.h>

// Map definitions

COW_MAP_SORTED_ITER_DECL(int, inpM_SetMap, inpM_MapInt2SetMap);

// Class definitions

///////////////////////////////////////////////////////////////////////////////

COW_COW_DECL(inpM_SetMap);
COW_MAP_SORTED_ITER_DECL(cow_String, inpM_SetMapCOW, inpM_MapString2SetMap);
typedef cow_ConstMapIterator<cow_String, inpM_SetMapCOW> inpM_MapString2SetMapIT;

class inpM_SetMap  : public mem_AllocationOperators
{
  public:

    inpM_SetMap();
    inpM_SetMap(const inpM_BaseSetMap&);
    inpM_SetMap(aio_istream&);
    void Print(aio_ostream&) const;
    bool HasInstance(const cow_String& instName) const {
	return instanceMap.IsMember(instName);
    }
    const inpM_SetMap& ConstGet(const cow_String& instName) const {
	return instanceMap.ConstGet(instName).ConstGet();
    }
    const inpM_SetMap& ConstGetDefault(const cow_String& instName, const inpM_SetMap & defaultMap) const {
        if (instanceMap.IsMember(instName))
            return instanceMap.ConstGet(instName).ConstGet();
        else
            return defaultMap;
    }
    const inpM_BaseSetMap& ConstGetMap() const {
	return sets;
    }
    const inpM_MapString2SetMap& ConstGetInstanceMap() const {
	return instanceMap;
    }
    bool IsEmpty() const;
    cow_ListString Instances() const;

    const inpM_BaseSet& ConstGetSet(const cow_String& setName) const;
    const inpM_BaseSet& ConstGetNestedSet(
	const cow_String& instanceName, 
	const cow_String& setName) const;

    const inpM_BaseSetMap& ConstGetSetMap() const {
	return ConstGetMap();
    }
    const inpM_BaseSetMap& ConstGetNestedSetMap(
	const cow_String& instanceName) const {
	return ConstGet(instanceName).ConstGetMap();
    }

    void InsertSet(const cow_String& setName,
		   const inpM_BaseSet&);
    void InsertNestedSet(const cow_String& instanceName,
			 const cow_String& setName,
			 const inpM_BaseSet&);
    void InsertNestedSetMap(const cow_String& instanceName,
			    const inpM_BaseSetMap&);

    bool HasSet(const cow_String& setName) const {
	return sets.IsMember(setName);
    }
    bool HasNestedSet(const cow_String& instanceName,
				 const cow_String& setName) const;

    bool RemoveSet(const cow_String& setName);
    bool RemoveNestedSet(const cow_String& instanceName,
			       const cow_String& setName);

    void Renumber(const inpM_IdMap&, bool inverse = false);

    cow_ListTranslatedString Cleanup(const inpM_IdMap&);
    void CleanupShowWarning(const inpM_IdMap&);
    void Cleanup();

    void Merge(const inpM_SetMap&);
    void MergeSet(const cow_String& setName,
				  const inpM_BaseSet&);
    void MergeNestedSet(const cow_String& instanceName,
			      const cow_String& setName,
			      const inpM_BaseSet&);
    void InsertDuplicateOffsetIds(int offset, int repeatCount);
    void ChangeInstanceName(const cow_String& from, const cow_String& to);
    bool SearchAssemblyAndInstancesForSet(const cow_String& setName,
					  cow_String& instanceName) const;
    void DeleteAllSetsExceptThoseListed(const cow_ListString&);

    void RemoveQuotes();

  private:
    // internal helper functions
    inpM_SetMap& Get(const cow_String& instName) {
	return instanceMap.Get(instName).Get();
    }
    inpM_BaseSet& GetSet(const cow_String& setName) {
	return sets.Get(setName);
    }
    inpM_BaseSetMap& GetMap() {
	return sets;
    }
    void Insert(const cow_String& setName, const inpM_BaseSet& set) {
	sets.Insert(setName, set);
    }
    void Insert(const cow_String& instName, const inpM_BaseSetMap& map) {
	inpM_SetMapCOW ptr = new inpM_SetMap(map);
	instanceMap.Insert(instName, ptr);
    }

    // data members
    inpM_BaseSetMap sets;
    inpM_MapString2SetMap instanceMap;    

};
#endif
