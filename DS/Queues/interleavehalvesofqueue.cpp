#include<bits/stdc++.h>
#include<queue>
using namespace std;

queue<int> interleavehalves(queue<int> q){
    queue<int> q1,q2,qq;
    int hv=(q.size())/2;
    for(int i=0;i<hv;i++){
        q1.push(q.front());
        q.pop();
    }
    for(int i=0;i<hv;i++){
        q2.push(q.front());
        q.pop();
    }

    while(q1.empty() or q2.empty()){
        qq.push(q1.front());
        q1.pop();
        qq.push(q2.front());
        q2.pop();
    }
    return qq;    
}

int main(){
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);

    queue<int> ans=interleavehalves(q);
    while(!ans.empty()){
        cout<<ans.front()<<" ";
        ans.pop();
    }

    return 0;
}