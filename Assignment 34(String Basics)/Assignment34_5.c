/*
A34.5 Write a program to convert a given string into uppercase.
(Completed)
*/

#include<stdio.h>
#include<string.h>

int main()
{
    char str[100];
    int i;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\r\n")] = 0;
    for(i = 0; str[i]; i++)
    {
        if(str[i] >= 97 && str[i] <= 122)
            str[i] -= 32;
    }
    printf("String in upper case is \"%s\"", str);
    return 0;
}