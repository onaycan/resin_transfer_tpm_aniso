#ifndef SMASimSetAssociationItemSel_h
#define SMASimSetAssociationItemSel_h
// Begin local includes
#include <mem_AllocationOperators.h>

// Forward declarations
class SMASimSetAssociationItem;

/**
  This class is not in the public SIM API.
  It is an iterator over a selection of rows from an association table internally
  used by association selections.

  @nodoc
*/
class SMASimSetAssociationItemSelection
{
public:
    SMASimSetAssociationItemSelection();

    void First();
    void Next();
    bool IsDone() { return m_Current == NONE; }
    int CurrentValue() const;

    int FirstValue() const;
    int LastValue() const;
    int Length() const;

private:
    friend class SMASimSetAssociationItem;
    typedef int (*CompFunc)(int left, int right, void *userData);

    SMASimSetAssociationItemSelection(
        CompFunc compFunc, void *userData,
        const int *leftFirst, const int *leftLast, const int *rightFirst, const int *rightLast);

    enum CurrentRange{
        NONE,
        LEFT,
        RIGHT
    };

    CompFunc m_CompFunc;
    void *m_UserData;
    const int *m_LeftFirst;
    const int *m_LeftLast;
    const int *m_LeftCurrent;
    const int *m_RightFirst;
    const int *m_RightLast;
    const int *m_RightCurrent;
    CurrentRange m_Current;
};

#endif
