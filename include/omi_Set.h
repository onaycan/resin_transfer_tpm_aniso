#ifndef omi_Set_h
#define omi_Set_h

// Begin local Includes
#include <mem_AllocationOperators.h>
#include <omi_BlkBitVect.h>
#include <omi_BlkBitVectTrav.h>

class omi_SetIT;

class omi_Set  : public mem_AllocationOperators
{
  friend class omi_SetIT;

  public:

    omi_Set() {}

    void Insert(int i);
    bool IsMember(int i) const;
    void Remove(int i);
    void Clear();
    int Size() const;
    omi_Set& operator+=(const omi_Set& addset);
    omi_Set& operator&=(const omi_Set& andset);

  protected:

    omi_BlkBitVect posNums;  // including zero
    omi_BlkBitVect negNums;
};

class omi_SetIT  : public mem_AllocationOperators
{
  public:

    omi_SetIT(const omi_Set& set);
    void First();
    bool IsDone() const;
    void Next();
    int CurrentItem() const;

  private:

    omi_BlkBitVectTrav posIter;
    omi_BlkBitVectTrav negIter;
};

#endif
