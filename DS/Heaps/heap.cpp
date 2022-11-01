#include<bits/stdc++.h>
#include<queue>
using namespace std;

class compare
{
public:
    bool operator()(int a,int b){
        return a<b;
    }
};




int main(){
    int arr[]={10,15,20,13,6,90};
    int n=sizeof(arr)/sizeof(int);
    priority_queue<int,vector<int>,compare> heap;

    for(int x:arr){
        heap.push(x);
    }

    while(!heap.empty()){
        cout<<heap.top()<<endl;
        heap.pop();
    }

    return 0;
}