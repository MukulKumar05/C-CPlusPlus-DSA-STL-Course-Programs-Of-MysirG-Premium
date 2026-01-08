#include<iostream>
using namespace std;

/*
A15.7 Write a recursive function to print squares of first N
natural numbers.

Problem Summary: Define recursive function printSquaresOfFirstNNaturalNumbers(int N)
(Completed)
*/
void printSquaresofFirstNNaturalNumbers(int N)
{
    if(N > 1)
        printSquaresofFirstNNaturalNumbers(N - 1);
    cout<<N * N;
}

int main()
{
    
    return 0;
}