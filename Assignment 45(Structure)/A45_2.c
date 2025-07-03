#include<stdio.h>

/*
A45.2 Write a program to store information of 10 students and display them using
structure.

(Completed)
*/

struct Student
{
    int rollNumber;
    char name[100];
    char class[20];
    char section;
};

int main()
{
    struct Student s[10] = {
        {1, "Vijay", "12", 'B'},
        {2, "Mukul", "5", 'D'},
        {3, "Manju", "8", 'C'},
        {4, "Kanta", "8", 'D'},
        {5, "Anju", "9", 'A'},
        {6, "Bhumik", "Nursery", 'B'},
        {7, "Komal", "LKG", 'A'},
        {8, "Pradeep", "UKG", 'C'},
        {9, "Rakesh", "1", 'D'},
        {10, "Sanjay", "2", 'A'}
    };
    int i;
    printf("Students Data is:\n");
    for(i = 0; i < 10; i++)
    {
        displayStudentData(s[i]);
    }
    return 0;
}