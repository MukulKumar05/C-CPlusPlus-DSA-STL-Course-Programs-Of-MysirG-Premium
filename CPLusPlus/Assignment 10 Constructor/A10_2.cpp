#include<iostream>
#include<string.h>
using namespace std;

/*
A10.2 Define a class Customer with instance members cust_id, name, email,
mobile. Define non parameterised constructor and parameterised constructor
in the class.
(Completed)
*/
class Customer
{
    private:
        int cust_id;
        char name[100], email[100];
        long long int mobile;
    public:
        Customer()
        {
            cust_id = 0;
            name[0] = '\0';
            email[0] = '\0';
            mobile = 0;
        }
        Customer(int cID, const char *na, const char *em, long long int m)
        {
            cust_id = cID;
            strcpy(name, na);
            strcpy(email, em);
            mobile = m;
        }
        void setCustomerData(int cID, const char na[], const char em[], long long int m)
        {
            cust_id = cID;
            strcpy(name, na);
            strcpy(email, em);
            mobile = m;
        }
        void showCustomerDetails()
        {
            cout<<"Cust. ID: "<<cust_id<<", Name: "<<name<<", Email: "<<email<<", Mobile: "<<mobile<<endl;
        }
};

int main()
{
    Customer c1, c2(2, "Mukul Kumar", "mukulkumar125@gmail.com", 7899054321);
    c1.showCustomerDetails();
    c1.setCustomerData(1, "test user", "test@yahoo.com", 1234567890);
    c1.showCustomerDetails();
    c2.showCustomerDetails();
    return 0;
}