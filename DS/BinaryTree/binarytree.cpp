#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node * left;
    Node * right;

    Node(int d){
        data=d;
        left=right=NULL;
    }
};

Node * buildTree(){
    int d;
    cin>>d;
    if(d==(-1)){
        return NULL;
    }
    Node* n= new Node(d);
    n->left=buildTree();
    n->right=buildTree();
    return n;
}

void printPreorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printInorder(Node * root){
    if(root==NULL){
        return;
    }
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

void printPostorder(Node * root){
    if(root==NULL){
        return;
    }
    printPostorder(root->left);
    printPostorder(root->right);
    cout<<root->data<<" ";
}

int height(Node* root){
    if(root==NULL){
        return 0;
    }

    int h1=height(root->left);
    int h2=height(root->right);
    return 1+max(h1,h2);
}

int main(){
    Node * root=buildTree();
    printPreorder(root);
    cout<<endl;
    printInorder(root);
    cout<<endl;
    printPostorder(root);
    return 0;
}