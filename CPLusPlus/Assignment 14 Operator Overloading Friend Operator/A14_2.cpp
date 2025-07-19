#include<iostream>
using namespace std;

/*
A14.2 Define a class Time with appropriate instance variables and member
functions. Overload following operators:
1. << insertion operator
2. >> extraction operator
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
        friend ostream& operator<<(ostream&, Time);
        friend istream& operator>>(istream&, Time&);
};
ostream& operator<<(ostream &dout, Time t)
{
    dout<<t.hour<<" hours "<<t.min<<" minutes "<<t.second<<" seconds"<<endl;
    return dout;
}
istream& operator>>(istream &din, Time &t)
{
    din>>t.hour>>t.min>>t.second;
    return din;
}

int main()
{
    Time t1;
    cout<<"Enter time: ";
    cin>>t1;
    cout<<t1;
    return 0;
}