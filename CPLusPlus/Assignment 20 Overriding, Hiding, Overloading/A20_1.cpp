#include<iostream>
using namespace std;

/*
A20.1 Define a class A with two int type member variables. Define a member
function to setData() and showData() to set and display values of member
variables. Also define a member function with the name input() to take
input from the user. Define a class B with one int type member variable.
Override input() function in order to input three values from the user for
all three member variables. Also override showData() function to
display all three values. 
(Completed)
*/
class A
{
    private:
        int n1, n2;
    public:
        void setData(int n1, int n2) { this->n1 = n1; this->n2 = n2; }
        virtual void showData() { cout<<"n1 = "<<n1<<" n2 = "<<n2<<endl; }
        int& referenceOfn1() { return n1; }
        int& referenceOfn2() { return n2; }
        int getn1() { return n1; }
        int getn2() { return n2; }
        virtual void input()
        {
            cout<<"Enter values of n1 and n2: ";
            cin>>n1>>n2;
        }
};
class B: public A
{
    private:
        int n3;
    public:
        void setData(int n1, int n2, int n3) 
        { 
            int &x = referenceOfn1();
            int &y = referenceOfn2();
            x = n1; y = n2; this->n3 = n3; 
        }
        void input()
        {
            int &x = referenceOfn1();
            int &y = referenceOfn2();
            cout<<"Enter values of n1, n2 and n3: ";
            cin>>x>>y>>n3;
        }
        void showData() { cout<<"n1 = "<<getn1()<<" n2 = "<<getn2()<<" n3 = "<<n3<<endl; }
};

int main()
{
    B obj1;
    A *p = &obj1;
    p->input();
    p->showData();
    return 0;
}
