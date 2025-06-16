#include<stdio.h>

/*A28.1 Write a recursive function 
to calculate factorial of
a given number.
(Completed)
*/
int factorial(int n)
{
    if(n < 0)
        return -1;
    if(n == 1 || n == 0)
        return 1;  
    return n * factorial(n - 1);
}

/*A28.2 Write a recursive function 
to calculate HCF of 2 numbers.
(Completed) */
int smaller(int n1, int n2) 
{
    if(n1 < n2)
        return n1;
    return n2;  
}
int isPrime(int n)
{
    int i;
    for(i=2; i<=n/2; i++)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}
int nextPrimeAfter(int n) 
{
    while(!isPrime(++n)); 
    return n;
}
int hcf(int n1, int n2)
{
    int i=2, s=smaller(n1,n2);
    while(i<=s)
    {
        if(n1%i==0 && n2%i==0)
            return i*hcf(n1/i, n2/i);
        i=nextPrimeAfter(i); 
    }
    return 1;
}

/*A28.3 Write a recursive function to
print first N terms of fibonacci series. 
(Completed)
*/
 int nthTermOfFibonacciSeries(int N)
{
    if(N <= 0)
        return -1;
    if(N == 1)
        return 0;
    else if(N == 2)
        return 1;
    return nthTermOfFibonacciSeries(N-1) + nthTermOfFibonacciSeries(N-2);
}

void printFirstNTermsOfFibonacciSeries(int N)
{
    if(N<=0)
        printf("Incorrect value passed! Please provide positive value of N. ");
    if(N>1)
        printFirstNTermsOfFibonacciSeries(N-1);
    printf("%d ", nthTermOfFibonacciSeries(N));     
}



