#include<iostream>
#include<string.h>
using namespace std;

/*
A8.4 In question 3, define a methods to display date in the following
pattern-
i. 31-12-2022
ii. 31-Dec-2022
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
        void displayDateinNumericalMonth()
        {
            cout<<day<<"-"<<month<<"-"<<year;
        }
        void displayDateinAlphabeticalMonth()
        {
            char strMonth[4] = "\0";
            switch (month)
            {
            case 1:
                strcpy(strMonth, "Jan");
                break;
            case 2:
                strcpy(strMonth, "Feb");
                break;
            case 3:
                strcpy(strMonth, "Mar");
                break;
            case 4:
                strcpy(strMonth, "Apr");
                break;
            case 5:
                strcpy(strMonth, "May");
                break;
            case 6:
                strcpy(strMonth, "Jun");
                break;
            case 7:
                strcpy(strMonth, "Jul");
                break;
            case 8:
                strcpy(strMonth, "Aug");
                break;
            case 9:
                strcpy(strMonth, "Sep");
                break;
            case 10:
                strcpy(strMonth, "Oct");
                break;
            case 11:
                strcpy(strMonth, "Nov");
                break;
            case 12:
                strcpy(strMonth, "Dec");
                break;
            default:    
                cout<<"Invalid month number!!!";
                break;
            }
            cout<<day<<"-"<<strMonth<<"-"<<year;
        }
};

int main()
{
    Date d1;
    d1.setDate(23, 6, 2025);
    d1.displayDateinNumericalMonth();
    cout<<endl;
    d1.displayDateinAlphabeticalMonth();
    return 0;
}