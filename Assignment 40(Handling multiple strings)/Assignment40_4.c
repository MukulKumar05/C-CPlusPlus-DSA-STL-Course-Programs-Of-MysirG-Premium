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

/*
A40.4 Write a function to store each word of a string in a 2 dimensional char array.
(Completed)
*/
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

int main()
{
    char str[100];
    int i;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\r\n")] = 0;

    char wordsOfString[50][100] = {"\0"};
    storeStringEachWordin2DCharArray(str, wordsOfString);

    printf("Words of string are:\n");
    for(i = 0; i < wordsCountinString(str); i++)
    {
        printf("\n\"%s\"", wordsOfString[i]);
    }
    return 0;
}