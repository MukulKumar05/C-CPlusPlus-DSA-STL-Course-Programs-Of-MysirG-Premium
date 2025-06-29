#include<stdio.h>
#include<string.h>

void storeStringsin2DCharArray(char strs[10][100], int stringsCount)
{
    int i;
    fflush(stdin);
    for(i = 0; i < stringsCount; i++)
    {
        printf("\nEnter string %d: ", i + 1);
        fgets(strs[i], sizeof(strs[i]), stdin);
        strs[i][strcspn(strs[i], "\r\n")] = 0;
    }
}

int wordFoundinStringAtIndex(char str[], char word[])
{
    int i, j, k;
    for(i = 0; str[i]; i++)
    {
        if(str[i] == word[0])
        {
            k = i;
            j = 0;
            while(word[j])
            {
                if(word[j] == str[k])
                {
                    j++;
                    k++;
                }
                else
                    break;
            }
            if(word[j] == '\0')
                return i;
        }
    }
    return -1;
}

/*
A41.5 A 2d array is full with 10 email ids. Write a function to find how many of them
belongs to gmail.com
(Completed)
*/

int gmailAccountsCount(char emailIDs[10][100])
{
    int i, gmailIDsCount = 0;
    for(i = 0; i < 10; i++)
    {
        if(wordFoundinStringAtIndex(emailIDs[i], "gmail.com") != -1)
            gmailIDsCount++;
    }
    return gmailIDsCount;
}

int main()
{
    char emailIDs[10][100] = {"\0"};
    storeStringsin2DCharArray(emailIDs, 10);
    printf("Gmail IDs count is %d", gmailAccountsCount(emailIDs));
    return 0;
}