#include<iostream>
using namespace std;

/*
7.4 Define a function to swap two arrays.
(Completed)
*/
void swapTwoArrays(int *arr1, int *arr2, int size)
{  
    int i, temp[6] = {0};
    for(i = 0; i < size; i++)
    {
        temp[i] = arr1[i];
    }
    for(i = 0; i < size; i++)
    {
        arr1[i] = arr2[i];
    }
    for(i = 0; i < size; i++)
    {
        arr2[i] = temp[i];
    }
}
void printArray(int arr[], int size)
{
    int i;
    for(i = 0; i < size; i++)
        cout<<arr[i]<<" ";
}

int main()
{
    int a1[6] = {2, 4, 6, 8, 10, 12}, a2[6] = {11, 22, 33, 44, 55, 66};
    cout<<"Arrays before swapping are: "<<endl;
    cout<<"Array 1:"<<endl;
    printArray(a1, 6);
    cout<<endl<<"Array 2:"<<endl;
    printArray(a2, 6);
    swapTwoArrays(a1, a2, 6);
    cout<<endl<<"Arrays after swapping are: "<<endl;
    cout<<"Array 1:"<<endl;
    printArray(a1, 6);
    cout<<endl<<"Array 2:"<<endl;
    printArray(a2, 6);
    cout<<endl;
    return 0;
}