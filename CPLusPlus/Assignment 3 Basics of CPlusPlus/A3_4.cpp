/*
A3.4 Write a C++ program to find the maximum of two numbers.
(Completed)
*/

#include<iostream>

using namespace std;

int main()
{
    double num1, num2;
    cout<<"To check the greater number between two numbers,\nEnter first number: ";
    cin>>num1;
    cout<<"Enter second number: ";
    cin>>num2;
    if(num1 > num2)
        cout<<num1<<" is greater."<<endl;
    else
        cout<<num2<<" is greater."<<endl;
    return 0;
}