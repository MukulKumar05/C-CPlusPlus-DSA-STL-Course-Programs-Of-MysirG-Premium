#include<iostream>
using namespace std;

/*
A8.3 Define a class Date to represent date (like d=31, m=12, y=2022).
Declare appropriate number of instance member variables and also define
instance member functions to set date and get date.
(Completed)
*/
class Date
{
    private:
        int day, month, year;
    public:
        void setDate(int d, int m, int y)
        {
            day = d;
            month = m;
            year = y;
        }
        Date getDate()
        {
            Date d;
            d.day = day;
            d.month = month;
            d.year = year;
            return d;
        }
        void displayDate()
        {
            cout<<"d="<<day<<", m="<<month<<", y="<<year;
        }
};


int main()
{
    Date d1, d2;
    d1.setDate(23, 6, 2025);
    d2.setDate(1, 1, 2018);
    d1.displayDate();
    cout<<endl;
    d2.displayDate();
    d2 = d1.getDate();
    cout<<endl;
    cout<<"After running getDate function"<<endl;
    d1.displayDate();
    cout<<endl;
    d2.displayDate();
    return 0;
}