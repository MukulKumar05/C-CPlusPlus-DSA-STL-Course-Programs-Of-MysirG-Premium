/*
A3.5 Write a C++ program to add all the numbers of an array of size 10.
(Completed)
*/

#include<iostream>
using namespace std;

int main()
{
    int arr[10], i, sum;
    cout << "Enter values of array:" << endl; 
    for(i=0;i<10;i++)
        cin>>arr[i];
    for(i=0,sum=0;i<10;i++)
        sum += arr[i];
    cout<<"Sum of array elements is "<< sum;       
    return 0;
}