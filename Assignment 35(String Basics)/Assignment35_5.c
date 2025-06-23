/*
A35.5 Write a program to find first occurence of a given character in a given
string.
(Completed)
*/

#include<stdio.h>
#include<string.h>

int main()
{
    char str[100] = {'\0'}, ch;
    int i;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\r\n")] = 0;
    printf("Enter character whose first occurence is to be checked: ");
    scanf("%c", &ch);
    for(i = 0; str[i]; i++)
    {
        if(str[i] == ch)
        {
            printf("First occurence of character \'%c\' found in string \"%s\" at position %d", ch, str, i + 1);
            break;
        }
    }
    if(str[i] == '\0')
        printf("Character \'%c\' not found in string \"%s\"", ch, str);
    return 0;
}