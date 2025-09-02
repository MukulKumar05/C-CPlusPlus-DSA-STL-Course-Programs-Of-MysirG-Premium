#include<iostream>
using namespace std;

/*
A1.2 In question 1, define a parameterised constructor to create an array
of specified size.

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
};

int main()
{
    Array arr(20);
    return 0;
}