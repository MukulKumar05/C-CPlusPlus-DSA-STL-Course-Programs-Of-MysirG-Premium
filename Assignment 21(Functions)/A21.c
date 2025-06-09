/* A21.1 Write a function to calculate the area of a circle. (TSRS)
A21.2 Write a function to calculate simple interest. (TSRS)
A21.3 Write a function to check whether a given number is even or odd. Return 1 if the number
is even, otherwise return 0. (TSRS)
A21.4 Write a function to print first N natural numbers (TSRN)
A21.5 Write a function to print first N odd natural numbers. (TSRN)
*/

#include<stdio.h>
// A21.1 (Completed)
float CircleArea(float radius)
{
    return 3.14 * radius * radius;
}

// A21.2 (Completed)
float simpleInterest(float principal, float rate, float time)
{
    return (principal * rate * time) / 100;
}

// A21.3 (Completed)
int isEvenNumber(int number)
{
    if(number % 2)
        return 0;
    else
        return 1;
}

// A21.4 (Completed)
void printFirstNNaturalNumbers(int N)
{
    int i;
    for(i = 1; i <= N; i++)
    {
        printf("%d ", i);
    }  
}

// A21.5 (Completed)
void printFirstNOddNaturalNumbers(int N)
{
    int i;
    for(i = 1; i <= N; i++)
    {
        printf("%d ", 2 * i - 1);
    }
}

int main()
{
    float rd = 7, p = 100000, rt = 7, t = 3;
    //printf("Area of circle is %f.", CircleArea(rd));
    // printf("Simple interest is %f.", simpleInterest(p, rt, t));
    // if(isEvenNumber(59))
    //     printf("Even number");
    // else
    //     printf("Odd number");

    //printFirstNNaturalNumbers(13);
    printFirstNOddNaturalNumbers(7);
    return 0;
}

