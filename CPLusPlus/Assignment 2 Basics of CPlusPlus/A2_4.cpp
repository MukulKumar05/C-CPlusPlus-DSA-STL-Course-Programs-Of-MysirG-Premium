/*
A2.4 Write a C++ program to calculate the area of a circle.
(Completed)
*/

#include<iostream>

using namespace std;

int main()
{
    float radius;
    cout<<"Enter radius of circle: ";
    cin>>radius;
    cout<<"Area of circle is "<<3.14 * radius * radius<<endl;
    return 0;
}