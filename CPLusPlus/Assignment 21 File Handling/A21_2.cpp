#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

/*
A21.2 Write a c++ program to read and display content of a file.

(Completed)
*/

int main()
{
    ifstream fin;
    char fileContent[1000] = "\0";
    fin.open("sunrise.txt", ios::in);
    int i;
    for(i = 0; fin.get(fileContent[i]); i++);
    fin.close();
    cout<<"Content of file \"sunrise.txt\" is:\n"<<fileContent<<endl;
    return 0;
}