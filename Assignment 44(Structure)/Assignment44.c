#include<stdio.h>
#include<string.h>

/*
A44.1 Define a structure Employee with member variables id, name, salary.

(Completed)
*/
struct Employee
{
    int id;
    char name[100];
    float salary;
};

/*
A44.2 Write a function to take input employee data from the user. [Refer structure from
question 1 ]

(Completed)
*/
void employeeDataInput(struct Employee* emp)
{
    printf("Enter employee id: ");
    scanf("%d", &(emp->id));
    fflush(stdin);
    printf("Enter employee name: ");
    fgets(emp->name, sizeof(emp->name), stdin);
    emp->name[strcspn(emp->name, "\r\n")] = 0;
    printf("Enter employee salary: ");
    scanf("%f", &(emp->salary));
}

/*
A44.3 Write a function to display employee data. [Refer structure from question 1]

(Completed)
*/
void displayEmployeeData(struct Employee emp)
{
    printf("\nEmployee Details are:\n");
    printf("Employee ID: %d", emp.id);
    printf("\nEmployee Name: %s", emp.name);
    printf("\nEmployee Salary: %f", emp.salary);
}

/*
A44.4 Write a function to find the highest salary employee from a given array of 10
employees. [Refer structure from question 1]

(Completed)
*/
struct Employee highestSalariedEmployee(struct Employee e[], int size)
{
    struct Employee maxSalEmp = e[0];
    int i;
    for(i = 0; i < size; i++)
    {
        if(e[i].salary > maxSalEmp.salary)
            maxSalEmp = e[i];
    }
    return maxSalEmp;
}

/*
A44.5 Write a function to sort employees according to their salaries [Refer structure
from question 1]

(Completed)
*/
void swapEmployeesData(struct Employee* e1, struct Employee* e2)
{
    struct Employee temp;
    temp = *e1;
    *e1 = *e2;
    *e2 = temp;
}

void sortEmployeesBasedOnSalary(struct Employee e[], int Empsize)
{

    int i, j;
    for(i = 0; i < Empsize - 1; i++)
        for(j = i + 1; j < Empsize; j++)
            if(e[j].salary < e[i].salary)
                swapEmployeesData(&e[j], &e[i]);
}

/*
A44.6 Write a function to sort employees according to their names [refer structure from
question 1]

(Completed)
*/
void sortEmployeesBasedOnName(struct Employee e[], int Empsize)
{
    int i, j;
    char temp[100];
    for(i = 0; i < Empsize - 1; i++)
        for(j = i + 1; j < Empsize; j++)
            if(strcmp(e[j].name, e[i].name) == -1)
                swapEmployeesData(&e[j], &e[i]);
}


int main()
{
    struct Employee maxSalEmp, e[10] = {
        {1, "Mukul Kumar Yadav", 12000},
        {2, "Vijay Pal Yadav", 20000},
        {3, "Kanta Yadav", 10000},
        {4, "Manju Yadav", 15000},
        {5, "Anju Yadav", 10000},
        {6, "Pradeep yadav", 60000},
        {7, "Rakesh Yadav", 22000},
        {8, "Raghuvir Yadav", 95000},
        {9, "Sanjay Yadav", 30000},
        {10, "Santara Yadav", 50000}
    };
    // employeeDataInput(&e);
    
    // displayEmployeeData(&e);

    // maxSalEmp = highestSalariedEmployee(e, 10);
    // printf("Highest Salaried Employee Details are:\n");
    // displayEmployeeData(maxSalEmp);

    // sortEmployeesBasedOnSalary(e, 10);
    // printf("Employees data after sorting is:\n");
    // int i;
    // for(i = 0; i < 10; i++)
    //     displayEmployeeData(e[i]);

    sortEmployeesBasedOnName(e, 10);
    printf("Employees data after sorting name wise is:\n");
    int i;
    for(i = 0; i < 10; i++)
        displayEmployeeData(e[i]);
    return 0;
}
