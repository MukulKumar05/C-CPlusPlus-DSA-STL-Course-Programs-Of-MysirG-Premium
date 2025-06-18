#include<stdio.h>

/*A30.3 Write a program to find
the second smallest number in an
array. Take array values
from the user. 
(Completed)
*/

int main()
{
    int a[10], b[10], i, j;
    printf("Enter values of array:\n"); 
    for(i=0;i<10;i++)
        scanf("%d", &a[i]);
    for(i=0; i<10; i++)
        b[i]=a[i];    
    for(i=0; i<2; i++)
        for(j=i+1; j<10; j++)
            if(b[j]<b[i])
            {
                b[j]=b[j]+b[i];
                b[i]=b[j]-b[i];
                b[j]=b[j]-b[i];
            }
    printf("Second smallest element of array is %d.", b[1]);
    return 0;
}