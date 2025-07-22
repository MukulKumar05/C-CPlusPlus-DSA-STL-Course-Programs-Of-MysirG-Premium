#include<iostream>
using namespace std;

/*
A17.1 Define a class Time with instance variables hr, min and sec. Provide
instance methods setTime() and showTime(). setTime() method has formal
arguments with the same name as instance variables. Also define
setters and getters.
(Completed)
*/
class Time
{
    private:
        int hr, min, sec;
    public:
        void setTime(int hr, int min, int sec)
        {
            this->hr = hr;
            this->min = min;
            this->sec = sec;
        }
        void showTime()
        {
            cout<<hr<<" hours "<<min<<" minutes "<<sec<<" seconds"<<endl;
        }
        void setHour(int hr)
        {
            this->hr = hr;
        }
        void setMinute(int min)
        {
            this->min = min;
        }
        void setSecond(int sec)
        {
            this->sec = sec;
        }
        int getHour()
        {
            return hr;
        }
        int getMinute()
        {
            return min;
        }
        int getSecond()
        {
            return sec;
        }
        void normalize()
        {
            while(sec > 60)
            {
                sec = sec - 60;
                min = min + 1; 
            }
            while(min > 60)
            {
                min = min - 60;
                hr = hr + 1; 
            }
        }
        Time add(Time t)
        {
            Time sumTimes;
            sumTimes.hr = hr + t.hr;
            sumTimes.min = min + t.min;
            sumTimes.sec = sec + t.sec;
            return sumTimes;
        }
        bool operator>(Time t)
        {
            if(hr > t.hr)
                return true;
            else if(hr < t.hr)
                return false;
            else if(min > t.min)
                return true;
            else if(min < t.min)
                return false;
            else if(sec > t.sec)
                return true;
            else if(sec < t.sec)
                return false;
            else
                return false;
        }
        friend ostream& operator<<(ostream&, Time);
        friend istream& operator>>(istream&, Time&);
};
ostream& operator<<(ostream &dout, Time t)
{
    dout<<t.hr<<" hours "<<t.min<<" minutes "<<t.sec<<" seconds"<<endl;
    return dout;
}
istream& operator>>(istream &din, Time &t)
{
    din>>t.hr>>t.min>>t.sec;
    return din;
}

int main()
{
    Time t1;
    t1.setHour(3);
    t1.setMinute(19);
    t1.setSecond(36);
    cout<<"Time t1 is: "<<t1.getHour()<<":"<<t1.getMinute()<<":"<<t1.getSecond()<<endl;
    return 0;
}
