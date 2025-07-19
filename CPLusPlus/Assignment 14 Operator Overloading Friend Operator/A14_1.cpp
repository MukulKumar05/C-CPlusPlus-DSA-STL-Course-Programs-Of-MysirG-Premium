#include<iostream>
using namespace std;

/*
A14.1 Define a class Complex and overload following operators as a
friend.
1. +
2. -
3. *
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
        friend Complex operator+(Complex, Complex);
        friend Complex operator-(Complex, Complex);
        friend Complex operator*(Complex, Complex);
        
        bool operator==(Complex c)
        {
            if(real == c.real && imaginary == c.imaginary)
                return true;
            return false;
        }
};
Complex operator+(Complex c1, Complex c2)
{
    Complex temp;
    temp.real = c1.real + c2.real;
    temp.imaginary = c1.imaginary + c2.imaginary;
    return temp;
}
Complex operator-(Complex c1, Complex c2)
{
    Complex temp;
    temp.real = c1.real - c2.real;
    temp.imaginary = c1.imaginary - c2.imaginary;
    return temp;
}
Complex operator*(Complex c1, Complex c2)
{
    Complex product;
    product.real = c1.real * c2.real - c1.imaginary * c2.imaginary;
    product.imaginary = c1.real * c2.imaginary + c1.imaginary * c2.real;
    return product;
}

int main()
{
    Complex c1, c2, c3;
    c1.setComplexNumber(5, 6);
    c2.setComplexNumber(2, 3);
    // c1.printComplexNumber();
    // c2.printComplexNumber();
    c3 = c1 * c2;
    c3.printComplexNumber();
    return 0;
}
