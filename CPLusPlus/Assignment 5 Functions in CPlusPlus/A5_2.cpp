#include<iostream>
using namespace std;

/*
A5.2 Write a C++ function using the default argument that is able to add 2 or 3 numbers.
(Completed)
*/
double add(float n1, float n2, float n3 = 0)
{
    return n1 + n2 + n3;
}

int main()
{
    int a = 10, b = 5, c = 2;
    cout<<a<<" + "<<b<<" = "<<add(a, b)<<endl;
    cout<<a<<" + "<<b<<" + "<<c<<" = "<<add(a, b, c)<<endl;
    return 0;
}