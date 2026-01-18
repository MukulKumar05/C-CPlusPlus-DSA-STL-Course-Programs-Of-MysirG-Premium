#include<iostream>
using namespace std;

/*
A16.7 Write a recursive function to print binary of a
given decimal number.

Problem Summary: define recursive function printBinaryOfDecimalNumber(int number)
(Completed)
*/
void floating_binaryOfDecimal(float);
void floating_binaryOfDecimal(float n)
{
    int i;
    for(i = 1; i <= 8; i++)
    {
        n = n * 2;
        if(n >= 1)
        {
            int integral = n;
            n = n - integral;
            cout<<integral;
            if(n == 0)
                break;
        }
        else
            cout<<"0";
    }
}

void print_binaryOfDecimal(float);
void print_binaryOfDecimal(float n)
{
    if(n == 0)
        cout<<"0";
    else if(n < 0)
    {
        cout<<"-";
        print_binaryOfDecimal(n * -1);
    }
    else
    {
        int integral = n;
        if(integral == n)
        {
            print_binaryOfDecimal(integral / 2);
            cout<<integral % 2;
        }
        else
        {
            float fraction = n - integral;
            print_binaryOfDecimal(integral);
            cout<<".";
            floating_binaryOfDecimal(fraction);
        }
    }
}

int main()
{
    
    return 0;
}