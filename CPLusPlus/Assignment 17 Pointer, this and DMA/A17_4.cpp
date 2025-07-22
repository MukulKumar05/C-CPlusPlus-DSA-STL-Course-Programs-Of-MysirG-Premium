#include<iostream>
using namespace std;

/*
A17.4 In question-1, define a method to display Time object array values.
Array is received through argument.
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
            cout<<hr<<":"<<min<<":"<<sec<<endl;
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
void SwapTimeObjects(Time &t1, Time &t2)
{
    Time temp;
    temp = t1;
    t1 = t2;
    t2 = temp;
}
void sortTimeObjects(Time *t, int size)
{
    int i,j;
    for(i=0;i<size-1;i++)
        for(j=i+1;j<size;j++)
            if(t[i] > t[j])
            {
                SwapTimeObjects(t[i], t[j]);
            }
}
void displayTimeObjects(Time *t, int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        t[i].showTime();
    }
}

int main()
{
    Time *tmp = createDynamicArray(5);
    tmp[0].setTime(8, 21, 46);
    tmp[1].setTime(5, 21, 46);
    tmp[2].setTime(11, 6, 53);
    tmp[3].setTime(5, 17, 45);
    tmp[4].setTime(5, 21, 40);
    cout<<"Time objects before sorting are:"<<endl;
    displayTimeObjects(tmp, 5);
    sortTimeObjects(tmp, 5);
    cout<<endl<<"Time objects after sorting are:"<<endl;
    displayTimeObjects(tmp, 5);
    delete tmp;
    return 0;
}