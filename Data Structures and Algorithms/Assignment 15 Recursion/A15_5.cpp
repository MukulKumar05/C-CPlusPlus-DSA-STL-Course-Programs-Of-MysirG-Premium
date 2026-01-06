#include<iostream>
using namespace std;

/*
A15.5 Write a recursive function to print first N
even natural numbers.

Problem Summary: define recursive function printFirstNEvenNaturalNumbers(int N)
(Completed)
*/
void printFirstNEvenNaturalNumbers(int N)
{
    if(N > 1)
        printFirstNEvenNaturalNumbers(N - 1);
    cout<<2 * N;    
}

int main()
{
    
    return 0;
}