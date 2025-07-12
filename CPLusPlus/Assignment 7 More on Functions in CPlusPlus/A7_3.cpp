#include<iostream>
#include<string.h>
using namespace std;

/*
7.3 Define a function to print a substring from startIndex(inclusive) to
endIndex(exclusive). Define function in such a way that if second 
argument is not provided, string will print till the last possible
index.
(Completed)
*/

void printSubstringFromStringWithinIndices(char str[], int startIndex, int endIndex = '\0')
{
    int i;
    if(endIndex)
    {
        for(i = startIndex; i < endIndex; i++)
            cout<<str[i];
    }
    else
    {
        for(i = startIndex; str[i]; i++)
            cout<<str[i];
    }
}






int main()
{
    char s[] = "Welcome to my world!!!";
    printSubstringFromStringWithinIndices(s, 11);
    return 0;
}