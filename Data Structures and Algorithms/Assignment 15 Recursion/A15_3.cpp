#include<iostream>
using namespace std;

/*
A15.3 Write a recursive function to print first N odd natural numbers.

Problem Summary: define recursive function printFirstNOddNaturalNumbers(int N)
(Completed)
*/
void printFirstNOddNaturalNumbers(int N)
{
    if(N > 1)
        printFirstNOddNaturalNumbers(N - 1);
    cout<<2 * N - 1;    
}

int main()
{
    
    return 0;
}