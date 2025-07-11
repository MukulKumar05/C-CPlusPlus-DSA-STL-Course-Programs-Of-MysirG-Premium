#include<iostream>
using namespace std;

/*
A6.1 Define a C++ function to sort an array of integers in ascending or
descending order depending on bool type argument (true for ascending
and false for descending). Use default argument to implement it.
(Completed)
*/
void sortArray(int arr[], int size, bool sortOrder = true)
{
    int i,j;
    if(sortOrder == true)
    {
        for(i=0;i<size-1;i++)
            for(j=i+1;j<size;j++)
                if(arr[j]<arr[i])
                {
                    arr[j]=arr[j]+arr[i];
                    arr[i]=arr[j]-arr[i];
                    arr[j]=arr[j]-arr[i];
                }
    }
    else
    {
        for(i=0;i<size-1;i++)
            for(j=i+1;j<size;j++)
                if(arr[j]>arr[i])
                {
                    arr[j]=arr[j]+arr[i];
                    arr[i]=arr[j]-arr[i];
                    arr[j]=arr[j]-arr[i];
                }
    }
}


int main()
{
    int arr[10] = {67, 59, 19, 3, 100, 58, 49, 6, 2, 87}, i;
    sortArray(arr, 10);
    cout<<"Array after sorting is:"<<endl;
    for(i = 0; i < 10; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
