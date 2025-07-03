#include<stdio.h>

/*
A45.1 Write a program to calculate the difference between 2 time periods.

(Completed)
*/

struct timePeriod
{
    int hours;
    int minutes;
    int seconds;
};

struct timePeriod differenceOf2TimePeriods(struct timePeriod t1, struct timePeriod t2)
{
    struct timePeriod diffTime;
    diffTime.hours = t1.hours - t2.hours;
    diffTime.minutes = t1.minutes - t2.minutes;
    diffTime.seconds = t1.seconds - t2.seconds;
    return diffTime;
}

void displayTimePeriod(struct timePeriod t)
{
    printf("\nHours: %d", t.hours);
    printf("\nMinutes: %d", t.minutes);
    printf("\nSeconds: %d", t.seconds);
}

int main()
{
    struct timePeriod t1 = {5, 25, 36}, t2 = {7, 40, 16};
    struct timePeriod differTime = differenceOf2TimePeriods(t1, t2);
    displayTimePeriod(differTime);
    return 0;
}
