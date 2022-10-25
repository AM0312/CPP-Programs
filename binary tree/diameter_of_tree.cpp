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

int height(node* root){
    if(root==NULL){
        return 0;
    }
    int h1=height(root->left);
    int h2=height(root->right);
    return 1+max(h1,h2);
}

int diameter(node* root){
    if(root==NULL){
        return 0;
    }
    int d1=height(root->left)+height(root->right);
    int d2=diameter(root->left);
    int d3=diameter(root->right);
    return max(d1,max(d2,d3));
}

class Hdpair{
public:
    int height;
    int diameter;
};

Hdpair optdia(node *root){
    Hdpair p;
    if(root==NULL){
        p.height=p.diameter=0;
        return p;
    }

    Hdpair left=optdia(root->left);
    Hdpair right=optdia(root->right);

    p.height=max(left.height,right.height)+1;

    int d1=left.height+right.height;
    int d2=left.diameter;
    int d3=right.diameter;
    p.diameter=max(d1,max(d2,d3));
    return p;
}

int main(){
    node* root=buildTree();
    cout<<diameter(root)<<endl;
    cout<<optdia(root).diameter<<endl;
    return 0;
}