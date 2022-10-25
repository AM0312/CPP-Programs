#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void insertAtHead(node *&head, int data)
{
    if (head == NULL)
    {
        head = new node(data);
        return;
    }
    node *n = new node(data);
    n->next = head;
    head = n;
}

void printLL(node *head)
{
    while (head != NULL)
    {
        cout << head->data << "-->";
        head = head->next;
    }
    cout << endl;
}

void iterativeReverse(node *&head)
{
    node *prev = NULL, *cur = head, *temp;
    while (cur != NULL)
    {
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    head = prev;
    return;
}

int main()
{
    node *head = NULL;
    insertAtHead(head, 4);
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 5);

    printLL(head);
    iterativeReverse(head);
    printLL(head);
    return 0;
}