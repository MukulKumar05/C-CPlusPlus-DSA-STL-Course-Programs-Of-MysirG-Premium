#include<iostream>
using namespace std;

/*
7.2 Define overloaded functions to calculate volume of a cuboid, cone and 
sphere.
(Completed)
*/


double volume(double, double, double);
double volume(double, double);
double volume(double);



int main()
{
    float l = 3, b = 2, h = 10, r = 4;
    cout<<"Volume of cuboid is "<<volume(l, b, h)<<endl;
    cout<<"Volume of cone is "<<volume(h, r)<<endl;
    cout<<"Volume of sphere is "<<volume(r)<<endl;
    return 0;
}

double volume(double length, double breadth, double height)
{
    return length * breadth * height;
}
double volume(double height, double baseRadius)
{
    return 0.333333 * 3.14 * baseRadius * baseRadius * height;
}
double volume(double radius)
{
    return 1.333333 * 3.14 * radius * radius * radius;
}