/*A31.5 Write a function to find the
first occurence of adjacent duplicate
values in the array. Function has
to return the value of the element. 
(Completed)
*/
int firstOccuredAdjacentDuplicateValue(int arr[], int size)
{
    int i;
    for(i=0; i<size-1;i++)
        if(arr[i] == arr[i+1])
            return arr[i];
    return -1;       
}