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

pair<int,bool> isHeightBalanced(node* root){
    pair<int,bool> p,l,r;
    if(root==NULL){
        p.first=0;
        p.second=true;
        return p;
    }
    l=isHeightBalanced(root->left);
    r=isHeightBalanced(root->right);
    
    p.first=max(l.first,r.first)+1;
    if(abs(l.first-r.first)<=1 and l.second and r.second) p.second=true;
    else p.second=false;
    return p;
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
    // root->left->right->right->left=new node(9);
    // root->left->right->right->right=new node(10);

    pair<int,bool> ans=isHeightBalanced(root);
    if(ans.second) cout<<"Balanced"<<endl;
    else cout<<"not balanced"<<endl;
    return 0;
}