#include<iostream>
using namespace std;

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
A6.5 Define a function to print all the prime factors of a given number.
[for example num=36, prime factors are 2, 3]
(Completed)
*/
void printAllUniquePrimeFactorsofNumber(int number)
{
    int i;
    cout<<"Prime factors of "<<number<<" are: ";
    if(isPrimeNumber(number))
        cout<<number;
    else
    {
        for(i = 2; i <= number / 2; i++)
        {
            if(isPrimeNumber(i) && number % i == 0)
                cout<<i<<", ";
        }
        cout<<"\b\b  ";
    }
}



int main()
{
    int n = 36;
    printAllUniquePrimeFactorsofNumber(n);
    cout<<endl;
    return 0;
}