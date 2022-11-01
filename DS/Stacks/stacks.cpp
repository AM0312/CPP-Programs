#include<bits/stdc++.h>
#include<stack>
using namespace std;

void InsertAtBottom(stack<int> &s,int data){
    if(s.empty()){
        s.push(data);
        return;
    }

    int temp=s.top();
    s.pop();
    InsertAtBottom(s,data);
    s.push(temp);
}

void reverse(stack<int> &s){
    if(s.empty()){
        return;
    }
    int temp=s.top();
    s.pop();
    reverse(s);
    InsertAtBottom(s,temp);
}

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    reverse(s);

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}