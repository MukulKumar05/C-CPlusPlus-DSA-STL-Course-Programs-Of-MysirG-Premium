#include<stdio.h>

/*A29.2 Write a program to calculate
the average of numbers stored in an
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
    printf("Average of array elements is %f.", sum/10.0);       
    return 0;
}