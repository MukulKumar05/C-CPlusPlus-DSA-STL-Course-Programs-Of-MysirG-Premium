#include<iostream>
using namespace std;

/*
A8.2 Define a class Time to represent Time (like 3 hr 45 min 2o sec). Declare
appropriate number of instance member variables and also define instance
member functions to set values for time and display values of time.
(Completed)
*/
class Time
{
    private:
        int hours, minutes, seconds;
    public:
        void setTime(int h, int m, int s)
        {
            hours = h;
            minutes = m;
            seconds = s;
        }
        void displayTime()
        {
            cout<<hours<<" hours "<<minutes<<" minutes "<<seconds<<" seconds ";
        }
};

int main()
{
    Time t1;
    t1.setTime(8, 11, 27);
    t1.displayTime();
    return 0;
}