#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
A46.3 Write a program to calculate the sum of n numbers entered by the user using
malloc and free.

(Completed)
*/

int main()
{
    int n, i, sum = 0;
    printf("Enter number of values which you want to enter: ");
    scanf("%d", &n);
    int* arr = (int*) malloc(n*4);
    printf("Enter values: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    free(arr);
    printf("Sum of %d numbers is %d", n, sum);
    return 0;
}