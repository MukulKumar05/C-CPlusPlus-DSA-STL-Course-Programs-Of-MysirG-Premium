/* A 19.3 Write a program which takes the day number of a week and displays a unique greeting message
 for the day.
 (Done)
 */ 

#include<stdio.h>
int main()
{
    int dayNumber;
    printf("Enter day number: ");
    scanf("%d", &dayNumber);
    switch (dayNumber)
    {
    case 1:
        printf("Happy Sunday");
        break;
    case 2:
        printf("Happy Monday");
        break;
    case 3:
        printf("Happy Tuesday");
        break;
    case 4:
        printf("Happy Wednesday");
        break;
    case 5:
        printf("Happy Thursday");
        break;
    case 6:
        printf("Happy Friday");
        break;
    case 7:
        printf("Happy Saturday");
        break;
    default:
        printf("Invalid day number entered ! Please enter correct day number from 1 to 7");
        break;
    }
    return 0;
}

