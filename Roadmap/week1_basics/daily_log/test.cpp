#include <iostream>
#include <math.h>
using namespace std;

class List
{
public:
    List()
    {
        head = NULL;
        counter = 0;
    }
    void add(double);
    void getData(double *&, int &);
    List *clone();
    List *mergeWith(List *);
    int cut(int, List *&, List *&);
    void removeAllNodes();
    void print();

protected:
    struct Node
    {
        double data;
        Node *next;
        Node(double d)
        {
            data = d;
            next = NULL;
        }
    };
    int counter;
    Node *head;
    Node *mid;
};

void List::add(double n)
{
    Node *node = new Node(n);
    node->next = head;
    head = node;
    counter++;
    if (counter % 2 == 0 || counter == 1)
    {
        mid = node;
        for (int i = 1; i < round(counter / 2.0); i++)
        {
            mid = mid->next;
        }
    }
}

void List::removeAllNodes()
{
    while (head)
    {
        Node *temp = head->next;
        delete head;
        head = temp;
        counter--;
    }
    mid = NULL;
}

void List::print()
{
    Node *node = head;
    for (int i = 0; i < counter; i++)
    {
        if (node == mid)
        {
            cout << "[" << node->data << "] ";
        }
        else
        {
            cout << node->data << " ";
        }
        node = node->next;
    }
    cout << ", Mid = :" << mid->data << endl;
}
int main()
{
    List list1;
    for (int i = 1; i <= 10; i++)
    {
        list1.add(i);
        list1.print();
    }
    list1.removeAllNodes();
    for (int i = 1; i <= 10; i++)
    {
        list1.add(i);
        list1.print();
    }
}
