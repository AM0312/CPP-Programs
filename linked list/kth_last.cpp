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

int getkthlast(node* head,int k){
    node* fast=head,*slow=head;
    int cnt=1;
    while(cnt<=k){
        fast=fast->next;
        cnt++;
    }
    while(fast!=NULL){
        slow=slow->next;
        fast=fast->next;
    }
    return slow->data;
}

int main()
{
    node* head=NULL;
    insertAtHead(head,8);
    insertAtHead(head,7);
    insertAtHead(head,6);
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);

    printLL(head);
    cout<<getkthlast(head,4);
    return 0;
}