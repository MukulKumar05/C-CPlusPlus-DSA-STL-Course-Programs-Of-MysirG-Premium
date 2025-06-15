#include<stdio.h>

/* A27.1 Write a recursive function to calculate sum of first N natural numbers.
(Completed)*/
int sumOfFirstNNaturalNumbers(int N)
{
    if(N > 0)
        return sumOfFirstNNaturalNumbers(N - 1) + N;
    return 0;
}

/* A27.2 Write a recursive function to calculate sum of first N odd natural numbers.
(Completed)*/
int sumofFirstNOddNaturalNumbers(int N)
{
    if(N > 0)
        return sumofFirstNOddNaturalNumbers(N - 1) + 2 * N - 1;
    return 0;
}

/* A27.3 Write a recursive function to calculate sum of first N even natural numbers.
(Completed)*/
int sumofFirstNEvenNaturalNumbers(int N)
{
    if(N > 0)
        return sumofFirstNEvenNaturalNumbers(N - 1) + 2 * N;
    return 0;
}

/* A27.4 Write a recursive function to calculate sum of squares of first n natural numbers.
(Completed)*/
int sumOfSquaresOfFirstNNaturalNumbers(int N)
{
    if(N > 0)
        return sumOfSquaresOfFirstNNaturalNumbers(N - 1) + N * N;
    return 0;
}

/* A27.5 Write a recursive function to calculate sum of digits of a given number.
(Completed)*/
int digitsSum(int number)
{
    if(number)
        return digitsSum(number / 10) + number % 10;
    return 0;
}

int main()
{
    int x = 783;
    printf("Sum of digits of number %d is %d.", x, digitsSum(x));
    return 0;
}
