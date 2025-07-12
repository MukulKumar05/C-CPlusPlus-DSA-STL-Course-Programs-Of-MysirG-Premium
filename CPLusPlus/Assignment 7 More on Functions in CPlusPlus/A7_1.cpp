#include<iostream>
using namespace std;

/*
7.1 Define a function to calculate HCF of two numbers.
(Completed)
*/
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
        cout<<"HCF is not defined.";
        return -1;
    }

    // if any one number is 0, then other non zero number is HCF
    else if(n1 == 0 && n2)
        return n2;
    else if(n2 == 0 && n1)
        return n1;

    // if numbers are same, then print any one number as hcf
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

int main()
{
    int a = 66, b = 60;
    cout<<"HCF("<<a<<", "<<b<<") = "<<hcf(a, b)<<endl;
    return 0;
}
