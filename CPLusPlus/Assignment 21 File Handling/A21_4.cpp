#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

/*
A21.4 In question 3, define a member function to store new employee
record in a file.

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
        void setEmployee(int empid, const char name[], float salary)
        {
            this->empid = empid;
            strcpy(this->name, name);
            this->salary = salary;
        }
        void saveEmployeeDataInFile(const char fileName[])
        {
            ofstream fout;
            fout.open(fileName, ios::app);
            // fout.write((const char*)this, sizeof(*this));  // data is not readable on text file when we write data to file using write()
            fout<<empid<<","<<name<<","<<salary<<endl;
            fout.close();
        }
};

int main()
{
    Employee emp1, emp2, emp3, emp4, emp5;
    emp1.setEmployee(1, "Mukul Kumar Yadav", 20000);
    // emp1.saveEmployeeDataInFile("employeesRecords.txt");
    emp2.setEmployee(2, "Vijay Pal Yadav", 30000);
    emp2.saveEmployeeDataInFile("employeesRecords.txt");
    emp3.setEmployee(3, "Kanta Yadav", 5000);
    emp3.saveEmployeeDataInFile("employeesRecords.txt");
    emp4.setEmployee(4, "Manju Yadav", 25000);
    emp4.saveEmployeeDataInFile("employeesRecords.txt");
    emp5.setEmployee(5, "Anju Yadav", 12000);
    emp5.saveEmployeeDataInFile("employeesRecords.txt");
    return 0;
}