#include<stdio.h>
#include<string.h>

/*
A45.4 Write a program to enter the marks of 5 students in Chemistry, Mathematics and
Physics (each out of 100) using a structure named Marks having elements roll no.,
name, chem_marks, maths_marks and phy_marks and then display the percentage
of each student.

(Completed)
*/

struct Marks
{
    int rollNumber;
    char name[100];
    float chem_marks;
    float maths_marks;
    float phy_marks;
};

void displayStudentData(struct Marks s)
{
    printf("\nRoll Number: %d", s.rollNumber);
    printf("\nName: %s", s.name);
    printf("\nChemistry Marks: %f", s.chem_marks);
    printf("\nMathematics Marks: %f", s.maths_marks);
    printf("\nPhysics Marks: %f", s.phy_marks);
}

float studentPercentage(struct Marks s)
{
    return (s.chem_marks + s.maths_marks + s.phy_marks) / 3.0;
}

void studentDataInput(struct Marks* s)
{
    printf("Enter roll number: ");
    scanf("%d", &(s->rollNumber));
    fflush(stdin);
    printf("Enter name: ");
    fgets(s->name, sizeof(s->name), stdin);
    s->name[strcspn(s->name, "\r\n")] = 0;
    printf("Enter Chemistry Marks: ");
    scanf("%f", &(s->chem_marks));
    printf("Enter Mathematics Marks: ");
    scanf("%f", &(s->maths_marks));
    printf("Enter Physics Marks: ");
    scanf("%f", &(s->phy_marks));
}

int main()
{
    struct Marks s[5];
    int i;
    printf("Students Data Input:\n");
    for(i = 0; i < 5; i++)
    {
        printf("Enter data of student %d:\n", i + 1);
        studentDataInput(&s[i]);
    }
    printf("All students percentages are:\n");
    for(i = 0; i < 5; i++)
        printf("\nPercentage of student %d: %f", i + 1, studentPercentage(s[i]));
    return 0;
}