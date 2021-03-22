#include "complex_vector.h"
#include <stdio.h>
#include <stdlib.h>

void* GetReal(complex* coordinates)
{
    return &(coordinates->Real);
};

void* GetImage(complex* coordinates)
{
    return &(coordinates->Image);
};

void* minus_complex(void* z)
{
    complex* coords = (complex*)z;
    float* coord_1 = GetReal(coords);
    float* coord_2 = GetImage(coords);
    complex* c = malloc(sizeof(complex));
    c->Real = - *coord_1;
    c->Image = - *coord_2;
    return (void*)c;
};

void* sum_complex(void* z1, void* z2)
{
    complex* coord_1 = (complex*)z1;
    complex* coord_2 = (complex*)z2;
    float* a1 = (float*)GetReal(coord_1);
    float* a2 = (float*)GetImage(coord_1);
    float* b1 = (float*)GetReal(coord_2);
    float* b2 = (float*)GetImage(coord_2);
    complex* c = malloc(sizeof(complex));
    c->Real = *a1 + *b1;
    c->Image = *a2 + *b2;
    return (complex*)c;
};

void* mult_complex(void* z1, void* z2)
{
    complex* coord_1 = (complex*)z1;
    complex* coord_2 = (complex*)z2;
    float* a1 = (float*)GetReal(coord_1);
    float* a2 = (float*)GetImage(coord_1);
    float* b1 = (float*)GetReal(coord_2);
    float* b2 = (float*)GetImage(coord_2);
    complex* c = malloc(sizeof(complex));
    c->Real = *a1 * *b1 - *a2 * *b2;
    c->Image = *a1 * *b2 + *a2 * *b1;
    return (void*)c;
}

complex* zero_compl = NULL;
complex* one_compl = NULL;

void* init_zero_one_compl(){
if (zero_compl == NULL){
    zero_compl = malloc(sizeof(complex));
    zero_compl->Image = 0;
    zero_compl->Real = 0;
    one_compl = malloc(sizeof(complex));
    one_compl->Image = 1;
    one_compl->Real = 1;
    };
    return 0;
};

void* complexCoordOutput(complex* z)
{
    printf("(%.2f; %.2fi)", z->Real, z->Image);
    return 0;
};

struct VectorN* create0compl(size_t size)
{
    init_zero_one_compl();
    return Create0(size, sizeof(complex), zero_compl, one_compl, minus_complex, sum_complex, mult_complex);
};
struct VectorN* create1compl(size_t size)
{
    init_zero_one_compl();
    return Create1(size, sizeof(complex), zero_compl, one_compl, minus_complex, sum_complex, mult_complex);
};
struct VectorN* createFromValuesCompl(size_t size, void* coordinates)
{
    init_zero_one_compl();
    return CreateFromValues(size, sizeof(complex), zero_compl, one_compl, coordinates, minus_complex, sum_complex, mult_complex);
};

struct VectorN* printVectorComplex(struct VectorN* v)
{
    printf("[");
    for(int i = 0; i < v->dimension - 1; i++){
        complexCoordOutput(v->coordinates+i*v->elementSize);
        printf(", ");
    }
    complexCoordOutput(v->coordinates+(v->dimension-1)*v->elementSize);
    printf("]\n");
    return 0;
};
struct VectorN* scanVectorComplex()
{
    printf("Enter dimension of vector:");
    int dimension = 0;
    scanf("%d", &dimension);
    complex* h = malloc(sizeof(complex));
    for(int i = 0; i < dimension; i++){
        printf("Enter %d coordinate:\n", i+1);
        printf("Real:");
        scanf("%f", (float*)GetReal(h+i));
        printf("Imaginary:");
        scanf("%f", (float*)GetImage(h+i));
    };
    return createFromValuesCompl(dimension, h);
};
