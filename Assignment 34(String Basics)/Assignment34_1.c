/*
A34.1 Write a program to calculate the length of the string. (without using
builtin method)
(Completed)
*/

#include<stdio.h>
#include<string.h>

int main()
{
    char str[100];
    int i;
    printf("Enter string: ");
    fgets(str, 50, stdin);
    /* Refer W3 schools website to study about strcspn function*/
    str[strcspn(str, "\r\n")] = 0; 
    for(i = 0; str[i]; i++);
    printf("Length of string \"%s\" is %d.", str, i);
    return 0;
}
