#include<stdio.h>

/*A29.3 Write a program to calculate
the sum of all even numbers and sum of
all odd numbers, which are stored in an
array of size 10. Take array values
from the user. 
(Completed)
*/
int main()
{
    int arr[10], i, esum, osum;
    printf("Enter values of array:\n"); 
    for(i=0;i<10;i++)
        scanf("%d", &arr[i]);
    for(i=0,esum=0,osum=0;i<10;i++)
        if(arr[i] % 2)
            osum += arr[i];
        else
            esum += arr[i];   
    printf("Sum of all even elements is %d.\n", esum);
    printf("Sum of all odd elements is %d.", osum);       
    return 0;
}