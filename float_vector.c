#include "float_vector.h"
#include <stdio.h>
#include <stdlib.h>

void* zero_float = NULL;
void* one_float = NULL;

void* minus_float(void* x)
{
    float* a = (float*)x;
    float* c = malloc(sizeof(float));
    *c = 0.0f - *a;
    return (void*)c;
};

void* sum_float(void* x, void* y)
{
    float* a = (float*)x;
    float* b = (float*)y;
    float* c = malloc(sizeof(float));
    *c = *a + *b;
    return (void*)c;
};

void* mult_float(void* x, void* y)
{
    float* a = (float*)x;
    float* b = (float*)y;
    float* c = malloc(sizeof(float));
    *c = *a * *b;
    return (void*)c;
};

struct VectorN* Create0Float(size_t size){
    if (zero_float == NULL){ //not zero_float
        zero_float = malloc(sizeof(float));
        *(float*)zero_float = 0.0f;
        one_float = malloc(sizeof(float));
        *(float*)one_float = 1.0f;
    }
    return Create0(size, sizeof(float), zero_float, one_float, minus_float, sum_float, mult_float);
};

struct VectorN* Create1Float(size_t size){
    if (zero_float == NULL){ //not zero_float
        zero_float = malloc(sizeof(float));
        *(float*)zero_float = 0.0f;
        one_float = malloc(sizeof(float));
        *(float*)one_float = 1.0f;
    }
    return Create1(size, sizeof(float), zero_float, one_float, minus_float, sum_float, mult_float);
};

struct VectorN* CreateFromValuesFloat(size_t size, void* values){
    if (zero_float == NULL){ //not zero_float
        zero_float = malloc(sizeof(float));
        *(float*)zero_float = 0.0f;
        one_float = malloc(sizeof(float));
        *(float*)one_float = 1.0f;
    }
    //printf("%f", *(float*)values);
    return CreateFromValues(size, sizeof(float), zero_float, one_float, values, minus_float, sum_float, mult_float);
};

struct VectorN* printVectorFloat(struct VectorN* v)
{
    printf("[");
    for(int i = 0; i < v->dimension - 1; i++){
        printf("%.2f, ", *(float*)(v->coordinates+i*v->elementSize));
    };
    printf("%.2f]\n", *(float*)(v->coordinates + (v->dimension-1)*v->elementSize));
    return 0;
};

struct VectorN* scanVectorFloat()
{
    printf("Enter dimension of vector:");
    int dimension = 0;
    scanf("%d", &dimension);
    float *coordinates = (float *)malloc(dimension * sizeof(float));
    for(int i = 0; i < dimension; i++)
    {
        printf("Enter %d coordinate:", i+1);
        scanf("%f", coordinates + i);
    };
    for(int i = 0; i < dimension; i++)
    {
    };
    return CreateFromValuesFloat(dimension, coordinates);
};
