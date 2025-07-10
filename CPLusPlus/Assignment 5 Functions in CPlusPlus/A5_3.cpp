#include<iostream>
#include<math.h>
using namespace std;

/*
A5.3 Define overloaded functions to calculate area of circle, area of rectangle
and area of triangle.
(Completed)
*/
double area(float radius)
{
    return 3.14 * radius * radius;
}

double area(float length, float breadth)
{
    return length * breadth;
}

double area(float side1, float side2, float side3)
{
    float semiPerimeter = (side1 + side2 + side3) / 2;
    return sqrt(semiPerimeter * (semiPerimeter - side1) * (semiPerimeter - side2) * (semiPerimeter - side3));
}


int main()
{
    float radius = 7, length = 7, breadth = 3, s1= 3, s2 = 3, s3 = 3;
    cout<<"Area of circle having radius "<<radius<<" is "<<area(radius)<<endl;
    cout<<"Area of rectangle having length = "<<length<<" and breadth = "<<breadth<<" is "<<area(length, breadth)<<endl;
    cout<<"Area of triangle having length of sides as "<<s1<<", "<<s2<<" and "<<s3<<" is "<<area(s1, s2, s3)<<endl;
    return 0;
}