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

int findClosestInBST(node* root,int target){
    int close;
    int diff=INT_MAX;

    node* temp=root;
    while(temp!=NULL){
        int cur=abs(temp->key-target);
        if(cur==0){
            return temp->key;
        }
        if(cur<diff){
            diff=cur;
            close=temp->key;
        }
        if(temp->key<target){
            temp=temp->right;
        }
        else{
            temp=temp->left;
        }
    }
    return close;
}

int main()
{
    node* root=NULL;
    int arr[]={8,3,10,1,6,14,4,7,13};
    for(int x:arr){
        root=insert(root,x);
    }
    cout<<findClosestInBST(root,17);
    return 0;
}