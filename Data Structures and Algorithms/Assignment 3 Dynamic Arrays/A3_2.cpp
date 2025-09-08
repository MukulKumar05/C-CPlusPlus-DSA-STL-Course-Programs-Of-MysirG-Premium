#include<iostream>
using namespace std;

/*
A3.2 In question 1, define a parameterised constructor to create an array
of specified size.

(Completed)
*/
class DynArray
{
    private:
        int capacity;
        int lastIndex;
        int *ptr;
    public:
        DynArray(int);
        ~DynArray();
};
DynArray::DynArray(int cap)
{
    if(cap<=0)
        cap=10;
    capacity=cap;
    lastIndex=-1;
    ptr=new int[capacity];
}
DynArray::~DynArray()
{
    delete []ptr;
}

int main()
{
    DynArray arr1(5);
    return 0;
}
