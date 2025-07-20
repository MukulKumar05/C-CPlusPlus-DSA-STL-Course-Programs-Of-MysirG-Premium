#include<iostream>
#include<string.h>
using namespace std;

/*
A15.5 Define a class Student with roll no, name and age as instance
variables. Create setStudent() and showStudent() methods in the class.
Overload operator== to compare two Student objects.
(Completed)
*/
class Student
{
    private:
        int roll_no, age;
        char name[100];
    public:
        void setStudent(int roll_no, int age, const char name[])
        {
            this->roll_no = roll_no;
            this->age = age;
            strcpy(this->name, name);
        }
        void showStudent()
        {
            cout<<"Roll No: "<<roll_no<<" , Name: "<<name<<" , Age: "<<age<<endl;
        }
        friend int operator==(Student&, Student&);  
};
int operator==(Student &s1, Student &s2)
{
    if(s1.roll_no == s2.roll_no && s1.age == s2.age && strcmp(s1.name, s2.name) == 0)
        return 1;
    return 0;
}

int main()
{
    Student s1, s2;
    s1.setStudent(1, 8, "Mukul Kumar");
    s2.setStudent(1, 8, "Mukul Kumar");
    // s1.showStudent();
    if(s1 == s2)
        cout<<"Student details are same."<<endl;
    else
        cout<<"Student details are not same."<<endl;
    return 0;
}