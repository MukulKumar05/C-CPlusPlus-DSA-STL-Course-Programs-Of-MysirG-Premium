#include<iostream>
using namespace std;

/*
A19.4 Define a function to implement selection sort.

Problem Summary: Define selectionSort(int arr[], int size)
(Completed)
*/
void swapNumbers(int* num1, int* num2)
{
    int c;
    c = *num1;
    *num1 = *num2;
    *num2 = c;
}
void displayArray(int arr[], int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
}
int getSmallestElementIndexOfArrayFrom(int arr[], int startIndex, int endIndex)
{
    int smallest = arr[startIndex], i, smallestIndex = startIndex;
    for(i = startIndex; i <= endIndex; i++)
    {
        if(arr[i] < smallest)
        {
            smallest = arr[i];
            smallestIndex = i;
        }
    }
    return smallestIndex;
}
void selectionSort(int arr[], int size)
{
    int round, smallestIndex;
    for(round = 1; round < size; round++)
    {
        smallestIndex = getSmallestElementIndexOfArrayFrom(arr, round - 1, size - 1);
        swapNumbers(&arr[round - 1], &arr[smallestIndex]);
    }
}

int main()
{
    int arr[9] = {38, 90, 47, 69, 52, 88, 71, 18, 20};
    selectionSort(arr, 9);
    displayArray(arr, 9);
    cout<<endl;
    return 0;
}