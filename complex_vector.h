#ifndef complex_vector_h
#define complex_vector_h

#include <stdio.h>
#include "vector_c.h"

typedef struct ComplexCoord {
    float Real;
    float Image;
}complex;

void* GetReal(complex* coordinates);
void* GetImage(complex* coordinates);
void* minus_complex(void* z);
void* sum_complex(void* z1, void* z2);
void* mult_complex(void* z1, void* z2);
void* complexCoordOutput(complex* z);
struct VectorN* create0compl(size_t size);
struct VectorN* create1compl(size_t size);
struct VectorN* createFromValuesCompl(size_t size, void* coordinates);
struct VectorN* printVectorComplex(struct VectorN* v);
struct VectorN* scanVectorComplex(void);


#endif /* complex_vector_h */
