#include<iostream>
using namespace std;

/*
A1.3 In the question 1, add a method to check whether an array is empty or
not by returning True or False.

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
};

int main()
{
    Array arr(20);
    if(arr.isArrayEmpty())
        cout<<"Array arr is empty"<<endl;
    else
        cout<<"Array arr is not empty"<<endl;
    return 0;
}