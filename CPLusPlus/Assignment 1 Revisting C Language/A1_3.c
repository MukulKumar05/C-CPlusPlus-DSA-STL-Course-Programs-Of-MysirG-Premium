/*
A1.3 Write a C program to swap values of two int variables.
(Completed)
*/

#include<stdio.h>

int main()
{
    int x, y, z;
    printf("Enter first number: ");
    scanf("%d", &x);
    printf("Enter second number: ");
    scanf("%d", &y);
    printf("Before swapping:\nThe numbers are x=%d and y=%d",x,y);
    z = x;
    x = y;
    y = z;
    printf("\nAfter swapping:\nThe numbers are x=%d and y=%d",x,y);
    return 0;
}