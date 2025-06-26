#include<stdio.h>
#include<string.h>

/*
A38.1 Write a function to check whether a given string is palindrome or not.
(Completed)
*/
int isStringPalindrome(char str[])
{
    char reversedString[100] = {'\0'};
    char originalStr[100] = {'\0'};
    strcpy(originalStr, str);
    strcpy(reversedString, strrev(originalStr));
    if(strcmp(str, reversedString))
        return 0;
    return 1;
}

/*
A38.2 Write a function to trim a string (removing leading spaces from both the ends).
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

/*
A38.3 Write a function to count words in a given string.
(Completed)
*/

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
A38.4 Write a function to reverse a string word wise. (For example if the given string
is "Mysirg Education Services" then the resulting string should be "Services
Education Mysirg" ).
(Completed)
*/
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

void tranfromStringToLowerCase(char str[])
{
    int i;
    for(i = 0; str[i]; i++)
        if(str[i] >= 65 && str[i] <= 90)
            str[i] += 32;
}

/*
A38.5 Write a function to do case insensitive comparison of two strings.
(Completed)
*/
int stringsCaseInsensitiveComparison(char orgS1[], char orgS2[])
{
    char s1[100] = "\0";
    char s2[100] = "\0";
    strcpy(s1, orgS1);
    strcpy(s2, orgS2);
    tranfromStringToLowerCase(s1);
    tranfromStringToLowerCase(s2);
    return strcmp(s1, s2);
}

int main()
{
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\r\n")] = 0;
    
    // if(isStringPalindrome(str))
    //     printf("String \"%s\" is palindrome string.", str);
    // else
    //     printf("String \"%s\" is not palindrome string.", str);

    // printf("Original string is \"%s\"", str);
    // trimString(str);
    // printf("\nString after trimming is \"%s\"", str);

    // printf("\nWords count in string \"%s\" is %d", str, wordsCountinString(str));

    // printf("Entered string is \"%s\"", str);
    // reverseStringWordWise(str);
    // printf("\nString when reversed word wise is \"%s\"", str);

    char str2[100];
    printf("Enter another string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\r\n")] = 0;
    int result = stringsCaseInsensitiveComparison(str, str2);
    printf("Result of string comparison is %d", result);
    return 0;
}
