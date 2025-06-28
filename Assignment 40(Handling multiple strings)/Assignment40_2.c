#include<stdio.h>
#include<string.h>

int vowelsCountinString(char str[])
{
    int i, vowelCount = 0;
    for(i = 0; str[i]; i++)
        if(str[i] == 'A' || str[i] == 'E' || str[i] == 'I'|| str[i] == 'O'|| str[i] == 'U' || str[i] == 'a'|| str[i] == 'e'|| str[i] == 'i'|| str[i] == 'o'|| str[i] == 'u')
            vowelCount++;
    return vowelCount;
}

void storeStringsin2DCharArray(char strs[50][100], int stringsCount)
{
    int i;
    fflush(stdin);
    for(i = 0; i < stringsCount; i++)
    {
        printf("\nEnter string %d: ", i + 1);
        fgets(strs[i], sizeof(strs[i]), stdin);
        strs[i][strcspn(strs[i], "\r\n")] = 0;
    }
    for(i = stringsCount; i < 50; i++)
    {
        strs[i][0] = '\0';
    }
}

/*
A40.2 Write a program to find the number of vowels in each of the 5 strings stored in two
dimensional arrays, taken from the user.
(Completed)
*/

int main()
{
    char strs[50][100];
    int i;
    storeStringsin2DCharArray(strs, 5);
    printf("Vowels count of 5 entered strings is:\n");
    for(i = 0; i < 5; i++)
    {
        printf("Vowels count of string \"%s\" : %d\n", strs[i], vowelsCountinString(strs[i]));
    }
    return 0;
}