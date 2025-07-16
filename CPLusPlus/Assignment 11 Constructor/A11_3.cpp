#include<iostream>
using namespace std;

/*
A11.3 Define a class Date with d, m, y as instance variables. Initialise 
members using initialisers.
(Completed)
*/
class Date
{
    private:
        int d, m, y;
    public:
        Date(int d, int m, int y) : d(d), m(m), y(y)
        {}
        void showDate()
        {
            cout<<"d: "<<d<<", m: "<<m<<", y: "<<y<<endl;
        }
};


int main()
{
    Date d1(1, 7, 2025);
    d1.showDate();
    return 0;
}