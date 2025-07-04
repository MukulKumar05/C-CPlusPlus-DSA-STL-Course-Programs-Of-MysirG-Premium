#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
A46.2 Write a program to ask the user to input a number of data values he would like to
enter then create an array dynamically to accomodate the data values. Now take
the input from the user and display the average of data values.

(Completed)
*/

int main()
{
    int valCount, i;
    float sum = 0;
    printf("Enter number of data values which you want to enter: ");
    scanf("%d", &valCount);
    int* arr = (int*) calloc(valCount, 4);
    printf("Enter values of array: ");
    for(i = 0; i < valCount; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(i = 0; i < valCount; i++)
    {
        sum += arr[i];
    }
    free(arr);
    printf("Average of data values is %f", sum / valCount);
    return 0;
}