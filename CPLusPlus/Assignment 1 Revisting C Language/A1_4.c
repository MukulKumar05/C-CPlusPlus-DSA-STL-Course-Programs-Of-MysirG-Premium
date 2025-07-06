/*
A1.4 Write a C function to calculate LCM of two numbers (TSRS).
(Completed)
*/

#include<stdio.h>

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

int main()
{
    int num1 = 35, num2 = 21;
    printf("LCM of %d and %d is %d.", num1, num2, lcm(num1, num2));
    return 0;
}