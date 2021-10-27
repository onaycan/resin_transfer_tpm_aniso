/*   -*- mode: c++ -*-   */
#ifndef inpM_InstanceMap_h
#define inpM_InstanceMap_h

///////////////////////////////////////////////////////////////////////////////
//
// File Name: inpM_InstanceMap.h
//

// Includes

// Forward declarations

// Begin local includes
#include <mem_AllocationOperators.h>
#include <cow_Map.h>
#include <cow_ListString.h>
#include <inpM_IdMap.h>

// Class definition

template <class T>
class inpM_InstanceMap;

template <class T>
class inpM_InstanceMap : public mem_AllocationOperators
{
  public:

    inpM_InstanceMap();
    virtual ~inpM_InstanceMap();
    inpM_InstanceMap(const inpM_InstanceMap<T>&);
    inpM_InstanceMap<T>& operator=(const inpM_InstanceMap<T>&);

    T& Get();
    T& Get(const cow_String& instanceName);
    inpM_InstanceMap<T>& GetMap(const cow_String& instanceName);

    const T& ConstGet() const;
    const T& ConstGet(const cow_String& instanceName) const;
    const inpM_InstanceMap<T>& ConstGetMap(const cow_String& instanceName)const;

    void Insert(const cow_String& instName, const T&);
    bool IsMember(const cow_String& instanceName) const;
    cow_ListString Instances() const;

    // Unimplemented methods for specialization

    inpM_IdMap Renumber(int start = 1, bool noRenumbering = false);
    void Update(const inpM_IdMap&);

    void RemoveQuotes();

  private:

    cow_COW<T,cow_Direct<T> > item;
    cow_Map<cow_String,inpM_InstanceMap<T> >* map;
};

#define INPM_INSTANCE_MAP_DECL(Item, Map)\
typedef inpM_InstanceMap<Item> Map;\
COW_COW_DECL(Item);\
COW_MAP_SORTED_ITER_DECL(cow_String, Map, Map ## Base);

#define INPM_INSTANCE_MAP_IMPL(Item, Map)\
template class inpM_InstanceMap<Item>;\
COW_COW_IMPL(Item);\
COW_MAP_SORTED_ITER_IMPL(cow_String, Map, Map ## Base);\

#endif
