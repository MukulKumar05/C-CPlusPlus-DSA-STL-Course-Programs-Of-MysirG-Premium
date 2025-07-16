#include<iostream>
#include<string.h>
using namespace std;

/*
A11.2 Define a class student and write a program to enter student details
using constructor and define member function to display all the details.
(Completed)
*/
class student
{
    private:
        int rollNumber;
        char name[100];
    public:
        student(int rollNumber, const char studentName[]):rollNumber(rollNumber)
        {
            strcpy(name, studentName);
        }
        void displayStudentData()
        {
            cout<<"Roll Number: "<<rollNumber<<", Name: "<<name<<endl;
        }
};

int main()
{
    student s1(1, "Mukul Kumar");
    s1.displayStudentData();   
    return 0;
}