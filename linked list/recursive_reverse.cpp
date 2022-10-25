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

node* recreverse(node* head){
    if(head==NULL or head->next==NULL){
        return head;
    }

    node* shead=recreverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return shead;
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

    head=recreverse(head);
    printLL(head);
    return 0;
}