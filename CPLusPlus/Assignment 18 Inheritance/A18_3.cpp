#include<iostream>
#include<math.h>
using namespace std;

/*
A18.3 Define a class Coordinate with x and y as instance variables. Define
overloaded versions of getDistance(), first with no argument calculating
distance from origin, and second with one argument of Coordinate type to 
calculate distance between two coordinates. Also define other methods if
required.
(Completed)
*/
double squareOf(double num)
{
    return num * num;
}
class Coordinate
{
    private:
        float x, y;
    public:
        void setCoordinate(double x, double y)
        {
            this->x = x;
            this->y = y;
        }
        double getDistance()
        {
            return sqrt(x * x + y * y);
        }
        double getDistance(Coordinate P)
        {
            return sqrt(squareOf(x - P.x) + squareOf(y - P.y));
        }
};


int main()
{
    Coordinate c1, c2;
    c1.setCoordinate(3, 2);
    c2.setCoordinate(9, 7);
    cout<<"Distance between points c1 and c2 is "<<c1.getDistance(c2)<<endl;
    cout<<"Distance of point c2 from origin is "<<c2.getDistance()<<endl;
    return 0;
}