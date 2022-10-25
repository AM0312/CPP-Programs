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

void traverseTree(node* root,int d,map<int,vector<int> > &m){
    if(root==NULL){
        return;
    }
    m[d].push_back(root->data);
    traverseTree(root->left,d-1,m);
    traverseTree(root->right,d+1,m);
}

void verticalOrderPrint(node* root){
    map<int , vector<int> > m;
    int d=0;
    traverseTree(root,d,m);

    for(auto p:m){
        int key=p.first;
        vector<int> line=p.second;

        for(auto data:line){
            cout<<data<<" ";
        }
        cout<<endl;
    }
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

    verticalOrderPrint(root);
    return 0;
}