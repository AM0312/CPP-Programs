#include <bits/stdc++.h>
#include<queue>
using namespace std;
 
class Node {
public:
    int data;
    Node* left, *right;
    Node(int d){
        data=d;
        left=right=NULL;
    }
};

Node* LevelOrderBuild(){
    int d;
    cin>>d;

    Node* root=new Node(d);
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* current=q.front();
        q.pop();

        int c1,c2;
        cin>>c1>>c2;

        if(c1!=-1){
            current->left=new Node(c1);
            q.push(current->left);
        }

        if(c2!=-1){
            current->right=new Node(c2);
            q.push(current->right);
        }
    }
    return root;
}

void LevelOrderPrint(Node * root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node * temp=q.front();
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

bool isSymmetric(Node* root) {
    queue<Node*> q1;
    queue<Node*> q2;
    if(root == NULL || (root->right==NULL && root->left==NULL)){
        return true;
    }
    if(root->right == NULL || root->left == NULL){
        return false;
    }
    q1.push(root->left);
    q2.push(root->right);
    while(!q1.empty() && !q2.empty())
    {
        Node* f1 = q1.front();
        q1.pop();
        Node* f2 = q2.front();
        q2.pop();
        if(q1.empty() && !q2.empty()) {
            return false;
        }
        if(!q1.empty() && q2.empty()) {
            return false;
        }
        if(f1->left==NULL && f2->right!=NULL) {
            return false;
        }
        if(f1->left!=NULL && f2->right==NULL) {
            return false;
        }
        if(f1->data != f2->data) {
            return false;
        }
        if(f1->left) {
            q1.push(f1->left);
        }
        if(f1->right) {
            q1.push(f1->right);
        }
        if(f2->right) {
            q2.push(f2->right);
        }
        if(f2->left) {
            q2.push(f2->left);
        }
    }
    if(q1.empty() && q2.empty()) {
        return true;
    }
    return false;
}

int main(){
    Node* root=LevelOrderBuild();
    LevelOrderPrint(root);
    if(isSymmetric(root)){
        cout<<"true"<<endl;
        return 0;
    }
    cout<<"false"<<endl;
    return 0;
}