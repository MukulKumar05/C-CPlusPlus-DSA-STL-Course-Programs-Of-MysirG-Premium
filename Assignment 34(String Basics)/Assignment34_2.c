/*
A34.2 Write a program to count the occurence of a given character in a given string.    
(Completed)
*/

#include<stdio.h>
#include<string.h>

int main()
{
    char name[50], ch;
    int i, occurCount = 0;
    printf("Enter a string: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\r\n")] = 0;
    printf("Enter a character to check its occurence count in string: ");
    scanf("%c", &ch);
    for(i = 0; name[i]; i++)
        if(name[i] == ch)
            occurCount++;
    printf("%c occurs %d times in string \"%s\"", ch, occurCount, name);
    return 0;
}