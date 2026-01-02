#include<iostream>
using namespace std;

/*
A15.1 Write a recursive function to print first N natural numbers.

Problem Summary: define recursive function printFirstNNaturalNumbers(int N)
(Completed)
*/
void printFirstNNaturalNumbers(int N)
{
    if(N > 1)
        printFirstNNaturalNumbers(N - 1);
    cout<<N;    
}

int main()
{
    
    return 0;
}
