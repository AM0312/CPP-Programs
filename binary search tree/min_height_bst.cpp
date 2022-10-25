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

node* sortedArrayToBST(vector<int> arr,int s,int e){
    if(s>e) return NULL;
    int mid=(s+e)/2;
    node* root=new node(arr[mid]);
    root->left=sortedArrayToBST(arr,s,mid-1);
    root->right=sortedArrayToBST(arr,mid+1,e);
    return root; 
}

int main()
{
    node* root;
    vector<int> arr{1,2,3,4,5,6,7,8};
    int n=arr.size();
    root=sortedArrayToBST(arr,0,n);
    printInOrder(root);
    return 0;
}