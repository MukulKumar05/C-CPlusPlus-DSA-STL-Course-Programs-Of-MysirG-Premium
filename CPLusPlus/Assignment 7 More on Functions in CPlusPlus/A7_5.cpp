#include<iostream>
#include<stdlib.h>
using namespace std;

/*
7.5 Define a function to merge two sorted arrays of same size.
(Completed)
*/
int* mergeTwoArrays(int a1[], int a2[], int size)
{
    int i, j;
    int *mergedArr = (int *)calloc(size * 2, sizeof(int));
    for(i = 0; i < size; i++)
        mergedArr[i] = a1[i];
    for(i = 0; i < size; i++)
        mergedArr[i+size] = a2[i];
    return mergedArr;
}
void printArray(int arr[], int size)
{
    int i;
    for(i = 0; i < size; i++)
        cout<<arr[i]<<" ";
}


int main()
{
    int arr1[6] = {2, 4, 6, 8, 10, 12}, arr2[6] = {11, 22, 33, 44, 55, 66};
    int *mergedArr = NULL;
    mergedArr = mergeTwoArrays(arr1, arr2, 6);
    cout<<"Merged Array is:"<<endl;
    printArray(mergedArr, 12);
    free(mergedArr);
    cout<<endl;
    return 0;
}