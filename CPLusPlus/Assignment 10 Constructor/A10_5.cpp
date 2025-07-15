#include<iostream>
#include<string.h>
using namespace std;

/*
A10.5 Define a class Complex with instance variables for real and imaginary
part of a complex number. Define only one parameterised constructor in the
class to initialise complex object. Also define showData method in the class
to display object data. Now create an array of Complex class with size 5
and display values of each object.
(Completed)
*/
class Complex
{
    private:
        int real, imaginary;
    public:
        Complex(int r, int i)
        {
            real = r;
            imaginary = i;
        }
        void showData()
        {
            cout<<"Real Part: "<<real<<", Imaginary Part: "<<imaginary<<endl;
        }
};



int main()
{
    Complex num[5] = {Complex(3, 4), Complex(5, 7), Complex(10, 12), Complex(11, 22), Complex(7, 19)};
    int i;
    for(i = 0; i < 5; i++)
    {
        cout<<"num ["<<i<<"]: ";
        num[i].showData();
    }
    return 0;
}