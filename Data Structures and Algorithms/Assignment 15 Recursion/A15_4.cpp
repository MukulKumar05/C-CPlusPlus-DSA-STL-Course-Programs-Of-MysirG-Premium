#include<iostream>
using namespace std;

/*
A15.4 Write a recursive function to print first N odd natural
numbers in reverse order.

Problem Summary: define recursive function printFirstNOddNaturalNumbersInReverse(int N)
(Completed)
*/
void printFirstNOddNaturalNumbersReverse(int N)
{
    printf("%d ", 2 * N - 1);
    if(N > 1)
        printFirstNOddNaturalNumbersReverse(N - 1);
}

int main()
{
    
    return 0;
}