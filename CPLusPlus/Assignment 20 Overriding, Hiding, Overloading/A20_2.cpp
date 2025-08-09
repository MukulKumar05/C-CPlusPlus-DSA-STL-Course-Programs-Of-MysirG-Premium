#include<iostream>
#include<string.h>
using namespace std;

/*
A20.2 Define a class Shape with member variable to store name of the
shape (like rectangle, square, circle, etc.). Provide methods to set
and display name of the shape. Define a pure virtual function area()
in Shape class. Define two derived classes of Shape, one is rectangle
and second is square. Define appropriate members in both the classes.
Demonstrate usage of the classes by making driver function main().
(Completed)
*/
class Shape
{
    private:
        char name[50];
    protected:
        void setShapeName(const char* name) { strcpy(this->name, name); }
    public:
        void displayShapeName() { cout<<name; }
        virtual double area() = 0;
};
class Rectangle: public Shape
{
    private:
        float length, breadth;
    public:
        Rectangle() { setShapeName("Rectangle"); }
        void setLengthAndBreadth(float length, float breadth) { this->length = length; this->breadth = breadth; }
        float getLength() { return length; }
        float getBreadth() { return breadth; }
        double area() { return length * breadth; }
};
class Square: public Shape
{
    private:
        float side;
    public:
        Square() { setShapeName("Square"); }
        void setSide(float side) { this->side = side; }
        float getside() { return side; }
        double area() { return side * side; }
};

int main()
{
    Rectangle r1;
    r1.setLengthAndBreadth(5, 3);
    cout<<"Area of ";
    r1.displayShapeName();
    cout<<" r1 with length = "<<r1.getLength()<<" and breadth = "<<r1.getBreadth()<<" is "<<r1.area()<<endl;
    Square s1;
    s1.setSide(5);
    cout<<"Area of ";
    s1.displayShapeName();
    cout<<" s1 with side = "<<s1.getside()<<" is "<<s1.area()<<endl;
    return 0;
}