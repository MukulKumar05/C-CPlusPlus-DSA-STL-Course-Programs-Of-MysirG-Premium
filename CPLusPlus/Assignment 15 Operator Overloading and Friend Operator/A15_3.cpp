#include<iostream>
using namespace std;

/*
A15.3 Create a Coordinate class with 2 instance variables x and y. Overload
comma operator such that when you write c3 = (c1, c2) then c2 is assigned to
c3. Where c1, c2 and c3 are objects of Coordinate class.
(Completed)
*/
class Coordinate
{
    private:
        int x, y;
    public:
        void setCoordinate(int x, int y)
        {
            this->x = x;
            this->y = y;
        }
        void displayCoordinate()
        {
            cout<<"x="<<x<<" y="<<y<<endl;      
        }
        friend Coordinate operator,(Coordinate, Coordinate);

};
Coordinate operator,(Coordinate c1, Coordinate c2)
{
    return c2;
}

int main()
{
    Coordinate c1, c2, c3;
    c1.setCoordinate(2, 3);
    c2.setCoordinate(5, 6);
    // c1.displayCoordinate();
    // c2.displayCoordinate();
    c3 = (c1, c2);
    c3.displayCoordinate();
    return 0;
}