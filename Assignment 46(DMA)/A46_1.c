#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
A46.1 Define a function to input variable length string and store it in an array without
memory wastage.

(Completed)
*/

/* Earlier logic before watching tutorial.*/
char* inputString()
{
    int strLen;
    printf("Enter length of string which you want to enter: ");
    scanf("%d", &strLen);
    fflush(stdin);
    char* str = (char*) calloc(strLen, 1);
    printf("Enter string: ");
    fgets(str, strLen, stdin);
    str[strcspn(str, "\r\n")] = 0;
    return str;
}

/* 
Logic by me after watching tutorial (Mysirg Solution)
(Completed)
*/
char* inputStringNew()
{
    char *p = NULL, *q = NULL, ch;
    int i, size = 1;
    printf("Enter a string: ");
    p = (char*) malloc(size);
    while(1)
    {
        ch = getchar();
        if(ch == '\n')
            break;
        if(q)
        {
            p = (char*) malloc(size);
            for(i = 0; i < size; i++)
            {
                p[i] = q[i];
            }
            p[i - 1] = ch;
            free(q);
            q = NULL;
        }
        else
            *p = ch;
        q = (char*) malloc(size + 1);
        for(i = 0; i < size; i++)
        {
            q[i] = p[i];
        }
        q[i] = '\0';
        size++;
        free(p);
        p = NULL;
    }
    return q;
}

int main()
{
    // char* st = inputString();
    // printf("Entered string is \"%s\"", st);
    char *st = inputStringNew();
    printf("Entered string is \"%s\"", st);
    return 0;
}
