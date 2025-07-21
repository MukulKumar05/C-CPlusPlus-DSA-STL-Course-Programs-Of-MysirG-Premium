#include<iostream>
using namespace std;

/*
A16.3 In question-2, write a non-member function in which instantiate
Complex class dynamically. Initialise instance variables and display
their values.
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
        friend Complex* generateDynamicComplexNumber(int, int);


};
Complex* generateDynamicComplexNumber(int a, int b)
{
    Complex *c = new Complex;
    c->a = a;
    c->b = b;
    return c;
}
int main()
{
    Complex *cmp = generateDynamicComplexNumber(5, 6);
    cmp->showData();
    delete cmp;
    return 0;
}