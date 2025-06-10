/*
A22.1 Write a function to calculate the factorial of a number. (TSRS)

A22.2 Write a function to calculate the number of combinations one can make from n items
and r selected at a time. (TSRS)

A22.3 Write a function to calculate the number of arrangements one can make from n items and
r selected at a time. (TSRS)

A22.4 Write a function to check whether a given number contains a given digit or not. (TSRS)

A22.5 Write a function to print all prime factors of a given number. For example, if the number
is 36 then your result should be 2, 2, 3, 3. (TSRN)
*/

#include<stdio.h>

// A22.1 (Completed)
int factorial(int number)
{
    int i, fact = 1;
    if(number == 0)
        return 1;
    else
    {
        for(i = 1; i <= number; i++)
        {
            fact *= i;
        }
        return fact;
    }
}

// A22.2 (Completed)
int combination(int n, int r)
{
    return factorial(n) / (factorial(n - r) * factorial(r)); 
}

// A22.3 (Completed)
int permutation(int n, int r)
{
    return factorial(n) / factorial(n - r);
}

// A22.4 (Completed)
int isDigitinNumber(int digit, int number)
{
    int i;
    while(number)
    {
        if(number % 10 == digit)
            return 1;
        number /= 10;
    }
    return 0;
}


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

// A22.5 (Completed) (Unique Prime Factors of any number)
void printAllUniquePrimeFactorsofNumber(int number)
{
    int i;
    printf("Prime factors of %d are: ", number);
    if(isPrimeNumber(number))
        printf("%d", number);
    else
    {
        for(i = 2; i <= number / 2; i++)
        {
            if(isPrimeNumber(i) && number % i == 0)
                printf("%d, ", i);
        }
        printf("\b\b  ");
    }
}

// A22.5 (Completed) (Prime Factors of any number)
void printAllPrimeFactorsofNumber(int number)
{
    int i, num;
    printf("Prime factors of %d are: ", number);
    if(isPrimeNumber(number))
        printf("%d", number);
    else
    {
        num = number;
        for(i = 2; i <= number / 2; i++)
        {
            if(isPrimeNumber(i) && number % i == 0)
            {
                while(num % i == 0)
                {
                    printf("%d, ", i);
                    num /= i;
                }
                if(num == 1)
                    break;
            }
        }
        printf("\b\b  ");
    }
}

int main()
{
    // printf("5! = %d", factorial(5));
    // printf("5 c 3 = %d", combination(5, 3));
    // printf("5 p 3 = %d", permutation(5, 3));
    // int n = 359, d = 4;
    // if(isDigitinNumber(d, n))
    //     printf("Number %d contains digit %d.", n, d);
    // else
    //     printf("Number %d does not contain digit %d.", n, d);
    printAllPrimeFactorsofNumber(36);
    return 0;
}

