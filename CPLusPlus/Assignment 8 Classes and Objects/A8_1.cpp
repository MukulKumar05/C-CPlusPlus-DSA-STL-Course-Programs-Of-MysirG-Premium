#include<iostream>
using namespace std;

/*
A8.1 Define a class Complex to represent a complex number. Declare instance
member variables to store real and imaginary part of a complex number, also
define instance member functions to set values of complex number and print
values of complex number.
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
            cout<<"Real part: "<<real<<endl;
            cout<<"Imaginary part: "<<imaginary;
        }
};

int main()
{
    Complex c1;
    c1.setComplexNumber(5, 15);
    c1.printComplexNumber();
    return 0;
}
