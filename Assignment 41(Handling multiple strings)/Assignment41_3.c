#include<stdio.h>
#include<string.h>

int isCharinString(char name[], char ch)
{
    int i;
    for(i = 0; name[i]; i++)
        if(name[i] == ch)
            return 1;
    return 0;
}

/*
A41.3 Write a function to check whether a pair of strings are anagram or not. Both the
strings are stored in a 2d char array.

Meaning of anagram ->
An anagram in the context of strings refers to two strings that contain the same characters, 
but in a different order. In other words, one string can be formed by rearranging the 
letters of the other. 

(Completed)
*/
int areStringsAnagram(char strs[2][100])
{
    int i, j;
    if(strcmp(strs[0], strs[1]))
    {
        // checking whether all characters of first string are present in second string
        for(i = 0; strs[0][i]; i++)
        {
            if(isCharinString(strs[1], strs[0][i]) == 0) // character in 1 string not found in another string
                return 0;  
        }

        // checking whether all characters of second string are present in first string
        for(i = 0; strs[1][i]; i++)
        {
            if(isCharinString(strs[0], strs[1][i]) == 0) // character in 1 string not found in another string
                return 0;  
        }

        return 1;

    }
    return 0; // strings order is same. So, strings are not anagram strings.
}

int main()
{
    char strs[2][100] = {"no", "on"};
    if(areStringsAnagram(strs))
        printf("Strings \"%s\" and \"%s\" are anagram.", strs[0], strs[1]);
    else
        printf("Strings \"%s\" and \"%s\" are not anagram.", strs[0], strs[1]);
    return 0;
}