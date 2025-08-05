#include<iostream>
using namespace std;

/*
A18.2 Define a class Circle with radius as private instance variable and
setRadius(), getRadius(), getArea() as public instance methods. Define a
class ThickCircle as a subclass of Circle with thickness as private
instance variable and getThickness(), setThickness() as public instance
methods. Provide an overridden method getArea() to calculate area of thick
portion of circle.

(Completed)
*/
class Circle
{
    private:
        float radius;
    public:
        void setRadius(float radius) { this->radius = radius; }
        float getRadius() { return radius; }
        virtual double getArea() {return 3.14 * radius * radius; }
};
class ThickCircle: public Circle
{
    private:
        float thickness;
    public:
        float getThickness() { return thickness; }
        void setThickness(float thickness) { this->thickness = thickness; }
        double getArea() { return 3.14 * (getRadius() + thickness) * (getRadius() + thickness) - Circle::getArea(); }
};

int main()
{
    
    ThickCircle tc;
    tc.setRadius(4);
    tc.setThickness(2);
    Circle *p = &tc;
    cout<<"Area of thick portion of circle is "<<p->getArea();
    return 0;
}