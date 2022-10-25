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

class Pair{
public:
    int inc;
    int exc;
};

Pair maxSubsetSum(node* root){
    Pair p;
    if(root==NULL){
        p.inc=p.exc=0;
        return p;
    }
    Pair left=maxSubsetSum(root->left);
    Pair right=maxSubsetSum(root->right);

    p.inc=root->data+left.exc+right.exc;
    p.exc=max(left.inc,left.exc)+max(right.inc,right.exc);
    return p;
}

void levelOrderPrint(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp=q.front();
        if(temp==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
    return;
}

int main(){
    node* root=buildTree();
    levelOrderPrint(root);
    
    Pair p=maxSubsetSum(root);
    cout<<max(p.inc,p.exc)<<endl;
}