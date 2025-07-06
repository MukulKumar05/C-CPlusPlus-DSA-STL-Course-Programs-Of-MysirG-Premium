/*
A1.5 Write a C function to check whether a given number is a Prime number or not. (TSRS).
(Completed)
*/

#include<stdio.h>

int isPrimeNumber(int number)
{
    int i;
    for(i = 2; i <= number / 2; i++)
    {
        if(number % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int x = 23;
    if(isPrimeNumber(x))
        printf("%d is a prime number.", x);
    else
        printf("%d is not a prime number.", x);
    return 0;
}