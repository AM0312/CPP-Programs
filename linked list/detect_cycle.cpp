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

bool containsCycle(node * head){
    node* slow=head,*fast=head;
    while(slow and fast and fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
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
    return 0;
}