#ifndef inpM_OmiSet_h
#define inpM_OmiSet_h

// This is an enhanced version of omi_Set.  It carries additional
// methods and features which depend on cow.  (It is illegal for omni
// coding to refer to cow coding.)

// Begin local Includes

#include <omi_Set.h>
#include <cow_ListInt.h>
#include <cow_Map.h>
#include <cow_String.h>

class inpM_OmiSetIT;

/////////////////////////////////////////////////////////////
// 
// The class is represented via two forms..
// a) has a single value that is stored in m_singleData
// b) has > 1 value stored in omi_Set
// Valid states: 
// 1) m_singleData == INT_MAX && set == 0 (empty)
// 2) m_singleData != INT_MAX && set == 0 (single) OR
// 3) m_singleData == INT_MAX && set != 0 (many).
// Motivation : omi_Sets are expensive in terms of memory..
// 
////////////////////////////////////////////////////////////
class inpM_OmiSet  : public mem_AllocationOperators
{
    friend class inpM_OmiSetIT;
  public:
    inpM_OmiSet();
    ~inpM_OmiSet();
    inpM_OmiSet(const inpM_OmiSet&);
    inpM_OmiSet(const cow_ListInt&);
    void Insert(int i);
    bool IsMember(int i) const;
    void Remove(int i);
    void Clear();
    int Size() const;
    inpM_OmiSet& operator=(const inpM_OmiSet& rhs);
    inpM_OmiSet& operator+=(const inpM_OmiSet& addset);
    inpM_OmiSet& operator&=(const inpM_OmiSet& andset);
    cow_ListInt ConstGetArrayCounterpart() const;
    void Merge(const cow_ListInt&);
    void Intersection(const inpM_OmiSet&);
    void Remove(const cow_ListInt&);
    
  private:
    void SwitchToOmiSet();
    void CheckState() const;
    omi_Set* set;
    int m_singleData; // specialization to improve performance
    // when only 1 entity is present in the set.
};

class inpM_OmiSetIT  : public mem_AllocationOperators
{
  public:
    inpM_OmiSetIT(const inpM_OmiSet& set);
    void First() { iter.First(); }
    bool IsDone() const { return iter.IsDone(); }
    void Next() { iter.Next(); }
    int CurrentItem() const { return iter.CurrentItem(); }
    ~inpM_OmiSetIT() { if (m_single) delete m_single; m_single = 0; }

  private:
    omi_SetIT iter;
    omi_Set* m_single; // temporary construct to hold a single value in omi_Set
};

COW_MAP_ITER_DECL(cow_String, inpM_OmiSet, inpM_MapString2BlkBitVect);

// numerically sorted iterator: instances are sorted in ascending order
// based on the smallest ID in each instance
class inpM_MapString2BlkBitVectNSIT  : public mem_AllocationOperators
{
  public:
    inpM_MapString2BlkBitVectNSIT(const inpM_MapString2BlkBitVect&);
    ~inpM_MapString2BlkBitVectNSIT();
    void First();
    void Next();
    bool IsDone() const;
    const cow_String& CurrentKey() const;
    const inpM_OmiSet& CurrentValue() const;
    
  private:
    inpM_MapString2BlkBitVect newMap;
    inpM_MapString2BlkBitVectIT* ptr2Iterator;
};

#endif
