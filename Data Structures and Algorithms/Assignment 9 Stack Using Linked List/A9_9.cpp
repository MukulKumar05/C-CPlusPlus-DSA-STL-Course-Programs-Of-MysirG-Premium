#include<iostream>
#include<string.h>
using namespace std;
#define STACK_UNDERFLOW -1
#define INVALID_INDEX 2

/*
A9.9 Define a method to convert infix to postfix expression.

Problem Summary: convertInfixToPostfixExpression()
(Completed)
*/

// Function to get the precedence level of an operator
int getOperatorPrecedence(char op) {
    switch (op) {
        case '*':
        case '/':
        case '%':
            return 4;
        case '+':
        case '-':
            return 3;
        case '^':
            return 2;
        case '<':
        case '>':
        case '=': // For relational operators like ==, !=, <=, >=, you might need more specific handling or string input
            return 1; // Basic relational operators (simplified for char input)
        // Add more cases for other operators like logical, bitwise, assignment, etc.
        default:
            return 0; // Low precedence for unknown or unsupported operators
    }
}

// Function to check if the first operator has higher precedence
bool hasHigherPrecedence(char op1, char op2) {
    return getOperatorPrecedence(op1) > getOperatorPrecedence(op2);
}

class DynArray
{
    private:
        int capacity;
        int lastIndex;
        char *ptr;
    protected:
        void doubleArray();
        void halfArray();
    public:
        DynArray(int);
        DynArray(const char*);
        ~DynArray();
        int currentCapacity();
        bool isEmpty();
        bool isFull();
        void append(char);
        void displayString();
        void insert(int,char);
        void edit(int, char);
        void del(int);
        int get(int);
        int count();
        DynArray(DynArray&);
        DynArray& operator=(DynArray&);
        DynArray& convertInfixToPostfix();
        // friend DynArray convertInfixToPostfix(DynArray);
};
struct node
{
    char item;
    node *next;
};
class Stack
{
    private:
        node *top;
    public:
        Stack();
        void push(char);
        void displayElements();
        void pop();
        ~Stack();
        char peekTopElement();
        bool isEmpty();
        Stack(Stack&);
        Stack& operator=(Stack&);
};
DynArray& DynArray::convertInfixToPostfix()
{
    int i;
    DynArray postfixExp("");
    Stack s;
    for(i = 0; i <= lastIndex; i++) // to dry run from here
    {
        if(ptr[i] == '(')
        {
            s.push(ptr[i]);
        }
        else if(ptr[i] >= 'A' && ptr[i] <= 'Z' || ptr[i]>= 'a' && ptr[i] <= 'z' || ptr[i]>= '0' && ptr[i] <= '9')
        {
            postfixExp.append(ptr[i]);
        }
        else if(ptr[i] == ')')
        {
            while(!s.isEmpty() && s.peekTopElement() != '(')
            {
                postfixExp.append(s.peekTopElement());
                s.pop();
            }
            s.pop();
        }
        else // if character is an operator
        {
            if(s.isEmpty())
            {
                s.push(ptr[i]);
            }
            else
            {
                if(hasHigherPrecedence(ptr[i], s.peekTopElement()))
                    s.push(ptr[i]);
                else
                {
                    while(!s.isEmpty() && !hasHigherPrecedence(ptr[i], s.peekTopElement()))
                    {
                        postfixExp.append(s.peekTopElement());
                        s.pop();   
                    }
                    s.push(ptr[i]);
                }
            }
        }
    }
    while(!s.isEmpty())
    {
        postfixExp.append(s.peekTopElement());
        s.pop();
    }
    *this = postfixExp;
    return *this;
}
// DynArray convertInfixToPostfix(DynArray infixExp)
// {
//     int i;
//     DynArray postfixExp("");
//     Stack s;
//     for(i = 0; i <= infixExp.lastIndex; i++)
//     {
//         if(infixExp.ptr[i] == '(')
//         {
//             s.push(infixExp.ptr[i]);
//         }
//         else if(infixExp.ptr[i] >= 'A' && infixExp.ptr[i] <= 'Z' || infixExp.ptr[i]>= 'a' && infixExp.ptr[i] <= 'z' || infixExp.ptr[i]>= '0' && infixExp.ptr[i] <= '9')
//         {
//             postfixExp.append(infixExp.ptr[i]);
//         }
//         else if(infixExp.ptr[i] == ')')
//         {
//             while(s.peekTopElement() != '(')
//             {
//                 postfixExp.append(s.peekTopElement());
//                 s.pop();
//             }
//             s.pop();
//         }
//         else // if character is an operator
//         {
//             if(hasHigherPrecedence(infixExp.ptr[i], s.peekTopElement()))
//                 s.push(infixExp.ptr[i]);
//             else
//             {
//                 postfixExp.append(s.peekTopElement());
//                 s.pop();
//             }
//         }
//     }
//     while(!s.isEmpty())
//     {
//         postfixExp.append(s.peekTopElement());
//         s.pop();
//     }
//     return postfixExp;
// }
DynArray::DynArray(DynArray &a)
{
    capacity = a.capacity;
    lastIndex = a.lastIndex;
    ptr = new char[capacity];
    int i;
    for(i = 0; i <= lastIndex; i++)
        ptr[i] = a.ptr[i];
}
DynArray& DynArray::operator=(DynArray &a)
{
    capacity = a.capacity;
    lastIndex = a.lastIndex;
    delete []ptr;
    ptr = new char[capacity];
    int i;
    for(i = 0; i <= lastIndex; i++)
        ptr[i] = a.ptr[i];
    return *this;
}
DynArray::DynArray(int cap)
{
    if(cap<=0)
        cap=10;
    capacity=cap;
    lastIndex=-1;
    ptr=new char[capacity];
}
DynArray::DynArray(const char *str)
{
    int i, strLength = strlen(str);
    capacity = strLength;
    lastIndex = strLength - 1;
    ptr = new char[capacity];
    for(i = 0; i <= lastIndex; i++)
    {
        ptr[i] = str[i];
    }
}
DynArray::~DynArray()
{
    delete []ptr;
}
void DynArray::doubleArray()
{
    capacity *= 2;
    char* newPtr = new char[capacity];
    int i;
    for(i = 0; i <= lastIndex; i++)
        newPtr[i] = ptr[i];
    delete []ptr;
    ptr = newPtr;
}
void DynArray::halfArray()
{
    capacity /= 2;
    char* newPtr = new char[capacity];
    int i;
    for(i = 0; i <= lastIndex; i++)
        newPtr[i] = ptr[i];
    delete []ptr;
    ptr = newPtr;
}
int DynArray::currentCapacity() { return capacity; }
bool DynArray::isEmpty()
{
    return lastIndex==-1;
}
bool DynArray::isFull()
{
    return capacity-1==lastIndex;
}
void DynArray::append(char data)
{
    if(isFull())
        doubleArray();
    ptr[lastIndex+1]=data;
    lastIndex++;
}
void DynArray::displayString()
{
    int i;
    for(i = 0; i <= lastIndex; i++)
        cout<<ptr[i]<<" ";
    cout<<endl;
}
void DynArray::insert(int index,char data)
{
    if(index<0 || index>lastIndex+1)
        throw INVALID_INDEX;
    if(isFull())
        doubleArray();
    int i;
    for(i=lastIndex;i>=index;i--)
        ptr[i+1]=ptr[i];
    ptr[index]=data;
    lastIndex++;
}
void DynArray::edit(int index, char data)
{
    if(index<0 || index>lastIndex)
        throw INVALID_INDEX;
    ptr[index]=data;
}
void DynArray::del(int index)
{
    if(index<0 || index>lastIndex)
        throw INVALID_INDEX;
    int i;
    for(i=index;i<lastIndex ; i++)
    {
        ptr[i]=ptr[i+1];
    }
    lastIndex--;
    if(lastIndex + 1 == capacity / 2)
        halfArray();
}
int DynArray::get(int index)
{
    if( index<0 || index>lastIndex)
        throw INVALID_INDEX;
    return ptr[index];
}
int DynArray::count()
{
    return lastIndex+1;
}



Stack& Stack::operator=(Stack &s)
{
    this->~Stack();
    top = nullptr;
    if(s.top) // if stack s has >= 1 elements
    {
        if(s.top->next) // stack has > 1 elements
        {
            top = nullptr;
            node *ptr = s.top;
            while(ptr->next)
                ptr = ptr->next;
            push(ptr->item);
            while(ptr != s.top)
            {
                node *ptr2 = s.top;
                while(ptr2->next != ptr)
                    ptr2 = ptr2->next;
                push(ptr2->item);
                ptr = ptr2; 
            }
        }
        else // stack has only 1 element
        {
            top = nullptr;
            push(s.top->item);
        }
        
    }
    else // stack is empty
        top = nullptr;
    return *this;
}
Stack::Stack(Stack &s)
{
    if(s.top) // if stack s has >= 1 elements
    {
        if(s.top->next) // stack has > 1 elements
        {
            top = nullptr;
            node *ptr = s.top;
            while(ptr->next)
                ptr = ptr->next;
            push(ptr->item);
            while(ptr != s.top)
            {
                node *ptr2 = s.top;
                while(ptr2->next != ptr)
                    ptr2 = ptr2->next;
                push(ptr2->item);
                ptr = ptr2; 
            }
        }
        else // stack has only 1 element
        {
            top = nullptr;
            push(s.top->item);
        }
        
    }
    else // stack is empty
        top = nullptr;
}
Stack::Stack()
{
    top = nullptr;
}
void Stack::push(char data)
{
    if(top)
    {
        node *newPtr = new node;
        newPtr->next = top;
        top = newPtr;
        top->item = data;
    }
    else
    {
        top = new node;
        top->next = nullptr;
        top->item = data;
    }
}
void Stack::displayElements()
{
    if(top == nullptr)
        cout<<"Stack is empty."<<endl;
    else
    {
        node *ptr = top;
        while(ptr)
        {
            cout<<ptr->item<<" ";
            ptr = ptr->next;
        }
    }
}
void Stack::pop()
{
    if(top)
    {
        node *ptr = top;
        top = top->next;
        delete ptr;
    }
    else
        cout<<"Deletion not possible because stack is already empty."<<endl;
}
Stack::~Stack()
{
    while(top)
        pop();
}
char Stack::peekTopElement()
{
    if(top)
        return top->item;
    throw STACK_UNDERFLOW;
}
bool Stack::isEmpty()
{
    if(top)
        return false;
    return true;
}
void moveElementsinReverseOrderFrom(Stack &s1, Stack &s2)
{
    while(!s1.isEmpty())
    {
        s2.push(s1.peekTopElement());
        s1.pop();
    }
}
void reverseStack(Stack &s)
{
    Stack s1;
    moveElementsinReverseOrderFrom(s, s1);
    Stack s2;
    moveElementsinReverseOrderFrom(s1, s2);
    moveElementsinReverseOrderFrom(s2, s);
}
bool isPalindrome(int number)
{
    int x = number;
    Stack s;
    while(number)
    {
        s.push(number % 10);
        number /= 10;
    }
    while(x)
    {
        if(x % 10 != s.peekTopElement())
            return false;
        s.pop();
        x /= 10;
    }
    return true;
}
int main()
{
    DynArray infixExp("K+L-M*N+(O^P)*W/U/V*T+Q"), postfixExp("");
    postfixExp = infixExp;
    postfixExp.convertInfixToPostfix();
    postfixExp.displayString();
    return 0;
}