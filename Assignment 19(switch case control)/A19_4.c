/* Write a menu driven program with the following options:
1. Check whether a given set of three numbers are lengths of an isosceles triangle
or not.
2. Check whether a given set of three numbers are lengths of sides of a right
angled triangle or not.
3. Check whether a given set of three numbers are lenghts of sides of an 
equilateral triangle or not.
4. Exit 

(Done)
*/

#include<stdio.h>
int main()
{
    int choice;
    float s1, s2, s3;
    while(choice != 4)
    {
        printf("Triangle type checks\nSelect one of the following options:\n");
        printf("1. Check whether a given set of three numbers are lengths of an isosceles triangle or not\n");
        printf("2. Check whether a given set of three numbers are lengths of sides of a right angled triangle or not.\n");
        printf("3. Check whether a given set of three numbers are lenghts of sides of an equilateral triangle or not.\n");
        printf("4. Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter lengths of sides of triangle: ");
            scanf("%d%d%d", &s1, &s2, &s3);
            if(s1 == s2 || s2 == s3 || s3 == s1)
                printf("Its an isosceles triangle.\n");
            else
                printf("Its not an isosceles triangle.\n");
            break;
        case 2:
            printf("Enter lengths of sides of triangle: ");
            scanf("%d%d%d", &s1, &s2, &s3);
            if(s1*s1 == s2*s2 + s3*s3 || s2*s2 == s1*s1 + s3*s3 || s3*s3 == s1*s1 + s2*s2)
                printf("Its a right angled triangle.\n");
            else
                printf("Its not a right angled triangle.\n");
            break;
        case 3:
            printf("Enter lengths of sides of triangle: ");
            scanf("%d%d%d", &s1, &s2, &s3);
            if(s1 == s2 && s2 == s3)
                printf("Its an equilateral triangle.\n");
            else
                printf("Its not an equilateral triangle.\n");
            break;
        case 4:
            break;
        default:
            printf("Invalid data entered ! Please select correct choice number from 1 to 4.\n");
            break;
        }
    }
    return 0;
}