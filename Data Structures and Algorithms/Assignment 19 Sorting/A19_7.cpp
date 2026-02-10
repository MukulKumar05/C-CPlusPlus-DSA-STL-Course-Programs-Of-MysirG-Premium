#include<iostream>
using namespace std;

/*
A19.7 Define a function to implement merge sort using recursion.

Problem Summary: Define mergeSort(int arr[], int size) using recursion.
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
void merge(int arr[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
    int arr2[high - low + 1] = {0};
    while(i <= mid && j <= high)
    {
        if(arr[i] < arr[j])
        {
            arr2[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            arr2[k] = arr[j];
            k++;
            j++;
        }
    }
    while(i <= mid)
    {
        arr2[k] = arr[i];
        k++;
        i++;
    }
    while(j <= high)
    {
        arr2[k] = arr[j];
        k++;
        j++;
    }
    for(k = 0, i = low; i <= mid; i++, k++)
    {
        arr[i] = arr2[k];
    }
    for(j = mid + 1; j <= high; j++, k++)
    {
        arr[j] = arr2[k];
    }
}
void mergeSortAlgo(int arr[], int low, int high)
{
    if(low < high)
    {
        int mid = (low + high) / 2;
        mergeSortAlgo(arr, low, mid);
        mergeSortAlgo(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}
void mergeSort(int arr[], int size)
{
    mergeSortAlgo(arr, 0, size - 1);
}

int main()
{
    int arr[13] = {75, 29, 83, 42, 16, 90, 56, 34, 20, 71, 88, 92, 7};
    mergeSort(arr, 13);
    displayArray(arr, 13);
    cout<<endl;
    return 0;
}