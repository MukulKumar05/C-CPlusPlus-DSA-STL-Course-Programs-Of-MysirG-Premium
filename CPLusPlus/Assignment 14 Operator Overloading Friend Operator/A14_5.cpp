#include<iostream>
using namespace std;

/*
A14.5 In question 4, define a friend operator+ to concatenate
two Array objects.
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
        friend Array* operator+(Array&, Array&);
};
Array* operator+(Array &a1, Array &a2)
{
    Array *temp = new Array(a1.size + a2.size);
    int i;
    for(i = 0; i < a1.size; i++)
    {
        temp->p[i] = a1.p[i];
    }
    for(i = 0; i < a2.size; i++)
    {
        temp->p[a1.size + i] = a2.p[i];
    }
    return temp;
}

int main()
{
    Array a1(6), a2(4), a3(8);
    int arr[6] = {10, 20, 30, 40, 50, 60};
    int arr2[4] = {11, 22, 33, 44};
    a1.setArrayValues(arr);
    a2.setArrayValues(arr2);
    Array *ptr = a1 + a2;
    a3 = *ptr;
    delete ptr;
    // a1.displayArray();
    // a2.displayArray();
    a3.displayArray();
    return 0;
}