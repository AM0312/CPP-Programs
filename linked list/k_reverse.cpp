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

node *kreverse(node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    node *prev = NULL, *cur = head, *temp;
    int cnt = 1;
    while (cur != NULL and cnt <= k)
    {
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
        cnt++;
    }
    if(temp!=NULL){
        head->next=kreverse(temp,k);
    }
    return prev;
}

int main()
{
    node *head = NULL;

    insertAtHead(head, 7);
    insertAtHead(head, 6);
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 0);

    printLL(head);
    head=kreverse(head,3);
    printLL(head);
    return 0;
}