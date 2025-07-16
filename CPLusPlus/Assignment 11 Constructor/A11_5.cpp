#include<iostream>
using namespace std;

/*
A11.5 Define Circle class with radius as instance variable. Define two
constructors in the class- non parameterised and parameterised.
(Completed)
*/
class Circle
{
    private:
        float radius;
    public:
        Circle()
        {
            radius = 0;
        }
        Circle(float radius) : radius(radius)
        {}
        void showRadius()
        {
            cout<<"Radius: "<<radius<<endl;
        }        
};



int main()
{
    Circle c1, c2(7);
    c1.showRadius();
    c2.showRadius();
    return 0;
}