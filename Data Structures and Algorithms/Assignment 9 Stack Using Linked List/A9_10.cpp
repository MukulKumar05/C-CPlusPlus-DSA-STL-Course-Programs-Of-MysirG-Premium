#include<iostream>
#include<string.h>
using namespace std;
#define STACK_UNDERFLOW -1
#define INVALID_INDEX 2
#define UNDEFINED_OPERATOR 3
#define INVALID_STRING 4

/*
A9.10 Define a method to evaluate postfix expression.

Problem Summary: evaluatePostfixExpression()
(Completed)
*/

int numericCharacterAsNumber(char ch)
{
    return ch - '0';
}

int NumericStringAsNumber(char *s)
{
    int i, number = 0;
    for(i = 0; i < strlen(s); i++)
    {
        number = number * 10 + (s[i] - '0');
    }
    return number;
}

bool isStringANumericString(char *str)
{
    int i, strLength = strlen(str);
    for(i = 0; i < strLength; i++)
    {
        if(str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

bool isStringAnArithmeticOperator(char *str)
{
    if(strlen(str) == 1)
    {
        if(str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/')
            return true;
        return false;
    }
    return false;
}

char singleDigitIntegerAsCharacter(int digit)
{
    return digit + '0';
}

int subResultOfPostfixExpression(int operand1, int operand2, char op)
{
    switch(op) 
    {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
        default:
            cout<<"Undefined operator "<<op<<" found!"<<endl;
            throw UNDEFINED_OPERATOR;
    }
}

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
        int evaluatePostfixExpression();
        // friend DynArray convertInfixToPostfix(DynArray);
};
struct node
{
    int item;
    node *next;
};
class Stack
{
    private:
        node *top;
    public:
        Stack();
        void push(int);
        void displayElements();
        void pop();
        ~Stack();
        int peekTopElement();
        bool isEmpty();
        Stack(Stack&);
        Stack& operator=(Stack&);
};
// int DynArray::evaluatePostfixExpression()
// {
//     Stack s;
//     int i;
//     for(i = 0; i <= lastIndex; i++)
//     {
//         if(ptr[i] >= '0' && ptr[i] <= '9')
//         {
//             s.push(ptr[i]);
//         }
//         else
//         {
//             char operand1 = s.peekTopElement();
//             s.pop();
//             char operand2 = s.peekTopElement();
//             s.pop();
//             char subResultToPushInStack = singleDigitIntegerAsCharacter(subResultOfPostfixExpression(operand1, operand2, ptr[i]));
//             s.push(subResultToPushInStack);
//         }
//     }
// }
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
void Stack::push(int data)
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
int Stack::peekTopElement()
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
int evaluatePostfixExpression(char s[100][10])
{
    Stack stk;
    int i;
    for(i = 0; s[i][0]; i++)
    {
        if(isStringANumericString(s[i]))
        {
            stk.push(NumericStringAsNumber(s[i]));
        }
        else if(isStringAnArithmeticOperator(s[i]))
        {
            int operand1 = stk.peekTopElement();
            stk.pop();
            int operand2 = stk.peekTopElement();
            stk.pop();
            stk.push(subResultOfPostfixExpression(operand1, operand2, s[i][0]));
        }
        else // invalid string
        {
            cout<<"Found an invalid string in the array of strings!"<<endl;
            throw INVALID_STRING;
        }
    }
    return stk.peekTopElement();
}
int main()
{
    char str[100][10] = {"2", "3", "1", "*", "+", "9", "-"};
    cout<<"Result of Postfix expression is "<<evaluatePostfixExpression(str)<<endl;
    return 0;
}