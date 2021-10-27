#ifndef cls_TypeAdapter_h
#define cls_TypeAdapter_h

// Begin local includes

#include <typ_typeTag.h>
#include <cls_ClassMetadata.h>
// End local includes

// Forward declarations
class cls_WriteVisitor;
class cls_ReadVisitor;

template <class T>
class cls_AbsTypeAdapter
    : public cls_ClassMetadata
{
public:
    cls_AbsTypeAdapter(
        const cow_String& name,
        int version = 1,
        typ_typeTag bcid = typ_NONE
        );

    // Overrides for virtual functions
    void DBWrite( const void *ptr, const cls_WriteVisitor &wv ) const;
    void Delete( void *ptr ) const;
};

template <class T>
class cls_TypeAdapter
    : public cls_AbsTypeAdapter<T>
{
public:
    cls_TypeAdapter(
        const cow_String& name,
        int version = 1,
        typ_typeTag bcid = typ_NONE
        );

    // Overrides for virtual functions
    void* Ctor( const cls_ReadVisitor& rv ) const;
};


#define CLS_ABS_TYPEADAPTER_DECL(TYPE,NAME)     \
    typedef cls_AbsTypeAdapter<TYPE> NAME

#define CLS_ABS_TYPEADAPTER_IMPL(TYPE,NAME)     \
    CLS_ABS_TYPEADAPTER_DECL(TYPE,NAME);        \
    template class cls_AbsTypeAdapter<TYPE>;

#define CLS_TYPEADAPTER_DECL(TYPE,NAME)         \
    typedef cls_TypeAdapter<TYPE> NAME

#define CLS_TYPEADAPTER_IMPL(TYPE,NAME)         \
    CLS_TYPEADAPTER_DECL(TYPE,NAME);            \
    template class cls_AbsTypeAdapter<TYPE>;    \
    template class cls_TypeAdapter<TYPE>;

#endif  // #ifdef cls_TypeAdapter_h
