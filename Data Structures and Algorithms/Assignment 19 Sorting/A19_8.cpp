#include<iostream>
using namespace std;

/*
A19.8 Define a function to implement merge sort using iteration.

Problem Summary: Define mergeSort() using iteration.
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
void merge(int arr[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
    int arr2[high - low + 1] = {0};
    while(i <= mid && j <= high)
    {
        if(arr[i] < arr[j])
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

void mergeSort(int arr[], int size)
{
    int low = 0, high = size - 1, mid;
    Stack arrIndices;
    SLL executedCalls;
    arrIndices.push(low, high);
    while(!arrIndices.isEmpty())
    {
        while(low < high)
        {
            mid = (low + high) / 2;
            if(!executedCalls.isDataInList(low, mid))
            {
                high = mid;
            }
            else if(!executedCalls.isDataInList(mid + 1, high))
            {
                low = mid + 1;
            }
            if(high != mid && low != mid + 1)
            {
                merge(arr, low, mid, high);
                break;
            }
            arrIndices.push(low, high);
        }
        executedCalls.insertAtStart(arrIndices.peekLow(), arrIndices.peekHigh());
        arrIndices.pop();
        if(!arrIndices.isEmpty())
        {
            high = arrIndices.peekHigh();
            low = arrIndices.peekLow();
        }
    }
}

int main()
{
    int arr[13] = {75, 29, 83, 42, 16, 90, 56, 34, 20, 71, 88, 92, 7};
    mergeSort(arr, 13);
    displayArray(arr, 13);
    cout<<endl;
    return 0;
}