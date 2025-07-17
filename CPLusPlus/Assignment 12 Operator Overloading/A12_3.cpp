#include<iostream>
using namespace std;

/*
A12.3 In Question-2, overload pre-increment and post-increment operator to
increment Time object value by one second.
(Completed)
*/
class Time
{
    private:
        int hour, min, second;
    public:
        void setTime(int h, int m, int s)
        {
            hour = h;
            min = m;
            second = s;
        }
        void showTime()
        {
            cout<<hour<<" hours "<<min<<" minutes "<<second<<" seconds"<<endl;
        }
        void normalize()
        {
            while(second > 60)
            {
                second = second - 60;
                min = min + 1; 
            }
            while(min > 60)
            {
                min = min - 60;
                hour = hour + 1; 
            }
        }
        Time add(Time t)
        {
            Time sumTimes;
            sumTimes.hour = hour + t.hour;
            sumTimes.min = min + t.min;
            sumTimes.second = second + t.second;
            return sumTimes;
        }
        bool operator>(Time t)
        {
            if(hour > t.hour)
                return true;
            else if(hour < t.hour)
                return false;
            else if(min > t.min)
                return true;
            else if(min < t.min)
                return false;
            else if(second > t.second)
                return true;
            else if(second < t.second)
                return false;
            else
                return false;
        }

        // pre-increment operator
        Time& operator++()
        {
            ++second;
            normalize();
            return *this;
        }

        // post-increment operator
        Time operator++(int)
        {
            Time temp = *this;
            second++;
            normalize();
            return temp;
        }

};


int main()
{
    Time t1, t2;
    t1.setTime(2, 30, 47);
    t2.setTime(0, 0, 0);
    // t1.showTime();
    // t2.showTime();
    t2 = t1++;
    // t1.showTime();
    // t2.showTime();
    t2 = ++t1;
    t1.showTime();
    t2.showTime();
    return 0;
}