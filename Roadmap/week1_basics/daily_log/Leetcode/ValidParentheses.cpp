#include <iostream>
#include <string>
using namespace std;

class Stack
{
private:
    struct Node
    {
        char op;
        Node *next;
        Node(char c) : op(c), next(nullptr) {}
    };
    Node *head;
    int topStack;

public:
    Stack() : head(nullptr), topStack(-1) {}
    ~Stack()
    {
        while (head)
        {
            this->pop();
        }
    }
    void push(char);
    void pop();
    bool isEmpty();
    char get();
};

void Stack::push(char c)
{
    Node *node = new Node(c);
    node->next = head;
    head = node;
    topStack++;
}

void Stack::pop()
{
    Node *temp = head->next;
    delete head;
    head = temp;
    topStack--;
}

bool Stack::isEmpty()
{
    return topStack == -1;
}

char Stack::get()
{
    return head->op;
}

class Solution
{
public:
    bool isValid(string s)
    {
        Stack stack;
        for (char c : s)
        {
            if (c == ')')
            {
                if (stack.isEmpty())
                {
                    return false;
                }
                else if (stack.get() == '(')
                {
                    stack.pop();
                }
                else
                    return false;
            }
            else if (c == ']')
            {
                if (stack.isEmpty())
                    return false;
                else if (stack.get() == '[')
                    stack.pop();
                else
                    return false;
            }
            else if (c == '}')
            {
                if (stack.isEmpty())
                    return false;
                else if (stack.get() == '{')
                    stack.pop();
                else
                    return false;
            }
            else
                stack.push(c);
        }
        return stack.isEmpty();
    }
};

int main()
{
    Solution s;
    cout << s.isValid("()()())()(()())()(()()()()()()()()()()()())");
    // string s = ")";
    // cout << s.find()
}