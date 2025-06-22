/*
A34.4 Write a program to count spaces in a given string.
(Completed)
*/

#include<stdio.h>
#include<string.h>

int main()
{
    char str[100];
    int i, spacesCount = 0;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\r\n")] = 0;
    for(i = 0; str[i]; i++)
    {
        if(str[i] == ' ')
            spacesCount++;
    }
    printf("Spaces count in string \"%s\" is %d", str, spacesCount);
    return 0;
}