#include<stdio.h>

/* A33.1 Write a program to calculate the sum of two matrices each of order 3X3.
(Completed)
*/

int main()
{
    int m1[3][3], m2[3][3], i, j, matrixSum[3][3];
    printf("Enter elements of matrix 1 row wise:\n");
    for (i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            scanf("%d", &m1[i][j]);
    
    printf("Enter elements of matrix 2 row wise:\n");
    for (i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            scanf("%d", &m2[i][j]);
    
    for (i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            matrixSum[i][j] = m1[i][j] + m2[i][j];
    
    printf("Sum of matrices is:\n");
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
            printf("%d\t", matrixSum[i][j]);
        printf("\n");
    }
    return 0;
}
