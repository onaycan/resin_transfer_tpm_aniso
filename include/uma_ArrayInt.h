#ifndef uma_ArrayInt_h
#define uma_ArrayInt_h
///
/// A simple substitute to plain local dynamic array of integers:
///   c-tor allocates memory, 
///   [] checks boundaries, 
///   d-tor frees memory.
/// Default c-tor not implemented, copy c-tor and operator= prohibited.
///

// Begin local includes
#include <mem_AllocationOperators.h>
// End local includes

// Forward declarations
class aio_ostream;

///////////////////////////////////////////////////////////////////////////////

class uma_ArrayInt : public mem_AllocationOperators
{
public: // Public documented API

    /// Constructor(s)
    uma_ArrayInt(int size);
    uma_ArrayInt(int size, int initialValue);

    /// Accessors
    bool IsNull() const { return m_size == 0; }
    int Size() const { return m_size; }
    int operator[](int i) const;
    const int * Values() const { return m_buff; }
    
    /// Mutators
    int & operator[](int i);
    int * Values() { return m_buff; }

///////////////////////////////////////////////////////////////////////////////
private:
    int m_size;
    int * m_buff;
    uma_ArrayInt(const uma_ArrayInt &); // not permitted!
    uma_ArrayInt & operator=(const uma_ArrayInt &); // not permitted!

    uma_ArrayInt(); // delayed allocation
    void Allocate(int size);
    void Free();
public: // Internal, undocumented, not to be used explicitly by client
    ~uma_ArrayInt();
};

aio_ostream& operator<<( aio_ostream&, const uma_ArrayInt &);

///////////////////////////////////////////////////////////////////////////////


#endif // uma_ArrayInt_h
