#include<iostream>
using namespace std;

/*
A15.1 Define a class Complex and provide a unary friend operator- to negate
the real and imaginary part of a complex number.
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
            if(imaginary >= 0)
                cout<<real<<"+"<<imaginary<<"i"<<endl;
            else
                cout<<real<<imaginary<<"i"<<endl;
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
        friend Complex operator-(Complex&);


};
Complex operator-(Complex &c)
{
    Complex temp;
    temp.real = -c.real;
    temp.imaginary = -c.imaginary;
    return temp;
}
int main()
{
    Complex c1, c2;
    c1.setComplexNumber(5, 6);
    c2 = -c1;
    c1.printComplexNumber();
    c2.printComplexNumber();
    return 0;
}
