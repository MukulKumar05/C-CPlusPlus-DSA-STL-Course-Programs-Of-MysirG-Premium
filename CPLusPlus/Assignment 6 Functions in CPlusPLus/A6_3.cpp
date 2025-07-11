#include<iostream>
using namespace std;

/*
A6.3 Define a function to rotate an array by n positions in the d direction.
Implement position and direction using default arguments. Argument d can
be -1 or 1 denoting left or right direction. Argument n should be the last
argument with default value 1.
(Completed)
*/
void rotateArraybyNPositionsInDirectionD(int arr[], int size, int d = 1, int n = 1)
{
    int temp, i;
    if(n < 0)
        cout<<"Error! Incorrect value of position passed!"<<endl;
    else if(d == -1)
        while(n)
        {
            temp = arr[0];
            for(i=1; i<size; i++)
                arr[i-1] = arr[i];
            arr[size-1] = temp;
            n--;  
        }
    else if(d == 1) 
        while(n) 
        {
            temp = arr[size-1];
            for(i=size-2; i>=0; i--)
                arr[i+1]=arr[i];
            arr[0] = temp;
            n--;
        } 
    else
        cout<<"Error! Incorrect value of direction passed!"<<endl;
}

int main()
{
    int i, arr[] = {32, 29, 40, 12, 70};
    rotateArraybyNPositionsInDirectionD(arr, 5);
    cout<<"Array after rotation is"<<endl;
    for(i = 0; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}