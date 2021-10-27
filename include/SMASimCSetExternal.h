#ifndef SMASimCSetExternal_h
#define SMASimCSetExternal_h
// Begin local includes
#include <mem_AllocationOperatorsTiny.h>

class SMASimCSet;
class SMASimCtation;
/**
   An external cset is a represenation of cset as a buffer of bytes that can later be used to reconstruct
   the cset. Note the reconstructed cset will be a volatile cset even though the original may not have been.
**/
class SMASimCSetExternal
    : public mem_AllocationOperatorsTiny  
{
    friend class SMASimCtation;
public:
    /// Construction from a cset
    SMASimCSetExternal(const SMASimCSet& cset);

    /// Construction from a cset and a supplied buffer
    SMASimCSetExternal(const SMASimCSet& cset, char* buffer);

    /// Construction from a buffer
    SMASimCSetExternal(const char* buffer, int len);

    /// Destructor
    ~SMASimCSetExternal();

    /// Test for NULL
    bool IsNull() const { return Size() == 0; }

    /// Return the const externalized version of the cset as a byte buffer
    const char* Buffer()const { return m_buffer; };

    /// Return the size of the buffer holding the cset
    int Size() const { return m_size; }

private:
    /// Assignment operator. Unimplemented.
    SMASimCSetExternal& operator=(SMASimCSetExternal& rhs);

    /// Copy constructor. Unimplemented.
    SMASimCSetExternal(const SMASimCSetExternal& cpy);
    void Externalize(const SMASimCSet& cset);

    /// Construction from a buffer, this constructor should only be 
    /// used when internalizing an SMASimDSetExternal object
    SMASimCSetExternal(const char* buffer);

    /// members
    char* m_buffer;
    bool  m_ownBuffer;
    int   m_size;
};


#endif
