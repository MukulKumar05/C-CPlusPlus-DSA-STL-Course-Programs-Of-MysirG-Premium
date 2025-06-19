/*A31.3 Write a function to sort 
an array of any size. (TSRN)
(Completed)
*/
void sortArray(int arr[], int size)
{
   int i,j;
   for(i=0;i<size-1;i++)
        for(j=i+1;j<size;j++)
            if(arr[j]<arr[i])
            {
                arr[j]=arr[j]+arr[i];
                arr[i]=arr[j]-arr[i];
                arr[j]=arr[j]-arr[i];
            }
}