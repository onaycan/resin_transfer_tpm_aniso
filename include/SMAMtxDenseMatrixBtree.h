#ifndef SMAMtxDenseMatrixBtree_h
#define SMAMtxDenseMatrixBtree_h

// Begin local includes

#include <cow_Btree.h>

class SMAMtxDenseMatrix;
typedef SMAMtxDenseMatrix* SMAMtxDenseMatrixPtr;

COW_BTREE_DECL(int, SMAMtxDenseMatrixPtr, SMAMtxDenseMatrixBtree);

#endif // SMAMtxDenseMatrixBtree_h
