#include<iostream>
using namespace std;

/*
A17.2 In question-1, define a method to dynamically create an array of
Time objects with specified size (received through argument) and return
array.
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
Time* createDynamicArray(int size)
{
    Time *t = new Time[size];
    return t;
}
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
    Time *tmp = createDynamicArray(5);
    delete tmp;
    return 0;
}