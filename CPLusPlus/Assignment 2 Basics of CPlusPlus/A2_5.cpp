/*
A2.5 Write a C++ program to calculate the volume of a cuboid.
(Completed)
*/

#include<iostream>

using namespace std;

int main()
{
    float length, breadth, height;
    cout<<"Enter length, breadth and height of cuboid: ";
    cin>>length>>breadth>>height;
    cout<<"Volume of cuboid is "<<length * breadth * height<<endl;
    return 0;
}