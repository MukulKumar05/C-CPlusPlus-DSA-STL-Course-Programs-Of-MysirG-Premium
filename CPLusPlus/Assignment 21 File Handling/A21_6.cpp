#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

/*
A21.6 In question 3, define a member function to search an employee by his
empid in a file. Print his record if found, otherwise display a message
of search failed.

(Completed)
*/

string extractFirstNumericSubstringFromString(string originalStr)
{
    int i;
    // char* substring = new char[strlen(originalStr)]();
    string subString;
    for(i = 0; originalStr[i] >= '0' && originalStr[i] <= '9'; i++)
    {
        // substring[i] = originalStr[i];
        subString += originalStr[i];
    }
    return subString;
}

int numberofNumericString(string s)
{
    int i, number = 0;
    for(i = 0; i < s.length(); i++)
    {
        number = number * 10 + (s[i] - '0');
    }
    return number;
}

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
        void searchEmployeebyEmpIDInFile(const char fileName[])
        {
            ifstream fin;
            int firstNumericSubstringAsNumber;
            fin.open(fileName, ios::in);
            if(!fin)
                cout<<"File \""<<fileName<<"\" does not exist"<<endl;
            else
            {
                string line;
                while(getline(fin, line))
                {
                    // cout<<"First numeric substring from line \""<<line<<"\" is "<<extractFirstNumericSubstringFromString(line)<<endl;
                    string firstNumericSubstring = extractFirstNumericSubstringFromString(line);
                    firstNumericSubstringAsNumber = numberofNumericString(firstNumericSubstring);

                    // cout<<"first Numeric Substring As Number is "<<firstNumericSubstringAsNumber<<endl;
                    // cout<<"Value of empid is "<<empid<<endl;
                    if(empid == firstNumericSubstringAsNumber)
                    {
                        cout<<"Employee Record found with empid = "<<empid;
                        cout<<" . The employee record is:"<<endl;
                        cout<<line<<endl;
                        break;
                    }
                }
                if(empid != firstNumericSubstringAsNumber)
                {
                    cout<<"Employee not found with empid = "<<empid<<" in the file \""<<fileName<<"\" ."<<endl;
                }

            }
            fin.close();   
        }
};

int main()
{
    Employee emp4;
    emp4.setEmployee(4, "Manju Yadav", 25000);
    emp4.searchEmployeebyEmpIDInFile("employeesRecords.txt");
    return 0;
}