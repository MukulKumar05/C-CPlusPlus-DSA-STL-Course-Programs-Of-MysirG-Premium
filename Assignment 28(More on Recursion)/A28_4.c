#include<stdio.h>

/*A28.4 Write a program in C to count
the digits of a given number using
recursion. 
(Completed)
*/
 int digitsCount(int n)
 {
     if(n)
         return 1 + digitsCount(n/10);
     return 0;   
 }
int main()
{
    int x = 30900;
    printf("Digits count of %d is %d.", x, digitsCount(x));
    return 0;
}