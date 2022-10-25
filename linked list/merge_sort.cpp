#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* next;

    node(int data){
        this->data=data;
        next=NULL;
    }
};

void insertAtHead(node* &head,int data){
    if(head==NULL){
        head=new node(data);
        return;
    }
    node* n=new node(data);
    n->next=head;
    head=n;
}

void printLL(node* head){
    while(head!=NULL){
        cout<<head->data<<"-->";
        head=head->next;
    }
    cout<<endl;
}

node* midpoint(node* head){
    node* fast=head->next,*slow=head;
    while(fast and fast->next){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
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

node* merge_sort(node* head){
    if(head==NULL or head->next==NULL){
        return head;
    }

    node *mid=midpoint(head);

    node* a=head,*b=mid->next;
    mid->next=NULL;
    a=merge_sort(a);
    b=merge_sort(b);
    return merge(a,b);
}

int main()
{
    node* head=NULL;
    insertAtHead(head,4);
    insertAtHead(head,1);
    insertAtHead(head,2);
    insertAtHead(head,3);
    insertAtHead(head,5);

    printLL(head);
    head=merge_sort(head);
    
    printLL(head);
    return 0;
}