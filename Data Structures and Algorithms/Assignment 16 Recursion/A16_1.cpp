#include<iostream>
using namespace std;

/*
A16.1 Write a recursive function to calculate sum of first N
natural numbers.

Problem Summary: define recursive function sumOfFirstNNaturalNumbers(int N)
(Completed)
*/
int sumOfFirstNNaturalNumbers(int N)
{
    if(N > 0)
        return sumOfFirstNNaturalNumbers(N - 1) + N;
    return 0;
}

int main()
{
    
    return 0;
}
