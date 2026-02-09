#include<iostream>
using namespace std;

/*
A19.6 Define a function to implement quick sort using iteration.

Problem Summary: Define quickSort() using iteration.
(Completed)
*/

#define STACK_UNDERFLOW 1
struct node
{
    int low;
    int high;
    node *next;
};
class Stack
{
    private:
        node *top;
    public:
        Stack();
        void push(int, int);
        void pop();
        int peekLow();
        int peekHigh();
        bool isEmpty();
        ~Stack();
};
Stack::Stack()
{
    top=nullptr;
}
void Stack::push(int lowData, int highData)
{
    node *n=new node;
    n->low = lowData;
    n->high = highData;
    n->next=top;
    top=n;
}

void Stack::pop()
{
    if(top==nullptr)
        throw STACK_UNDERFLOW;
    node *t;
    t=top;
    top=top->next;
    delete t;
}

Stack::~Stack()
{
    while(top!=nullptr)
        pop();
}
int Stack::peekLow()
{
    if(isEmpty())
        throw STACK_UNDERFLOW;
    return top->low;
}
int Stack::peekHigh()
{
    if(isEmpty())
        throw STACK_UNDERFLOW;
    return top->high;
}
bool Stack::isEmpty()
{
    return top==nullptr;
}
void reverseStack(Stack &s)
{
    Stack s1;
    while(!s.isEmpty()){
        s1.push(s.peekLow(), s.peekHigh());
        s.pop();
    }
    Stack s2;
    while(!s1.isEmpty()){
        s2.push(s1.peekLow(), s1.peekHigh());
        s1.pop();
    }
    while(!s2.isEmpty()){
        s.push(s2.peekLow(), s2.peekHigh());
        s2.pop();
    }
}
class SLL
{
    private:
        node *start;
    public:
        SLL();
        void insertAtStart(int, int);
        node* search(int, int);
        void deleteFirst();
        void deleteLast();
        void deleteNode(node*);
        void deleteNode(int, int);
        bool isDataInList(int, int);
        ~SLL();
};
SLL::SLL()
{
    start=nullptr;
}
void SLL::insertAtStart(int lowData, int highData)
{
    node *n=new node;
    n->low=lowData;
    n->high = highData;
    n->next=start;
    start=n;
}

node* SLL::search(int lowData, int highData)
{
    node *t;
    t=start;
    while(t!=nullptr){
        if(t->low==lowData && t->high == highData)
            return t;
        t=t->next;
    }
    return nullptr;
}
void SLL::deleteFirst()
{
    if(start!=nullptr)
    {
        node *t;
        t=start;
        start=start->next;
        delete t;
    }
}
void SLL::deleteLast()
{
    if(start!=nullptr)
    {
        node *t;
        if(start->next==nullptr) //single node in the list
        {
            delete start;
            start=nullptr;
        }
        else{
            t=start;
            while(t->next->next!=nullptr){
                t=t->next;
            }
            delete t->next;
            t->next=nullptr;
        }
    }
}
void SLL::deleteNode(node *temp)
{
    if(temp!=nullptr){
        node *t=search(temp->low, temp->high);
        if(t==temp)
        {
            t=start;
            if(start==temp)
            {
                deleteFirst();
            }
            else{
                while(t->next!=temp)
                {
                    t=t->next;
                }
                t->next=temp->next;
                delete temp;
            }
        }
    }
}
void SLL::deleteNode(int lowData, int highData)
{
    node *temp=search(lowData, highData);
    if(temp!=nullptr)
    {
        node *t;
        t=start;
        if(start==temp)
            deleteFirst();
        else
        {
            while(t->next!=temp)
            {
                t=t->next;
            }
            t->next=temp->next;
            delete temp;
        }
    }
}
bool SLL::isDataInList(int lowData, int highData)
{
    return search(lowData, highData);
}
SLL::~SLL()
{
    while(start!=nullptr)
        deleteFirst();
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
int partition(int A[], int left, int right)
{
    int loc = left;
    while(left < right)
    {
        while(left < right && A[loc] <= A[right])
        {
            right--;
        }
        if(left < right && A[loc] > A[right])
        {
            swapNumbers(&A[loc], &A[right]);
            loc = right;
        }
        while(left < right && A[left] <= A[loc])
        {
            left++;
        }
        if(left < right && A[left] > A[loc])
        {
            swapNumbers(&A[left], &A[loc]);
            loc = left;
        }
    }
    return loc;
}
void quickSort(int arr[], int size)
{
    int low = 0, high = size - 1, partitioningIndex;
    Stack partitionIndices1;
    SLL executedCalls;
    partitionIndices1.push(low, high);
    while(!partitionIndices1.isEmpty())
    {
        while(low < high)
        {
            partitioningIndex = partition(arr, low, high);
            if(!executedCalls.isDataInList(low, partitioningIndex - 1))
            {
                high = partitioningIndex - 1;
            }
            else if(!executedCalls.isDataInList(partitioningIndex + 1, high))
            {
                low = partitioningIndex + 1;
            }
            if(high != partitioningIndex - 1 && low != partitioningIndex + 1)
            {
                break;
            }
            partitionIndices1.push(low, high);
        }
        executedCalls.insertAtStart(partitionIndices1.peekLow(), partitionIndices1.peekHigh());
        partitionIndices1.pop();
        if(!partitionIndices1.isEmpty())
        {
            high = partitionIndices1.peekHigh();
            low = partitionIndices1.peekLow();
        }
    }
}

int main()
{
    int arr[9] = {58, 62, 91, 43, 29, 37, 88, 72, 16};
    quickSort(arr, 9);
    displayArray(arr, 9);
    cout<<endl;
    return 0;
}