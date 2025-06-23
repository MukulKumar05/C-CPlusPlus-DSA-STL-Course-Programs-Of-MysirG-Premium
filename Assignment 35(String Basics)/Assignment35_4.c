/*
A35.4 Write a program in C to copy one string to another char array.
(Completed)
*/

#include<stdio.h>
#include<string.h>

int main()
{
    char str[100] = {'\0'}, strNew[100] = {'\0'};
    int i;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\r\n")] = 0;
    for(i = 0; str[i]; i++)
        strNew[i] = str[i];
    printf("String Str: \"%s\"", str);
    printf("\nString strNew: \"%s\"", strNew);
    return 0;
}