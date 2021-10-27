/*   -*- mode: c++ -*-   */
#ifndef inp_Data_h
#define inp_Data_h

///////////////////////////////////////////////////////////////////////////////
//
// File Name: inp_Data.h
//
// Description:  Data line classes
//

// Includes

// Forward declarations

class inp_DataArray;
class inp_Element;
template <class Value> class omi_IntTable;
typedef omi_IntTable<inp_Element> inp_MapInt2Element;

// Begin local includes
#include <mem_AllocationOperators.h>

#include <inp_types.h>
#include <cow_ListString.h>
#include <cow_MapInt2ListInt.h>


// Class definition

class inp_DataArrayImpl  : public mem_AllocationOperators
{
    friend class inp_DataArray;

  public:

    inp_DataArrayImpl();
    virtual ~inp_DataArrayImpl();

    virtual int Rows() const = 0;
    virtual int Cols(int row) const = 0;

    virtual inp_Types::typeEnm Type(int i, int j) const = 0;
    virtual bool IsNone(int i, int j) const = 0;
    virtual bool HasValue(int i, int j) const = 0;

    virtual int AsInt(int, int) const = 0;
    virtual double AsDouble(int, int) const = 0;
    virtual cow_String AsString(int, int) const = 0;
    virtual cow_String AsStringVerbatim(int, int) const = 0;

    virtual inp_DataArrayImpl& Set(int row, int col, int i) = 0;
    virtual inp_DataArrayImpl& Set(int row, int col, double d) = 0;
    virtual inp_DataArrayImpl& Set(int row, int col, const cow_String& s) = 0;

    virtual void Append(const char*) = 0;
    virtual void AppendRaw(const char*) = 0;

    virtual bool HasRowContinuation(int) const = 0;

  private:

    virtual inp_DataArrayImpl* Copy() const = 0;
    inp_DataArrayImpl(const inp_DataArrayImpl&);
    inp_DataArrayImpl& operator=(const inp_DataArrayImpl&);
};


class inp_ElementDataArrayImpl: public inp_DataArrayImpl
{
  public:

    inp_ElementDataArrayImpl();
    inp_ElementDataArrayImpl(const inp_DataArray&);
    inp_ElementDataArrayImpl(const cow_MapInt2ListInt&);
    inp_ElementDataArrayImpl(const cow_ListInt&,
			     const inp_MapInt2Element&);
    virtual ~inp_ElementDataArrayImpl();

    virtual int Rows() const;
    virtual int Cols(int row) const;

    virtual inp_Types::typeEnm Type(int i, int j) const;
    virtual bool IsNone(int i, int j) const;
    virtual bool HasValue(int i, int j) const;

    virtual int AsInt(int, int) const;
    virtual double AsDouble(int, int) const;
    virtual cow_String AsString(int, int) const;
    virtual cow_String AsStringVerbatim(int, int) const;

    virtual inp_DataArrayImpl& Set(int row, int col, int i);
    virtual inp_DataArrayImpl& Set(int row, int col, double d);
    virtual inp_DataArrayImpl& Set(int row, int col, const cow_String& s);

    virtual void Append(const char*);
    virtual void AppendRaw(const char*);

    virtual bool HasRowContinuation(int) const;

  private:

    virtual inp_DataArrayImpl* Copy() const;
    inp_ElementDataArrayImpl(const inp_ElementDataArrayImpl&);
    inp_ElementDataArrayImpl& operator=(const inp_ElementDataArrayImpl&);
    void CopyElementData(const inp_ElementDataArrayImpl&);

    // Members

    int nrows;
    int* ncols;
    int** data;
};

class inp_NodeDataArrayImpl: public inp_DataArrayImpl
{
  public:

    inp_NodeDataArrayImpl();
    inp_NodeDataArrayImpl(int numberNodes);
    inp_NodeDataArrayImpl(const inp_DataArray&);
    virtual ~inp_NodeDataArrayImpl();

    virtual int Rows() const;
    virtual int Cols(int row) const;

    virtual inp_Types::typeEnm Type(int i, int j) const;
    virtual bool IsNone(int i, int j) const;
    virtual bool HasValue(int i, int j) const;

    virtual int AsInt(int, int) const;
    virtual double AsDouble(int, int) const;
    virtual cow_String AsString(int, int) const;
    virtual cow_String AsStringVerbatim(int, int) const;

    virtual inp_DataArrayImpl& Set(int row, int col, int i);
    virtual inp_DataArrayImpl& Set(int row, int col, double d);
    virtual inp_DataArrayImpl& Set(int row, int col, const cow_String& s);

    virtual void Append(const char*);
    virtual void AppendRaw(const char*);
    virtual void Append(int id, double x, double y, double z);

    virtual bool HasRowContinuation(int) const;

  private:

    virtual inp_DataArrayImpl* Copy() const;
    inp_NodeDataArrayImpl(const inp_NodeDataArrayImpl&);
    inp_NodeDataArrayImpl& operator=(const inp_NodeDataArrayImpl&);
    void CopyNodeData(const inp_NodeDataArrayImpl&);

    int nrows;
    int allocatedSize;
    int* ids;
    double** data;
};

class inp_RawDataArrayImpl: public inp_DataArrayImpl
{
    friend class inp_ElementDataArrayImpl;
    friend class inp_NodeDataArrayImpl;

  public:

    inp_RawDataArrayImpl();
    virtual ~inp_RawDataArrayImpl();

    virtual int Rows() const;
    virtual int Cols(int row) const;

    virtual inp_Types::typeEnm Type(int i, int j) const;
    virtual bool IsNone(int i, int j) const;
    virtual bool HasValue(int i, int j) const;

    virtual int AsInt(int, int) const;
    virtual double AsDouble(int, int) const;
    virtual cow_String AsString(int, int) const;
    virtual cow_String AsStringVerbatim(int, int) const;

    virtual inp_DataArrayImpl& Set(int row, int col, int i);
    virtual inp_DataArrayImpl& Set(int row, int col, double d);
    virtual inp_DataArrayImpl& Set(int row, int col, const cow_String& s);

    virtual void Append(const char*);
    virtual void AppendRaw(const char*);

    virtual bool HasRowContinuation(int) const;

  private:

    static inp_Types::typeEnm Type(const char*);
    virtual inp_DataArrayImpl* Copy() const;
    inp_RawDataArrayImpl(const inp_RawDataArrayImpl&);
    inp_RawDataArrayImpl& operator=(const inp_RawDataArrayImpl&);
    void CopyRawData(const inp_RawDataArrayImpl&);
    
    // Members

    int nrows;
    int allocatedSize;
    char** rawData;
    int* ncols;
};

class inp_DataArray  : public mem_AllocationOperators
{
    friend class inp_ElementDataArrayImpl;
    friend class inp_NodeDataArrayImpl;

  public:

    inp_DataArray(): dataArray(new inp_RawDataArrayImpl()) {}
    void Set(inp_DataArrayImpl* adoptMe) { dataArray = adoptMe; }
    inp_DataArrayImpl* Copy() const { return dataArray.GetRef().Copy(); }

    inline int Rows() const;
    inline int Cols(int row) const;

    inline inp_Types::typeEnm Type(int i, int j) const;
    inline bool IsNone(int i, int j) const;
    inline bool HasValue(int i, int j) const;

    inline int AsInt(int i, int j) const;
    inline double AsDouble(int, int) const;
    inline cow_String AsString(int, int) const;
    inline cow_String AsStringVerbatim(int, int) const;

    inline int AsInt(int i, int j, int) const;
    inline double AsDouble(int, int, double) const;
    cow_String AsString(int, int, const cow_String&) const;
    inline cow_String AsStringVerbatim(int, int, const cow_String&) const;

    inline inp_DataArray& Set(int i, int j, int ival);
    inline inp_DataArray& Set(int i, int j, double dval);
    inline inp_DataArray& Set(int i, int j, const cow_String& sval);

    void RemoveNullRightColumn(int row);
    inline void Append(const char* buf);
    inline void AppendRaw(const char*);
    inline void Append(const cow_ListString& buf);

    bool HasRowContinuation(int) const;

  private:

    cow_CountedHld<inp_DataArrayImpl> dataArray;
};

inline int
inp_DataArray::Rows() const
{
    return dataArray.GetRef().Rows();
}

inline int
inp_DataArray::Cols(int row) const
{
    return dataArray.GetRef().Cols(row);
}

inline inp_Types::typeEnm
inp_DataArray::Type(int row, int col) const
{
    return dataArray.GetRef().Type(row, col);
}

inline bool
inp_DataArray::IsNone(int row, int col) const
{
    return dataArray.GetRef().IsNone(row, col);
}

inline bool
inp_DataArray::HasValue(int row, int col) const
{
    return dataArray.GetRef().HasValue(row, col);
}

inline int
inp_DataArray::AsInt(int row, int col) const
{
    return dataArray.GetRef().AsInt(row, col);
}

inline int
inp_DataArray::AsInt(int row, int col, int def) const
{
    if (row < Rows())
	if (col < Cols(row))
	    return dataArray.GetRef().AsInt(row, col);
    return def;
}

inline double
inp_DataArray::AsDouble(int row, int col) const
{
    return dataArray.GetRef().AsDouble(row, col);
}

inline double
inp_DataArray::AsDouble(int row, int col, double def) const
{
    if (row < Rows())
	if (col < Cols(row))
	    return dataArray.GetRef().AsDouble(row, col);
    return def;
}

inline cow_String
inp_DataArray::AsString(int row, int col) const
{
    return dataArray.GetRef().AsString(row, col);
}

inline cow_String
inp_DataArray::AsStringVerbatim(int row, int col) const
{
    return dataArray.GetRef().AsStringVerbatim(row, col);
}

inline cow_String
inp_DataArray::AsStringVerbatim(int row, int col, const cow_String& def) const
{
    if (row < Rows())
	if (col < Cols(row))
	    return dataArray.GetRef().AsStringVerbatim(row, col);
    return def;
}

inline inp_DataArray&
inp_DataArray::Set(int i, int j, int ival)
{
    dataArray.GetPtr()->Set(i, j, ival);
    return *this;
}

inline inp_DataArray&
inp_DataArray::Set(int i, int j, double dval)
{
    dataArray.GetPtr()->Set(i, j, dval);
    return *this;
}

inline inp_DataArray&
inp_DataArray::Set(int i, int j, const cow_String& sval)
{
    dataArray.GetPtr()->Set(i, j, sval);
    return *this;
}

inline void
inp_DataArray::Append(const char* buf)
{
    dataArray.GetPtr()->Append(buf);
}      

inline void
inp_DataArray::AppendRaw(const char* buf)
{
    dataArray.GetPtr()->AppendRaw(buf);
}      

inline void
inp_DataArray::Append(const cow_ListString& buf)
{
    cow_String str;
    cow_ListStringIT iter(buf);
    for (iter.First(); ! iter.IsDone(); iter.Next())
	str.Append(iter.CurrentItem()).Append(",");

    int l = str.Length();
    if (l > 0)
	dataArray.GetPtr()->Append(str.Substr(0, l-1).CStr());
    else
	dataArray.GetPtr()->Append(str.CStr());
}

inline bool 
inp_DataArray::HasRowContinuation(int row) const
{
    return dataArray.GetPtr()->HasRowContinuation(row);
}


#endif /* inp_Data_h */
