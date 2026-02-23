#include<iostream>
using namespace std;
#define HEAP_UNDERFLOW -1
#define EMPTY_HEAP 0

/*
A20.10 Define a method to sort elements of an array using heap sort.

Problem Summary:
Define heapSort()
(Completed)
*/
class Heap
{
    private:
        int capacity;
        int arrLastIndex;
        int heapLastIndex;
        int *ptr;
    protected:
        void doubleArray();
        void halfArray();
    public:
        Heap(int);
        ~Heap();
        int currentCapacity();
        bool isArrayEmpty();
        bool isHeapEmpty();
        bool isArrayFull();
        void displayArrayElements();
        void displayHeapElements();
        void insert(int);
        void del();
        int max();
        Heap(Heap&);
        Heap& operator=(Heap&);
        void heapSort();
};
Heap::Heap(int cap)
{
    if(cap<=0)
        cap=10;
    capacity=cap;
    arrLastIndex=-1;
    heapLastIndex = -1;
    ptr=new int[capacity];
}
Heap::~Heap()
{
    delete []ptr;
}
int Heap::currentCapacity() { return capacity; }
bool Heap::isArrayEmpty()
{
    return arrLastIndex==-1;
}
bool Heap::isHeapEmpty()
{
    return heapLastIndex == -1;
}
bool Heap::isArrayFull()
{
    return capacity-1==arrLastIndex;
}
void Heap::doubleArray()
{
    capacity *= 2;
    int* newPtr = new int[capacity];
    int i;
    for(i = 0; i <= arrLastIndex; i++)
        newPtr[i] = ptr[i];
    delete []ptr;
    ptr = newPtr;
}
void Heap::halfArray()
{
    capacity /= 2;
    int* newPtr = new int[capacity];
    int i;
    for(i = 0; i <= arrLastIndex; i++)
        newPtr[i] = ptr[i];
    delete []ptr;
    ptr = newPtr;
}
void Heap::insert(int data)
{
    if(isArrayFull())
        doubleArray();
    if(isArrayEmpty()) // array is empty
    {
        ptr[0] = data;
        arrLastIndex++;
        heapLastIndex++;
    }
    else // array is not empty
    {
        if(heapLastIndex != arrLastIndex) // there are deleted elements of heap in array
        {
            for(int tempIndex = arrLastIndex + 1; tempIndex > heapLastIndex + 1; tempIndex--)
            {
                ptr[tempIndex] = ptr[tempIndex - 1];
            }
        }
        int index = heapLastIndex + 1;
        while(index)
        {
            if(ptr[(index - 1) / 2] >= data)
            {
                ptr[index] = data;
                break;
            }
            else
            {
                ptr[index] = ptr[(index - 1) / 2];
                index = (index - 1) / 2;
            }
        }
        if(index == 0)
        {
            ptr[index] = data;
        }
        heapLastIndex++;
        arrLastIndex++;
    }
}
void Heap::displayArrayElements()
{
    int i;
    for(i = 0; i <= arrLastIndex; i++)
        cout<<ptr[i]<<" ";
    cout<<endl;
}
void Heap::displayHeapElements()
{
    int i;
    for(i = 0; i <= heapLastIndex; i++)
        cout<<ptr[i]<<" ";
    cout<<endl;
}
int greaterNum(int num1, int num2)
{
    if(num1 > num2)
        return num1;
    return num2;
}
int indexOfGreaterNumberInArray(int arr[], int index1, int index2)
{
    if(arr[index1] > arr[index2])
        return index1;
    return index2;
}
void Heap::del()
{
    if(isHeapEmpty())
        throw HEAP_UNDERFLOW;
    int heapLastElement = ptr[heapLastIndex];
    int toBeDeletedElement = ptr[0];
    heapLastIndex--;
    int index = 0;
    while(index * 2 + 1 <= heapLastIndex)
    {
        if(index * 2 + 2 <= heapLastIndex) // index has both left and right child in heap
        {
            if(greaterNum(ptr[index * 2 + 1], ptr[index * 2 + 2]) <= heapLastElement)
            {
                ptr[index] = heapLastElement;
                break;
            }
            else
            {
                ptr[index] = greaterNum(ptr[index * 2 + 1], ptr[index * 2 + 2]);
                index = indexOfGreaterNumberInArray(ptr, index * 2 + 1, index * 2 + 2);
            }
        }
        else if(index * 2 + 1 <= heapLastIndex) // index element has only left child
        {
            if(ptr[index * 2 + 1] <= heapLastElement)
            {
                ptr[index] = heapLastElement;
                break;
            }
            else
            {
                ptr[index] = ptr[index * 2 + 1];
                index = index * 2 + 1;
            }
        }
    }
    if(index * 2 + 1 > heapLastIndex)
    {
        ptr[index] = heapLastElement;
    }
    ptr[heapLastIndex + 1] = toBeDeletedElement;
}
int Heap::max()
{
    if(isHeapEmpty())
        throw EMPTY_HEAP;
    return ptr[0];
}
Heap::Heap(Heap &a)
{
    capacity = a.capacity;
    arrLastIndex = a.arrLastIndex;
    heapLastIndex = a.heapLastIndex;
    ptr = new int[capacity];
    int i;
    for(i = 0; i <= arrLastIndex; i++)
        ptr[i] = a.ptr[i];
}
Heap& Heap::operator=(Heap &a)
{
    capacity = a.capacity;
    arrLastIndex = a.arrLastIndex;
    heapLastIndex = a.heapLastIndex;
    delete []ptr;
    ptr = new int[capacity];
    int i;
    for(i = 0; i <= arrLastIndex; i++)
        ptr[i] = a.ptr[i];
    return *this;
}
void Heap::heapSort()
{
    while(!isHeapEmpty())
    {
        del();
    }
}

int main()
{
    Heap h1(10);
    h1.insert(40);
    h1.insert(70);
    h1.insert(10);
    h1.insert(90);
    h1.insert(60);
    h1.insert(30);
    h1.insert(50);
    h1.insert(20);
    h1.insert(80);
    h1.heapSort();
    h1.displayArrayElements();
    return 0;
}