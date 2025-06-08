/* A20.3 Write a program to check whether a given character is uppercase alphabet  or lower case alphabet
or some other special character, using switch case statenment.

(Completed)
*/

#include<stdio.h>
int main()
{
    char ch;
    printf("Enter a character: ");
    scanf("%c", &ch);
    switch (ch)
    {
    case 'A' ... 'Z':
        printf("Entered character is upper case alphabet.");
        break;
    case 'a' ... 'z':
        printf("Entered character is lower case alphabet.");
        break;
    default:
        printf("Entered character is some other special character.");
        break;
    }
    return 0;
}

