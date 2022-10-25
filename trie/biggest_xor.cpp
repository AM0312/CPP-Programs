#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    Node *left,*right;    
};

class Trie{
    Node* root;
public:
    Trie(){
        root=new Node();
    }
    
    void insert(int n){
        Node* temp=root;
        for(int i=31;i>=0;i--){
            int bit=(n>>i)&1;
            if(bit==0){
                if(temp->left==NULL){
                    temp->left=new Node();
                }
                temp=temp->left;
            }
            else{
                if(temp->right==NULL){
                    temp->right=new Node();
                }
                temp=temp->right;
            }
        }
    }

    int max_xor_helper(int value){
        int cur_ans=0;
        Node* temp=root;
        for(int j=31;j>=0;j--){
            int bit=(value>>j)&1;
            if(bit==0){
                if(temp->right!=NULL){
                    temp=temp->right;
                    cur_ans+=(1<<j);
                }
                else{
                    temp=temp->left;
                }
            }
            else{
                if(temp->left!=NULL){
                    temp=temp->left;
                    cur_ans+=(1<<j);
                }
                else{
                    temp=temp->right;
                }
            }
        }
        return cur_ans;
    }

    int max_xor(int *input,int n){
        int max_xor=0;
        for(int i=0;i<n;i++){
            int value=input[i];
            insert(value);
            int cur_xor=max_xor_helper(value);
            max_xor=max(max_xor,cur_xor);
        }
        return max_xor;
    }    
};


int main(){
    int input[]={3,10,5,25,9,2};
    int n=sizeof(input)/sizeof(int);

    Trie t;
    cout<<t.max_xor(input,n)<<endl;

    return 0;
}