#include<iostream>
using namespace std;

/*
A16.5 Write a recursive function to calculate factorial of a number.

Problem Summary: define recursive function factorialOfNumber(int number)
(Completed)
*/
int factorial(int n)
{
    if(n < 0)
        return -1;
    if(n == 1 || n == 0)
        return 1;  
    return n * factorial(n - 1);
}

int main()
{
    
    return 0;
}