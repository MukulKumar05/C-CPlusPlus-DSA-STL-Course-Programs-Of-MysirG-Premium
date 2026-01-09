#include<iostream>
using namespace std;

/*
A15.8 Write a recursive function to print squares of first N
natural numbers in reverse order.

Problem Summary: define recursive function printSquaresOfFirstNNaturalNumbersInReverse(int N)
(Completed)
*/
void printSquaresofFirstNNaturalNumbersInReverse(int N)
{
    cout<<N * N<<" ";
    if(N > 1)
        printSquaresofFirstNNaturalNumbersInReverse(N - 1);
}

int main()
{
    int n = 6;
    printSquaresofFirstNNaturalNumbersInReverse(n);
    return 0;
}