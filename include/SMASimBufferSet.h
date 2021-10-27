#ifndef SMASimBufferSet_h
#define SMASimBufferSet_h

// begin local includes
#include <mem_AllocationOperatorsTiny.h>
#include <SMASimSerializationType.h>
#include <SMASimTypeKey.h>
// end local includes

/**
* Buffer types
**/
/// \note When adding buffer types keep SMASimnDpaBufferType last and make sure the 
///       new type can be printed (see SMASimBufferSet.C)
enum SMASimBufferType {
    SMASimbufMain,       ///< the data itself
    SMASimbufIndicesNZ,  ///< the non-zero IDs integer buffer, for sparse serialization
    SMASimbufSparseMap,  ///< The 'sparse map' integer buffer, for sparse serialization
    SMASimbufDiagonal,   ///< The 'diagonal' used for SymSparse matrix
    SMASimnDpaBufferType ///< Number of buffer types
};

/// Rteurn the name of the buffer
const char * SMASimstringNameOf( SMASimBufferType k);

/// Debug output
inline SMASimDebugOut& operator <<( SMASimDebugOut& uos, const SMASimBufferType & k) {
    uos << SMASimstringNameOf(k);
    return uos;
}

// -------------------------------------------------------

/// Buffer classes.  All are arrays,  indexed by buffer type

/**
* Holds a full set of buffer pointers, only the applicable buffers will be allocated
**/
class SMASimBufferSet : public mem_AllocationOperatorsTiny
{
public:
    /// Default constructor
    SMASimBufferSet(){Init();}

    /// Initialize buffer pointers to NULL
    void Init();

    /// Return the number of buffers
    int Count() const { return SMASimnDpaBufferType;}

    /// Return a specific buffer pointer reference
    void*&  operator[]( int k ) {    
        CheckRange(k);
        return m_data[k];}

    /// Return a specific buffer pointer
    void*   operator[]( int k ) const {  
        CheckRange(k);
        return m_data[k];}

    /// Debug output
    SMASimDebugOut& WriteDebug(SMASimDebugOut&) const;

private:
    void CheckRange( int e)const {
        SMASimVALIDATE ( SMASimbufMain <= e && e < SMASimnDpaBufferType);
    }
    void* m_data[SMASimnDpaBufferType ];

};

/// Debug output
inline SMASimDebugOut& operator<<(SMASimDebugOut& uos, SMASimBufferSet const& iargs)
{
    return iargs.WriteDebug(uos);
}

/**
* Holds the sizes of each buffer type
**/
class SMASimBufferSizes  : public mem_AllocationOperatorsTiny
{
public:
    /// Default constructor
    SMASimBufferSizes(){Init();}

    /// Initialize buffer sizes to zero
    void Init();

    /// Return the number of buffer sizes
    int Count() const { return SMASimnDpaBufferType;}

    /// Return a reference to the size of a specific buffer
    size_t& operator[](int k) {
        CheckRange(k);
        return m_data[k];}

    /// Return the size specific buffer
    size_t operator[](int k) const {    
        CheckRange(k);
        return m_data[k];}

    /// Assignment operator
    bool operator==(const SMASimBufferSizes& other) const;

    /// Debug output
    SMASimDebugOut& WriteDebug(SMASimDebugOut&) const;

private:
    void CheckRange( int e)const {
        SMASimVALIDATE ( SMASimbufMain <= e && e < SMASimnDpaBufferType);
    }
    size_t m_data[SMASimnDpaBufferType ];
};

/// Debug output
inline SMASimDebugOut& operator<<(SMASimDebugOut& uos, SMASimBufferSizes const& iargs)
{
    return iargs.WriteDebug(uos);
}

/** 
* Holds the type of each buffer
**/
class SMASimBufferDataKeys  : public mem_AllocationOperatorsTiny
{
public:
    /// Default constructor
    SMASimBufferDataKeys(){Init();}

    /// Initialze buffer types
    void Init();

     /// Return the number of buffer types
    int Count() const { return SMASimnDpaBufferType;}

    /// Return a reference to the type of a specific buffer
    SMASimTypeKey&  operator[](int k) {
        CheckRange(k);
        return m_data[k];}

    /// Return the type specific buffer
    SMASimTypeKey  operator[](int k) const {    
        CheckRange(k);
        return m_data[k];}

	/// Returns true if argument is equal to this
    bool operator==(const SMASimBufferDataKeys& other) const;

    /// Debug output
    SMASimDebugOut& WriteDebug(SMASimDebugOut&) const;

private:
    void CheckRange( int e)const {
        SMASimVALIDATE ( SMASimbufMain <= e && e < SMASimnDpaBufferType);
    }
    SMASimTypeKey m_data[SMASimnDpaBufferType ];
};

/// Debug output
inline SMASimDebugOut& operator<<(SMASimDebugOut& uos, SMASimBufferDataKeys const& iargs)
{
    return iargs.WriteDebug(uos);
}

#endif // SMASimBufferSet_h
