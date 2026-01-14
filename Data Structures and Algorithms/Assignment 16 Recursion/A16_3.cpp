#include<iostream>
using namespace std;

/*
A16.3 Write a recursive function to calculate sum of first N
even natural numbers.

Problem Summary: define recursive function sumOfFirstNEvenNaturalNumbers(int N)
(Completed)
*/
int sumofFirstNEvenNaturalNumbers(int N)
{
    if(N > 0)
        return sumofFirstNEvenNaturalNumbers(N - 1) + 2 * N;
    return 0;
}

int main()
{
    
    return 0;
}