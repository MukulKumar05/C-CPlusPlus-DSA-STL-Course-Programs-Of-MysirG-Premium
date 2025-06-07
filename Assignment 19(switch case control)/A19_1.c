/* A19.1 Write a program which takes the month number as an input and display number of days in that month.*/

#include<stdio.h>
int main()
{
    int monthNumber;
    printf("Enter month number: ");
    scanf("%d", &monthNumber);
    switch (monthNumber)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        printf("Number of days: 31");
        break;
    case 2:
        printf("Number of Days in Non-Leap Year: 28\nNumber of Days in Leap Year: 29");
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        printf("Number of days: 30");
        break;
    default:
        printf("Invalid month number entered ! Please enter number from 1 to 12");
        break;
    }
    return 0;
}
