#include<iostream>
using namespace std;

/*
A10.1 Define a class Cuboid with length, breadth and height as instance
member variables. Define constructors to initialize member variables.
(Completed)
*/
class Cuboid
{
    private:
        int length, breadth, height;
    public:
        Cuboid(int l, int b, int h)
        {
            length = l;
            breadth = b;
            height = h;
        }
        void showCuboidDimensions()
        {
            cout<<"Length = "<<length<<", Breadth = "<<breadth<<", Height = "<<height<<endl;
        }
};

int main()
{
    Cuboid c1(13, 24, 55);
    c1.showCuboidDimensions();
    return 0;
}
