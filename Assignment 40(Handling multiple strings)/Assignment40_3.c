#include<stdio.h>
#include<string.h>

/*
A40.3 Write a program to sort 10 city names stored in two dimensional arrays, taken from
the user.
(Completed)
*/
void sort2DCharArray(char cityNames[10][100], int size)
{
   int i, j;
   char temp[100];
   for(i = 0; i < size - 1; i++)
        for(j = i + 1; j < size; j++)
            if(strcmp(cityNames[j], cityNames[i]) == -1)
            {
                /* logic to swap two strings in a 2D array*/
                strcpy(temp, cityNames[j]); 
                strcpy(cityNames[j], cityNames[i]);  
                strcpy(cityNames[i], temp);  
            }
}

int main()
{
    char cities[50][100] = {"Jaipur", "Bhubanweshwar", "Rampur", "Bengaluru", "Agra", "Mumbai", "Coimbatore", "Raipur", "Ludhiana", "Ranchi"};
    int i;
    sort2DCharArray(cities, 10);
    printf("City names after sorting are:\n");
    for(i = 0; i < 10; i++)
    {
        printf("\n\"%s\"", cities[i]);
    }
    return 0;
}