#include<iostream>
using namespace std;

/*
A1.4 In question 1, define a method to append a new element in the array.

(Completed)
*/
class Array
{
    private:
        int capacity, lastIndex;
        int *ptr;
    public:
        Array(int size)
        {
            ptr = new int[size];
            capacity = size;
            lastIndex = -1;
        }
        ~Array()
        {
            delete []ptr;
        }
        bool isArrayEmpty()
        {
            if(lastIndex == -1)
                return true;
            return false;
        }
        void displayArrayElements()
        {
            int i;
            for(i = 0; i <= lastIndex; i++)
                cout<<ptr[i]<<" ";
        }
        void append(int value)
        {
            if(lastIndex == capacity - 1)
                cout<<"Array is already full. Cannot append new element in array"<<endl;
            else
            {
                lastIndex++;
                ptr[lastIndex] = value;
            }
        }
};

int main()
{
    Array arr(20);
    arr.append(5);
    if(arr.isArrayEmpty())
        cout<<"Array arr is empty"<<endl;
    else
        cout<<"Array arr is not empty"<<endl;
    arr.append(13);
    arr.displayArrayElements();
    return 0;
}