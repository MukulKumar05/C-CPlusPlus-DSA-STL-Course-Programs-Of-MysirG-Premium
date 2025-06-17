#include<stdio.h>

/*A29.1 Write a program to calculate
the sum of numbers stored in an
array of size 10. Take array values
from the user. 
(Completed)
*/
int main()
{
    int arr[10], i, sum;
    printf("Enter values of array:\n"); 
    for(i=0;i<10;i++)
        scanf("%d", &arr[i]);
    for(i=0,sum=0;i<10;i++)
        sum += arr[i];
    printf("Sum of array elements is %d.", sum);       
    return 0;
}
