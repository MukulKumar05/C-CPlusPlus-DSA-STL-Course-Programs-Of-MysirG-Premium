#include<iostream>
using namespace std;

/*
A15.4 In Question-3, provide overloaded insertion and extraction operators.
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
        friend ostream& operator<<(ostream&, Coordinate);
        friend istream& operator>>(istream&, Coordinate &);

};
Coordinate operator,(Coordinate c1, Coordinate c2)
{
    return c2;
}
ostream& operator<<(ostream &dout, Coordinate c)
{
    dout<<"x="<<c.x<<" y="<<c.y<<endl;
    return dout;
}
istream& operator>>(istream &din, Coordinate &c)
{
    din>>c.x>>c.y;
    return din;
}

int main()
{
    Coordinate c1, c2, c3;
    // c1.setCoordinate(2, 3);
    cout<<"Enter values of coordinate: ";
    cin>>c2;
    // c2.setCoordinate(5, 6);
    cout<<c2;
    // c1.displayCoordinate();
    // c2.displayCoordinate();
    // c3 = (c1, c2);
    // c3.displayCoordinate();
    return 0;
}