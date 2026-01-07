#include<iostream>
using namespace std;

/*
A15.6 Write a recursive function to print first N even natural
numbers in reverse order.

Problem Summary: Define recursive function printFirstNEvenNaturalNumbersInReverse(int N)
(Completed)
*/
void printFirstNEvenNaturalNumbersReverse(int N)
{
    cout<<2 * N;
    if(N > 1)
        printFirstNEvenNaturalNumbersReverse(N - 1);    
}

int main()
{
    
    return 0;
}