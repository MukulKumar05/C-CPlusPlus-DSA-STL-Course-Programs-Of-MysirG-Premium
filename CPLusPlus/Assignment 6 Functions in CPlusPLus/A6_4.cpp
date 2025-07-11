#include<iostream>
using namespace std;

int nextPrimeNumberAfter(int number)
{
    if(number <= 1)
        return 2;
    else
    {
        int next_prime = number, count = -1;
        while(count)
        {
            count = 0;
            next_prime++;
            for(int i = 2; i <= next_prime / 2; i++)
            {
                if(next_prime % i == 0)
                {
                    count++;
                    break;
                }
            }
        }
        return next_prime;
    }
}

/*
A6.4 Define a function to calculate LCM of three numbers.
(Completed)
*/

int lcmOfThreeNumbers(int n1, int n2, int n3)
{
    int i = 2;
    while(n1 != 1 || n2 != 1 || n3 != 1)
    {
        if(n1 % i == 0 && n2 % i == 0 && n3 % i == 0)
            return i * lcmOfThreeNumbers(n1 / i, n2 / i, n3 / i);
        if(n1 % i == 0 && n2 % i == 0)
            return i * lcmOfThreeNumbers(n1 / i, n2 / i, n3);
        if(n1 % i == 0 && n3 % i == 0)
            return i * lcmOfThreeNumbers(n1 / i, n2, n3 / i);
        if(n2 % i == 0 && n3 % i == 0)
            return i * lcmOfThreeNumbers(n1, n2 / i, n3 / i);
        if(n1 % i == 0)
            return i * lcmOfThreeNumbers(n1 / i, n2, n3);
        if(n2 % i == 0)
            return i * lcmOfThreeNumbers(n1, n2 / i, n3);
        if(n3 % i == 0)
            return i * lcmOfThreeNumbers(n1, n2, n3 / i);
        i = nextPrimeNumberAfter(i);
    }
    return 1;
}

int main()
{
    
    int num1 = 15, num2 = 25, num3 = 40;
    cout<<"LCM("<<num1<<", "<<num2<<", "<<num3<<") = "<<lcmOfThreeNumbers(num1, num2, num3)<<endl;
    return 0;
}