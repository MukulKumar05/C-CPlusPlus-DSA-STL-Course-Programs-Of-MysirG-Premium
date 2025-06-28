#include<stdio.h>
#include<string.h>

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
A40.5 Write a function to remove duplicate names stored in the list of names stored in a
2d char array.
(Completed)
*/

int removeDuplicateNamesFrom2DCharArrayList(char strs[50][100], int stringsCount)
{
    char unique[50][100] = {"\0"};
    strcpy(unique[0], strs[0]);
    int i, ub = 0, j, occurCount;
    for(i = 1; i < stringsCount; i++)
    {
        for(j = 0; j <= ub; j++)
            if(strcmp(strs[i], unique[j]) == 0)
                break;
        if(j > ub)
        {
            ub++;
            strcpy(unique[ub], strs[i]);
        }
    }

    // reseting values of 2D char array to '\0' character
    for(i = 0; i < stringsCount; i++)
    {
        strcpy(strs[i], "\0");
    }

    // Assigning 2d char array values without duplicates to original strs 2D char array
    for(i = 0; i <= ub; i++)
    {
        strcpy(strs[i], unique[i]);
    }

    return ub + 1;  // returns count of unique elements
}

int main()
{
    char strs[50][100];
    int i, uniqueCount;
    storeStringsin2DCharArray(strs, 9);
    uniqueCount = removeDuplicateNamesFrom2DCharArrayList(strs, 9);
    printf("Unique strings are:\n");
    for(i = 0; i < uniqueCount; i++)
    {
        printf("\n\"%s\"", strs[i]);
    }
    return 0;
}