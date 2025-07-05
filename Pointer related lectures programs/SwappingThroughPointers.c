#include<stdio.h>

void swapNumbers(int*, int*); // function declaration

void swapNumbers(int* num1, int* num2)
{
    *num1 = *num1 + *num2;
    *num2 = *num1 - *num2;
    *num1 = *num1 - *num2;
}

int main()
{
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d%d", &a, &b);
    printf("Numbers before swapping are:- a = %d and b = %d", a, b);
    swapNumbers(&a, &b);
    printf("\nNumbers after swapping are:- a = %d and b = %d", a, b);
    printf("\n");
    return 0;
}
