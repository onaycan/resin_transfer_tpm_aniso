/* -*- mode: c++ -*- */
#ifndef BLOCKED_ARRAY_H
#define BLOCKED_ARRAY_H


// Begin local Includes
#include <mem_AllocationOperators.h>
#include <omi_types.h>

///////////////////////////////////////////////////////////////////////////////
//
// Name      : omi_BlockedArray template class definition
//
// Description:
//
//     The blocked array provides a simple storage mechanism for indexed 
//     entities of type <T>.  Instantiation of a blocked array determines 
//     an initial (and increment) size of the block pointers.  The size of 
//     blocks is set as a power of 2 to optimize the lookups to use 
//     exclusively shift (>>) and AND (&) operators to locate entities based 
//     on indicies.  omi_BlockedArrays will grow as needed and actual blocks 
//     are only allocated if cells (<T>) are inserted based on indicies within
//     a block's interval (based on index>>blockOrder).  This storage 
//     structure works well for containers of unknown size at initiation and
//     for containers holding entities based on a sparse distribution of 
//     indicies.  The overhead for holding contiguous arrays is low.  If the 
//     block sizes are kept =< machine page sizes, these blocked arrays can 
//     be advantagous for very large containers as well.
//
// Author:
//        
//     Phil Greene
//
// Creation date: 3-25-1999
//

template<class T>
class omi_BlockedArray  : public mem_AllocationOperators
{
   protected:
      uint blockPointerInc;
      uint blockPointerSize;
      uint blockSize;
      uint blockOrder;
      uint blockModulus;
      T  **blockPointers; 
      void Realloc( uint size );
      void Clear();

  private:
      void BlockInitialize(T*);
      void BlockCopy(T*, const T*);

   public:
      omi_BlockedArray( uint init_pointer_sz, 
                    uint block_order );

      omi_BlockedArray( const omi_BlockedArray<T>& blk_array );

      virtual ~omi_BlockedArray();

      omi_BlockedArray<T>& operator=( const omi_BlockedArray<T>& blk_array );

      inline T* GetCell( uint index ) const {
         uint offset = index>>blockOrder;
         T *block = offset < blockPointerSize ? 
                             blockPointers[offset] : 0;
         return (block != 0) ? &block[index & blockModulus] : 0;
      }

      void SetCell( uint index, const T& value );
      void DumpArray();
};

// declaration and instantiation macro's
#define OMI_BLOCKEDARRAY_DECL(TYPE,NAME)\
typedef omi_BlockedArray<TYPE> NAME;

#define OMI_BLOCKEDARRAY_IMPL(TYPE)\
template class omi_BlockedArray<TYPE>;

#endif


