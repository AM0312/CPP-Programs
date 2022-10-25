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

node *merge(node *a, node *b)
{
    if (a == NULL)
    {
        return b;
    }
    if (b == NULL)
    {
        return a;
    }
    node *c;
    if (a->data < b->data)
    {
        c = a;
        c->next = merge(a->next, b);
    }
    else
    {
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}

int main()
{
    node *head1 = NULL, *head2 = NULL,*head3;
    insertAtHead(head1, 8);
    insertAtHead(head1, 5);
    insertAtHead(head1, 3);
    insertAtHead(head1, 1);
    insertAtHead(head1, 0);

    insertAtHead(head2, 6);
    insertAtHead(head2, 4);
    insertAtHead(head2, 2);

    printLL(head1);
    printLL(head2);
    
    head3=merge(head1,head2);
    printLL(head3);

    return 0;
}