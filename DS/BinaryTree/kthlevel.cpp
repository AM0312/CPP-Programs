#include <bits/stdc++.h>
#include<queue>
#include<vector>
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

vector<int> printKthLevel(Node* root, int k){
    queue<Node*> que;
 
    que.push(root);
 
    vector<int> s;
 
    int level = 0;
    int flag = 0;
 
    while (!que.empty()) {
 
        int size = que.size();
 
        while (size--) {
            Node* ptr = que.front();
            que.pop();
 
            if (level == k) {
 
                flag = 1;
 
                s.push_back(ptr->data);
            }
            else {
 
                if (ptr->left)
                    que.push(ptr->left);
 
                if (ptr->right)
                    que.push(ptr->right);
            }
        }
 
        level++;
 
        if (flag == 1)
            break;
    }
    return s;
}



int main(){
    Node* root=LevelOrderBuild();
    LevelOrderPrint(root);
    int k;
    cin>>k;
    vector<int> v=printKthLevel(root,k);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}