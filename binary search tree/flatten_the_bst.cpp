#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int key;
    node *left,*right;

    node(int key){
        this->key=key;
        left=right=NULL;
    }
};

node* insert(node* root,int x){
    if(root==NULL){
        return new node(x);
    }
    if(x<root->key){
        root->left=insert(root->left,x);
    }
    else{
        root->right=insert(root->right,x);
    }
    return root;
}

void printInOrder(node* root){
    if(root==NULL){
        return;
    }
    printInOrder(root->left);
    cout<<root->key<<" ";
    printInOrder(root->right);
}

bool isPresent(node * root,int key){
    if(root==NULL){
        return false;
    }
    if(root->key=key){
        return true;
    }
    if(key<root->key){
        return isPresent(root->left,key);
    }
    return isPresent(root->right,key);
}

class LL{
public:
    node *head,*tail;
};

LL tree2LL(node* root){
    LL l;
    if(root==NULL){
        l.head=l.tail=NULL;
        return l;
    }
    if(root->left==NULL and root->right==NULL){
        l.head=l.tail=root;
        return l;
    }
    else if(root->left!=NULL and root->right==NULL){
        LL leftLL=tree2LL(root->left);
        leftLL.tail->right=root;
        l.head=leftLL.head;
        l.tail=root;
    }
    else if(root->left==NULL and root->right!=NULL){
        LL rightLL=tree2LL(root->right);
        root->right=rightLL.head;
        l.head=root;
        l.tail=rightLL.tail;
    }
    else{
        LL leftLL=tree2LL(root->left);
        LL rightLL=tree2LL(root->right);
        leftLL.tail->right=root;
        l.head=leftLL.head;
        l.tail=rightLL.tail;
    }
    return l;
}


int main()
{
    node* root=NULL;
    int arr[]={8,3,10,1,6,14,4,7,13};
    for(int x:arr){
        root=insert(root,x);
    }
    LL l=tree2LL(root);
    node* temp=l.head;
    while(temp!=NULL){
        cout<<temp->key<<"-->";
        temp=temp->right;
    }
    return 0;
}