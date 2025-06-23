/*
A35.2 Write a program to reverse a string.
(Completed)
*/

#include<stdio.h>
#include<string.h>

int main()
{
    char str[100];
    int i, strLength, rightIndex;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\r\n")] = 0;
    strLength = strlen(str);
    for(i = 0, rightIndex = strLength - 1; i < strLength / 2; i++, rightIndex--)
    {
        // in this loop block, 2 characters of string are swapped in every iteration
        // using swapping without using 3rd variable
        str[i] = str[i] + str[rightIndex];
        str[rightIndex] = str[i] - str[rightIndex];
        str[i] = str[i] - str[rightIndex];
    }
    printf("String after reversing is \"%s\"", str);
    return 0;
}