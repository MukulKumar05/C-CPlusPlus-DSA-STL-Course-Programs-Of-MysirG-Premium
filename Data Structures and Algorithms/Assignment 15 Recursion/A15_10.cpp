#include<iostream>
using namespace std;

/*
A15.10 Write a recursive function to print cubes of first N
natural numbers in reverse order.

Problem Summary: define recursive function printCubesOfFirstNNaturalNumbersInReverse(int N)
(Completed)
*/
void printCubesOfFirstNNaturalNumbersInReverse(int N)
{
    cout<<N * N * N<<" ";
    if(N > 1)
        printCubesOfFirstNNaturalNumbersInReverse(N - 1);
}

int main()
{
    int n = 4;
    printCubesOfFirstNNaturalNumbersInReverse(n);
    return 0;
}