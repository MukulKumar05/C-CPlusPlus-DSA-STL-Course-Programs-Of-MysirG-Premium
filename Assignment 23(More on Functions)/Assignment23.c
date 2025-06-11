#include<stdio.h>

// A23.1 Write a function to calculate LCM of two numbers. (TSRS)
// (Completed)
int lcm(int n1, int n2)
{
    int lcm, i = 2;
    
    // if any one number is 0
    if(n1 == 0 && n2 || n1 && n2 == 0)
    {
        printf("LCM is undefined.");
        return -1;
    }
    else
    {
        // converting negative numbers (if any) into positive
        if(n1 < 0)
            n1 = n1 * -1;
        if(n2 < 0)
            n2 = n2 * -1;

        // we will pick {greater number and its multiples} and will check the divisibility of each multiple of greater number with smaller number.
        if(n1 > n2)
        {
            lcm = n1;
            while(lcm % n2) // That smallest multiple of greater number (lcm) which is completely divisible by smaller number (n2) will be the LCM(n1, n2)
            {
                lcm = n1 * i;
                i++;
            }
        }
        else
        {
            lcm = n2;
            while(lcm % n1)
            {
                lcm = n2 * i;
                i++;
            }
        }
        return lcm;
    }
}

// A23.2 Write a function to calculate HCF of two numbers. (TSRS)
// (Completed)
int hcf(int n1, int n2)
{
    int hcf = 1;
    
    // negative numbers(if any) converted to positive
    if(n1 < 0)
        n1 = n1 * -1;
    if(n2 < 0)
        n2 = n2 * -1;

    // HCF(0,0) is not defined
    if(n1 == 0 && n2 == 0)
    {
        printf("HCF is not defined.");
        return -1;
    }

    // if any one number is 0, then other non zero number is HCF
    else if(n1 == 0 && n2)
        return n2;
    else if(n2 == 0 && n1)
        return n1;

    // if numbers are same, then print any one as hcf
    else if(n1 == n2)
        return n1;

    // the smaller number is picked and all numbers from 2 to this number are divided by n1 and n2 to check divisibility.
    // The last/highest possible factor of smaller number which also divides larger number will be HCF.
    else if(n1 < n2)
    {
        for(int i = n1; i >= 2; i--)
        {
            if(n1 % i == 0 && n2 % i == 0)
            {
                hcf = i;
                break;
            }
        }
        return hcf;
    }
    else
    {
        for(int i = n2; i >= 2; i--)
        {
            if(n1 % i == 0 && n2 % i == 0)
            {
                hcf = i;
                break;
            }
        }
        return hcf;
    }
}

// A23.3 Write a function to check whether a given number is Prime or not. (TSRS)
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

// A23.4 Write a function to find the next prime number of a given number. (TSRS)
// (Completed)
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

// A23.5 Write a function to print first N prime numbers. (TSRN)
// (Completed)
void printFirstNPrimeNumbers(int N)
{
    int num = 2;
    printf("First %d prime numbers are: ", N);
    while(N)
    {
        if(isPrimeNumber(num))
        {
            printf("%d, ", num);
            N--;
        }
        num++;
    }
    printf("\b\b  ");
}



int main()
{
    int num1 = 35, num2 = 21, x = 23;
    // printf("LCM of %d and %d is %d.", num1, num2, lcm(num1, num2));
    // printf("HCF of %d and %d is %d.", num1, num2, hcf(num1, num2));
    // if(isPrimeNumber(x))
    //     printf("%d is a prime number.", x);
    // else
    //     printf("%d is not a prime number.", x);

    // printf("Next prime number after %d is %d.", x, nextPrimeNumberAfter(x));

    printFirstNPrimeNumbers(11);



    return 0;
}
