#include<iostream>
#include<string.h>
using namespace std;

/*
A16.1 Define a class Person with name and age as instance variables. 
Provide parameterised constructor with two formal arguments name
& age, to initialise instance variables.
(Completed)
*/
class Person
{
    private:
        char name[100];
        int age;
    public:
        Person(const char name[], int age)
        {
            strcpy(this->name, name);
            this->age = age;
        }
        void displayPersonDetails()
        {
            cout<<"Name: "<<name<<" , Age: "<<age<<endl;
        }
};
int main()
{
    Person p1("Mukul Kumar", 28);
    p1.displayPersonDetails();
    return 0;
}
