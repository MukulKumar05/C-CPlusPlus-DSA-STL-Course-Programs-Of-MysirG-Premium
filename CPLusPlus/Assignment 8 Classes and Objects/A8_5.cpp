#include<iostream>
using namespace std;

/*
A8.5 Define a class Circle with radius as its property. Provide setRadius()
and getRadius() methods. Also define methods to return area and
circumference of circle.
(Completed)
*/
class Circle
{
    private:
        float radius;
    public:
        void setRadius(float r)
        {
            radius = r;
        }
        float getRadius()
        {
            return radius;
        }
        double area()
        {
            return 3.14 * radius * radius;
        }
        double circumference()
        {
            return 2 * 3.14 * radius;
        }
};

int main()
{
    Circle c1;
    c1.setRadius(7);
    float circleRadius = c1.getRadius();
    cout<<"Area of circle with radius "<<circleRadius<<" is "<<c1.area()<<endl;
    cout<<"Circumference of circle with radius "<<circleRadius<<" is "<<c1.circumference()<<endl;
    return 0;
}