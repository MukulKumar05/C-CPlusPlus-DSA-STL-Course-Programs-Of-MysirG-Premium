#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

/*
A21.8 In question 3, define a member function to delete an employee
record of given empid.

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

void copyContentFromFiletoFile(const char sourceFile[], const char DestinationFile[])
{
    ifstream fin;
    fin.open(sourceFile, ios::in);
    if(!fin)
        cout<<"File \""<<sourceFile<<"\" does not exist"<<endl;
    else
    {
        ofstream fout;
        fout.open(DestinationFile, ios::out);
        string line;
        while(getline(fin, line))
        {
            fout<<line<<endl;
        }
        fout.close();
    }
    fin.close();
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
        void editEmployeeDataInFile(const char fileName[], int employeeID, const char employeeName[], float employeeSalary)
        {
            copyContentFromFiletoFile(fileName, "employeeRecordsOriginal.txt");
            ifstream fin;
            fin.open("employeeRecordsOriginal.txt", ios::in);
            ofstream fout;
            fout.open(fileName, ios::out);
            string line;
            int firstNumericSubstringAsNumber, deleteStatus = 0;
            while(getline(fin, line))
            {
                string firstNumericSubstring = extractFirstNumericSubstringFromString(line);
                firstNumericSubstringAsNumber = numberofNumericString(firstNumericSubstring);
                if(empid == firstNumericSubstringAsNumber)
                {
                    fout<<employeeID<<","<<employeeName<<","<<employeeSalary<<endl;
                    deleteStatus = 1;
                }
                else
                {
                    fout<<line<<endl;
                }
            }
            if(deleteStatus == 0)
                cout<<"Employee not found with empid = "<<empid<<" in the file \""<<fileName<<"\" ."<<endl;
            fout.close();
            fin.close();
        }
        void deleteEmployeeRecordinFile(const char fileName[])
        {
            copyContentFromFiletoFile(fileName, "employeeRecordsOriginal.txt");
            ifstream fin;
            fin.open("employeeRecordsOriginal.txt", ios::in);
            ofstream fout;
            fout.open(fileName, ios::out);
            string line;
            int firstNumericSubstringAsNumber, deleteStatus = 0;
            while(getline(fin, line))
            {
                string firstNumericSubstring = extractFirstNumericSubstringFromString(line);
                firstNumericSubstringAsNumber = numberofNumericString(firstNumericSubstring);
                if(empid == firstNumericSubstringAsNumber)
                {
                    deleteStatus = 1;
                }
                else
                {
                    fout<<line<<endl;
                }
            }
            if(deleteStatus == 0)
                cout<<"Employee not found with empid = "<<empid<<" in the file \""<<fileName<<"\" ."<<endl;
            fout.close();
            fin.close();
        }
};

int main()
{
    Employee emp4;
    emp4.setEmployee(1012, "Rakesh Yadav", 65000);
    emp4.deleteEmployeeRecordinFile("employeesRecords.txt");
    return 0;
}