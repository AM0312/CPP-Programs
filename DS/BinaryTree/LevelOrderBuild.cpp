#include<bits/stdc++.h>
#include<queue>
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

int NodeSum(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int sum=0;

    while(!q.empty()){
        Node* temp=q.front();
        if(temp==NULL){
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            q.pop();
            sum+=temp->data;\
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
    return sum;
}

int height(Node* root){
    if(root==NULL){
        return 0;
    }

    int h1=height(root->left);
    int h2=height(root->right);
    return 1+max(h1,h2);
}

int diameter(Node* root){
    if(root==NULL){
        return 0;
    }

    int D1=height(root->left)+height(root->right);
    int D2=diameter(root->left);
    int D3=diameter(root->right);
    return max(max(D1,D2),D3);
}

class HDpair{
public:
    int height;
    int diameter;
};

HDpair optimised_diameter(Node* root){
    HDpair p;

    if(root==NULL){
        p.height=p.diameter=0;
        return p;
    }

    HDpair left=optimised_diameter(root->left);
    HDpair right=optimised_diameter(root->right);

    p.height=max(left.height,right.height)+1;

    int D1=left.height+right.height;
    int D2=left.diameter;
    int D3=right.diameter;

    p.diameter=max(D1,max(D2,D3));
    return p;
}

int main(){
    Node* root=LevelOrderBuild();
    LevelOrderPrint(root);
    cout<<"Diameter of tree is "<<diameter(root)<<endl;
    cout<<"Optimised diameter is "<<optimised_diameter(root).diameter;
    return 0;
}