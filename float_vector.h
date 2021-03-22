#ifndef float_vector_h
#define float_vector_h
#include "vector_c.h"
#include <stdio.h>

void* minus_float(void* x);
void* sum_float(void* x, void* y);
void* mult_float(void* x, void* y);
struct VectorN* Create0Float(size_t size);
struct VectorN* Create1Float(size_t size);
struct VectorN* CreateFromValuesFloat(size_t size, void* values);
struct VectorN* printVectorFloat(struct VectorN* v);
struct VectorN* scanVectorFloat(void);

#endif /* float_vector_h */
