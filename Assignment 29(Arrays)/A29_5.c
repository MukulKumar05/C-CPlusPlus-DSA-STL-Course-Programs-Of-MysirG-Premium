#include<stdio.h>

/*A29.5 Write a program to find the
smallest number stored in an
array of size 10. Take array values
from the user. 
(Completed)
*/
int main()
{
    int arr[10], i, smallest;
    printf("Enter values of array:\n"); 
    for(i=0;i<10;i++)
        scanf("%d", &arr[i]);
    smallest = arr[0];
    for(i=1;i<10;i++)
        if(arr[i] < smallest)
            smallest = arr[i];
    printf("Smallest number in array is %d.", smallest);
    return 0;
}