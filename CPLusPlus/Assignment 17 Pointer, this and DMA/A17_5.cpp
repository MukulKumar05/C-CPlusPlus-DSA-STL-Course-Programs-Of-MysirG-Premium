#include<iostream>
#include<conio.h>
using namespace std;

/*
A17.5 Define a class String with char pointer and length of the string as
instance member variables. Define a method to dynamically create an array
of char type and hold the input string in such a way that the array 
length is just enough to accomodate the input string.
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

};

int main()
{
    String s1;
    cout<<"Enter string: ";
    s1.inputString();
    cout<<endl;
    s1.displayString();
    return 0;
}