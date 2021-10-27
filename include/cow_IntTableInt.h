/* -*- mode: c++ -*- */
#ifndef cow_IntTableInt_h
#define cow_IntTableInt_h

// Begin local includes
#include <mem_AllocationOperators.h>

#include <cow_COW.h>
#include <omi_IntTableInt.h>

// Forward declaration

class cow_IntTableIntIT;

// Class definition

COW_COW_DECL(omi_IntTableInt);

class cow_IntTableInt  : public mem_AllocationOperators
{
    friend class cow_IntTableIntIT;

  public:

    cow_IntTableInt(): tbl(new omi_IntTableInt()) {}
    bool Remove(const int& key) { return tbl.Get().Remove(key); }
    bool Insert(const int& key, const int& value) { 
	return tbl.Get().Insert(key, value);
    }
    const int& ConstGet(const int& key) const {
	return tbl.ConstGet().ConstGet(key);
    }
    bool ConstGetValue(const int& key, int& val) const {
        return tbl.ConstGet().ConstGetValue(key, val);
    }
    int& Get(const int& key) { return tbl.Get().Get(key); }
    bool IsMember(const int& key) const {
	return tbl.ConstGet().IsMember(key);
    }
    int Size() const { return tbl.ConstGet().Size(); }
    bool IsEmpty() const { return tbl.ConstGet().IsEmpty(); }
    void Clear() { tbl.Get().Clear(); }

private:

    omi_IntTableIntCOW tbl;
};

// Const Iterator over Map

class cow_IntTableIntIT  : public mem_AllocationOperators
{
  public:

    cow_IntTableIntIT(const cow_IntTableInt& t): 
	iter(t.tbl.ConstGet()) {}

    void First() { iter.First(); }
    void Last() { iter.Last(); }

    void Next() { iter.Next(); }

    bool IsDone() const { return iter.IsDone(); }

    const int& CurrentValue() const {
	return iter.CurrentValue();
    }

    int CurrentKey() const { return iter.CurrentKey(); }

  private:

    omi_IntTableIntIT iter;
};

typedef cow_IntTableIntIT cow_IntTableIntSIT;

#endif // cow_IntTableInt_h
