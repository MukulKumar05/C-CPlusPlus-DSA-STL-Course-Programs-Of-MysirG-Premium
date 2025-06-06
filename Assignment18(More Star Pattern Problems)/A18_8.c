#include<stdio.h>
int main()
{
    int i, j;
    for(i = 1; i <= 4; i++)
    {
        for(j = 1; j <= 7; j++)
        {
            if(j >= 6 - i && j <= 2 + i)
                printf(" ");
            else
                printf("*");
        }
        printf("\n");
    }
    return 0;
}