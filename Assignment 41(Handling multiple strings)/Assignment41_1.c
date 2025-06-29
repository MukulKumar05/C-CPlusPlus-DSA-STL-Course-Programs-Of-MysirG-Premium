#include<stdio.h>
#include<string.h>

void trimString(char str[])
{
    char trimmedStr[100] = "\0";
    int i, j;
    for(i = 0; str[i] == ' '; i++);
    for(j = 0; str[i]; i++, j++)
        trimmedStr[j] = str[i];
    for(j--; trimmedStr[j] == ' '; j--)
        trimmedStr[j] = '\0';
    strcpy(str, trimmedStr);
}

int wordsCountinString(char originalStr[])
{
    int i, singleSpacesCount = 0;
    char str[100] = {'\0'};
    strcpy(str, originalStr);
    trimString(str);
    if(strlen(str) == 0)
        return 0;
    for(i = 1; str[i]; i++)
    {
        if(str[i] == ' ' && str[i - 1] != ' ')
            singleSpacesCount++;
    }
    return singleSpacesCount + 1;
}

void storeStringEachWordin2DCharArray(char originalStr[100], char stringWords[50][100])
{
    int i, currentSpaceIndex, j, k = 0, l;
    char str[100] = "\0";
    strcpy(str, originalStr);
    trimString(str);
    for(i = 0; str[i]; i++)
    {
        j = i;
        for(; str[i] != ' ' && str[i] != '\0'; i++);
        currentSpaceIndex = i;
        for(l = 0; j < currentSpaceIndex; j++, l++)
        {
            stringWords[k][l] = str[j];
        }
        stringWords[k][l] = '\0';
        k++;
    }
}

int stringsCountin2DCharArray(char strs[50][100])
{
    int i, j;
    for(i = 0; i < 50; i++)
    {
        for(j = 0; strs[i][j]; j++);
        if(j == 0)
            return i;
    }
}

/*
A41.1 Write a program to find words ending with a letter 's' and store each such word in a
2D char array.
(Completed)
*/

int main()
{
    char str[100];
    int i, k;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\r\n")] = 0;

    char wordsOfString[50][100] = {"\0"};
    char stringWordsEndingWithS[50][100] = {"\0"};
    storeStringEachWordin2DCharArray(str, wordsOfString);

    int stringsCount = stringsCountin2DCharArray(wordsOfString);
    

    // adding only those words in a new 2D char array where last letter is 's'
    for(i = 0, k = 0; i < stringsCount; i++)
    {
        if(wordsOfString[i][strlen(wordsOfString[i]) - 1] == 's')
        {
            strcpy(stringWordsEndingWithS[k], wordsOfString[i]);
            k++;
        }
    }

    // printing words of string ending with letter 's'
    printf("Strings ending with letter \'s\' are:\n");
    int sEndstrCount = stringsCountin2DCharArray(stringWordsEndingWithS);
    for(i = 0; i < sEndstrCount; i++)
    {
        printf("\"%s\"\n", stringWordsEndingWithS[i]);
    }
    return 0;
}
