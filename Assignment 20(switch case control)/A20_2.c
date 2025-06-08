/*A20.2 Write a menu driven program with the following options:
1. Factorial of a number
2. Check Even and Odd
3. Area of circle
4. Sum of first N natural numbers
5. Exit

(Completed)
*/

#include<stdio.h>
int main()
{
    int choice = 0;
    while (choice != 5)
    {
        printf("\nCommon Mathematical Operations:\n1. Factorial of a number\n2. Check Even and Odd\n");
        printf("3. Area of circle\n4. Sum of first N natural numbers\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            int i = 1, fact = 1, number;
            printf("Enter a number to find its factorial: ");
            scanf("%d", &number);
            for(i = 1; i <= number; i++)
            {
                fact *= i;
            }
            printf("\n%d! = %d\n", number, fact);
            break;
        }
        case 2:
        {
            int number;
            printf("Enter number to check for even and odd: ");
            scanf("%d", &number);
            if(number % 2)
                printf("\n%d is odd number.\n", number);
            else
                printf("\n%d is even number.\n", number);
            break;
        }
        case 3:
        {
            float radius;
            printf("Enter radius of circle: ");
            scanf("%f", &radius);
            printf("\nArea of circle is %lf", 3.14 * radius * radius);
            break;
        }
        case 4:
        {
            int N, i, sum = 0;
            printf("Enter value of N: ");
            scanf("%d", &N);
            for(i = 1; i <= N; i++)
            {
                sum = sum + i;
            }
            printf("Sum of first %d natural numbers is %d.", N, sum);
            break;
        }
        case 5:
            break;
        default:
            printf("\nPlease enter correct choice number from 1 to 5.\n");
            break;
        }
    }
    
    return 0;
    
}