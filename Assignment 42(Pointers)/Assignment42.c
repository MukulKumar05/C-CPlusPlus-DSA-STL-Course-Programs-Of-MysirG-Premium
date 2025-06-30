#include<stdio.h>
#include<string.h>

/*
A42.1 Write a function to swap values of two int variables (TSRN).
(Completed)
*/
void swapNumbers(int* num1, int* num2)
{
    *num1 = *num1 + *num2;
    *num2 = *num1 - *num2;
    *num1 = *num1 - *num2;
}

/*
A42.2 Write a function to search all occurences of a given character in a given string.
Result of search is a list of indices to be stored in the given array. 
[ void search_all_occurences(char* str, char ch, int* arr); ]

(Completed)
*/
void search_all_occurences(char* str, char ch, int* arr)
{
    int i, j = 0;
    for(i=0; str[i]; i++)
        if(ch == str[i])
        {
            arr[j] = i;
            j++;
        }
    if(arr[0] != -1)
    {
        printf("Character \'%c\' occurs at index(ces):\n", ch);
        for(i = 0; arr[i] != -1; i++)
            printf("%d ", arr[i]);
    }
    else
        printf("Character \'%c\' not found in string.", ch);
}

/*
A42.3 Write a function to convert a given string into uppercase.
(Completed)
*/
void tranfromStringToUpperCase(char *str)
{
    int i;
    for(i = 0; str[i]; i++)
        if(str[i] >= 97 && str[i] <= 122)
            str[i] -= 32;
}

/*
A42.4 Write a function to convert a given string into lowercase.
(Completed)
*/
void tranfromStringToLowerCase(char *str)
{
    int i;
    for(i = 0; str[i]; i++)
        if(str[i] >= 65 && str[i] <= 90)
            str[i] += 32;
}

/*
A42.5 Write a function to extract a substring from a given string with specified start index
(inclusive) and end index (exclusive), and store the extracted string in another char
array. [void extract_string(char *str, int start_index, int end_index, char *result);]

(Completed)
*/
void extract_string(char *str, int start_index, int end_index, char *result)
{
    int i, j;
    for(i = start_index, j = 0; i < end_index; i++, j++)
        result[j] = str[i];
}

int main()
{
    // int a, b;
    // printf("Enter two numbers: ");
    // scanf("%d%d", &a, &b);
    // printf("Numbers before swapping are:- a = %d and b = %d", a, b);
    // swapNumbers(&a, &b);
    // printf("\nNumbers after swapping are:- a = %d and b = %d", a, b);
    
    // char str[100], ch;
    // int a[100] = {-1}, i;
    // for(i = 1; i < 100; i++)
    //     a[i] = -1;
    // printf("Enter a string: ");
    // fgets(str, sizeof(str), stdin);
    // str[strcspn(str, "\r\n")] = 0;
    // printf("Enter a character whose occurences are to be searched in string: ");
    // scanf("%c", &ch);
    // printf("Entered string is \"%s\"", str);
    // printf("\nEntered character is \'%c\'", ch);
    // search_all_occurences(str, ch, a);
    
    // tranfromStringToUpperCase(str);
    // printf("String in upper case is \"%s\"", str);

    // tranfromStringToLowerCase(str);
    // printf("String in lower case is \"%s\"", str);

    char str[100], extractedString[100] = "\0";
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\r\n")] = 0;
    extract_string(str, 10, 15, extractedString);
    printf("Extracted string is \"%s\"", extractedString);
    return 0;
}
