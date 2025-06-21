#include<stdio.h>

/* A33.2 Write a program to calculate the product of two matrices each of order 3X3.
(Completed)
*/

int main()
{
    int m1[3][3], m2[3][3], i, j, k, matrixProduct[3][3];
    printf("Enter elements of matrix 1 row wise:\n");
    for (i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            scanf("%d", &m1[i][j]);
    
    printf("Enter elements of matrix 2 row wise:\n");
    for (i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            scanf("%d", &m2[i][j]);
    
    // assigning value = 0 to all elements of product matrix
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            matrixProduct[i][j] = 0;
    
    // matrix multiplication logic
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            for(k = 0; k < 3; k++)
                matrixProduct[i][j] += m1[i][k] * m2[k][j];
    
    // printing product matrix
    printf("Matrix product is:\n");
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
            printf("%d ", matrixProduct[i][j]);
        printf("\n");
    }
    return 0;
}