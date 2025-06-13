#include<stdio.h>

/*A25.1 write a recursive function to print first N natural numbers. 
(Completed)*/
void printFirstNNaturalNumbers(int N)
{
    if(N > 1)
        printFirstNNaturalNumbers(N - 1);
    printf("%d ", N);    
}

/*A25.2 Write a recursive function to
print first N natural numbers in Reverse
Order
(Completed)*/
void printFirstNNaturalNumbersReverse(int N)
{
    printf("%d ", N);
    if(N > 1)
        printFirstNNaturalNumbersReverse(N - 1);
}

/*A25.3 Write a recursive function 
to print first N odd natural numbers.
(Completed)*/
void printFirstNOddNaturalNumbers(int N)
{
    if(N > 1)
        printFirstNOddNaturalNumbers(N - 1);
    printf("%d ", 2 * N - 1);    
}

/*A25.4 Write a recursive function to print first N odd natural numbers in
reverse order.
(Completed)
*/
void printFirstNOddNaturalNumbersReverse(int N)
{
    printf("%d ", 2 * N - 1);
    if(N > 1)
        printFirstNOddNaturalNumbersReverse(N - 1);
}

/*A25.5 Write a recursive function to print first N even natural numbers.
(Completed)*/
void printFirstNEvenNaturalNumbers(int N)
{
    if(N > 1)
        printFirstNEvenNaturalNumbers(N - 1);
    printf("%d ", 2 * N);    
}

int main()
{
    printFirstNEvenNaturalNumbers(10);
    return 0;
}
