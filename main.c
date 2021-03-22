#include "interface.h"

int main()
{
    while (1)
    {
        int typeOfVector;
        printf("Select type of vectors: 1 - Real, 2 - Complex\n");
        scanf("%d", &typeOfVector);
        if (typeOfVector == 1)
        {
            floatVectorsUI();
        continue;
        }
        else if (typeOfVector == 2)
        {
            complexVetorsUI();
            continue;
        }
        else
        {
            printf("Incorrect value!\n");
        };
    };
};
