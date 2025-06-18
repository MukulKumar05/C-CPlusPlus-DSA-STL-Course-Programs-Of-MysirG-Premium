#include<stdio.h>

/*A30.5 Write a program in C to copy
the elements of one array into another
array. Take array values
from the user. 
(Completed)
*/

int main()
{
    int a[10], b[10], i, j;
    printf("Enter values of array a:\n"); 
    for(i=0;i<10;i++)
        scanf("%d", &a[i]);
    for(i=0; i<10; i++)
        b[i]=a[i];    
    printf("array a elements are:\n");
    for(i=0;i<10;i++)
        printf("%d ", a[i]);
    printf("\narray b elements are:\n");
    for(i=0;i<10;i++)
        printf("%d ", b[i]);
    return 0;
}