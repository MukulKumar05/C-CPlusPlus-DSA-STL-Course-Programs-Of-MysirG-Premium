/* A20.4 Write a program to check whether a given character is vowel or consonant or some other
special character, using switch case statement.

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
    {
        switch (ch)
        {
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            printf("Entered character is a vowel.");
            break;
        default:
            printf("Entered character is a consonant.");
        }
        break;
    }
    case 'a' ... 'z':
    {
        switch (ch)
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            printf("Entered character is a vowel.");
            break;
        default:
            printf("Entered character is a consonant.");
        }
        break;
    }
    default:
        printf("Entered character is some other special character.");
        break;
    }
    return 0;
}

