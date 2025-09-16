#include <iostream>
#include <string>
using namespace std;

int main()
{
    struct Node
    {
        int val;
        Node *next;
        Node(int n) : val(n), next(nullptr) {}
    };
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = node1->next->val < node2->next->val ? node1 : node2;
    cout << node3;
}