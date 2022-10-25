#include<bits/stdc++.h>
using namespace std;

int join_ropes(int ropes[],int n){
    priority_queue<int,vector<int>,greater<int> > pq(ropes,ropes+n);
    int cost=0;

    while(pq.size()>1){
        int a,b;
        a=pq.top();
        pq.pop();
        b=pq.top();
        pq.pop();
        cost+=(a+b);
        pq.push(a+b);
    }
    return cost;
}

int main(){
    int ropes[]={4,3,2,6};
    int n=4;
    cout<<join_ropes(ropes,n);
    return 0;
}