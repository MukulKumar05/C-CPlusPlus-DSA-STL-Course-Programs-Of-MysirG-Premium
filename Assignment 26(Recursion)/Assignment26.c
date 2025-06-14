#include<stdio.h>

/* A26.1 Write a recursive function to print first N even natural numbers 
in reverse order.
(Completed)*/
void printFirstNEvenNaturalNumbersReverse(int N)
{
    printf("%d ", 2 * N);
    if(N > 1)
        printFirstNEvenNaturalNumbersReverse(N - 1);    
}

/* A26.2 Write a recursive function to print squares of first N natural numbers.
(Completed)
*/
void printSquaresofFirstNNaturalNumbers(int N)
{
    if(N > 1)
        printSquaresofFirstNNaturalNumbers(N - 1);
    printf("%d ", N * N);
}

/* A26.3 Write a recursive function to print binary of a given decimal number.
(Completed)*/
void printBinaryofDecimal(int number)
{
    if(number / 2 != 0)
        printBinaryofDecimal(number / 2);
    printf("%d", number % 2);
}

/* A26.4 Write a recursive function to print octal of a given decimal number.
(Completed)*/
void printOctalofDecimal(int number)
{
    if(number / 8 != 0)
        printOctalofDecimal(number / 8);
    printf("%d", number % 8);
}

/* A26.5 Write a recursive function to print reverse of a given number.
(Completed)*/
void printReverse(int number)
{
    if(number)
    {
        printf("%d", number % 10);
        printReverse(number / 10);
    }
}

int main()
{
    printReverse(376);
    return 0;
}
