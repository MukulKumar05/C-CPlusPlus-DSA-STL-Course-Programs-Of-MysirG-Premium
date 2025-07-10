#include<iostream>
using namespace std;

struct Complex
{
    int real, imaginary;
};

/*
A5.5 Write functions using function overloading to add two numbers having 
different data types.
(Completed)
*/
double sum(double num1, double num2)
{
    return num1 + num2;
}
double sum(double num, Complex c)
{
    return num + c.real;
}



int main()
{
    Complex c1;
    c1.real = 5;
    c1.imaginary = 3;
    int a = 3, b = 4;
    float c = 4.7;
    double d = 4.792;
    cout<<a<<" + "<<c<<" = "<<sum(a, c)<<endl;
    cout<<a<<" + "<<c1.real<<" = "<<sum(a, c1)<<endl;
    return 0;
}