#include<iostream>
#include<stdlib.h>
using namespace std;

/*
A11.1 Define a class Numbers with size and arr pointer as instance variables.
Provide constructor to initialise instance members, dynamically allocate an
array of given size and store address in arr variable of object. Also define
destructor to deallocate memory of array. Implement deep copy using copy 
constructor to avoid memory issues.
(Completed)
*/
class Numbers
{
    private:
        int size;
        int *arr = NULL;
    public:
        Numbers(int s, int* values)
        {
            size = s;
            arr = (int *)calloc(size, sizeof(int));
            int i;
            for(i = 0; i < size; i++)
            {
                arr[i] = values[i];
            }
        }
        Numbers(Numbers &N)
        {
            size = N.size;
            arr = (int *)calloc(size, sizeof(int));
            int i;
            for(i = 0; i < size; i++)
            {
                arr[i] = N.arr[i];
            }
        }
        ~Numbers()
        {
            free(arr);
        }
        void showNumbers()
        {
            int i;
            for(i = 0; i < size; i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }

};

int main()
{
    int arr[6] = {10, 20, 30, 40, 50, 60};
    int arr2[5] = {11, 22, 33, 44, 55};
    Numbers n1(6, arr);
    Numbers n2(5, arr2);
    Numbers n3 = n2;
    n1.showNumbers();
    n2.showNumbers();
    n3.showNumbers();
    return 0;
}
