#include<iostream>
using namespace std;

/*
A16.2 Define a class Complex with instance variables a and b to store
real and imaginary part of a complex number. Provide setData() method
with formal arguments with the name a and b, to set the values of
instance variables. Also define showData() method to display instance
member variable values.
(Completed)
*/
class Complex
{
    private:
        int a, b;
    public:
        void setData(int a, int b)
        {
            this->a = a;
            this->b = b;
        }
        void showData()
        {
            if(b >= 0)
                cout<<a<<"+"<<b<<"i"<<endl;
            else
                cout<<a<<b<<"i"<<endl;
        }
        friend Complex operator+(Complex, Complex);
        friend Complex operator-(Complex, Complex);
        friend Complex operator*(Complex, Complex);
        
        bool operator==(Complex c)
        {
            if(a == c.a && b == c.b)
                return true;
            return false;
        }
        friend Complex operator-(Complex&);


};
int main()
{
    
    return 0;
}