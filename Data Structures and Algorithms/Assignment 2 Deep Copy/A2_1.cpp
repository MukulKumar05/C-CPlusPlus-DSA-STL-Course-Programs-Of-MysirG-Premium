#include<iostream>
using namespace std;
#define ARRAY_OVERFLOW 1
#define INVALID_INDEX 2

/*
A2.1 Define a copy constructor in Array class to perform deep copy.

(Completed)
*/
class Array
{
    private:
        int capacity;
        int lastIndex;
        int *ptr;
    public:
        Array(int);
        bool isEmpty();
        bool isFull();
        void append(int);
        void insert(int,int);
        void edit(int,int);
        void del(int);
        int get(int);
        int count();
        int find(int);
        ~Array();
        Array(Array&);
        void displayArrayElements();
};
void Array::displayArrayElements()
{
    int i;
    for(i = 0; i <= lastIndex; i++)
        cout<<ptr[i]<<" ";
}
Array::Array(int cap){
    if(cap<=0)
        cap=10;
    capacity=cap;
    lastIndex=-1;
    ptr=new int[cap];
}
bool Array::isEmpty(){
    return lastIndex==-1;
}
bool Array::isFull(){
    return capacity-1==lastIndex;
}
void Array::append(int data){
    if(isFull())
        throw ARRAY_OVERFLOW;
    ptr[lastIndex+1]=data;
    lastIndex++;
}
void Array::insert(int index,int data){
    if(index<0 || index>lastIndex+1)
        throw INVALID_INDEX;
    if(isFull())
        throw ARRAY_OVERFLOW;
    int i;
    for(i=lastIndex;i>=index;i--)
    {
        ptr[i+1]=ptr[i];
    }
    ptr[index]=data;
    lastIndex++;
}
void Array::edit(int index, int data){
    if(index<0 || index>lastIndex)
        throw INVALID_INDEX;
    ptr[index]=data;
}
void Array::del(int index){
    if(index<0 || index>lastIndex)
        throw INVALID_INDEX;
    int i;
    for(i=index;i<lastIndex ; i++)
    {
        ptr[i]=ptr[i+1];
    }
    lastIndex--;
}

int Array::get(int index){
    if( index<0 || index>lastIndex)
        throw INVALID_INDEX;
    return ptr[index];
}
int Array::count(){
    return lastIndex+1;
}
Array::~Array(){
    delete []ptr;
}
int Array::find(int data){
    for(int i=0;i<=lastIndex;i++)
        if(ptr[i]==data)
            return i;
    return -1;
}
Array::Array(Array &a)
{
    capacity = a.capacity;
    lastIndex = a.lastIndex;
    ptr = new int[capacity];
    int i;
    for(i = 0; i <= lastIndex; i++)
        ptr[i] = a.ptr[i];
}
int main()
{
    Array arr1(10);
    arr1.append(10);
    arr1.append(20);
    arr1.append(30);
    arr1.append(40);
    Array arr2 = arr1;
    arr2.append(50);
    arr2.insert(1, 15);
    arr2.edit(0, 5);
    arr2.del(0);
    cout<<arr2.find(15)<<endl;
    arr2.displayArrayElements();
    return 0;
}
