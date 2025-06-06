#include<stdio.h>
int main()
{
    int i, j, k;
    for (i = 1; i <= 5; i++)
    {
        k = 0;
        for(j = 1; j <= 9; j++)
        {
            if(j >= 6 - i && j <= 4 + i)
            {
                if(i % 2)
                {
                    if((j + i) % 2 == 0)
                    {
                        if(j <= 5)
                        {
                            k++;
                            printf("%d", k);
                        }
                        else
                        {
                            k--;
                            printf("%d", k);
                        }
                    }
                    else
                        printf(" ");
                }
                else
                {
                    if((j + i) % 2 == 0)
                    {
                        if(j <= 5)
                        {
                            k++;
                            printf("%d", k);
                        }
                        else
                        {
                            printf("%d", k);
                            k--;
                        }
                    }
                    else
                        printf(" ");
                }
            }
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
