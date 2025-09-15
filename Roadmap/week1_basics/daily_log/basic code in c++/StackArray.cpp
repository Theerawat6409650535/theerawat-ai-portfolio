#include <iostream>
using namespace std;

class Stack
{
private:
    int *stack;
    int topOfStack;

public:
    Stack(int);
    ~Stack();
    void push(int);
    int pop();
    bool isEmpty();
    void printTop();
    void printAll();
};

Stack::Stack(int size = 20)
{
    topOfStack = -1;
    stack = new int[size]();
}

Stack::~Stack()
{
    delete[] stack;
}

void Stack::push(int data)
{
    stack[++topOfStack] = data;
}

int Stack::pop()
{
    return stack[topOfStack--];
}

void Stack::printTop()
{
    if (this->isEmpty())
    {
        cout << "Stack is empty !!!" << endl;
    }
    else
    {
        cout << "Top of stack : " << stack[topOfStack] << endl;
    }
}

void Stack::printAll()
{
    if (this->isEmpty())
    {
        cout << "Stack is empty !!!" << endl;
    }
    else
    {
        cout << "All member in stack : ";
        for (int i = topOfStack; i > -1; i--)
        {
            cout << stack[i] << ", ";
        }
        cout << endl;
    }
}

bool Stack::isEmpty()
{
    return topOfStack == -1;
}

int main(int argv, char **argc)
{
    Stack s;
    s.printTop();
    s.push(10);

    s.printTop();
    s.push(20);

    s.printTop();
    s.push(30);

    s.printTop();
    s.push(40);

    s.printTop();
    s.push(50);

    s.printAll();
    s.pop();

    s.printAll();
    s.pop();

    s.printAll();
    s.pop();

    s.printAll();
    s.pop();

    s.printAll();
    s.pop();

    s.printAll();
}