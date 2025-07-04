#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
A46.4 Write a function to merge two array elements and store it in dynamically created
array. Return address of this dynamically created array.

(Completed)
*/
int* mergedArray(int* arr1, int size1, int* arr2, int size2)
{
    int* mrgArr = (int*) calloc(size1 + size2, 4);
    int i;
    for(i = 0; i < size1; i++)
    {
        mrgArr[i] = arr1[i];
    }
    for(i = 0; i < size2; i++)
    {
        mrgArr[i + size1] = arr2[i];
    }
    return mrgArr;
}

int main()
{
    int i, a[4] = {11, 22, 33, 44}, b[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int* mrgA = mergedArray(a, 4, b, 12);
    printf("Merged array is:\n");
    for(i = 0; i < 16; i++)
    {
        printf("%d ", mrgA[i]);
    }
    return 0;
}