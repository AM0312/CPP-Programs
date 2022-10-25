#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

node *buildTree()
{
    int d;
    cin >> d;
    if (d == -1)
        return NULL;
    node *n = new node(d);
    n->left = buildTree();
    n->right = buildTree();
    return n;
}

void printAtLevelK(node* root,int k){
    if(root==NULL){
        return;
    }
    if(k==0){
        cout<<root->data<<" ";
        return ;
    }
    printAtLevelK(root->left,k-1);
    printAtLevelK(root->right,k-1);
    return;
}

int printNodesAtDistanceK(node* root,node* target,int k){
    if(root==NULL){
        return -1;
    }
    if(root==target){
        printAtLevelK(target,k);
        return 0;
    }

    int dl=printNodesAtDistanceK(root->left,target,k);
    if(dl!=-1){
        if(dl+1==k){
            cout<<root->data<<" ";
        }
        else{
            printAtLevelK(root->right,k-2-dl);
        }
        return 1+dl;
    }

    int dr=printNodesAtDistanceK(root->right,target,k);
    if(dr!=-1){
        if(dr+1==k){
            cout<<root->data<<" ";
        }
        else{
            printAtLevelK(root->left,k-2-dr);
        }
        return 1+dr;
    }
    return -1;
}

int main(){
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->right=new node(6);
    root->left->right->left=new node(7);
    root->left->right->right=new node(8);
    root->left->right->right->left=new node(9);
    root->left->right->right->right=new node(10);

    node* target=root->left->right;
    int k=2;
    printNodesAtDistanceK(root,target,k);
    return 0;
}