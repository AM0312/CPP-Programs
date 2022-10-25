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

node* inorderSuccessor(node* root,node* target){
    if(target->right!=NULL){
        node* temp=target->right;
        while(temp->left!=NULL){
            temp=temp->left;
        }
        return temp;
    }
    node *temp=root,*succ=NULL;
    while(temp!=NULL){
        if(temp->key>target->key){
            succ=temp;
            temp=temp->left;
        }
        else if(temp->key<target->key){
            temp=temp->right;
        }
        else break;
    }
    return succ;

}

int main()
{
    node* root=NULL;
    int arr[]={8,3,10,1,6,14,4,7,13};
    for(int x:arr){
        root=insert(root,x);
    }
    node *t=root->left->right->right;
    cout<<inorderSuccessor(root,t)->key;
    return 0;
}