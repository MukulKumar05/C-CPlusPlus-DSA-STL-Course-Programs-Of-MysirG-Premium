#include<iostream>
using namespace std;

/*
A16.10 Write a recursive function to calculate x power y.

Problem Summary: define recursive function numberRaisedToPower(int base, int power)
(Completed)
*/
int numberRaisedToPower(int base, int power)
{
    if(power == 0)
        return 1;
    return base * numberRaisedToPower(base, power - 1);  
}

int main()
{
    
    return 0;
}