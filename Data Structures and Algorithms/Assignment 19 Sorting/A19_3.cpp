#include<iostream>
using namespace std;

/*
A19.3 Define a function to implement insertion sort.

Problem Summary: Define insertionSort(int arr[], int size)
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
void modifiedBubbleSort(int arr[], int size)
{
    int round, i, swapStatus = 0;
    for(round = 1; round < size; round++)
    {
        for(i = 0; i < size - round; i++)
        {
            if(arr[i] > arr[i + 1])
            {
                swapNumbers(&arr[i], &arr[i + 1]);
                swapStatus = 1;
            }
        }
        if(swapStatus == 0)
            break;
    }
}
void insertionSort(int arr[], int size)
{
    int i, j;
    for(i = 1; i < size; i++)
    {
        for(j = i; j > 0; j--)
        {
            if(arr[j] < arr[j - 1])
            {
                swapNumbers(&arr[j], &arr[j - 1]);
            }
            else
                break;
        }
    }
}

int main()
{
    int arr[10] = {52, 78, 16, 39, 84, 91, 26, 31, 15, 43};
    insertionSort(arr, 10);
    displayArray(arr, 10);
    cout<<endl;
    return 0;
}