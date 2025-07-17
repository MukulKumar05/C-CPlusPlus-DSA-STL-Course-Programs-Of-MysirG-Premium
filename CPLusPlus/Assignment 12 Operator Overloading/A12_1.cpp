#include<iostream>
using namespace std;

/*
A12.1 Define a class Complex with appropriate instance variables and member
functions. Define following operators in the class:
1. +
2. -
3. *
4. ==
(Completed)
*/
class Complex
{
    private:
        int real, imaginary;
    public:
        void setComplexNumber(int r, int i)
        {
            real = r;
            imaginary = i;
        }
        void printComplexNumber()
        {
            cout<<real<<" + "<<imaginary<<"i"<<endl;
        }
        Complex operator+(Complex c)
        {
            Complex temp;
            temp.real = real + c.real;
            temp.imaginary = imaginary + c.imaginary;
            return temp;
        }
        Complex operator-(Complex c)
        {
            Complex temp;
            temp.real = real - c.real;
            temp.imaginary = imaginary - c.imaginary;
            return temp;
        }
        Complex operator*(Complex c)
        {
            Complex product;
            product.real = real * c.real - imaginary * c.imaginary;
            product.imaginary = real * c.imaginary + imaginary * c.real;
            return product;
        }
        bool operator==(Complex c)
        {
            if(real == c.real && imaginary == c.imaginary)
                return true;
            return false;
        }
};

int main()
{
    Complex c1, c2, c3;
    c1.setComplexNumber(2, 3);
    c2.setComplexNumber(2, 3);
    c1.printComplexNumber();
    c2.printComplexNumber();
    // c3 = c1 + c2;
    // c3 = c1 * c2;
    // c3.printComplexNumber();
    if(c1 == c2)
        cout<<"Complex numbers are same";
    else
        cout<<"Complex numbers are not same";

    return 0;
}
