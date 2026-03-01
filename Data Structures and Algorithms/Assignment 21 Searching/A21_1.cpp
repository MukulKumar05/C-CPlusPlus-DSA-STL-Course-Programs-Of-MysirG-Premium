#include<iostream>
using namespace std;

/*
A21.1 Define a method implementing linear search.

Problem Summary:
Define linearSearch(int arr[], int size)
(Completed)
*/
int linearSearch(int itemToSearch, int arr[], int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        if(arr[i] == itemToSearch)
            return i;
    }
    return -1;
}

int main()
{
    int arr[10] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
    int item = 36;
    int searchResult = linearSearch(item, arr, 10);
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
