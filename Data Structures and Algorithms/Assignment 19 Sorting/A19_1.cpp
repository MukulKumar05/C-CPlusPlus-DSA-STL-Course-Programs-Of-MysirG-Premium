#include<iostream>
using namespace std;

/*
A19.1 Define a function to implement bubble sort.

Problem Summary: Define bubbleSort(int arr[], int size)
(Completed)
*/
void swapNumbers(int* num1, int* num2)
{
    *num1 = *num1 + *num2;
    *num2 = *num1 - *num2;
    *num1 = *num1 - *num2;
}
void displayArray(int arr[], int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
}
void bubbleSort(int arr[], int size)
{
    int round, i;
    for(round = 1; round < size; round++)
    {
        for(i = 0; i < size - round; i++)
        {
            if(arr[i] > arr[i + 1])
            {
                swapNumbers(&arr[i], &arr[i + 1]);
            }
        }
    }
}

int main()
{
    int arr[6] = {24, 58, 11, 67, 92, 43};
    bubbleSort(arr, 6);
    displayArray(arr, 6);
    cout<<endl;
    return 0;
}
