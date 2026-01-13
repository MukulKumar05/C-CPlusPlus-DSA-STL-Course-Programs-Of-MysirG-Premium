#include<iostream>
using namespace std;

/*
A16.2 Write a recursive function to calculate sum of first N
odd natural numbers.

Problem Summary: define recursive function sumOfFirstNOddNaturalNumbers(int N)
(Completed)
*/
int sumofFirstNOddNaturalNumbers(int N)
{
    if(N > 0)
        return sumofFirstNOddNaturalNumbers(N - 1) + 2 * N - 1;
    return 0;
}

int main()
{
    
    return 0;
}