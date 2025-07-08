/*
A3.1 Write a C++ program to calculate an average of 3 numbers.
(Completed)
*/

#include<iostream>

using namespace std;

int main()
{
    float n1, n2, n3;
    cout<<"Enter 3 numbers: ";
    cin>>n1>>n2>>n3;
    cout<<"Average of these 3 numbers is "<<(n1 + n2 + n3) / 3<<endl;
    return 0;
}
