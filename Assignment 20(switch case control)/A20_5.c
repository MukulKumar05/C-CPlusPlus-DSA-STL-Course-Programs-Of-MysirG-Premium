/* A20.5 Write a menu driven program with the following options:
1. Calculate LCM of two numbers
2. Calculate sum of the digits of a number
3. Volume of a cuboid
4. Check whether a given number is Prime or not
5. Exit

(Completed)
*/

#include<stdio.h>
int main()
{
    int choice = 0;
    while (choice != 5)
    {
        printf("Select your choice:\n1. Calculate LCM of two numbers\n");
        printf("2. Calculate sum of the digits of a number\n3. Volume of a cuboid\n");
        printf("4. Check whether a given number is Prime or not\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            int n1, n2, lcm, i = 2;
            printf("Enter two numbers to find their LCM: ");
            scanf("%d%d", &n1, &n2);

            // if any one number is 0
            if(n1 == 0 && n2 || n1 && n2 == 0)
                printf("LCM is undefined.");
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
                printf("LCM is %d.", lcm);
            }
            break;
        }
        case 2:
        {
            int number, num, sum = 0;
            printf("Enter a number to find some of its digits: ");
            scanf("%d", &number);
            num = number;
            while(num)
            {
                sum += num % 10;
                num /= 10;
            }
            printf("Sum of digits of %d is %d.", number, sum);
            break;
        }
        case 3:
        {
            float length, breadth, height;
            printf("Enter length, breadth and height of cuboid: ");
            scanf("%f%f%f", &length, &breadth, &height);
            printf("Volume of cuboid is %f.", length * breadth * height);
            break;
        }
        case 4:
        {
            int number, i = 2;
            printf("Enter a number to check whether the number is prime or not: ");
            scanf("%d", &number);
            while(number > i)
            {
                if(number % i == 0)
                    break;
                i++;
            }
            if(number == i)
                printf("%d is a prime number.", number);
            else
                printf("%d is not a prime number.", number);
            break;
        }
        case 5:
        break;
        default:
            printf("Please enter correct choice number from 1 to 5.\n");
            break;
        }
    }
    return 0;
}