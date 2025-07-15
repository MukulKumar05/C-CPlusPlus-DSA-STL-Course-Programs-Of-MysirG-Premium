#include<iostream>
#include<string.h>
using namespace std;

/*
A10.4 Define a class Book with bookid, title and price as instance member
variables. Define non parameterised and parameterised constructor in
the class.
(Completed)
*/
class Book
{
    private:
        int bookid;
        char title[100];
        float price;
    public:
        Book()
        {
            bookid = 0;
            title[0] = '\0';
            price = 0;
        }
        Book(int bid, const char* tit, float pr)
        {
            bookid = bid;
            strcpy(title, tit);
            price = pr;
        }
        void showBookDetails()
        {
            cout<<"Bookid: "<<bookid<<", Title: "<<title<<", Price: "<<price<<endl;
        }
};


int main()
{
    Book b1(1, "Story of My Life", 450), b2;
    b1.showBookDetails();
    b2.showBookDetails();
    return 0;
}