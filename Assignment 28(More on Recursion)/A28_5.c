#include<stdio.h>

/*A28.5 Write a program in C to 
calculate the power of any number
using recursion. 
(Completed)
*/
int numberRaisedToPower(int base, int power)
{
    if(power == 0)
        return 1;
    return base * numberRaisedToPower(base, power - 1);  
}
int main()
{
    int x = 8, p = 2;
    printf("%d^%d = %d", x, p, numberRaisedToPower(x, p)); 
    return 0;
}