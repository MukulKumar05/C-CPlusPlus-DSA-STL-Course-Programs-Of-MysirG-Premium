#include<iostream>
#include<string.h>
using namespace std;

/*
A10.3 Define a class Time with hr, min, sec as instance member variables.
Define constructor to initialise time object.
(Completed)
*/
class Time
{
    private:
        int hr, min, sec;
    public:
        Time()
        {
            hr = 0;
            min = 0;
            sec = 0;
        }
        Time(int h, int m, int s)
        {
            hr = h;
            min = m;
            sec = s;
        }
        void showTime()
        {
            cout<<hr<<" hours "<<min<<" minutes "<<sec<<" seconds "<<endl;
        }
};


int main()
{
    Time t1, t2(1, 34, 18);
    t1.showTime();
    t2.showTime();
    return 0;
}