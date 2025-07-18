#include<iostream>
using namespace std;

/*
A13.4 In question-3, define operator pre decrement and post decrement to 
decrease distance by 1cm.
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

        // pre-decrement operator--
        Distance operator--()
        {
            --cm;
            return *this;
        }

        // post-decrement operator--
        Distance operator--(int)
        {
            Distance temp;
            temp = *this;
            cm--;
            return temp;
        }
};


int main()
{
    Distance d1(2, 3, 4), d2;
    // d1.showDistance();
    // d2.showDistance();
    d2 = d1--;
    // d1.showDistance();
    // d2.showDistance();
    d2 = --d1;
    d1.showDistance();
    d2.showDistance();

    return 0;
}