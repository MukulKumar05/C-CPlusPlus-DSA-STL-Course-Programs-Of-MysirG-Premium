#include<iostream>
using namespace std;

/*
A13.3 Consider a class Distance
class Distance
{
    int km, m, cm;
    public:
        //methods;
};
Overload the operator+ to add two distance objects.
(Completed)
*/
class Distance
{
    private:
        int km, m, cm;
    public:
        Distance(int km = 0, int m = 0, int cm = 0) : km(km), m(m), cm(cm) {}
        void showDistance()
        {
            cout<<km<<" km "<<m<<" m "<<cm<<" cm "<<endl;
        }
        Distance operator+(Distance d)
        {
            Distance sum;
            sum.km = km + d.km;
            sum.m = m + d.m;
            sum.cm = cm + d.cm;
            return sum;
        }
};


int main()
{
    Distance d1(2, 3, 4), d2(3, 4, 5), sum;
    sum = d1 + d2;
    sum.showDistance();
    return 0;
}