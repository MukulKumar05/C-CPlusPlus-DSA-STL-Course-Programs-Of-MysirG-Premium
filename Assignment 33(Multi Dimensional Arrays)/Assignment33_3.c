/* A33.3 Write a program to print the transpose of a given matrix.
(Completed)
*/

#include<stdio.h>
int main()
{
    int m[3][3], mTranspose[3][3], i, j;
    printf("Enter elements of matrix of order 3X3: \n");
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            scanf("%d", &m[i][j]);
        }
    }

    // calculating transponse of matrix
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            mTranspose[i][j] = m[j][i];
    
    // printing transpose matrix
    printf("Matrix transpose is:\n");
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
            printf("%d ", mTranspose[i][j]);
        printf("\n");
    }
    return 0;
}