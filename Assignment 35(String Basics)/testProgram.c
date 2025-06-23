#include<stdio.h>

int main()
{
    char ch1, ch2;
    printf("Enter char 1: ");
    scanf("%c", &ch1);
    fflush(stdin);
    printf("Enter char 2: ");
    scanf("%c", &ch2);
    printf("Before swapping: \n");
    printf("Char 1: %c\n", ch1);
    printf("Char 2: %c\n", ch2);
    ch1 = ch1 + ch2;
    ch2 = ch1 - ch2;
    ch1 = ch1 - ch2;
    printf("After swapping: \n");
    printf("Char 1: %c\n", ch1);
    printf("Char 2: %c\n", ch2);
    return 0;
}