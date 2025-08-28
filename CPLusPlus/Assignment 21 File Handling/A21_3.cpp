#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

/*
A21.3 Define a class Employee with empid, name and salary as instance
variables. Also provide instance methods to input and display Employee
record.
(Completed)
*/

class Employee
{
    private:
        int empid;
        char name[100];
        float salary;
    public:
        void inputEmployeeData()
        {
            cout<<"Enter employee id: ";
            cin>>empid;
            cin.ignore();
            cout<<"Enter employee name: ";
            cin.getline(name, sizeof(name));
            cout<<"Enter employee salary: ";
            cin>>salary;
        }
        void displayEmployeeData()
        {
            cout<<"Employee ID: "<<empid<<" , Employee Name: "<<name<<" , Employee Salary: "<<salary<<endl;
        }
};

int main()
{
    Employee emp;
    emp.inputEmployeeData();
    emp.displayEmployeeData();
    return 0;
}