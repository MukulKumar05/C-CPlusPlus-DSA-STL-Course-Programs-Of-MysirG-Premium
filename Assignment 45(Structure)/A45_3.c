#include<stdio.h>
#include<string.h>

/*
A45.3 Write a program to store information of n students and display them using structure

(Completed)
*/

struct Student
{
    int rollNumber;
    char name[100];
    char class[20];
    char section;
};

void displayStudentData(struct Student s)
{
    printf("\nRoll Number: %d", s.rollNumber);
    printf("\nName: %s", s.name);
    printf("\nClass: %s", s.class);
    printf("\nSection: %c", s.section);
}

void studentDataInput(struct Student* s)
{
    printf("Enter roll number: ");
    scanf("%d", &(s->rollNumber));
    fflush(stdin);
    printf("Enter name: ");
    fgets(s->name, sizeof(s->name), stdin);
    s->name[strcspn(s->name, "\r\n")] = 0;
    printf("Enter class: ");
    fgets(s->class, sizeof(s->class), stdin);
    s->class[strcspn(s->class, "\r\n")] = 0;
    printf("Enter section: ");
    scanf("%c", &(s->section));
}

int main()
{
    struct Student s[10];
    int i;
    printf("Students Data Input:\n");
    for(i = 0; i < 10; i++)
    {
        printf("Enter data of student %d:\n", i + 1);
        studentDataInput(&s[i]);
    }
    printf("\nAll entered students data is:\n");
    for(i = 0; i < 10; i++)
    {
        displayStudentData(s[i]);
    }
    return 0;
}