#include<stdio.h>

/*A30.4 Write a program to sort 
an array of 10 elements in
descending order. 
(Completed)
*/
int main()
{
    int arr[10], i, j;
    printf("Enter values of array:\n"); 
    for(i=0;i<10;i++)
        scanf("%d", &arr[i]);
    for(i=0;i<9;i++)
        for(j=i+1;j<10;j++)
            if(arr[j]>arr[i])
            {
                arr[j]=arr[j]+arr[i];
                arr[i]=arr[j]-arr[i];
                arr[j]=arr[j]-arr[i];
            }
    printf("Array after sorting in descending order is:\n");
    for(i=0;i<10;i++)
        printf("%d ", arr[i]);
    return 0;
}