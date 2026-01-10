#include<iostream>
using namespace std;

/*
A15.9 Write a recursive function to print cubes of first N
natural numbers.

Problem Summary: define recursive function printCubesOfFirstNNaturalNumbers(int N)
(Completed)
*/
void printCubesOfFirstNNaturalNumbers(int N)
{
    if(N > 1)
        printCubesOfFirstNNaturalNumbers(N - 1);
    cout<<N * N * N<<" ";
}

int main()
{
    int n = 4;
    printCubesOfFirstNNaturalNumbers(n);
    return 0;
}