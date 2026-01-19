#include<iostream>
using namespace std;

/*
A16.8 Write a recursive function to find nth term of the
Fibonacci series.

Problem Summary: define recursive function NthTermOfFibonacciSeries(int N)
(Completed)
*/
int nthTermOfFibonacciSeries(int N)
{
    if(N <= 0)
        return -1;
    if(N == 1)
        return 0;
    else if(N == 2)
        return 1;
    return nthTermOfFibonacciSeries(N-1) + nthTermOfFibonacciSeries(N-2);
}

int main()
{
    
    return 0;
}