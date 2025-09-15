#include <iostream>
using namespace std;

class Stack
{
private:
    struct Node
    {
        int data;
        Node *next;
        Node(int n)
        {
            data = n;
            next = nullptr;
        }
    };
    Node *topOfStack;

public:
    Stack();
    ~Stack();
    void push(int);
    int pop();
    bool isEmpty();
    void printTop();
    void printAll();
};

Stack::Stack()
{
    topOfStack = nullptr;
}

Stack::~Stack()
{
    while (topOfStack)
    {
        Node *temp = topOfStack->next;
        delete topOfStack;
        topOfStack = temp;
    }
}

void Stack::push(int data)
{
    Node *node = new Node(data);
    node->next = topOfStack;
    topOfStack = node;
}

int Stack::pop()
{
    int result = topOfStack->data;
    Node *tmp = topOfStack;
    topOfStack = topOfStack->next;
    delete tmp;
    return result;
}