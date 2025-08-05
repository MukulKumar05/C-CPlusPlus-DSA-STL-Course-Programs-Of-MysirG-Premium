#include<iostream>
#include<string.h>
using namespace std;

/*
A18.4 Define a class Shape with shapeName as instance variable. Provide
setter and getter.
(Completed)
*/
class Shape
{
    private:
        char shapeName[50];
    public:
        void setShapeName(const char shapeName[]) { strcpy(this->shapeName, shapeName); }
        char* getshapeName() { return shapeName; }
};


int main()
{
    Shape s1;
    s1.setShapeName("Rectangle");
    cout<<"Name of shape is "<<s1.getshapeName()<<endl;
    return 0;
}