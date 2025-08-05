#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;

/*
A18.5 In question 3 & 4, derive a class StraightLine from Shape with two
Coordinate type objects as instance members. Provide methods to setLine(),
getDistance() and showLine().
(Completed)
*/
double squareOf(double num) {  return num * num;  }
class Coordinate
{
    private:
        float x, y;
    public:
        void setCoordinate(double x, double y) { this->x = x;  this->y = y; }
        double getDistance() {  return sqrt(x * x + y * y); }
        double getDistance(Coordinate P) { return sqrt(squareOf(x - P.x) + squareOf(y - P.y));  }
        float getX() { return x; }
        float getY() { return y; }
};
class Shape
{
    private:
        char shapeName[50];
    public:
        void setShapeName(const char shapeName[]) { strcpy(this->shapeName, shapeName); }
        char* getshapeName() { return shapeName; }
};
class StraightLine: public Shape
{
    private:
        Coordinate p1, p2;
    public:
        void setLine(Coordinate p1, Coordinate p2)
        {
            this->p1 = p1;
            this->p2 = p2;
        }
        double getDistance()
        {
            return p1.getDistance(p2);
        }
        void showLine()
        {
            float xCofficient, yCofficient, constantNum;
            xCofficient = p2.getY() - p1.getY();
            yCofficient = p1.getX() - p2.getX();
            constantNum = p1.getY() * (p2.getX() - p1.getX()) + p1.getX() * (p1.getY() - p2.getY());
            if(yCofficient >= 0)
            {
                if(constantNum >= 0)
                    cout<<xCofficient<<"x+"<<yCofficient<<"y+"<<constantNum<<"=0"<<endl;
                else
                    cout<<xCofficient<<"x+"<<yCofficient<<"y"<<constantNum<<"=0"<<endl;
            }
            else
            {
                if(constantNum >= 0)
                    cout<<xCofficient<<"x"<<yCofficient<<"y+"<<constantNum<<"=0"<<endl;
                else
                    cout<<xCofficient<<"x"<<yCofficient<<"y"<<constantNum<<"=0"<<endl;
            } 
        }
};


int main()
{
    StraightLine l1;
    Coordinate c1, c2;
    c1.setCoordinate(-2, 3);
    c2.setCoordinate(3, 5);
    l1.setShapeName("Straight Line");
    l1.setLine(c1, c2);
    cout<<"Distance of line l1 is "<<l1.getDistance()<<endl;
    cout<<"Equation of line l1 is ";
    l1.showLine();
    cout<<endl;
    return 0;
}