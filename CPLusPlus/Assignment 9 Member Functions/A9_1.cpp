#include<iostream>
using namespace std;

/*
A9.1 Define a class Complex to represent a complex number with instance 
variables a and b to store real and imaginary parts. Also define 
following member functions-
i. void setData(int,int)
ii. void showData()
iii. Complex add(Complex)
iv. Complex subtract(Complex)
v. Complex multiply(Complex)
(Completed)
*/
class Complex
{
    private:
        int a,b;
    public:
        void setData(int r, int i)
        {
            a = r;
            b = i;
        }
        void showData()
        {
            cout<<"Real part: "<<a<<", Imaginary part: "<<b<<endl;
        }
        Complex add(Complex c)
        {
            Complex sum;
            sum.a = a + c.a;
            sum.b = b + c.b;
            return sum;
        }
        Complex subtract(Complex c)
        {
            Complex difference;
            difference.a = a - c.a;
            difference.b = b - c.b;
            return difference;
        }
        Complex multiply(Complex c)
        {
            Complex product;
            product.a = a * c.a - b * c.b;
            product.b = a * c.b + b * c.a;
            return product;
        }

};

int main()
{
    Complex c1, c2, complexSum, complexDifference, complexProduct;
    c1.setData(2, 3);
    c2.setData(5, 6);
    // c1.showData();
    // c2.showData();
    complexSum = c1.add(c2);
    complexDifference = c1.subtract(c2);
    complexProduct = c1.multiply(c2);
    // complexSum.showData();
    // complexDifference.showData();
    complexProduct.showData();
    return 0;
}
