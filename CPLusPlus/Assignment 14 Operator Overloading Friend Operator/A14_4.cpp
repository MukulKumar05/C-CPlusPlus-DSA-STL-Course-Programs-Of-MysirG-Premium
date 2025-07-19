#include<iostream>
using namespace std;

/*
A14.4 Consider the following class Array
class Array
{
    int *p;
    int size;
    public:
        //methods
};
Define operator= to perform deep copy of Array objects.
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
            p = new int[size];
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
            delete []p;
        }
        Array& operator=(Array &a)
        {
            size = a.size;
            delete []p;
            p = new int[size];
            int i;
            for(i = 0; i < size; i++)
            {
                p[i] = a.p[i];
            }
            return *this;
        }
};


int main()
{
    Array a1(10), a2(5), a3(8);
    int arr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int arr2[5] = {11, 22, 33, 44, 55};
    a1.setArrayValues(arr);
    a2.setArrayValues(arr2);
    a3 = a2 = a1;
    a1.displayArray();
    a2.displayArray();
    a3.displayArray();
    return 0;
}