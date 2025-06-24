#include<stdio.h>
#include<string.h>

/*
A36.1 Write a function to calculate length of the string.
(Completed)
*/
int stringLength(char str[])
{
    int i; 
    for(i = 0; str[i]; i++);
    return i;
}

/*
A36.2 Write a function to reverse a string.
(Completed)
*/
void reverseString(char str[])
{
    int i, strLength, rightIndex;
    strLength = strlen(str);
    for(i = 0, rightIndex = strLength - 1; i < strLength / 2; i++, rightIndex--)
    {
        // in this loop block, 2 characters of string are swapped in every iteration
        // using swapping without using 3rd variable
        str[i] = str[i] + str[rightIndex];
        str[rightIndex] = str[i] - str[rightIndex];
        str[i] = str[i] - str[rightIndex];
    }
}

/*
A36.3 Write a function to compare two strings.
(Completed)
*/
int stringCompare(char s1[], char s2[])
{
    int i;
    for(i = 0; s1[i] || s2[i]; i++)
    {
        if(s1[i] > s2[i])
            return 1;
        else if(s1[i] < s2[i])
            return -1;
    }
    return 0;
}

/*
A36.4 Write a function to transform string into uppercase.
(Completed)
*/
void tranfromStringToUpperCase(char str[])
{
    int i;
    for(i = 0; str[i]; i++)
        if(str[i] >= 97 && str[i] <= 122)
            str[i] -= 32;
}

/*
A36.5 Write a function to transform a string into lowercase.
(Completed)
*/
void tranfromStringToLowerCase(char str[])
{
    int i;
    for(i = 0; str[i]; i++)
        if(str[i] >= 65 && str[i] <= 90)
            str[i] += 32;
}


int main()
{
    char s[100] = {'\0'};
    char sNew[100] = {'\0'};
    printf("Enter string: ");
    fgets(s, sizeof(s), stdin);
    /* Refer W3 schools website to study about strcspn function*/
    s[strcspn(s, "\r\n")] = 0;
    
    // printf("Length of string \"%s\" is %d", s, stringLength(s));
    
    // reverseString(s);
    // printf("String after reversing is \"%s\"", s);

    // printf("Enter second string: ");
    // fgets(sNew, sizeof(sNew), stdin);
    /* Refer W3 schools website to study about strcspn function*/
    // sNew[strcspn(sNew, "\r\n")] = 0;

    // int stringCompareResult = stringCompare(s, sNew);
    // printf("String comparison result is %d", stringCompareResult);

    tranfromStringToLowerCase(s);
    printf("String in lower case is \"%s\"", s);
    return 0;
}
