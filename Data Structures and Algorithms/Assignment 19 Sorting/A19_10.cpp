#include<iostream>
#include<string.h>
using namespace std;

/*
A19.10 In question 9, define a function to sort Employee Array data
by name. Use Quick Sort.

Problem Summary: define sortEmployeeArrayByName() . Use Quick Sort.
(Completed)
*/
class Employee
{
    private:
        int emp_id;
        string name;
        float salary;
    public:
        void setEmployee(int, string, float);
        int getEmployeeID();
        string getEmployeeName();
        float getEmployeeSalary();
        void displayEmployee();
};
void Employee::setEmployee(int eID, string n, float sal)
{
    emp_id = eID;
    name = n;
    salary = sal;
}
int Employee::getEmployeeID()
{
    return emp_id;
}
string Employee::getEmployeeName()
{
    return name;
}
float Employee::getEmployeeSalary()
{
    return salary;
}
void Employee::displayEmployee()
{
    cout<<"Employee ID: "<<emp_id<<" , Employee Name: "<<name<<" , Employee Salary: "<<salary;
}
void swapEmployeesData(Employee* e1, Employee* e2)
{
    Employee temp;
    temp = *e1;
    *e1 = *e2;
    *e2 = temp;
}
void displayArray(int arr[], int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
}
int partition(Employee A[], int left, int right)
{
    int loc = left;
    while(left < right)
    {
        while(left < right && A[loc].getEmployeeName().compare(A[right].getEmployeeName()) <= 0)
        {
            right--;
        }
        if(left < right && A[loc].getEmployeeName().compare(A[right].getEmployeeName()) > 0)
        {
            swapEmployeesData(&A[loc], &A[right]);
            loc = right;
        }
        while(left < right && A[left].getEmployeeName().compare(A[loc].getEmployeeName()) <= 0)
        {
            left++;
        }
        if(left < right && A[left].getEmployeeName().compare(A[loc].getEmployeeName()) > 0)
        {
            swapEmployeesData(&A[left], &A[loc]);
            loc = left;
        }
    }
    return loc;
}
void quick(Employee arr[], int low, int high)
{
    if(low < high)
    {
        int partioningIndex = partition(arr, low, high);
        quick(arr, low, partioningIndex - 1);
        quick(arr, partioningIndex + 1, high);
    }
}
void sortEmployeeArrayByName(Employee arr[], int size)
{
    quick(arr, 0, size - 1);
}
void displayEmployeesArrayData(Employee e[], int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        e[i].displayEmployee();
        cout<<endl;
    }
}

int main()
{
    Employee e[12];
    e[0].setEmployee(1, "Xavier", 25000);
    e[1].setEmployee(2, "Shikhar Dhawan", 50000);
    e[2].setEmployee(3, "Rohit Sharma", 5000);
    e[3].setEmployee(4, "Virat Kohli", 15000);
    e[4].setEmployee(5, "Mahendra Singh Dhoni", 12000);
    e[5].setEmployee(6, "Mohammad Shami", 64000);
    e[6].setEmployee(7, "Ambati Rayadu", 28000);
    e[7].setEmployee(8, "Manish Pandey", 21000);
    e[8].setEmployee(9, "Suresh Raina", 125000);
    e[9].setEmployee(10, "Kedar Jhadhav", 90000);
    e[10].setEmployee(11, "Surya Kumar Yadav", 94000);
    e[11].setEmployee(12, "Unmukt Chand", 58000);
    sortEmployeeArrayByName(e, 12);
    displayEmployeesArrayData(e, 12);
    return 0;
}