#include<iostream>
using namespace std;

/*
A9.2 Define a class Time to represent a time with instance variables h, m
and s to store hour, minute and second. Also define following member
functions-
i. void setTime(int, int, int)
ii. void showTime()
iii. void normalize()
iv. Time add(Time)
v. bool is_greater(Time)
(Completed)
*/
class Time
{
    private:
        int h, m, s;
    public:
        void setTime(int hr, int min, int sec)
        {
            h = hr;
            m = min;
            s = sec;
        }
        void showTime()
        {
            cout<<h<<" hours "<<m<<" minutes "<<s<<" seconds"<<endl;
        }
        void normalize()
        {
            while(s > 60)
            {
                s = s - 60;
                m = m + 1; 
            }
            while(m > 60)
            {
                m = m - 60;
                h = h + 1; 
            }
        }
        Time add(Time t)
        {
            Time sumTimes;
            sumTimes.h = h + t.h;
            sumTimes.m = m + t.m;
            sumTimes.s = s + t.s;
            return sumTimes;
        }
        bool is_greater(Time t)
        {
            if(h > t.h)
                return true;
            else if(h < t.h)
                return false;
            else if(m > t.m)
                return true;
            else if(m < t.m)
                return false;
            else if(s > t.s)
                return true;
            else if(s < t.s)
                return false;
            else
                return false;
        }
};

int main()
{
    Time t1, t2, sum;
    // t1.setTime(2, 30, 47);
    // t1.showTime();
    // t1.normalize();
    // t1.showTime();
    // t2.setTime(2, 30, 47);
    // sum = t1.add(t2);
    // sum.showTime();
    // if(t1.is_greater(t2))
    //     cout<<"time t1 is greater than time t2"<<endl;
    // else
    //     cout<<"time t1 is not greater than time t2"<<endl;

    // t1.setTime(3, 172, 189);
    // t1.showTime();
    // t1.normalize();
    // t1.showTime();
    return 0;
}