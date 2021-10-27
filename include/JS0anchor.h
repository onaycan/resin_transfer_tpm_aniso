#ifndef JS0anchor_H
#define JS0anchor_H

// This empty function is called by all constructors and assignment operators
// of the CATString implementation provided by A6 at the point of call.
// This ensures that modules that call CATString aquire a dependence on
// the dummy JS0GROUP module, so that the dependency graph will be
// compatible with V6.

void JS0anchor();

#endif
