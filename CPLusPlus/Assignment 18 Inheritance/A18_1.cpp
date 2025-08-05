#include<iostream>
#include<string.h>
using namespace std;

/*
A18.1 Define a class Person with name and age as instance variables as
private members. Provide setters and getters as protected members.
Derive a class Employee from Person class with private instance variable
salary. Provide public methods setEmployee() and showEmployee().
(Completed)
*/
class Person
{
    private:
        char name[100];
        int age;
    protected:
        void setName(const char *name) { strcpy(this->name, name); }
        void setAge(int age) { this->age = age; }
        char* getName() { return name; }
        int getAge() { return age; }
};
class Employee: public Person
{
    private:
        float salary;
    public:
        void setEmployee(const char *name, int age, float salary)
        {
            setName(name);
            setAge(age);
            this->salary = salary;
        }
        void showEmployee()
        {
            cout<<"Name: "<<getName()<<" , Age: "<<getAge()<<" , Salary: "<<salary<<endl;
        }
};

int main()
{
    Employee e1;
    e1.setEmployee("Mukul Kumar", 28, 12000);
    e1.showEmployee();
    return 0;
}
