#include<iostream>
#include<string.h>
using namespace std;

/*
A6.2 Define a function to sort an array of strings in ascending or 
descending order depending on bool type argument (true for 
ascending and false for descending). Use default argument to
implement it.
(Completed)
*/
void sort2DCharArray(char arrOfStrs[50][100], int size, bool sortOrder = true)
{
   int i, j;
   char temp[100];
   if(sortOrder == true)
   {
       for(i = 0; i < size - 1; i++)
        for(j = i + 1; j < size; j++)
            if(strcmp(arrOfStrs[j], arrOfStrs[i]) == -1)
            {
                /* logic to swap two strings in a 2D array*/
                strcpy(temp, arrOfStrs[j]); 
                strcpy(arrOfStrs[j], arrOfStrs[i]);  
                strcpy(arrOfStrs[i], temp);  
            } 
   }
   else
   {    
        for(i = 0; i < size - 1; i++)
            for(j = i + 1; j < size; j++)
                if(strcmp(arrOfStrs[i], arrOfStrs[j]) == -1)
                {
                    /* logic to swap two strings in a 2D array*/
                    strcpy(temp, arrOfStrs[j]); 
                    strcpy(arrOfStrs[j], arrOfStrs[i]);  
                    strcpy(arrOfStrs[i], temp);  
                }
   }
   
}

int main()
{
    char cities[50][100] = {"Jaipur", "Bhubanweshwar", "Rampur", "Bengaluru", "Agra", "Mumbai", "Coimbatore", "Raipur", "Ludhiana", "Ranchi"};
    int i;
    sort2DCharArray(cities, 10);
    cout<<"City names after sorting are:"<<endl;
    for(i = 0; i < 10; i++)
        cout<<endl<<"\""<<cities[i]<<"\"";
    return 0;
}