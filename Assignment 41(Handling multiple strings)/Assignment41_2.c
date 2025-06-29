#include<stdio.h>
#include<string.h>

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

int frequencyOfCharacterInString(char str[], char ch)
{
    int j, occurCount = 0;
    for(j = 0; str[j]; j++)
        if(ch == str[j])
            occurCount++;
    return occurCount;
}

/*
A41.2 Write a function to return the most repeating character in a list of strings.
(Completed)
*/
char mostRepeatingCharacterInListOfStrings(char strs[50][100])
{
    char str[5000] = "\0", maxFreqChar;
    int i, j, k = 0, strsCount = stringsCountin2DCharArray(strs), maxFreq, currentCharFreq;
    for(i = 0; i < strsCount; i++)
    {
        for(j = 0; strs[i][j]; j++, k++)
        {
            str[k] = strs[i][j];
        }
    }

    // printf("Combined string is \"%s\"", str);

    /* Storing unique characters in string unique[]*/
    char unique[256] = {str[0]};
    int ub = 0, occurCount;
    for(i = 1; str[i]; i++)
    {
        for(j = 0; j <= ub; j++)
            if(str[i] == unique[j])
                break;
        if(j > ub)        
            unique[++ub] = str[i];
    }

    // printf("Unique string characters are \"%s\"", unique);

    // finding character with maximum frequency in str[]
    maxFreq = frequencyOfCharacterInString(str, unique[0]);
    maxFreqChar = unique[0];
    for(i = 1; unique[i]; i++)
    {
        currentCharFreq = frequencyOfCharacterInString(str, unique[i]);
        if(currentCharFreq > maxFreq)
        {
            maxFreq = currentCharFreq;
            maxFreqChar = unique[i];
        }
    }
    return maxFreqChar;

}

int main()
{
    char strs[50][100] = {"Vijay", "Kanta", "Manju", "Anju", "Mukul"};
    char mostRepeatingChar = mostRepeatingCharacterInListOfStrings(strs);
    printf("Most repeating character (first occurence) in list of strings is \'%c\'", mostRepeatingChar);
    return 0;
}