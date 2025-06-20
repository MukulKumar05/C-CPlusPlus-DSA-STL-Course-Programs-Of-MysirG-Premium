#include<stdio.h>

/*A32.1 Write a function to swap two
elements of given array with 
specified indices. 
(Completed)
*/
void swapArrayElementsAtIndices(int arr[], int i1, int i2)
{
    arr[i1]=arr[i1]+arr[i2];
    arr[i2]=arr[i1]-arr[i2];
    arr[i1]=arr[i1]-arr[i2];
}

/*A32.2 Write a function to count
total number of duplicate elements
in an array. (Means elements that 
occurs 2 times in an array)
(Completed)
*/
int duplicateElementsCountInArray(int arr[], int size)
{
    int unique[100]={arr[0]}, i, ub=0, j, occurCount, duplicateCount=0;
    for(i=1;i<size;i++)
    {
        for(j=0;j<=ub;j++)
            if(arr[i]==unique[j])
                break;
        if(j>ub)        
            unique[++ub]=arr[i];
    }
    
    for(i=0;i<=ub;i++)
    {
        occurCount=0;
        for(j=0;j<size;j++)
            if(unique[i]==arr[j])
                occurCount++;
        if(occurCount==2)
            duplicateCount++;
    }
    return duplicateCount;
}

/*A32.3 Write a function to print
all unique elements in an array. 
(Completed)
*/
void printUniqueArrayElements(int arr[], int size)
{
    int unique[100]={arr[0]}, i, ub=0, j;
    for(i=1;i<size;i++)
    {
        for(j=0;j<=ub;j++)
            if(arr[i]==unique[j])
                break;
        if(j>ub)        
            unique[++ub]=arr[i];
    }
    for(i=0;i<=ub;i++)
        printf("%d ", unique[i]);
}

/* A32.4 Write a function to merge two arrays of the same size sorted in descending order.
(Completed)
*/
void printTwoArraysMergedInDescendingOrder(int a1[], int a2[], int size)
{
    int mergedArr[100] = {0}, mergedArrSize = size * 2, i, j;
    for(i = 0; i < size; i++)
        mergedArr[i] = a1[i];
    for(i = 0; i < size; i++)
        mergedArr[i+size] = a2[i];
    
    for(i = 0; i < mergedArrSize - 1; i++)
        for(j = i+1; j < mergedArrSize; j++)
            if(mergedArr[j] > mergedArr[i])
            {
                mergedArr[j] = mergedArr[j] + mergedArr[i];
                mergedArr[i] = mergedArr[j] - mergedArr[i];
                mergedArr[j] = mergedArr[j] - mergedArr[i];
            }
    
    printf("Merged Array sorted in descending order is:\n");
    for(i = 0; i < mergedArrSize; i++)
        printf("%d ", mergedArr[i]);
}

/* A32.5 Write a function to count the frequency of each element of an array.
(Completed)
*/
void printArrayElementsFrequency(int arr[], int size)
{
    int unique[100]={arr[0]}, i, ub=0, j, occurCount;
    for(i=1;i<size;i++)
    {
        for(j=0;j<=ub;j++)
            if(arr[i]==unique[j])
                break;
        if(j>ub)        
            unique[++ub]=arr[i];
    }
    
    for(i=0;i<=ub;i++)
    {
        occurCount=0;
        for(j=0;j<size;j++)
            if(unique[i]==arr[j])
                occurCount++;
        printf("\nFrequency of %d is %d.", unique[i], occurCount);
    }
}

int main()
{
    int arr[10], i;
    printf("Enter values of array: \n"); 
    for(i=0;i<10;i++)
        scanf("%d", &arr[i]);
    printArrayElementsFrequency(arr, 10);
    return 0;
}
