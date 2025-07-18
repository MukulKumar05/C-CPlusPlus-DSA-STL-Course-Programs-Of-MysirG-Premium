#include<iostream>
#include<stdlib.h>
using namespace std;
/*
A13.5 Consider the following class Array
class Array
{
int *p;
int size;
public:
    //methods
};
Define constructor to allocate an array of given size (size is given 
through parameter). Define a subscript operator to access element at given
index. Define destructor to deallocate the memory of array.
(Completed) 
*/
class Array
{
    private:
        int *p;
        int size;
    public:
        Array(int size) : size(size)
        {
            p = (int *)calloc(size, sizeof(int));
            int i;
            for(i = 0; i < size; i++)
            {
                p[i] = 0;
            }
        }
        void setArrayValues(int arr[])
        {
            int i;
            for(i = 0; i < size; i++)
            {
                p[i] = arr[i];
            }
        }
        void displayArray()
        {
            int i;
            for(i = 0; i < size; i++)
            {
                cout<<p[i]<<" ";
            }
            cout<<endl;
        }
        int& operator[](int index)
        {
            return *(p + index);
        }
        ~Array()
        {
            free(p);
        }
};



int main()
{
    Array a1(5);
    int arr[5] = {10, 20, 30, 40, 50};
    a1.setArrayValues(arr);
    // a1.displayArray();
    a1[4] = 55;
    a1[1] = 22;
    a1.displayArray();
    // cout<<a1[1];
    // cout<<a1[4];
    return 0;
}