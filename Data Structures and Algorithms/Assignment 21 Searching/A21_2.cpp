#include<iostream>
using namespace std;

/*
A21.2 Define a method implementing binary search.

Problem Summary:
Define binarySearch(int itemToSearch, int arr[], int size)
(Completed)
*/
int binarySearchAlgo(int itemToSearch, int arr[], int low, int high)
{
    if(low > high)
        return -1;
    int mid = (low + high) / 2;
    if(arr[mid] == itemToSearch)
        return mid;
    else if(itemToSearch < arr[mid])
        return binarySearchAlgo(itemToSearch, arr, low, mid - 1);
    else if(itemToSearch > arr[mid])
        return binarySearchAlgo(itemToSearch, arr, mid + 1, high);
}
int binarySearch(int itemToSearch, int arr[], int size)
{
    return binarySearchAlgo(itemToSearch, arr, 0, size - 1);
}

int main()
{
    int arr[10] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
    int item = 36;
    int searchResult = binarySearch(item, arr, 10);
    if(searchResult != -1)
    {
        cout<<item<<" found at index "<<searchResult<<endl;
    }
    else
    {
        cout<<item<<" not found in array."<<endl;
    }
    return 0;
}