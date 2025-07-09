#include<iostream>
using namespace std;

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
/*
A4.1 Define a C++ function to print all prime numbers between two given numbers.
(Completed)
*/
void printAllPrimeNumbersBetweenNumbers(int num1, int num2)
{
    int i;
    cout<<"All Prime numbers between "<<num1<<" and "<<num2<<" are:"<<endl;
    for(i = num1 + 1; i < num2; i++)
    {
        if(isPrimeNumber(i))
            cout<<i<<", ";
    }
    cout<<"\b\b  ";
}

int greaterNumber(int n1, int n2)
{
    if(n1 > n2)
        return n1;
    return n2;
}
/*
A4.2 Define a C++ function to find the highest value digit in a given
number.
(Completed)
*/
int highestValueDigitInNumber(int number)
{
    if(number / 10)
        return greaterNumber(highestValueDigitInNumber(number / 10), number % 10);
    return number % 10; 
}

/*
A4.3 Define a C++ function to calculate x raised to the power y.
(Completed)
*/
int numberRaisedToPower(int x, int y)
{
    if(y == 0)
        return 1;
    return x * numberRaisedToPower(x, y - 1);  
}

/*
A4.4 Define a C++ function to print Pascal Triangle up to N lines.
(Completed)
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
    cout<<"Pascal Triangle of "<<linesCount<<" lines is:"<<endl;
    for(i = 0; i < linesCount; i++)
    {
        for(j = 0; j < 2 * linesCount - 1; j++)
        {
            if(pascalTriangle[i][j] == 0)
                cout<<" ";
            else
                cout<<pascalTriangle[i][j];
        }
        cout<<endl;
    }
}

/*
A4.5 Define a C++ function to check whether a given number is a term in a Fibonacci series or not.
(Completed)
*/
int isNumberFibonacciTerm(int number)
{
    int f1 = 0, f2 = 1, f3 = -1;
    if(number < 0)
        return 0;
    else if(number == 0)
        return 1;
    else
    {
        while(f3 < number)
        {
            f3 = f1 + f2;
            f1 = f2;
            f2 = f3;
        }
        if(f3 == number)
            return 1;
        else
            return 0;
    }
}

int main()
{
    // printAllPrimeNumbersBetweenNumbers(7, 29);
    int number = 8;
    // cout<<"Highest value digit in number "<<number<<" is "<<highestValueDigitInNumber(number)<<"."<<endl;
    // int a = 2, b = 4;
    // cout<<a<<"^"<<b<<" = "<<numberRaisedToPower(a, b)<<endl;
    // printPascalTriangleofLines(7);
    if(isNumberFibonacciTerm(number))
        cout<<number<<" is a fibonacci number."<<endl;
    else
        cout<<number<<" is not a fibonacci number."<<endl;
    return 0;
}
