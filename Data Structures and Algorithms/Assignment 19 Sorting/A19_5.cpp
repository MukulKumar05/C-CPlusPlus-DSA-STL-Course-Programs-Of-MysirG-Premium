#include<iostream>
using namespace std;

/*
A19.5 Define a function to implement quick sort using recursion.

Problem Summary: Define quickSort() using recursion
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
int partition(int A[], int left, int right)
{
    int loc = left;
    while(left < right)
    {
        while(left < right && A[loc] <= A[right])
        {
            right--;
        }
        if(left < right && A[loc] > A[right])
        {
            swapNumbers(&A[loc], &A[right]);
            loc = right;
        }
        while(left < right && A[left] <= A[loc])
        {
            left++;
        }
        if(left < right && A[left] > A[loc])
        {
            swapNumbers(&A[left], &A[loc]);
            loc = left;
        }
    }
    return loc;
}
void quick(int arr[], int low, int high)
{
    if(low < high)
    {
        int partioningIndex = partition(arr, low, high);
        quick(arr, low, partioningIndex - 1);
        quick(arr, partioningIndex + 1, high);
    }
}
void quickSort(int arr[], int size)
{
    quick(arr, 0, size - 1);
}

int main()
{
    int arr[9] = {58, 62, 91, 43, 29, 37, 88, 72, 16};
    quickSort(arr, 9);
    displayArray(arr, 9);
    cout<<endl;
    return 0;
}