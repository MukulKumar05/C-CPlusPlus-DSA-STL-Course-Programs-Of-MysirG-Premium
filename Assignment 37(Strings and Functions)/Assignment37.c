#include<stdio.h>
#include<string.h>

/*
A37.1 Write a function to count vowels in a given string.
(Completed)
*/
int vowelsCountinString(char str[])
{
    int i, vowelCount = 0;
    for(i = 0; str[i]; i++)
        if(str[i] == 'A' || str[i] == 'E' || str[i] == 'I'|| str[i] == 'O'|| str[i] == 'U' || str[i] == 'a'|| str[i] == 'e'|| str[i] == 'i'|| str[i] == 'o'|| str[i] == 'u')
            vowelCount++;
    return vowelCount;
}

/*
A37.2 Write a function to find a character in a given string. Return index of first occurence
of given character. Return -1 if character not found.
(Completed)
*/
int indexOfFirstOccurenceOfCharacterinString(char str[], char ch)
{
    int i;
    for(i = 0; str[i]; i++)
        if(str[i] == ch)
            return i;
    return -1;
}

/*
A37.3 Write a function to find character in a given string between specified indices (start
index (inclusive) and end index (exclusive) ).
(Completed)
*/
int indexOfFirstOccurenceOfCharacterinStringBtwIndices(char str[], char ch, int startIndex, int endIndex)
{
    int i;
    for(i = startIndex; i < endIndex; i++)
        if(str[i] == ch)
            return i;
    return -1;
}

/*
A37.4 Write a function to swap two characters of a given string with specified indices.
(Completed)
*/
void swapCharactersOfStringAtIndices(char str[], int index1, int index2)
{
    str[index1] = str[index1] + str[index2];
    str[index2] = str[index1] - str[index2];
    str[index1] = str[index1] - str[index2];
}

/*
A37.5 Write a function to check whether a given string is an alphanumeric string or not.
(Alphanumeric string must contain at least one alphabet and one digit).
(Completed)
*/
int isStringAlphanumeric(char str[])
{
    int i, alphabetCount = 0, digitCount = 0;
    for(i = 0; str[i]; i++)
    {
        if(str[i] >= 65 && str[i] <= 90 || str[i] >= 97 && str[i] <= 122)
            alphabetCount++;
        else if(str[i] >= 48 && str[i] <= 57)
            digitCount++;
    }
    if(alphabetCount && digitCount)
        return 1;
    return 0;
}

int main()
{
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\r\n")] = 0;
    // printf("Vowels count in string \"%s\" is %d", str, vowelsCountinString(str));

    // char ch;
    // int isCharFoundInString;
    // int isCharFoundInStrBtw2Inds;
    // printf("Enter character whose first occurence is to be checked: ");
    // scanf("%c", &ch);
    // int i1 = 4, i2 = 8;
    // isCharFoundInString = indexOfFirstOccurenceOfCharacterinString(str, ch);

    // isCharFoundInStrBtw2Inds = indexOfFirstOccurenceOfCharacterinStringBtwIndices(str, ch, i1, i2);
    // if(isCharFoundInStrBtw2Inds != -1)
    //     printf("First occurence of character \'%c\' found in string \"%s\" between indices %d & %d at index %d", ch, str, i1, i2, isCharFoundInStrBtw2Inds);
    // else
    //     printf("Character \'%c\' not found in string \"%s\" between indices %d & %d", ch, str, i1, i2);
    
    // printf("Entered string is \"%s\"\n", str);
    // swapCharactersOfStringAtIndices(str, 4, 7);
    // printf("String after swapping characters is \"%s\"\n", str);

    if(isStringAlphanumeric(str))
        printf("String \"%s\" is alphanumeric.\n", str);
    else
        printf("String \"%s\" is not alphanumeric.\n", str);
    return 0;
}
