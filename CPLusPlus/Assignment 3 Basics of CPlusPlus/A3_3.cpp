/*
A3.3 Write a C++ program to swap values of two int variables without using third variable.
(Completed)
*/

#include<iostream>

using namespace std;

int main()
{
    int x, y;
    cout<<"Enter first number: ";
    cin>>x;
    cout<<"Enter second number: ";
    cin>>y;
    cout<<"Before swapping:"<<endl<<"The values are first number="<<x<<" and second number="<<y<<endl;
    x = x + y;
    y = x - y;
    x = x - y;
    cout<<"After swapping:"<<endl<<"The values are first number="<<x<<" and second number="<<y<<endl;
    return 0;
}