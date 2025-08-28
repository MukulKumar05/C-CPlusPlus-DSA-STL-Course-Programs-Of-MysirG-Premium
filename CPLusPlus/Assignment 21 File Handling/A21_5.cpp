#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

/*
A21.5 In question 3, define a member function to print all employee records
stored in a file.

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
        static void printAllEmployeeRecordsFromFile(const char fileName[])
        {
            ifstream fin;
            fin.open(fileName, ios::in);
            if(!fin)
                cout<<"File \""<<fileName<<"\" does not exist"<<endl;
            else
            {
                string line;
                while(getline(fin, line))
                {
                    cout<<line<<endl;
                }
            }
            fin.close();
        }
};

int main()
{
    Employee::printAllEmployeeRecordsFromFile("employeesRecords.txt");
    return 0;
}