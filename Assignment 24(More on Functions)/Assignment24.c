#include<stdio.h>

// function to check whether a given number is Prime or not. (TSRS)
// (Completed)
int isPrimeNumber(int number)
{
    int i;
    for(i = 2; i <= number / 2; i++)
    {
        if(number % i == 0)
            return 0;
    }
    return 1;
}

/* A24.1 Write a function to print all Prime numbers between two given numbers. (TSRN)
(Completed)
*/

void printAllPrimeNumbersBetweenNumbers(int num1, int num2)
{
    int i;
    printf("All Prime numbers between %d and %d are:\n", num1, num2);
    for(i = num1 + 1; i < num2; i++)
    {
        if(isPrimeNumber(i))
        printf("%d, ", i);
    }
    printf("\b\b  ");
}

/* A24.2 Write a function to print first N terms of Fibonacci Series. (TSRN)
(Completed)*/
void printFirstNTermsOfFibonacciSeries(int N)
{
    int f1 = 0, f2 = 1, i = 1, fi;
    if(N <= 0)
        printf("Its a non-natural number. Please provide natural number !");
    printf("First %d terms of fibonacci series are:\n", N);
    while (i <= N)
    {
        printf("%d, ", f1);
        i++;
        fi = f1 + f2;
        f1 = f2;
        f2 = fi;
    }
    printf("\b\b  ");
}

/* A24.3 Write a function to print pascal triangle. (TSRN)
(Completed)
(Note-> need to improve alignment when triangle elements are of more than 1 digit)
*/

void printPascalTriangleofLines(int linesCount)
{
    int pascalTriangle[100][199], i, j;

    // entering values in pascal triangle
    for(i = 0; i < linesCount; i++)
    {
        for(j = 0; j < 2 * linesCount - 1; j++)
        {
            if(j >= linesCount - 1 - i && j <= linesCount - 1 + i)
            {
                if(j == linesCount - 1 - i || j == linesCount - 1 + i)
                    pascalTriangle[i][j] = 1;
                else
                    pascalTriangle[i][j] = pascalTriangle[i - 1][j -1] + pascalTriangle[i - 1][j + 1];
            }
            else
                pascalTriangle[i][j] = 0;
        }
    }

    // printing pascal triangle
    printf("Pascal Triangle of %d lines is:\n", linesCount);
    for(i = 0; i < linesCount; i++)
    {
        for(j = 0; j < 2 * linesCount - 1; j++)
        {
            if(pascalTriangle[i][j] == 0)
                printf(" ");
            else
                printf("%d", pascalTriangle[i][j]);
        }
        printf("\n");
    }
}

/* A24.4 Write a function to print all Armstrong numbers between two given numbers. (TSRN)
(Completed)
*/
int numberRaisedToPower(int base, int power)
{
    int pro = base;
    if(power == 0)
        return 1;
    else if(power < 0)
        return 1 / numberRaisedToPower(base, -power);
    else if(power == 1)
        return base;
    else
    {
        while (power - 1)
        {
            pro *= base;
            power--;
        }
        return pro;
    }
}

int isArmstrongNumber(int number)
{
    int n, count = 0, sum = 0;
    n = number;
    while (n)
    {
        count++;
        n /= 10;
    }
    n = number;
    while (n)
    {
        sum += numberRaisedToPower(n % 10, count);
        n /= 10;
    }
    if(sum == number)
        return 1;
    else
        return 0;
}

void printAllArmstrongNumbersBetweenNumbers(int num1, int num2)
{
    int i;
    printf("All armstrong numbers between %d and %d are:\n", num1, num2);
    for(i = num1 + 1; i < num2; i++)
    {
        if(isArmstrongNumber(i))
            printf("%d, ", i);
    }
    printf("\b\b  ");
}

/* A24.5 Write a function to find the sum of first N terms of the series 1!/1 +
2!/2 + 3!/3+ 4!/4 + 5!/5 ... n!/n . (TSRS)
(Completed)
*/
int factorial(int number)
{
    int i, fact = 1;
    if(number == 0)
        return 1;
    else
    {
        for(i = 1; i <= number; i++)
        {
            fact *= i;
        }
        return fact;
    }
}

int sumOfFirstNTermsOfSeries(int n)
{
    int i, sum = 0;
    for(i = 1; i <= n; i++)
        sum += factorial(i) / i;
    return sum;
}

int main()
{
    // printAllPrimeNumbersBetweenNumbers(11, 19);
    // printFirstNTermsOfFibonacciSeries(7);
    // printPascalTriangleofLines(5);
    // printAllArmstrongNumbersBetweenNumbers(1, 2500);

    int x = 5;
    printf("Sum Of first %d terms Of series is %d.", x, sumOfFirstNTermsOfSeries(x));
    return 0;
}
