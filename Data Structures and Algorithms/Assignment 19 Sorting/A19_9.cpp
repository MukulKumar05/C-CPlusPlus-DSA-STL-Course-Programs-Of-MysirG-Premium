#include<iostream>
#include<string.h>
using namespace std;

/*
A19.9 Define a class Employee with emp_id, name, salary as instance
variables. Provide setters and getters in the class to access
instance variables. Also define a function to sort Employee
Array data by salary. Use Merge Sort.

Problem Summary: Define class Employee with emp_id, name, salary as instance
variables.
Define setters and getters in the class Employee
Define sortEmployeeArrayBySalary(). Use Merge Sort
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
void swapNumbers(int* num1, int* num2)
{
    int c;
    c = *num1;
    *num1 = *num2;
    *num2 = c;
}
void displayArray(int arr[], int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
}
void merge(Employee arr[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
    Employee arr2[high - low + 1];
    while(i <= mid && j <= high)
    {
        if(arr[i].getEmployeeSalary() < arr[j].getEmployeeSalary())
        {
            arr2[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            arr2[k] = arr[j];
            k++;
            j++;
        }
    }
    while(i <= mid)
    {
        arr2[k] = arr[i];
        k++;
        i++;
    }
    while(j <= high)
    {
        arr2[k] = arr[j];
        k++;
        j++;
    }
    for(k = 0, i = low; i <= mid; i++, k++)
    {
        arr[i] = arr2[k];
    }
    for(j = mid + 1; j <= high; j++, k++)
    {
        arr[j] = arr2[k];
    }
}
void mergeSortAlgo(Employee arr[], int low, int high)
{
    if(low < high)
    {
        int mid = (low + high) / 2;
        mergeSortAlgo(arr, low, mid);
        mergeSortAlgo(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}
void sortEmployeeArrayBySalary(Employee arr[], int size)
{
    mergeSortAlgo(arr, 0, size - 1);
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
    e[0].setEmployee(1, "A", 25000);
    e[1].setEmployee(2, "B", 50000);
    e[2].setEmployee(3, "C", 5000);
    e[3].setEmployee(4, "D", 15000);
    e[4].setEmployee(5, "E", 12000);
    e[5].setEmployee(6, "F", 64000);
    e[6].setEmployee(7, "G", 28000);
    e[7].setEmployee(8, "H", 21000);
    e[8].setEmployee(9, "I", 125000);
    e[9].setEmployee(10, "J", 90000);
    e[10].setEmployee(11, "K", 94000);
    e[11].setEmployee(12, "L", 58000);
    sortEmployeeArrayBySalary(e, 12);
    displayEmployeesArrayData(e, 12);
    return 0;
}