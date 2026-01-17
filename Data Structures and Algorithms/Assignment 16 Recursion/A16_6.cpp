#include<iostream>
using namespace std;

/*
A16.6 Write a recursive function to calculate sum of the digits
of a given number.

Problem Summary: define recursive function sumOfDigitsOfNumber(int number)
(Completed)
*/
int digitsSum(int number)
{
    if(number)
        return digitsSum(number / 10) + number % 10;
    return 0;
}

int main()
{
    
    return 0;
}