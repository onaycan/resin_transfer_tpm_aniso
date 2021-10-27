#ifndef res_Holder_h
#define res_Holder_h

// Begin local includes
#include <mem_AllocationOperators.h>
#include <mdl_FlatArray.h>
#include <cow_COW.h>

template <class Type> class res_Holder  : public mem_AllocationOperators
{
public:
     res_Holder(Type* ptr, int size, int numColumns);
     res_Holder();
     res_Holder(const res_Holder<Type>& c);
     ~res_Holder();

     inline Type& Get(int rowIndex, int columnIndex);
     inline Type* Get(int rowIndex);
     inline Type ConstGet(int rowIndex, int columnIndex) const;
     inline const Type* ConstGet(int rowIndex) const;

     res_Holder<Type>& operator=(Type* ptr);
     res_Holder<Type>& operator=(const res_Holder<Type>& rhs);

     void SetNumComponents(int numComp);
     void SetSize(int size);

     inline int Size() const { return array.ConstGet().GetSize(); };
     inline int Width() const { return array.ConstGet().GetWidth(); };

     Type* GetPtr() const
       {
         mdl_FlatArray<Type>& data = const_cast<mdl_FlatArray<Type>&>(array.ConstGet());
         return data.GetPointer();
       };

     const Type* ConstGetPtr() const { return array.ConstGet().ConstGetPointer(); };
     
protected:
     cow_COW<mdl_FlatArray<Type>, cow_Virtual<mdl_FlatArray<Type> > > array;

private:
};

//
// SECTION: Inlines
//

template <class Type>
inline Type& res_Holder<Type>::Get(int rowIndex, int columnIndex)
{
     mdl_FlatArray<Type>& data = const_cast<mdl_FlatArray<Type>&>(array.ConstGet());
     return data.Get(rowIndex, columnIndex);
}

template <class Type>
inline Type* res_Holder<Type>::Get(int rowIndex)
{
     mdl_FlatArray<Type>& data = const_cast<mdl_FlatArray<Type>&>(array.ConstGet());
     Type* ret = data.GetPointer() + rowIndex*data.GetWidth();
     return ret;
}

template <class Type>
inline Type res_Holder<Type>::ConstGet(int rowIndex, int columnIndex) const
{
     return array.ConstGet().ConstGet(rowIndex,columnIndex);
}

template <class Type>
inline const Type* res_Holder<Type>::ConstGet(int rowIndex) const
{     
     const Type* ret = ConstGetPtr() + rowIndex*array.ConstGet().GetWidth();
     return ret;
}

//
// SECTION: MACROS
//
#define res_HOLDER_DECL(TYPE,ALIAS) \
typedef res_Holder<TYPE> ALIAS; \
typedef mdl_FlatArray<TYPE> ALIAS ## FLATARRAY; \
COW_COW2_DECL(ALIAS ## FLATARRAY,cow_Virtual);

#define res_HOLDER_IMPL(TYPE,ALIAS) \
template class res_Holder<TYPE>; \
template class mdl_FlatArray<TYPE>; \
COW_COW2_IMPL(ALIAS ## FLATARRAY, cow_Virtual);

#endif
