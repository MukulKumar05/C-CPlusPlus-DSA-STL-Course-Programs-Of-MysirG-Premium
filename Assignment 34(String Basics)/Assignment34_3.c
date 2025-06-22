/*
A34.3 Write a program to count vowels in a given string.
(Completed)
*/

#include<stdio.h>
#include<string.h>

int main()
{
    char str[100];
    int i, vowelCount = 0;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\r\n")] = 0;
    for(i = 0; str[i]; i++)
    {
        if(str[i] == 'A' || str[i] == 'E' || str[i] == 'I'|| str[i] == 'O'|| str[i] == 'U' || str[i] == 'a'|| str[i] == 'e'|| str[i] == 'i'|| str[i] == 'o'|| str[i] == 'u')
            vowelCount++;
    }
    printf("Vowels count in string \"%s\" is %d", str, vowelCount);
    return 0;
}