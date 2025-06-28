#include<stdio.h>
#include<string.h>

/*
40.1 Write a function to store strings, taken from user, to the given 2d char array.
(Completed)
*/
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

int main()
{
    char strs[50][100];
    int i, stringsCount;
    printf("Enter number of strings you want to enter: ");
    scanf("%d", &stringsCount);
    storeStringsin2DCharArray(strs, stringsCount);
    printf("Entered strings are:\n");
    for(i = 0; i < stringsCount; i++)
    {
        printf("\n\"%s\"", strs[i]);
    }
    printf("\n");
    return 0;
}
