#include <bits/stdc++.h>
using namespace std;
 
class Node {
public:
    string data;
    Node* left, *right;
    Node(string d){
        strcpy(data,d);
        left=right=NULL;
    }
};

bool isOp(string data)
{
    if(strcmp(data,'+')==0 || strcmp(data,'-')==0 || strcmp(data,'*')==0 || strcmp(data,'/')==0){
        return true;
    }
    return false;
}

Node* LevelOrderBuild(){
    string d;
    cin>>d;

    Node* root=new Node(d);
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* current=q.front();
        q.pop();

        string c1,c2;
        cin>>c1>>c2;

        if(c1!='-1'){
            current->left=new Node(c1);
            q.push(current->left);
        }

        if(c2!='-1'){
            current->right=new Node(c2);
            q.push(current->right);
        }
    }
    return root;
}



int evalTree(Node* root){
    if(root == NULL) {
        return 0;
    }
    if(!isOp(root->data)) {
        return stoi(root->data);
    }
    if(strcmp(root->data,'+')==0) {
        return evalTree(root->left)+evalTree(root->right);
    }
    if(strcmp(root->data,'-')==0) {
        return evalTree(root->left)-evalTree(root->right);
    }
    if(strcmp(root->data,'*')==0) {
        return evalTree(root->left)*evalTree(root->right);
    }
    if(strcmp(root->data,'/')==0) {
        return evalTree(root->left)/evalTree(root->right);
    }
}

int main(){
    Node* root=LevelOrderBuild();
    LevelOrderPrint(root);
    cout<<evalTree(root);
    return 0;
}