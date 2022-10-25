#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    char data;
    unordered_map<char,Node*> m;
    bool isTerminal;

    Node(char d){
        data=d;
        isTerminal=false;
    }
};

class Trie{
public:
    Node* root;
    Trie(){
        root=new Node('\0');
    }
    
    void insert(string word){
        Node* temp=root;
        for(char ch:word){
            if(temp->m.count(ch)==0){
                Node* n=new Node(ch);
                temp->m[ch]=n;
            }
            temp=temp->m[ch];
        }
        temp->isTerminal=true;
    }
};

void searchHelper(Trie t,string document,int i,unordered_map<string,bool> &m){
    Node* temp=t.root;
    for(int j=i;j<document.length();j++){
        char ch=document[j];
        if(temp->m.count(ch)==0){
            return;
        }
        temp=temp->m[ch];
        if(temp->isTerminal){
            string out=document.substr(i,j-i+1);
            m[out]=true;
        }
    }
    return;
}

void documentSearch(string document,vector<string> words){
    Trie t;
    for(auto w:words){
        t.insert(w);
    }

    unordered_map<string,bool> m;
    for(int i=0;i<document.length();i++){
        searchHelper(t,document,i,m);
    }
    for(auto w:words){
        if(m[w]){
            cout<<w<<" True"<<endl;
        }
        else{
            cout<<w<<" False"<<endl;
        }
    }
    return;
}

int main(){
    string document="little cute cat loves to code in c++,java & python";
    vector<string> words{"cute cat","ttle","cat","quick","big"};

    documentSearch(document,words);

    return 0;
}