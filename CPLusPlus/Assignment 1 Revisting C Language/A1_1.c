/*
A1.1 Write a C program to check whether a given number is even or odd.
(Completed)
*/

#include<stdio.h>

int main()
{
    int number;
    printf("Enter number to check whether it is odd or even: ");
    scanf("%d", &number);
    if(number % 2 == 0)
        printf("%d is even.", number);
    else
        printf("%d is odd.", number);
    return 0;
}
