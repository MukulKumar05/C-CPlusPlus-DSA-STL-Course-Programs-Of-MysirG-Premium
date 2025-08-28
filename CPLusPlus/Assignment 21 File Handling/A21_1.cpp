#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

/*
A21.1 Write a c++ program to copy content of file and store in other file.

(Completed)
*/

int main()
{
    ifstream fin;
    fin.open("employeesRecords.txt", ios::in);
    if(!fin)
        cout<<"File \"employeesRecords.txt\" does not exist"<<endl;
    else
    {
        ofstream fout;
        fout.open("employeeRecordsOriginal.txt", ios::out);
        string line;
        while(getline(fin, line))
        {
            fout<<line<<endl;
        }
        fout.close();
    }
    fin.close();
    return 0;
}
