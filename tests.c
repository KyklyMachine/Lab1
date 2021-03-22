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
    struct VectorN* v1 = CreateFromValuesFloat(3, coord1);
    float* coord2 = (float*)malloc(sizeof(float)*3);
        for(int i = 0; i < 3; i++)
        {
            *(coord2+i) = 2.2f + i;
        };
    struct VectorN* v2 = CreateFromValuesFloat(3, coord2);
    printf("============================================================\n");
    printf("Two vectors with coordinates:\n");
    printVectorFloat(v1);
    printVectorFloat(v2);
    printf("\nFirst test. Summ of vectors.\n");
    struct VectorN* v_summ = sumN(v1, v2);
    printf("Expected result: [3.70, 5.70, 7.70]\n");
    printf("Result of function SumN: ");
    printVectorFloat(v_summ);
    
    printf("\nSecond test. Scalar multiplication of vectors.\n");
    struct VectorN* v_mult = scalarMultN(v1, v2);
    printf("Expected result: [3.30, 8.00, 14.70]\n");
    printf("Result of function scalarMultN: ");
    printVectorFloat(v_mult);
    printf("============================================================\n");
    return 0;
};

void* complexVectorTests()
{
    
    struct VectorN* v1 = create1compl(3);
    struct VectorN* v2 = create1compl(3);
    
    printf("============================================================\n");
    printf("Two vectors with coordinates:\n");
    printVectorComplex(v1);
    printVectorComplex(v2);
    printf("\nFirst test. Summ of vectors.\n");
    struct VectorN* v_summ = sumN(v1, v2);
    printf("Expected result: [(2.00; 2.00i), (2.00; 2.00i), (2.00; 2.00i)]\n");
    printf("Result of function SumN: ");
    printVectorComplex(v_summ);
    
    printf("\nSecond test. Scalar multiplication of vectors.\n");
    struct VectorN* v_mult = scalarMultN(v1, v2);
    printf("Expected result: [(0.00; 2.00i), (0.00; 2.00i), (0.00; 2.00i)]\n");
    printf("Result of function scalarMultN: ");
    printVectorComplex(v_mult);
    printf("============================================================\n");
    return 0;
};
