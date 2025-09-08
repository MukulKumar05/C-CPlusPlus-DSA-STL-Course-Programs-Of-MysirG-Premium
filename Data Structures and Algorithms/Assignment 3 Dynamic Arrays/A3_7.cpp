#include<iostream>
using namespace std;

/*
A3.7 In question 1, define a method to append a new element in the
array.

(Completed)
*/
class DynArray
{
    private:
        int capacity;
        int lastIndex;
        int *ptr;
    protected:
        void doubleArray();
        void halfArray();
    public:
        DynArray(int);
        ~DynArray();
        int currentCapacity();
        bool isEmpty();
        bool isFull();
        void append(int);
        void displayArrayElements();
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
void DynArray::doubleArray()
{
    capacity *= 2;
    int* newPtr = new int[capacity];
    int i;
    for(i = 0; i <= lastIndex; i++)
        newPtr[i] = ptr[i];
    delete []ptr;
    ptr = newPtr;
}
void DynArray::halfArray()
{
    capacity /= 2;
    int* newPtr = new int[capacity];
    int i;
    for(i = 0; i <= lastIndex; i++)
        newPtr[i] = ptr[i];
    delete []ptr;
    ptr = newPtr;
}
int DynArray::currentCapacity() { return capacity; }
bool DynArray::isEmpty()
{
    return lastIndex==-1;
}
bool DynArray::isFull()
{
    return capacity-1==lastIndex;
}
void DynArray::append(int data)
{
    if(isFull())
    {
        doubleArray();
    }
    ptr[lastIndex+1]=data;
    lastIndex++;
}
void DynArray::displayArrayElements()
{
    int i;
    for(i = 0; i <= lastIndex; i++)
        cout<<ptr[i]<<" ";
    cout<<endl;
}

int main()
{
    DynArray arr1(5);
    for(int i = 1; i <= 5; i++)
    {
        arr1.append(i);
    }
    arr1.append(10);

    cout<<"Current capacity of the array is "<<arr1.currentCapacity()<<endl;
    if(arr1.isFull())
        cout<<"Array is full"<<endl;
    else
        cout<<"Array is not full"<<endl;
    arr1.displayArrayElements();
    return 0;
}
