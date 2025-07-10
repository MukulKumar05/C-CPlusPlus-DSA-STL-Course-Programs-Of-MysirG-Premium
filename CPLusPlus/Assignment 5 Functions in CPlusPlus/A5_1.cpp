#include<iostream>
using namespace std;

/*
A5.1 Define a C++ function to swap data of two int variables using call by reference.
(Completed)
*/
void swapNumbers(int &num1, int &num2)
{
    num1 = num1 + num2;
    num2 = num1 - num2;
    num1 = num1 - num2;
}


int main()
{
    int a, b;
    cout<<"Enter two numbers: ";
    cin>>a>>b;
    cout<<"Numbers before swapping are:- a = "<<a<<" and b = "<<b<<endl;
    swapNumbers(a, b);
    cout<<endl<<"Numbers after swapping are:- a = "<<a<<" and b = "<<b<<endl;
    return 0;
}
