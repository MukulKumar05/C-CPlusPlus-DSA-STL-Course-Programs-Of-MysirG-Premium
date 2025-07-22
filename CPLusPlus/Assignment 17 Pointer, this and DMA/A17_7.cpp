#include<iostream>
#include<conio.h>
using namespace std;

/*
A17.7 In question-5, define methods to print string, return string, 
return length of string.
(Completed)
*/
class String
{
    private:
        char *p;
        int strLength;
    public:
        String() 
        {
            p = nullptr;
            strLength = 0;
        }
        void inputString()
        {
            strLength = 2;
            delete []p;
            p = new char[strLength];
            int i;
            char ch = getch();
            if(ch != 13)
                cout<<ch;
            p[0] = ch;
            p[1] = '\0';
            while(ch != 13)
            {
                ch = getch();
                if(ch != 13)
                    cout<<ch;
                if(ch != 13)
                {
                    strLength++;
                    char *q = new char[strLength];
                    for(i = 0; p[i]; i++)
                    {
                        q[i] = p[i];
                    }
                    q[i] = ch;
                    q[i + 1] = '\0';
                    delete []p;
                    p = new char[strLength];
                    for(i = 0; q[i]; i++)
                    {
                        p[i] = q[i];
                    } 
                    p[i] = '\0';
                    delete []q;
                    q = nullptr;  
                }
                else
                {
                    break;
                }
            }
            strLength--;
        }
        void displayString()
        {
            int i;
            for(i = 0; p[i]; i++)
            {
                cout<<p[i];
            }
        }
        ~String()
        {
            delete []p;
            p = nullptr;
        }
        void tranfromStringToUpperCase()
        {
            int i;
            for(i = 0; p[i]; i++)
                if(p[i] >= 97 && p[i] <= 122)
                    p[i] -= 32;
        }
        void tranfromStringToLowerCase()
        {
            int i;
            for(i = 0; p[i]; i++)
                if(p[i] >= 65 && p[i] <= 90)
                    p[i] += 32;
        }
        char* getString()
        {
            return p;
        }
        int getStringLength()
        {
            return strLength;
        }

};

int main()
{
    String s1;
    cout<<"Enter string: ";
    s1.inputString();
    cout<<endl;
    char *str = s1.getString();
    cout<<str;
    cout<<endl<<"Length of this string is "<<s1.getStringLength()<<endl;
    return 0;
}