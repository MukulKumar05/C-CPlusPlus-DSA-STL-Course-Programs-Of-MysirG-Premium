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
A41.4 Write a function to store all the words in a given string which are starting 
from 'a', in a two dimensional char array.
(Completed)
*/
void storeAllWordsOfStringStartingfromChara(char originalStr[], char strsa[50][100])
{
    char strs[50][100] = {"\0"};
    int i, j;
    storeStringEachWordin2DCharArray(originalStr, strs);
    
    // storing only those words in strsa[] from strs[] where string starts with letter 'a'
    for(i = 0, j = 0; i < stringsCountin2DCharArray(strs); i++)
    {
        if(strs[i][0] == 'a')
        {
            strcpy(strsa[j], strs[i]);
            j++;
        }
    }
}

int main()
{
    char str[100] = "amar lives in assam. He is a good boy.";
    char strsa[50][100] = {"\0"};
    int i;
    storeAllWordsOfStringStartingfromChara(str, strsa);
    printf("Words of string starting with letter 'a' are:\n");
    for(i = 0; i < stringsCountin2DCharArray(strsa); i++)
    {
        printf("\"%s\"\n", strsa[i]);
    }
    return 0;
}

