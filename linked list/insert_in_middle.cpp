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

void insert_in_middle(node* &head,int data,int pos){
    if(pos==1){
        insertAtHead(head,data);
    }
    else{
        node* temp=head;
        for(int jumps=1;jumps<=pos-1;jumps++){
            temp=temp->next;
        }
        node* n=new node(data);
        n->next=temp->next;
        temp->next=n; 
    }
}

int main()
{
    node* head=NULL;
    insertAtHead(head,4);
    insertAtHead(head,1);
    insertAtHead(head,2);
    insertAtHead(head,3);
    insertAtHead(head,5);

    insert_in_middle(head,100,3);

    printLL(head);
    return 0;
}