/* A19.2 Write a menu driven program with the following options:
1. Addition
2. Subtraction
3. Multiplication
4. Division
5. Exit*/

#include<stdio.h>
int main()
{
    int choice, a, b;
    while(choice != 5)
    {
        printf("Mini Calculator:\nSelect one of the options:\n");
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter two numbers: ");
            scanf("%d%d", &a, &b);
            printf("Sum is %d\n\n", a + b);
            break;
        case 2:
            printf("Enter two numbers: ");
            scanf("%d%d", &a, &b);
            printf("Difference is %d\n\n", a - b);
            break;
        case 3:
            printf("Enter two numbers: ");
            scanf("%d%d", &a, &b);
            printf("Product is %d\n\n", a * b);
            break;
        case 4:
            printf("Enter two numbers: ");
            scanf("%d%d", &a, &b);
            printf("Quotient is %d\n\n", a / b);
            break;
        case 5:
            break;
        default:
            printf("Invalid choice entered ! Please enter correct choice.\n\n");
            break;
        }
    }
    return 0;
}