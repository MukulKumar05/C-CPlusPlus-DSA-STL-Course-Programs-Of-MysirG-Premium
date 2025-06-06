#include<stdio.h>
int main()
{
    int i, j;
    char k;
    for(i = 1; i <= 4; i++)
    {
        k = 64;
        for(j = 1; j <= 7; j++)
        {
            if(j >= 6 - i && j <= 2 + i)
                printf(" ");
            else if (j <= 4)
            {
                k++;
                printf("%c", k);
            }
            else if(i == 1 && j > 4)
            {
                k--;
                printf("%c", k);
            }
            else
            {
                printf("%c", k);
                k--;
            }
        }
        printf("\n");
    }
    return 0;
}