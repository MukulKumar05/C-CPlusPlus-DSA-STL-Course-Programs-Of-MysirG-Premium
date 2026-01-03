#include<iostream>
using namespace std;

/*
A15.2 Write a recursive function to print first N natural numbers
in reverse order.

Problem Summary: define recursive function printFirstNNaturalNumbersInReverse(int N)
(Completed)
*/
void printFirstNNaturalNumbersReverse(int N)
{
    printf("%d ", N);
    if(N > 1)
        printFirstNNaturalNumbersReverse(N - 1);
}

int main()
{
    
    return 0;
}