/*
A1.2 Write a C program to calculate factorial of a number.
(Completed)
*/

#include<stdio.h>

int main()
{
    int i = 1, number, fact = 1;
    printf("Enter a number: ");
    scanf("%d", &number);
    if(number < 0)
        printf("Factorial of negative number is not defined.");
    else if(number == 0)
        printf("Factorial of 0 is 1.");
    else
    {
        while(i <= number)
        {
           fact *= i;
           i++; 
        }
        printf("Factorial of %d is %d", number, fact);
    }
    return 0;
}