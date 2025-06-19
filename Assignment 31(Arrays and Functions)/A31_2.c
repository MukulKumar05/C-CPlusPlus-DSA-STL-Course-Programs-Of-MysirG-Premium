/*A31.2 Write a function to find the
smallest number from the given array
of any size. (TSRS)
(Completed)
*/
int smallestInArray(int arr[], int size)
{
    int smallest = arr[0], i;
    for(i=1;i<size;i++)
        if(arr[i] < smallest)
            smallest = arr[i];
    return smallest;       
}