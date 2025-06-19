/*A31.1 Write a function to find the
greatest number from the given array
of any size. (TSRS)
(Completed)
*/
int greatestInArray(int arr[], int size)
{
    int greatest = arr[0], i;
    for(i=1;i<size;i++)
        if(arr[i] > greatest)
            greatest = arr[i];
    return greatest;       
}
