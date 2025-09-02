#include<iostream>
using namespace std;

/*
A1.5 In question 1, define a method to insert a new element at specified
index.
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
        void insertAtIndex(int index, int value)
        {
            if(lastIndex == capacity - 1)
                cout<<"Array is already full. Cannot insert new element in array"<<endl;
            else if(index > lastIndex + 1)
            {
                cout<<"Currently the value of last filled index is "<<lastIndex<<". ";
                cout<<"So, Cannot insert new value at index "<<index<<" after index "<<lastIndex + 1<<endl;
            }
            else
            {
                lastIndex++;
                int i;
                for(i = lastIndex; i > index; i--)
                {
                    ptr[i] = ptr[i - 1];
                }
                ptr[index] = value;
            }
        }
};

int main()
{
    Array arr(20);
    arr.append(5);
    arr.append(13);
    arr.append(23);
    arr.append(21);
    arr.append(26);
    arr.append(24);
    arr.insertAtIndex(2, 40);
    arr.insertAtIndex(0, 50);
    arr.insertAtIndex(8, 60);
    arr.insertAtIndex(10, 70);
    arr.displayArrayElements();
    return 0;
}