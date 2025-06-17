#include<stdio.h>

/*A29.4 Write a program to find the
greatest number stored in an
array of size 10. Take array values
from the user. 
(Completed)
*/
int main()
{
    int arr[10], i, greatest;
    printf("Enter values of array:\n"); 
    for(i=0;i<10;i++)
        scanf("%d", &arr[i]);
    greatest = arr[0];
    for(i=1;i<10;i++)
        if(arr[i] > greatest)
            greatest = arr[i];
    printf("Greatest number in array is %d.", greatest);
    return 0;
}