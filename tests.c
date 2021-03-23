#include "tests.h"
#include "float_vector.h"
#include "complex_vector.h"
#include <stdlib.h>

void* floatVectorTests()
{
    float* coord1 = (float*)malloc(sizeof(float)*3);
        for(int i = 0; i < 3; i++)
        {
            *(coord1+i) = 1.5f + i;
        };
    struct VectorN* v1 = createFromValuesFloat(3, coord1);
    float* coord2 = (float*)malloc(sizeof(float)*3);
        for(int i = 0; i < 3; i++)
        {
            *(coord2+i) = 2.2f + i;
        };
    struct VectorN* v2 = createFromValuesFloat(3, coord2);
    printf("============================================================\n");
    printf("Two vectors with coordinates:\n");
    printVectorFloat(v1);
    printVectorFloat(v2);
    
    printf("\nFirst test. Summ of vectors.\n");
    struct VectorN* v_summ = SumN(v1, v2);
    printf("Expected result: [3.70, 5.70, 7.70]\n");
    printf("Result of function SumN: ");
    printVectorFloat(v_summ);
    
    printf("\nSecond test. Subtraction of vectors.\n");
    struct VectorN* v_subt = MinusN(v1, v2);
    printf("Expected result: [-0.70, -0.70, -0.70]\n");
    printf("Result of function minusN: ");
    printVectorFloat(v_subt);
    
    printf("\nThird test. Scalar multiplication of vectors.\n");
    struct VectorN* v_mult = ScalarMultN(v1, v2);
    printf("Expected result: [3.30, 8.00, 14.70]\n");
    printf("Result of function scalarMultN: ");
    printVectorFloat(v_mult);
    printf("============================================================\n");
    return 0;
};

void* complexVectorTests()
{
    float cord1[2][3] = {1.5, 2.2, 3, 4, 5.8, 6};
    float cord2[2][3] = {6, 5.8, 4, 3, 2.2, 1.5};
    struct VectorN* v1 = createFromValuesComplex(3, cord1);
    struct VectorN* v2 = createFromValuesComplex(3, cord2);
    printf("============================================================\n");
    printf("Two vectors with coordinates:\n");
    printVectorComplex(v1);
    printVectorComplex(v2);
    printf("\nFirst test. Summ of vectors.\n");
    struct VectorN* v_summ = SumN(v1, v2);
    printf("Expected result: [(7.50; 8.00i), (7.00; 7.00i), (8.00; 7.50i)]\n");
    printf("Result of function SumN: ");
    printVectorComplex(v_summ);
    
    printf("\nSecond test. Subtraction of vectors.\n");
    struct VectorN* v_subt = MinusN(v1, v2);
    printf("Expected result: [(-4.50; -3.60i), (-1.00; 1.00i), (3.60; 4.50i)]\n");
    printf("Result of function minusN: ");
    printVectorComplex(v_subt);
    
    printf("\nThird test. Scalar multiplication of vectors.\n");
    struct VectorN* v_mult = ScalarMultN(v1, v2);
    printf("Expected result: [(-3.76; 21.90i), (0.00; 25.00i), (3.76; 21.90i)]\n");
    printf("Result of function scalarMultN: ");
    printVectorComplex(v_mult);
    printf("============================================================\n");
    return 0;
};
