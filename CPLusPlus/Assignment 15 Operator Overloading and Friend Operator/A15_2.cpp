#include<iostream>
using namespace std;

/*
A15.2 Define a class Integer with instance variable of type int. Provide
a friend logical operator not ! . Also define a friend operator == to
compare two Integer objects.
(Completed)
*/
class Integer
{
    private:
        int number;
    public:
        void setInteger(int number)
        {
            this->number = number;
        }
        void displayInteger()
        {
            cout<<number;
        }
        friend int operator!(Integer);
        friend int operator==(Integer, Integer);
};
int operator!(Integer i)
{
    if(i.number)
        return 0;
    return 1;
}
int operator==(Integer i1, Integer i2)
{
    if(i1.number == i2.number)
        return 1;
    return 0;
}

int main()
{
    Integer i1, i2;
    i1.setInteger(0);
    i2.setInteger(0);
    // i1.displayInteger();
    // cout<<!i1;
    if(i1 == i2)
        cout<<"i1 is equal to i2"<<endl;
    else
        cout<<"i1 is not equal to i2"<<endl;
    return 0;
}