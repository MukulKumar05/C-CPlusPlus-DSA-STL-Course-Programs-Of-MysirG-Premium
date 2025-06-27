#include<stdio.h>
#include<string.h>

/*
A39.1 Write a function to count frequency of each character of the given string.
(Completed)
*/
void printfrequencyofEachCharacterinString(char originalStr[])
{
    char uniqueChars[100] = {originalStr[0]};
    int i, ub = 0, j, occurCount;
    for(i = 1; originalStr[i]; i++)
    {
        for(j = 0; j <= ub; j++)
            if(originalStr[i] == uniqueChars[j])
                break;
        if(j > ub)        
            uniqueChars[++ub] = originalStr[i];
    }
    
    for(i = 0; i <= ub; i++)
    {
        occurCount=0;
        for(j = 0; originalStr[j]; j++)
            if(uniqueChars[i] == originalStr[j])
                occurCount++;
        printf("\nFrequency of %c is %d.", uniqueChars[i], occurCount);
    }
}

/*
A39.2 Write a function to find a word in a given string.
(Completed)
*/
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
A39.3 Write a function to make first character of each word of the string capital.
(Completed)
*/
void makeStringEachWordinCapital(char originalStr[])
{
    char str[100] = "\0";
    int i;
    strcpy(str, originalStr);
    if(str[0] >= 97 && str[0] <= 122)
        str[0] -= 32;
    for(i = 1; str[i]; i++)
    {
        if(str[i] == ' ' && str[i + 1] >= 97 && str[i + 1] <= 122)
        {
            str[i + 1] -= 32;
        }
    }
    strcpy(originalStr, str);
}

/*
A39.4 Write a function to make acronym name from a given name. For example, "Ramesh
Chand Tiwari" becomes "R C Tiwari" , "Bhavesh Gupta" becomes "B Gupta"
(Completed)
*/
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

void reverseStringWordWise(char originalStr[])
{
    char str[100] = "\0";
    char reversedStringWordWise[100] = "\0";
    char reversedWordStringCornerSpaced[100] = "\0";
    int i, j, orStrLength, k = 0;
    strcpy(str, originalStr);
    trimString(str);
    orStrLength = strlen(str);
    for(i = orStrLength - 1; i >= -1; i--)
    {
        if(i == -1 || str[i] == ' ' && str[i + 1] != ' ')
        {
            for(j = i + 1; str[j] != '\0' && str[j] != ' '; j++, k++)
            {
                reversedStringWordWise[k] = str[j];
            }
            if(i != -1)
            {
                reversedStringWordWise[k] = ' ';
                k++;
            }
        }
    }
    
    // assigning left side corner spaces of original string to reversed string with corner spaces
    for(i = 0; originalStr[i] == ' '; i++)
    {
        reversedWordStringCornerSpaced[i] = originalStr[i];
    }
    
    // copying characters from reversed string to reversed string with corner spaces
    for(j = 0; reversedStringWordWise[j]; j++, i++)
    {
        reversedWordStringCornerSpaced[i] = reversedStringWordWise[j];
    }
    
    // assigning right side corner spaces of original string to reversed string with corner spaces
    for(j = strlen(originalStr) - 1; originalStr[j] == ' '; j--, i++)
    {
        reversedWordStringCornerSpaced[i] = originalStr[j];
    }
    strcpy(originalStr, reversedWordStringCornerSpaced);
}

void acronymNameforName(char originalStr[])
{
    char acronymedStr[100] = "\0";
    int i, j, spaceIndexbeforeLastName, currentSpaceIndex;

    // adding last word in new string
    for(i = strlen(originalStr) - 1; originalStr[i] != ' '; i--);
    // printf("value of i while assigning value to spaceIndexbeforeLastName var: %d", i);
    spaceIndexbeforeLastName = i;
    for(j = 0, i++; originalStr[i]; j++, i++)
    {
        acronymedStr[j] = originalStr[i]; 
    }
    // printf("\nacronym string with just last name is \"%s\"", acronymedStr);
    
    // adding first characters of other names in acronymed string
    currentSpaceIndex = spaceIndexbeforeLastName;
    // printf("\nValue of i before starting while loop: %d", i);
    // printf("\nValue of currentSpaceIndex before starting while loop: %d", currentSpaceIndex);
    while(i >= 0)
    {
        // printf("\nValue of i inside while loop before for loop is %d", i);
        for(i = currentSpaceIndex - 1; i > 0 && originalStr[i] != ' '; i--);
        // printf("\nValue of i inside while loop after for loop is %d", i);
        if(i >= 0)
        {
            // printf("\nOriginalStr[%d] = %c", i, originalStr[i]);
            if(originalStr[i] == ' ')
            {
                currentSpaceIndex = i;
                // printf("\nValue of currentSpaceIndex at i = %d is %d", i, currentSpaceIndex);
            }
            if(originalStr[i] == ' ' && originalStr[i + 1] != ' ')
            {
                // printf("\noriginalStr[%d] == \' \' && originalStr[%d] != \' \'", i, i + 1);
                // printf("\n then values assigned in acracronymedStr[] are:");
                acronymedStr[j] = ' ';
                // printf("\nacronymedStr[%d] = %c", j, acronymedStr[j]);
                j++;
                acronymedStr[j] = originalStr[i + 1];
                // printf("\nacronymedStr[%d] = %c", j, acronymedStr[j]);
                j++;
            }
            if(i == 0)
            {
                // printf("\nHere, i == %d, then", i);
                if(originalStr[i] != ' ')
                {
                    // printf("Here, i == 0 && originalStr[%d] != \' \' then", i);
                    acronymedStr[j] = ' ';
                    // printf("\nacronymedStr[%d] = %c", j, acronymedStr[j]);
                    j++;
                    acronymedStr[j] = originalStr[i];
                    // printf("\nacronymedStr[%d] = %c", j, acronymedStr[j]);
                    currentSpaceIndex = i;
                }
                else
                {
                    currentSpaceIndex = i;
                    // printf("\nWhen i == 0 && originalStr[%d] == \' \' then", i);
                    // printf("\ncurrentSpaceIndex = %d", currentSpaceIndex);
                }
            }
        }
    }
    // printf("\nFinal acronymed reversed string is \"%s\"", acronymedStr);
    reverseStringWordWise(acronymedStr);
    strcpy(originalStr, acronymedStr);
}

/*
A39.5 Write a function to concatenate two strings.
(Completed)
*/
void concatenateString2withString1(char s1[], char s2[])
{
    int i, j;
    for(i = 0; s1[i]; i++)
    {
        // printf("\ns1[%d] = %c", i, s1[i]);
    }
    for(j = 0; s2[j]; i++, j++)
    {
        s1[i] = s2[j];
        // printf("\ns1[%d] = s2[%d] (%c)", i, j, s2[j]);
    }
    s1[i] = '\0'; // the index after last character made null to denote termination of extended string
}

int main()
{
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\r\n")] = 0;
    // printfrequencyofEachCharacterinString(str);
    
    // char word[50];
    // printf("Enter word to search in string: ");
    // fgets(word, sizeof(word), stdin);
    // word[strcspn(word, "\r\n")] = 0;
    // int strInd = wordFoundinStringAtIndex(str, word);
    // if(strInd != -1)
    //     printf("Word \"%s\" found in string \"%s\" at index %d", word, str, strInd);
    // else
    //     printf("Word \"%s\" not found in string \"%s\"", word, str);

    // makeStringEachWordinCapital(str);
    // printf("String after capitalizing each string word is \"%s\"", str);

    // acronymNameforName(str);
    // printf("Acronym form is \"%s\"", str);

    char str2[100];
    printf("Enter another string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\r\n")] = 0;

    concatenateString2withString1(str, str2);
    printf("After concatenation\n");
    printf("\n String 1: \"%s\"", str);
    printf("\n String 2: \"%s\"", str2);
    return 0;
}
