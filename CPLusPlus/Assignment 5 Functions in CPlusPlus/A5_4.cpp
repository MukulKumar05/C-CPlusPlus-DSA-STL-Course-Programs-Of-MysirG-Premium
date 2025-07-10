#include<iostream>
using namespace std;

/*
A5.4 Write functions using function overloading to find a maximum of two
numbers and both the numbers can be integer or real.
(Completed)
*/
double greaterNumber(double num1, double num2)
{
    if(num1 > num2)
        return num1;
    return num2;
}

int main()
{
    int a = 3, b = 4;
    float c = 4.7;
    double d = 4.792;
    cout<<"Greater number between "<<c<<" and "<<b<<" is "<<greaterNumber(c, b)<<endl;
    return 0;
}