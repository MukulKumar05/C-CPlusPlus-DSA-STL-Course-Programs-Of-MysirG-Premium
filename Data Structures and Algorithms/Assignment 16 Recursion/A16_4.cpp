#include<iostream>
using namespace std;

/*
A16.4 Write a recursive function to calculate sum of squares of
first N natural numbers.

Problem Summary: define recursive function sumOfSquaresOfFirstNNaturalNumbers(int N)
(Completed)
*/
int sumOfSquaresOfFirstNNaturalNumbers(int N)
{
    if(N > 0)
        return sumOfSquaresOfFirstNNaturalNumbers(N - 1) + N * N;
    return 0;
}

int main()
{
    
    return 0;
}