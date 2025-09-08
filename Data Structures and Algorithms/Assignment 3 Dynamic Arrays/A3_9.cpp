#include<iostream>
using namespace std;
#define INVALID_INDEX 2

/*
A3.9 In question 1, define a method to edit an element at 
specified index.

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
        void insert(int,int);
        void edit(int, int);
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
        doubleArray();
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
void DynArray::insert(int index,int data)
{
    if(index<0 || index>lastIndex+1)
        throw INVALID_INDEX;
    if(isFull())
        doubleArray();
    int i;
    for(i=lastIndex;i>=index;i--)
        ptr[i+1]=ptr[i];
    ptr[index]=data;
    lastIndex++;
}
void DynArray::edit(int index, int data)
{
    if(index<0 || index>lastIndex)
        throw INVALID_INDEX;
    ptr[index]=data;
}

int main()
{
    DynArray arr1(5);
    arr1.append(1);
    for(int i = 2; i <= 4; i++)
    {
        arr1.insert(1, i);
    }
    arr1.insert(1, 5);
    arr1.insert(1, 10);
    try
    {
        arr1.edit(1, 15);
    }
    catch(int e)
    {
        cout<<"Invalid Index passed in edit function. Please pass valid index number."<<endl;
    }
    arr1.displayArrayElements();
    return 0;
}
