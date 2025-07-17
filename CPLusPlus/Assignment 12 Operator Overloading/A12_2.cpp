#include<iostream>
using namespace std;

/*
A12.2 Create a class Time which contains hour, min and second as fields. Overload
greater than (>) operator to compare two time objects.
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
};

int main()
{
    Time t1, t2;
    t1.setTime(2, 30, 47);
    t2.setTime(2, 30, 47);
    if(t1 > t2)
        cout<<"time t1 is greater than time t2"<<endl;
    else
        cout<<"time t1 is not greater than time t2"<<endl;
    return 0;
}