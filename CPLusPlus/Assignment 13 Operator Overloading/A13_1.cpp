#include<iostream>
using namespace std;

/*
A13.1 Define a C++ class fraction
class fraction
{
    long numerator;
    long denominator;
    public:
        fraction(long n=0, long d=0);
}
Define an operator+ to add two fraction objects.
(Completed)
*/
int smallerNumber(int n1, int n2)
{
    if(n1 < n2)
        return n1;
    return n2;
}
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
class fraction
{
    private:
        long numerator;
        long denominator;
    public:
        fraction(long n=0, long d=0)
        {
            numerator = n;
            denominator = d;
        }
        void printFraction()
        {
            cout<<numerator<<"/"<<denominator<<endl;
        }
        void simplifyFraction()
        {
            int i;
            for(i = 2; i <= smallerNumber(numerator, denominator); i++)
            {
                while(numerator % i == 0 && denominator % i == 0)
                {
                    numerator = numerator / i;
                    denominator = denominator / i;
                }
            }
        }
        fraction operator+(fraction f)
        {
            fraction sum;
            simplifyFraction();
            f.simplifyFraction();
            sum.denominator = lcm(denominator, f.denominator);
            sum.numerator = (sum.denominator / denominator) * numerator + (sum.denominator / f.denominator) * f.numerator;
            sum.simplifyFraction();
            return sum;
        }
};

int main()
{
    fraction f1(3, 12), f2(5, 2), fractionSum;
    fractionSum = f1 + f2;
    fractionSum.printFraction();
    return 0;
}
