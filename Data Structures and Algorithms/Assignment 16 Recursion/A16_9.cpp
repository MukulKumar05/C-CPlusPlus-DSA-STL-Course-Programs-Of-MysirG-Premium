#include<iostream>
using namespace std;

/*
A16.9 Write a recursive function to calculate HCF of two numbers.

Problem Summary: define recursive function hcf(int num1, int num2)
(Completed)
*/
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

int main()
{
    
    return 0;
}