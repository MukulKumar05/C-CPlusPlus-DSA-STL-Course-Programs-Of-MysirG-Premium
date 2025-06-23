/*
A35.3 Write a program in C to count the total number of alphabets, digits and special 
characters in a string.
(Completed)
*/

#include<stdio.h>
#include<string.h>

int main()
{
    char str[100];
    int i, alphabetCount = 0, digitCount = 0, specialCharCount = 0;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\r\n")] = 0;
    for(i = 0; str[i]; i++)
    {
        if(str[i] >= 65 && str[i] <= 90 || str[i] >= 97 && str[i] <= 122)
            alphabetCount++;
        else if(str[i] >= 48 && str[i] <= 57)
            digitCount++;
        else
            specialCharCount++;
    }
    printf("Total number of alphabets are: %d.\n", alphabetCount);
    printf("Total number of digits are: %d.\n", digitCount);
    printf("Total number of special characters are: %d.\n", specialCharCount);
    return 0;
}