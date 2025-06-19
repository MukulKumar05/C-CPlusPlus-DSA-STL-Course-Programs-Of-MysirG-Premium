/*A31.4 Write a function to rotate an
array by n position in d direction. 
The d is an indicative value for left
or right. (For example, if array of
size 5 is [32, 29, 40, 12, 70]; n is
2 and d is left, then the resulting
array after left rotation 2 times is
[40, 12, 70, 32, 29]) 
(Completed)
*/
void rotateArraybyNPositionsInDirectionD(int arr[], int size, int n, char d)
{
    int temp, i;
    if(n < 0)
        printf("Error! Incorrect value of position passed!\n");
    else if(d == 'l')
        while(n)
        {
            temp = arr[0];
            for(i=1; i<size; i++)
                arr[i-1] = arr[i];
            arr[size-1] = temp;
            n--;  
        }
    else if(d == 'r') 
        while(n) 
        {
            temp = arr[size-1];
            for(i=size-2; i>=0; i--)
                arr[i+1]=arr[i];
            arr[0] = temp;
            n--;
        } 
    else
        printf("Error! Incorrect value of direction passed!\n");
}